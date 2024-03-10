
#[diplomat::bridge]
mod ffi {

    #[diplomat::opaque]
    pub struct Example;
    
    impl Example {
        pub fn new() -> Box<Example> {
            Box::new(Example)
        }

        pub fn do_something<'a>(&'a self,bytes: &'a mut [u8]) {
            let to_write = "Hello, World!".as_bytes();
            for (i, byte) in to_write.iter().enumerate() {
                bytes[i] = *byte;
            }
        }
    } 

    
}