/*
Scalar Types
*/

#![allow(unused)]
fn main() {
    // Floating-Point Types
    {
        let x = 2.0; // f64

        let y: f32 = 3.0; // f32
    }

    // Numeric Operations
    {
        // addition
        let sum = 5 + 10;

        // subtraction
        let difference = 95.5 - 4.3;

        // multiplication
        let product = 4 * 30;

        // division
        let quotient = 56.7 / 32.2;
        let truncated = -5 / 3; // Results in -1

        // remainder
        let remainder = 43 % 5;
    }

    // The Boolean Type
    {
        let t = true;

        let f: bool = false; // with explicit type annotation
    }

    // The Character Type
    {
        let c = 'z';
        let z: char = 'ℤ'; // with explicit type annotation
        let heart_eyed_cat = '😻';
    }
}
