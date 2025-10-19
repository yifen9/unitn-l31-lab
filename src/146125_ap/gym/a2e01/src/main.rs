/*
Write a function called `modify_odd`
that takes a mutable reference to an array slice of integers `slice` and sets all odd numbers to 0.
Then write a second function that create a Vec,
filled with all numbers from 0 to 100, and pass it to `modify_odd`;
*/

#![allow(unused)]
fn main() {}

fn modify_odd(slice: &mut [u32]) {
    for elem in slice {
        if *elem % 2 == 1 {
            *elem = 0;
        }
    }
}

fn modify_odd_iterators(slice: &mut [u32]) {
    slice.iter_mut().for_each(|x| {
        if *x % 2 == 1 {
            *x = 0
        }
    });
}

fn modify_odd_recursive(slice: &mut [u32]) {
    if slice.len() == 0 {
        return;
    }
    if slice[0] % 2 != 0 {
        slice[0] = 0;
    }
    modify_odd_recursive(&mut slice[1..]);
}
