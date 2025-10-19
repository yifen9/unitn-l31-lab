/*
Concise Control Flow with `if let` and `let else`
*/

#![allow(unused)]
#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
    // --snip--
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn main() {
    {
        let config_max = Some(3u8);
        match config_max {
            Some(max) => println!("The maximum is configured to be {max}"),
            _ => (),
        }
    }
    {
        let config_max = Some(3u8);
        if let Some(max) = config_max {
            println!("The maximum is configured to be {max}");
        }
    }
    {
        let coin = Coin::Penny;
        let mut count = 0;
        match coin {
            Coin::Quarter(state) => println!("State quarter from {state:?}!"),
            _ => count += 1,
        }
    }
    {
        let coin = Coin::Penny;
        let mut count = 0;
        if let Coin::Quarter(state) = coin {
            println!("State quarter from {state:?}!");
        } else {
            count += 1;
        }
    }
}
