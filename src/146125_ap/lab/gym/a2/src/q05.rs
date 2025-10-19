/*
Write the following functions,
for each of the functions think carefully
about what is the best way to pass the arguments (&, &mut or passing ownership):
  - Write a function `max` that takes a Vec of i32 and returns the maximum value inside it.
  - Write a function `swap` that swaps the first and last element of a vector of i32.
  - Write a function `is_sorted` that takes a Vec of i32
    and returns a boolean indicating whether the vector is sorted in non-decreasing order.
  - Write a function `insert_if_longer` that takes a Vec of String (`vec`) and a String (`string`).
    This function should insert `string` into `vec` only if the length of `string` is greater than 10.
Also, when possible, implement these functions recursively, not iteratively.
*/

fn max(vec: &Vec<i32>) -> Option<i32> {
    if vec.len() == 0 {
        return Option::None;
    }

    let mut max = vec[0];
    for val in vec.iter() {
        if *val > max {
            max = *val;
        }
    }
    Option::Some(max)
}

// note: in general is always better using &[T] instead of &Vec<T> since it makes your code more flexible
fn max_2(vec: &[i32]) -> Option<i32> {
    if vec.len() == 0 {
        return Option::None;
    }
    let mut max = vec[0];
    for val in vec.iter() {
        if *val > max {
            max = *val;
        }
    }
    Option::Some(max)
}

fn max_recursive(vec: &[i32]) -> Option<i32> {
    if vec.len() == 0 {
        return Option::None;
    }
    if vec.len() == 1 {
        return Option::Some(vec[0]);
    }

    let (v1, v2) = vec.split_at(vec.len() / 2);

    let max_1 = max_recursive(v1);
    let max_2 = max_recursive(v2);

    match (max_2, max_1) {
        (Option::None, Option::None) => None,
        (Option::Some(e), Option::None) => Some(e),
        (Option::None, Option::Some(e)) => Some(e),
        (Option::Some(e1), Option::Some(e2)) => Some(i32::max(e1, e2)),
    }
}

// the same is true for mutable references, as long as you don't need to change the dimensions
fn swap(vec: &mut Vec<i32>) {
    swap2(vec.as_mut_slice());
}
fn swap2(vec: &mut [i32]) {
    if vec.len() <= 1 {
        return;
    }

    let last_index = vec.len() - 1;

    // option 1
    let x = vec[0];
    vec[0] = vec[last_index];
    vec[last_index] = x;

    // option 2
    // vec.swap(0,last_index);
}

fn is_sorted(vec: &Vec<i32>) -> bool {
    if vec.len() == 0 {
        return true;
    }

    let mut prev = vec[0];

    for i in vec {
        if *i < prev {
            return false;
        }
        prev = *i;
    }
    true
}

fn is_sorted_recursive(vec: &[i32]) -> bool {
    if vec.len() < 2 {
        return true;
    }
    if vec.len() == 2 {
        return vec[0] <= vec[1];
    }

    if vec.len() == 3 {
        return vec[0] <= vec[1] && vec[1] <= vec[2];
    }
    let (v1, v2) = vec.split_at(vec.len() / 2);

    if *v1.last().unwrap() > v2[0] {
        return false;
    }

    is_sorted_recursive(v1) && is_sorted_recursive(v2)
}

fn insert_if_longer(vec: &mut Vec<String>, string: String) {
    if string.len() > 10 {
        vec.push(string);
    }
}

// this option works as well,
// but this allocate some space on the heap when the function clone is called.
// the other option si better since it move the String.
fn insert_if_longer2(vec: &mut Vec<String>, string: &String) {
    if string.len() > 10 {
        vec.push(string.clone());
    }
}
