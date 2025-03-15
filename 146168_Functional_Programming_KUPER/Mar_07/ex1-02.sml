(*
Write a function to compute the smallest component of a tuple of type
    int*int*int
*)

fun min3 (a,b,c) =
    if a<b 
    then
        if a<c
        then a
        else c
    else
        if c<b
        then c
        else b
;