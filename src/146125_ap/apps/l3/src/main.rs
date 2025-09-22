fn no_dangle() -> String {
    let s = String::from("hello");
    s
}

fn main() {
    {
        let s1: i32 = 5;
        let _s2: i32 = s1;
        println!("{}", _s2);
    }
    let mut s = String::from("hello");

    let r1 = &s;
    let r2 = &s;
    let r3 = &s;
    println!("r1 and r2 and r3: {} and {} and {}", r1, r2, r3);

    let r3 = &mut s;
    println!("r3: {}", r3);
    println!("r1 and r2 and r3: {}", r3);
    println!("no_dangle: {}", no_dangle());
}
