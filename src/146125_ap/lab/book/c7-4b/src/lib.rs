/*
Creating Idiomatic `use` Paths
*/

#![allow(unused)]
// Bringing the `add_to_waitlist` function into scope with `use`, which is unidiomatic
mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}

use crate::front_of_house::hosting::add_to_waitlist;

pub fn eat_at_restaurant() {
    add_to_waitlist();
}

// Bringing two types with the same name into the same scope requires using their parent modules.
use std::fmt;
use std::io;

fn function1() -> fmt::Result {
    // --snip--
    Ok(())
}

fn function2() -> io::Result<()> {
    // --snip--
    Ok(())
}
