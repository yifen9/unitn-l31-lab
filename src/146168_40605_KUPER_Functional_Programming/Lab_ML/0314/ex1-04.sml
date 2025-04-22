(* Write a function that takes a list of pairs of integers and orders each pair so that the smallest number is first *)

fun flip(nil) = nil
    | flip((x as (a:int,b))::xs) =
        if a<b
        then x::flip(xs)
        else (b,a)::flip(xs);