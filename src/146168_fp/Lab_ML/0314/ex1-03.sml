(*
Write a program to compute the square of an integer, using the formula

n^2 = (n − 1)^2 + 2n − 1
*)

fun square(0) = 0
    | square(n) = square(n-1)+2*n-1;