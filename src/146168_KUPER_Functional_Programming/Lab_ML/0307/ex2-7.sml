(*
In the following code

fun foo (a,b,c,d) =
    if a=b
    then c+1
    else
        if a>b
        then c
        else b+d
;

Deduce the types of the variables and the function
*)

fun foo (a,b,c,d) =
    if a=b
    then c+1
    else
        if a>b
        then c
        else b+d
;
(* val foo = fn: int * int * int * int -> int *)