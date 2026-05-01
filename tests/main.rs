use std::ffi::{c_char, c_int};

#[repr(C)]
pub struct ffiConfig {
    pub no: *mut c_char,
    pub so: *mut c_char,
    pub we: *mut c_char,
    pub f: c_int,
    pub c: c_int,
}

/**
 * Create File `.cub` and run cub3d if it exist with the generate map
 */
fn generate_file_cub() {
    todo!()
}

fn main() {
    println!("Run cargo test");
}

#[cfg(test)]
mod test {
    use super::*;
    use std::ffi::CString;
    use std::fs::File;
    use libc::{c_char, c_int};

    /*
    `*mut c_char` -> char *
    `*const c_char` -> const char *
    `*mut ffiConfig` -> *t_config
    */
    unsafe extern "C" {
    fn ft_valid_path(filename: *const c_char) -> c_int;
    fn ft_parser(config: *mut ffiConfig ,filename: *const c_char) -> c_int;
    fn file_exist(filename: *const c_char) -> c_int;
    }

    fn run_ft_valid_path(filename: &str, return_code: i32) {
        File::create(filename).expect("FAIL: create file function");
        let c_str = CString::new(filename).unwrap();

        unsafe {
            let res = ft_valid_path(c_str.as_ptr());
            assert_eq!(res, return_code);
        }
        std::fs::remove_file(filename).expect("FAIL: remove file function");
    }


    #[test]
    fn valid_path() {
        run_ft_valid_path("valid.cub", 1);
    }

    #[test]
    fn double_ext() {
        run_ft_valid_path("a.cub.cub", 1);
    }

    #[test]
    fn contains_ext() {
        run_ft_valid_path("a.cub.vala", 0);
    }

    #[test]
    fn filename_less_than_four_letter() {
        run_ft_valid_path("a.S", 0);
    }


    #[test]
    fn golbal_parser() {
        let file_name = "a.cub";
        let mut config = ffiConfig {
            no: std::ptr::null_mut(),
            so: std::ptr::null_mut(),
            we: std::ptr::null_mut(),
            f: 0,
            c: 0,
        };
        File::create(file_name).expect("FAIL: create file function");
        let c_str = CString::new(file_name).unwrap();
        unsafe {
            let res = ft_parser(&mut config, c_str.as_ptr());
            assert_eq!(res, 1);
        }
        std::fs::remove_file(file_name).expect("FAIL: remove file function");
    }
}
