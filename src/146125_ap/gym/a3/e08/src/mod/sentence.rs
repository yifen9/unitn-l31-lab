#![allow(unused)]

use std::fmt::{Display, Formatter, Result};

pub struct Sentence {
    pub words: Vec<String>,
}

impl Display for Sentence {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(f, "{}", self.words.join(" "))
    }
}

impl Sentence {
    pub fn new_default() -> Self {
        Sentence { words: vec![] }
    }

    pub fn new(s: &str) -> Self {
        Sentence {
            words: s.split_whitespace().map(|str| str.to_string()).collect(),
        }
    }

    pub fn add_word(&mut self, word: String) {
        self.words.push(word);
    }
}
