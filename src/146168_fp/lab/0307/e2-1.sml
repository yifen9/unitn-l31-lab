(*
Write a function that computes the factorial of n,
    n! = 1 · 2 · · · n
where n ≥ 1. It need not work correctly for smaller n
*)

fun fact(n) =
    if n=1
    then 1
    else n * fact(n-1)
;