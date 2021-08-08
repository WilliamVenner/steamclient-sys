use std::path::PathBuf;

pub fn download(steamcmd_path: &PathBuf) {
	std::fs::create_dir_all(steamcmd_path.parent().unwrap()).unwrap();

	let response = reqwest::blocking::Client::new().get({
		#[cfg(windows)] {
			"https://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip"
		}
		#[cfg(unix)] {
			"https://steamcdn-a.akamaihd.net/client/installer/steamcmd_linux.tar.gz"
		}
	}).timeout(std::time::Duration::from_secs(30)).send().expect("Failed to get SteamCMD");

	let response = match response.status().as_u16() {
		200..=299 => response.bytes().expect("Failed to decode bytes"),
		code @ _ => panic!("HTTP {} from SteamCMD CDN", code)
	};

	let dir = steamcmd_path.parent().unwrap();

	#[cfg(windows)] {
		let mut zip = zip::ZipArchive::new(std::io::Cursor::new(response)).expect("Failed to read zip header");
		zip.extract(dir).expect("Failed to extract zip");
	}

	#[cfg(unix)] {
		let tar = flate2::read::GzDecoder::new(std::io::Cursor::new(response));
		let mut archive = tar::Archive::new(tar);
		archive.unpack(dir).expect("Failed to extract zip");
	}
}