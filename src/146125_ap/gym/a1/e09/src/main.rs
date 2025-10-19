/*
An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
For example:
  - `9` is an Armstrong number, because $9 = 9^1 = 9$
  - `10` is not an Armstrong number, because $10 ≠ 1^2 + 0^2 = 1$
  - `153` is an Armstrong number, because: $153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153$
  - `154` is not an Armstrong number, because: $154 ≠ 1^3 + 5^3 + 4^3 = 1 + 125 + 64 = 190$
    Write the function `is_armstrong` that determines whether a number is an Armstrong number;
*/

fn main() {}

pub fn is_armstrong(mut n: i32) -> bool {
    let original = n.clone();
    let mut digits = Vec::new();

    while n != 0 {
        digits.push(n % 10);
        n /= 10;
    }

    let num_digits = digits.len() as u32;
    let mut sum = 0;
    for d in digits {
        sum += d.pow(num_digits);
    }
    original == sum
}
