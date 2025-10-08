(* Write, in curried form, a function makeFnList that takes a function F from D to R=T1->T2. The result should be a function G that takes a list of elements of type D that applies F to each element in the list *)

fun makeFnList F nil =
    nil
| makeFnList F (x::xs) =
    F(x)::(makeFnList F xs)
;