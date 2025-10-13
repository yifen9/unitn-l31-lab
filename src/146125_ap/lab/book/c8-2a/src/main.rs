/*
Creating a New String
*/

#![allow(unused)]
fn main() {
    {
        let mut s = String::new();
    }
    {
        let data = "initial contents";

        let s = data.to_string();

        // The method also works on a literal directly:
        let s = "initial contents".to_string();
    }
    {
        let s = String::from("initial contents");
    }
    {
        let hello = String::from("السلام عليكم");
        let hello = String::from("Dobrý den");
        let hello = String::from("Hello");
        let hello = String::from("שלום");
        let hello = String::from("नमस्ते");
        let hello = String::from("こんにちは");
        let hello = String::from("안녕하세요");
        let hello = String::from("你好");
        let hello = String::from("Olá");
        let hello = String::from("Здравствуйте");
        let hello = String::from("Hola");
    }
}
