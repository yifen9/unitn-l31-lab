/*
We want to:
  - Write a function `append` that takes a `String`, appends the word "foobar" to it and returns it;
  - Write a `main` function in which we:
      - Declare a `String` initialized with some text.;
      - Pass the `String` to the function `append`;
      - Print the original `String` and the one returned by `append`;
        (do it in this order!)
*/

fn append(mut s: String) -> String {
    s.push_str("foobar");
    s
}

fn main() {
    let s1 = "test ".to_string();
    let s2 = append(s1.clone());
    println!("{}, {}", s1, s2);
}
