use std::env;

fn main() {
    let dir = env::current_dir().expect("Failed to get the current dir");
    println!("cargo:rustc-link-search=native={}/build", dir.display());
    println!("cargo:rustc-link-search=native={}/build/subprojects/libft", dir.display());
    println!("cargo:rustc-link-lib=dylib=cubparser");
    println!("cargo:rustc-link-lib=static=ft");
}