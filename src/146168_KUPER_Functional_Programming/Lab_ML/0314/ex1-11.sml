(*
Given a list of reals [a_1, . . . , a_n] compute

Π_{i<j}(a_i − a_j)
*)

fun prodDiff1(_,nil) =
    1.0
| profDiff1(a,b::bs) =
    (a-b) * profDiff1(a,bs)
;

fun prodDiff(nil) =
    1.0
| profDiff(b::bs) =
    prodDiff1(b,bs) * prodDiff(bs)
;