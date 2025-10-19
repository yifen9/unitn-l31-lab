/*
Write a function `count_character` that takes a string consisting of ASCII characters `string` as input and returns a HashMap.
The keys of the HashMap should be the characters in the string,
and the values should be an u32 representing how many times each character appears in the string.
*/

use std::collections::HashMap;

fn count_character(string: &str) -> HashMap<char, u32> {
    let mut map = HashMap::<char, u32>::new();

    for c in string.chars() {
        if let Some(val) = map.get_mut(&c) {
            *val += 1;
        } else {
            map.insert(c, 1);
        }
    }

    map
}

fn count_character_recursive(string: &str) -> HashMap<char, u32> {
    let mut map = HashMap::<char, u32>::new();

    if let Some(val) = string.chars().nth(0) {
        map.insert(val, 1);
    } else {
        return map;
    }

    let map_2 = count_character_recursive(&string[1..]);

    for (c, n) in map_2 {
        if let Some(val) = map.get_mut(&c) {
            *val += n;
        } else {
            map.insert(c, n);
        }
    }

    map
}
