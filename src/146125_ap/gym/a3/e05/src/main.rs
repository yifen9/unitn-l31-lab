/*
Implement two `tuple structs` named `Date` and `Hour`.
The former takes `u8`, `u8` and `u16` and the latter two `u8`
Implement a `BoxShipping` struct, with the fields `name: String`, `barcode: String`, `shipment_date: Date` and `shipment_hour: Hour`
Make BoxShipping displayable both with {:?} as well as with {} argument in the println! macro.
**Note**:
*Date and Hour structs should be formatted correctly, ex. 12/01/2001 and 09:00*
*/

#![allow(unused)]
fn main() {}

use std::fmt::{Display, Formatter, Result};

#[derive(Debug)]
struct Date(u8, u8, u16);
#[derive(Debug)]
struct Hour(u8, u8);

#[derive(Debug)]
struct BoxShipping {
    name: String,
    barcode: String,
    shipment_date: Date,
    shipment_hour: Hour,
}

impl Display for Date {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(f, "{:02}/{:02}/{:04}", self.0, self.1, self.2)
    }
}

impl Display for Hour {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(f, "{:02}:{:02}", self.0, self.1)
    }
}

impl Display for BoxShipping {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(
            f,
            "name: {}, barcode: {}, date of shipment: {}, hour of shipment: {}",
            self.name, self.barcode, self.shipment_date, self.shipment_hour
        )
    }
}
