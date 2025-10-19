/*
Write a function `string_reverse` that takes a `&str` as input and returns it, reversed as a `String`;
*/

fn string_reverse_with_rev(s: &str) -> String {
    let mut out = String::new();
    for c in s.chars().rev() {
        out.push(c);
    }
    out
}

fn string_reverse_with_pop_match(s: &str) -> String {
    let mut out = String::new();
    let mut s = s.to_string();
    loop {
        match s.pop() {
            None => break,
            Some(c) => out.push(c),
        }
    }
    out
}

fn string_reverse_with_pop_while_let(s: &str) -> String {
    let mut out = String::new();
    let mut s = s.to_string();
    while let Some(c) = s.pop() {
        out.push(c);
    }
    out
}

fn string_reverse_with_collect(s: &str) -> String {
    s.chars().rev().collect()
}
