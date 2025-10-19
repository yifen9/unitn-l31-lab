/*
Create a vending machine.
  1 Define an `enum Item` that lists the available items inside the machine (e.g. Coke, Coffee, ecc).
  2 Define the `enum Coin` that contains the coin type accepted by the machine (e.g. `Coin::FiftyCents`, `Coin::Euro2`).
    And implement the method `to_cents` that convert a `Coin` variant into a `u32`
    representing the number of cents (e.g. `1€ => 100`, `20¢ => 20`).
  3 Define the `struct VendingMachine` that has the following fields:

      - `coins: u32`
        This field represents the number of cents currently held inside the machine
        (e.g. if the user inserted 1€ and 10¢, then the `coins` should be at `110`).
      - `items: HashMap<Item, usize>`
        This field should associate an Item type to the number of available items to buy.

    Now implement the following methods for `VendingMachine`:

      - `new` method that takes an `HashMap` of Items contained in the `VendingMachine` initially
        and returns a new instance of the `struct`, set `coins` to 0.
      - `add_item` takes an `Item` variant and a `usize`;
        increments the number of the specified type of items contained by the machine
      - `insert_coin` takes a `Coin` variant and increment the field `coins` by the right value.
        Returns a `Result<&str, &str>` with the confirmation/error message.
      - `get_item_price` takes an `&Item` variant and returns a `u32` item price.
      - `buy` takes a `Item` variant and returns a `Result<u32, &str>`
        if you have enough money it returns the change,
        if you don't, it returns the error as a `&str`.

    **Note**:
    *For using `Item` as an `HashMap` key it needs to implement `PartialEq`, `Eq` and `Hash`. Keep in mind that you can derive them.*
*/

fn main() {}

use std::collections::HashMap;

pub struct VendingMachine {
    coins: u32,
    items: HashMap<Item, usize>,
}

impl VendingMachine {
    pub fn new(items: HashMap<Item, usize>) -> Self {
        Self { coins: 0, items }
    }

    pub fn add_item(&mut self, item: Item, qty: usize) {
        self.items.insert(item, qty);
    }

    pub fn insert_coin(&mut self, coin: Coin) -> Result<&str, &str> {
        let result = match coin {
            Coin::Cent10 => Ok("10 Cent inserted"),
            Coin::Cent20 => Ok("20 Cent inserted"),
            Coin::Cent50 => Ok("50 Cent inserted"),
            Coin::Eur1 => Ok("1 Euro inserted"),
            Coin::Eur2 => Ok("2 Euro inserted"),
            // _ => Err("Invalid coin inserted"),
        };

        if result.is_ok() {
            self.coins += coin.to_cents();
        }
        result
    }

    pub fn get_item_price(&self, item: &Item) -> u32 {
        match item {
            Item::Coke => 350,
            Item::Water => 100,
            Item::Tea => 250,
            Item::Sprite => 300,
        }
    }

    pub fn buy(&mut self, item: Item) -> Result<u32, &str> {
        let price = self.get_item_price(&item);

        if self.coins >= price {
            if let Some(available) = self.items.get_mut(&item) {
                if *available > 0 {
                    let change = self.coins - price;
                    self.coins = 0;
                    *available -= 1;
                    Ok(change)
                } else {
                    Err("Item finished")
                }
            } else {
                Err("Item not available")
            }
        } else {
            Err("Not enough money")
        }
    }
}

pub enum Coin {
    Cent10,
    Cent20,
    Cent50,
    Eur1,
    Eur2,
}

impl Coin {
    pub fn to_cents(&self) -> u32 {
        match self {
            Coin::Cent10 => 10,
            Coin::Cent20 => 20,
            Coin::Cent50 => 50,
            Coin::Eur1 => 100,
            Coin::Eur2 => 200,
        }
    }
}

#[derive(PartialEq, Eq, Hash, Debug)]
pub enum Item {
    Coke,
    Water,
    Tea,
    Sprite,
}
