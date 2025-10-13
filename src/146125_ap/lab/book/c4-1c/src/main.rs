/*
Memory and Allocation
*/

#![allow(unused)]
fn main() {
    {
        let s = String::from("hello"); // s is valid from this point forward

        // do stuff with s
    } // this scope is now over, and s is no
    // longer valid

    // Variables and Data Interacting with Move

    let x = 5;
    let y = x;

    let s1 = String::from("hello");
    let s2 = s1;

    // println!("{s1}, world!");

    // Scope and Assignment

    let mut s = String::from("hello");
    s = String::from("ahoy");

    println!("{s}, world!");

    // Variables and Data Interacting with Clone

    let s1 = String::from("hello");
    let s2 = s1.clone();

    println!("s1 = {s1}, s2 = {s2}");

    // Stack-Only Data: Copy

    let x = 5;
    let y = x;

    println!("x = {x}, y = {y}");
}
