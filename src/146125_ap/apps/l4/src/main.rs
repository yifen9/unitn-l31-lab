pub enum IpAddrKind {
    V4,
    V6,
}
enum IpAddr {
    V4(i32,i32,i32,i32),
    V6(String),
    V0(),
}


///     https://doc.rust-lang.org/book/ch06-00-enums.html
pub fn enum_usage(){
    let _four = IpAddrKind::V4;
    let _six = IpAddrKind::V6;

    let loopback = IpAddr::V6(String::from("::1"));
    let home = IpAddr::V4(127, 0, 0, 1);
}

fn main() {
    println!("Hello, world!");

    let mut  v = vec![String::from("something");10];
    // QUIZ: can i uncomment both lines?
    // let first_nonmut = v[0];
    // let sec_nonmut = v[1];

    let first_nonnmut = &v[0];
    // note that this now is a &String

    let mut first_mut = v.get_mut(0).unwrap();
    first_mut.push_str(" else");
    println!("First Element: {}",first_mut);

    let second_nonnmut = v.get(1).unwrap();
    // QUIZ: what happens if we write
    // println!("First Element: {}",first_mut);
    // nothing: it works // compiler error

    // let cheat = &mut first_mut;  //DNC
    let third_nonmut = v.get(2).unwrap();
    println!("Nonmut: second and third {}, {}", second_nonnmut, third_nonmut);

    let (v05, v6plus) = v.split_at_mut(6);
    let mut one_mut = v05.get_mut(5).unwrap();
    one_mut.push('a');
    let mut two_mut = v6plus.get_mut(0).unwrap();
    println!("5: {}, 6: {}",one_mut, two_mut);

    let mut vv = [v05,v6plus].concat();
    println!("{:?} == {:?}",v,vv);

    let x: i8 = 5;
    let y: Option<i8> = None; //Some(5);
    // QUIZ: can i do:
    // let sum = x + y;

    let nopt : Option<i32> = None;
    let opt = Some(10);

    let xxv = nopt.unwrap();
}
