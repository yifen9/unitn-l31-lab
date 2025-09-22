(*
Representing sets by lists

We represent a set by a list: the elements can be in any order, but without
repetitions

Write a function member(x,S) to test whether x is a member of set S
*)

fun member(_,nil) = false
| member(x,y::ys) = (
        x = y
    orelse
        member(x,ys)
    )
;