/*
Updating a String
*/

#![allow(unused)]
fn main() {
    // Appending to a String with `push_str` and `push`
    {
        {
            let mut s = String::from("foo");
            s.push_str("bar");
        }
        {
            let mut s1 = String::from("foo");
            let s2 = "bar";
            s1.push_str(s2);
            println!("s2 is {s2}");
        }
        {
            let mut s = String::from("lo");
            s.push('l');
        }
    }

    // Concatenation with the `+` Operator or the `format!` Macro
    {
        {
            let s1 = String::from("Hello, ");
            let s2 = String::from("world!");
            let s3 = s1 + &s2; // note s1 has been moved here and can no longer be used
        }
    }
    {
        let s1 = String::from("tic");
        let s2 = String::from("tac");
        let s3 = String::from("toe");

        let s = s1 + "-" + &s2 + "-" + &s3;
    }
    {
        let s1 = String::from("tic");
        let s2 = String::from("tac");
        let s3 = String::from("toe");

        let s = format!("{s1}-{s2}-{s3}");
    }
}
