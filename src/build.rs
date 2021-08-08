use std::path::PathBuf;

#[cfg(all(target_os = "windows", target_pointer_width = "64"))]
const STEAMCLIENT_DEPENDENCIES: &[&'static str] = &["steamclient64.dll", "vstdlib_s64.dll", "tier0_s64.dll"];
#[cfg(all(target_os = "windows", target_pointer_width = "32"))]
const STEAMCLIENT_DEPENDENCIES: &[&'static str] = &["steamclient.dll", "vstdlib_s.dll", "tier0_s.dll"];
#[cfg(target_os = "linux")]
const STEAMCLIENT_DEPENDENCIES: &[&'static str] = &["steamclient.so", "vstdlib_s.so", "tier0_s.so"];

#[allow(unused_macros)]
macro_rules! out_path {
	($path:literal) => {
		std::path::PathBuf::from(std::env::var("OUT_DIR").unwrap()).join($path)
	};
}

#[cfg(feature = "steamcmd")]
mod steamcmd;

#[derive(Copy, Clone, Debug)]
pub enum Target {
	Windows64,
	Windows32,
	Linux64,
	Linux32
}
impl Target {
	pub fn get() -> Target {
		let target = std::env::var("TARGET").unwrap();
		if target.starts_with("aarch64") || target.starts_with("x86_64") {
			// 64-bit
			if target.contains("windows") {
				Target::Windows64
			} else if target.contains("linux") {
				Target::Linux64
			} else {
				panic!("Unsupported target");
			}
		} else if target.starts_with("i686") {
			// 32-bit
			if target.contains("windows") {
				Target::Windows32
			} else if target.contains("linux") {
				Target::Linux32
			} else {
				panic!("Unsupported target");
			}
		} else {
			panic!("Unsupported target");
		}
	}
}

fn main() {
	println!("cargo:rerun-if-changed=src/build.rs");
    println!("cargo:rerun-if-env-changed=STEAMCLIENTDIR");

	let out_dir = PathBuf::from(std::env::var("OUT_DIR").unwrap());
	let target = Target::get();

	if let Ok(steamclient_dir) = std::env::var("STEAMCLIENTDIR") {
		let steamclient_dir = PathBuf::from(steamclient_dir);
		for dependency in STEAMCLIENT_DEPENDENCIES.iter() {
			let path = steamclient_dir.join(dependency);
			if !path.exists() {
				panic!("Couldn't find {} in this STEAMCLIENTDIR!", dependency);
			}
			std::fs::copy(path, out_dir.join(dependency)).unwrap();
		}
	} else {
		#[cfg(not(feature = "steamcmd"))] {
			panic!("STEAMCLIENTDIR is not set!");
		}

		#[cfg(feature = "steamcmd")] {
			let steamcmd_path = out_dir.join({
				#[cfg(windows)] {
					"steamcmd/windows/steamcmd.exe"
				}
				#[cfg(unix)] {
					"steamcmd/linux/steamcmd.sh"
				}
			});

			if steamcmd_path.exists() {
				steamcmd::update(&steamcmd_path, target);
			} else {
				steamcmd::download(&steamcmd_path);
				steamcmd::update(&steamcmd_path, target);
			}

			match target {
				Target::Windows64 | Target::Windows32 => {
					#[cfg(windows)]
					let redist_dir = steamcmd_path.parent().unwrap().join("steamapps/common/Steamworks SDK Redist");

					#[cfg(unix)]
					let redist_dir = dirs::home_dir().unwrap().join("~/Steam/steamapps/common/Steamworks SDK Redist");

					if !redist_dir.is_dir() {
						panic!("Missing {}", redist_dir.canonicalize().unwrap_or(redist_dir).display());
					}
					for entry in redist_dir.read_dir().unwrap() {
						let entry = entry.unwrap();
						if entry.file_type().unwrap().is_file() {
							std::fs::copy(entry.path(), out_dir.join(entry.file_name())).unwrap();
						}
					}
				},
				Target::Linux32 | Target::Linux64 => {
					let relative_path = format!("steamapps/common/Steamworks SDK Redist/{}steamclient.so", match target {
						Target::Linux32 => "",
						Target::Linux64 => "linux64/",
						_ => unreachable!()
					});

					#[cfg(unix)]
					let redist_path = dirs::home_dir().unwrap().join("Steam").join(relative_path);

					#[cfg(windows)]
					let redist_path = steamcmd_path.join(relative_path);

					if !redist_path.is_file() {
						panic!("Missing {}", redist_path.canonicalize().unwrap_or(redist_path).display());
					}

					std::fs::copy(redist_path, out_dir.join("steamclient.so")).unwrap();
				}
			}
		}
	};

	let link_file_name = match target {
		Target::Windows64 => "steamclient64",
		Target::Windows32 | Target::Linux64 | Target::Linux32 => "steamclient"
	};

    println!("cargo:rustc-link-search={}", out_dir.display());
    println!("cargo:rustc-link-lib=dylib={}", link_file_name);

    let mut build = autocxx_build::build("src/lib.rs", &[&PathBuf::from("lib/bindings")], &[]).unwrap();
    build.flag_if_supported("-std=c++14")
	.compile(&link_file_name);
}