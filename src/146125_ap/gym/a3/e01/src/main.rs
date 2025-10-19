/*
Given a number determine whether it is valid per the **Luhn formula**, creating the function `is_it_luhn`

The Luhn algorithm is a simple checksum formula used to validate a variety of identification numbers,
such as credit card numbers. Check if a given string is valid

Strings of length 1 or less are not valid.
Spaces are allowed in the input, but they should be stripped before checking.
All other non-digit characters are disallowed.

Ex 1: valid card number

**4539 3195 0343 6467**

The first step is to double every second digit, starting from the right. We will be doubling

*43 39 04 66*

If doubling the number results in a number greater than 9 then subtract 9 from the product. The results of our doubling:

**8569 6195 0383 3437**

Then sum all the digits is 80. If the sum is divisible by 10, then the number is valid.
*/

#![allow(unused)]
fn main() {}

fn is_it_luhn(s: String) -> bool {
    if s.len() <= 1 {
        false
    } else {
        let mut sum: u32 = 0;

        for (index, mut digit) in
            s.chars()
                .rev()
                .enumerate()
                .map(|(index, value)| match value.to_digit(10) {
                    Some(d) => (index, d),
                    None => panic!("NaN"),
                })
        {
            if index % 2 != 0 {
                digit *= 2;
                if digit > 9 {
                    digit -= 9
                }
            }
            sum += digit;
        }

        sum % 10 == 0
    }
}

fn is_it_luhn_optimal(s: String) -> bool {
    if s.len() <= 1 {
        false
    } else {
        s.chars()
            .rev()
            .enumerate()
            .map(|(index, value)| match value.to_digit(10) {
                Some(mut digit) => {
                    if index % 2 != 0 {
                        digit *= 2;
                        if digit > 9 {
                            digit -= 9
                        }
                        digit
                    } else {
                        digit
                    }
                }
                None => panic!("NaN"),
            })
            .sum::<u32>()
            % 10
            == 0
    }
}
