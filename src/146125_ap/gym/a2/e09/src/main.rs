/*
Create a `Vec` that can contain both an `i32` and a `String`;
*/

#![allow(unused)]

enum DoubleType {
    T1(i32),
    T2(String),
}

pub fn main() {
    let _double_vector = vec![DoubleType::T1(1), DoubleType::T2(String::from("Hello"))];
}
