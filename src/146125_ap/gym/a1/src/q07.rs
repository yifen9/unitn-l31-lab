/*
In the main function initialize a `HashMap<String, f32>` called `furniture`
that stores the pair `String` as key and `f32` as value,
where the `String` is the name of the furniture and the `f32` is its price.
Then write a function that borrows the `HashMap`,
takes a `furniture: String` as input and returns the corresponding `f32`.
If there is no such furniture in the `HashMap`, return `-1.0`;
*/

use std::collections::HashMap;

// Either return a reference or clone the value
// applies to all the solutions
fn get_furniture(furniture: &HashMap<String, f32>, name: String) -> &f32 {
    furniture.get(name.as_str()).unwrap_or(&-1.0)
}

fn get_furniture_2(furniture: &HashMap<String, f32>, name: String) -> &f32 {
    match furniture.get(name.as_str()) {
        Some(x) => x,
        None => &-1.0,
    }
}

fn get_furniture_3(furniture: &HashMap<String, f32>, name: String) -> f32 {
    if let Some(x) = furniture.get(name.as_str()) {
        x.clone()
    } else {
        -1.0
    }
}

fn main() {
    let mut furniture: HashMap<String, f32> = HashMap::new();
    furniture.insert("Sofa".to_string(), 1200.);
    furniture.insert("Lamp".to_string(), 149.99);
    furniture.insert("Television".to_string(), 700.50);
    furniture.insert("Table".to_string(), 1499.99);
}
