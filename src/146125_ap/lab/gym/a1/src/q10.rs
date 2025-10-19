/*
Write a function that takes a "matrix" (2x2, i32 tuple) as input, transposes and returns it.
*/

type Matrix = ((i32, i32), (i32, i32));

fn transpose(matrix: Matrix) -> Matrix {
    let mut trans = matrix;
    let tmp = trans.0.1;
    trans.0.1 = trans.1.0;
    trans.1.0 = tmp;

    trans
}
