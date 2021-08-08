use std::path::PathBuf;

use crate::Target;

/// Until Rust provides a way of detecting cargo check in a build script, let's only do this once a day...
fn check() -> Result<bool, Box<dyn std::error::Error>> {
	use std::convert::TryInto;

	const ONE_DAY: u64 = 60 * 60 * 24;

	let build_timestamp_path = out_path!("steamclient_sys_build_timestamp");
	let build_timestamp = std::fs::read(&build_timestamp_path)?;
	let build_timestamp = u64::from_le_bytes(build_timestamp.try_into().unwrap());

	let unix_timestamp = std::time::SystemTime::now().duration_since(std::time::UNIX_EPOCH)?.as_secs();

	if unix_timestamp - build_timestamp < ONE_DAY {
		Ok(true)
	} else {
		std::fs::write(build_timestamp_path, &unix_timestamp.to_le_bytes())?;
		Ok(false)
	}
}

pub fn update(steamcmd_path: &PathBuf, target: Target) {
	if check().unwrap_or_default() { return; }

	#[cfg(unix)]
	assert!(std::process::Command::new("chmod").args(&["+x", &steamcmd_path.to_string_lossy()]).output().unwrap().status.success(), "Failed to chmod steamcmd");

	std::process::Command::new(&steamcmd_path).args(&[
		"+@sSteamCmdForcePlatformType", match target {
			Target::Linux32 | Target::Linux64 => "linux",
			Target::Windows32 | Target::Windows64 => "windows",
		},
		"+@sSteamCmdForcePlatformBitness", match target {
			Target::Linux32 | Target::Windows32 => "32",
			Target::Linux64 | Target::Windows64 => "64",
		},
		"+login", "anonymous",
		"+app_update", "1007",
		"+quit"
	]).output().unwrap();
}