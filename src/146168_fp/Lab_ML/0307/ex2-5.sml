(*
Compute x^i where x is a real, and i a nonegative integer.

It doesn’t need to work for i < 0
*)

fun power (x:real,i) =
    if i=0
    then 1.0
    else x * power (x,i-1)
;