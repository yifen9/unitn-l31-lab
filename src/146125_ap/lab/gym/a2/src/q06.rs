/*
Write a function `build_vector` that takes a `Iter<i32>` and returns the `Vec<&i32>`
containing all the elements of the iterator;
*/

use std::slice::Iter;

fn build_vector(iterator: Iter<i32>) -> Vec<&i32> {
    let mut vector: Vec<&i32> = vec![];
    for el in iterator {
        vector.push(el)
    }
    vector
}

fn build_vector_collect(iterator: Iter<i32>) -> Vec<&i32> {
    let vector: Vec<&i32> = iterator.collect();
    vector
}
