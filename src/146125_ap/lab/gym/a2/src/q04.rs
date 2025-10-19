/*
Write a function `sub_slice` that takes two `&Vec<i32>` as input.
If the second vector is contained inside the first one it print the corresponding slice,
otherwise it print `Not found`;
*/

pub fn sub_slice(vector: &Vec<i32>, sub_vector: &Vec<i32>) {
    let slices_number = vector.len() - sub_vector.len();
    let slice_size = sub_vector.len();
    let mut found = false;
    for i in 0..=slices_number {
        let slice = vector.split_at(i).1.split_at(slice_size).0;
        println!("{:?}", slice);
        if slice == sub_vector {
            println!("Found");
            // println!("{:?}", slice);
            found = true;
        }
    }
    if !found {
        println!("Not found");
    }
}

pub fn sub_slice_recursive(vector: &[i32], sub_vector: &[i32]) {
    // recursive function
    pub fn sub_slice_recursive_inner(vector: &[i32], sub_vector: &[i32]) -> bool {
        if sub_vector.len() == 0 {
            return true;
        }

        if vector.len() < sub_vector.len() {
            return false;
        }

        if vector.split_at(sub_vector.len()).0 == sub_vector {
            return true;
        }

        return sub_slice_recursive_inner(vector.split_at(1).1, sub_vector);
    }

    if sub_slice_recursive_inner(vector, sub_vector) {
        println!("Found");
    } else {
        println!("Not found");
    }
}
