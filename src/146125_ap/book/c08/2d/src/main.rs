/*
Methods for Iterating Over Strings
*/

fn main() {
    {
        for c in "Зд".chars() {
            println!("{c}");
        }
    }
    {
        for b in "Зд".bytes() {
            println!("{b}");
        }
    }
}
