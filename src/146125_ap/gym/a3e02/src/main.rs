/*
For the following examples, decide which of the composite data structures is better (enum or structs). Then implement them
  - you are Rick, a car shop owner, and you have to choose the fuel of your car between Diesel, Gasoline, LPG, Methane and Electric
  - you have to program the recognition of the IP version of a router.
    Remember that IPv4 is formatted with 4 group of 3 integer values (from 0 to 255),
    IPv6 is instead formatted with 8 groups of 4 **hexadecimal** (so no strings!) values.
  - you have to track points in a 3-dimensional space, with the f64 values for each dimension
*/

#![allow(unused)]
fn main() {}

enum Fuel {
    Diesel,
    Gasoline,
    LPG,
    Methane,
    Electricity,
}

enum Ip {
    Ipv4([u8; 4]),
    Ipv6([u16; 8]),
}

struct PointNamedFields {
    x: f64,
    y: f64,
    z: f64,
}

// alternative
struct PointUnnamedFields(f64, f64, f64);
