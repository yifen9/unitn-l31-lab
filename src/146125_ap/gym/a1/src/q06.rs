/*
Write a function `lord_farquaad` that takes a `String` and outputs another `String`
in which every character 'e' is substituted by the character '💥';
*/

fn lord_farquaad_better(ee: String) -> String {
    ee.replace("e", "💥")
}

fn lord_farquaad(ee: String) -> String {
    let mut new_ee = String::new();
    for c in ee.chars() {
        if c == 'e' {
            new_ee.push_str("💥");
        } else {
            new_ee.push(c);
        }
    }
    new_ee
}
