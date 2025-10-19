/*
Given a vector of `i32`, create a function that returns the minimum and the maximum value inside that vector;
*/

fn main() {}

pub fn max_min(v: Vec<i32>) -> (i32, i32) {
    let mut max = 0;
    let mut min = 0;
    for num in v {
        if num >= max {
            max = num;
        }
        if num <= min {
            min = num;
        }
    }

    (max, min)
}
pub fn max_min_recursive(v: Vec<i32>, i: usize, j: usize, mut max: &mut i32, mut min: &mut i32) {
    if i == j {
        return;
    }

    if v[i] >= *max {
        *max = v[i];
    }

    if v[i] <= *min {
        *min = v[i];
    }

    max_min_recursive(v, i + 1, j, &mut max, &mut min);
}
