use autocxx::include_cpp;

include_cpp! {
	#include "SteamEngine.hpp"
	#include "SteamUser.hpp"
	#include "SteamUtils.hpp"
	#include "SteamUGC.hpp"
	safety!(unsafe_ffi)
	generate!("IEngine")
	generate!("CSteamID")
	generate!("SteamUser")
	generate!("SteamUtils")
	generate!("IUGC")
}

pub use ffi::*;
pub use autocxx::{c_int, c_long, c_longlong, c_short, c_uchar, c_uint, c_ulong, c_ulonglong, c_ushort, c_void};
