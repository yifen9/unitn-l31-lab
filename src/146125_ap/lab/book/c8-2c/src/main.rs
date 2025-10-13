/*
Indexing into Strings
*/

#![allow(unused)]
fn main() {
    {
        let s1 = String::from("hi");
        // let h = s1[0];
    }

    // Internal Representation
    {
        {
            let hello = String::from("Hola");
        }
        {
            let hello = String::from("Здравствуйте");
        }
        {
            let hello = "Здравствуйте";
            // let answer = &hello[0];
        }
    }

    // Slicing Strings
    {
        {
            let hello = "Здравствуйте";

            let s = &hello[0..4];
        }
    }
}
