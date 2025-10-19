/*
Adding Useful Functionality with Derived Traits
*/

#![allow(unused)]
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    {
        let rect1 = Rectangle {
            width: 30,
            height: 50,
        };

        // println!("rect1 is {rect1}");
    }
    {
        let rect1 = Rectangle {
            width: 30,
            height: 50,
        };

        println!("rect1 is {rect1:?}");
    }
    {
        let scale = 2;
        let rect1 = Rectangle {
            width: dbg!(30 * scale),
            height: 50,
        };

        dbg!(&rect1);
    }
}
