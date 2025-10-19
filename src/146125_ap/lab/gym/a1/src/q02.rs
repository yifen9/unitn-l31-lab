/*
Write a function `bigger` that takes two `i32` and returns the bigger number (`i32`)
without using another function call and additional variables;
*/

fn bigger(int1: i32, int2: i32) -> i32 {
    if int1 >= int2 {
        return int1;
    } else {
        return int2;
    }
}
