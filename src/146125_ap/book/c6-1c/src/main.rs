/*
The `Option` Enum and Its Advantages Over Null Values
*/

#![allow(unused)]
fn main() {
    {
        enum Option<T> {
            None,
            Some(T),
        }
    }
    {
        let some_number = Some(5);
        let some_char = Some('e');

        let absent_number: Option<i32> = None;
    }
    {
        let x: i8 = 5;
        let y: Option<i8> = Some(5);

        // let sum = x + y;
    }
}
