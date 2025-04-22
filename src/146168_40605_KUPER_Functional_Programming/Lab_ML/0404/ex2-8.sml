(* Write a function lreduce that takes a 2-argument function F , a list [a_1, ..., a_n] and produces F (··· F(F(a_1, a_2), a_3) ···, a_n) *)

fun reduce (F,nil) =
    raise EmptyList
| reduce (F,[a]) =
    a
| reduce (F,x::xs) =
    F (x, reduce (F,xs))
;

exception EmptyList;

fun lreduce(F,nil) =
    raise EmptyList
| lreduce(F,[x]) =
    x
| lreduce(F,x::y::zs) =
    lreduce(F, F(x,y)::zs)
;