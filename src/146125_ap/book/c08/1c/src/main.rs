/*
Reading Elements of Vectors
*/

#![allow(unused)]
fn main() {
    {
        let v = vec![1, 2, 3, 4, 5];

        let third: &i32 = &v[2];
        println!("The third element is {third}");

        let third: Option<&i32> = v.get(2);
        match third {
            Some(third) => println!("The third element is {third}"),
            None => println!("There is no third element."),
        }
    }
    {
        let v = vec![1, 2, 3, 4, 5];

        // let does_not_exist = &v[100];
        // let does_not_exist = v.get(100);
    }
    {
        let mut v = vec![1, 2, 3, 4, 5];

        let first = &v[0];

        // v.push(6);

        println!("The first element is: {first}");
    }
}
