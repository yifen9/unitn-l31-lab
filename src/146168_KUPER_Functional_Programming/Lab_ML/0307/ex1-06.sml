(* Cycle a list once, i.e., convert [a1,...,an] to [a2,...,an,a1]. It doesn’t have to work on the empty list *)

fun cycle (l) = tl(l) @ [hd(l)];