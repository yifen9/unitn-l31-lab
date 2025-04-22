(*
Suppose that sets are represented by lists. Write a function that takes such
a list, and produces the power set of the list

If S is a set, the power set of S is the set of all S′ such that S ⊆ S′
*)

fun powerSet(nil) =
    [nil]
| powerSet(x::xs) =
    powerSet(xs) @ insertAll(x,powerSet(xs))
;