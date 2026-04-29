use std::ffi::CString;
use libc::c_char;

/*
    `*mut c_char` -> char *
    `*const c_char` -> const char *
*/
unsafe extern "C" {
    fn ft_valid_path(filename: *const c_char);
}

fn main() {
    let c_str = CString::new("a.d").expect("FAIL");
    unsafe { ft_valid_path(c_str.as_ptr()); }
}

#[cfg(test)]
mod test {
    use super::*;
    use std::ffi::CString;

    #[test]
    fn valid_path() {
        let c_str = CString::new("a.cub").expect("Failed to create CString");
        unsafe {
            ft_valid_path(c_str.as_ptr());
        }
    }
}