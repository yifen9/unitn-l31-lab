#![allow(unused)]

use self::sentence::Sentence;
use std::collections::HashMap;

pub mod sentence;

fn magic_sentence(map: &HashMap<i32, Sentence>, i: i32, j: i32) -> Result<Sentence, &str> {
    let si = match map.get(&i) {
        Some(e) => e,
        None => return Err("i not found"),
    };

    let sj = match map.get(&j) {
        Some(e) => e,
        None => return Err("j not found"),
    };

    let mut sentence = Sentence::new_default();

    for (wordi, wordj) in si.words.iter().zip(sj.words.iter()) {
        if wordi == wordj {
            sentence.add_word(wordi.clone());
        }
    }

    Ok(sentence)
}
