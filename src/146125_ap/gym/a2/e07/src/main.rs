/*
Write a function `pancake_sort` that takes a `&mut Vec<i32>` and sorts it
using the [pancake sort](https://en.wikipedia.org/wiki/Pancake_sorting) algorithm;
*/

fn main() {}

fn flip(vector: &mut Vec<i32>, k: usize) {
    let (left, _) = vector.split_at_mut(k + 1);
    left.reverse();
}

fn find_max(vector: &[i32]) -> usize {
    let mut index = 0;
    for i in 0..vector.len() {
        if &vector[i] > &vector[index] {
            index = i;
        }
    }
    index
}

pub fn pancake_sort(vector: &mut Vec<i32>) {
    let mut index = vector.len();
    while index > 0 {
        let (first_half, _) = vector.split_at(index);
        index -= 1;
        let max_index = find_max(first_half);
        if index != max_index {
            flip(vector, max_index);
            flip(vector, index);
        }
    }
}

pub fn pancake_sort_recursive(vector: &mut Vec<i32>, len: usize) {
    if len == 0 || len == 1 {
        return;
    }
    let n = find_max(&vector[0..len]);
    if n < len {
        flip(vector, n);
        flip(vector, len - 1);
    }

    pancake_sort_recursive(vector, len - 1);
}
