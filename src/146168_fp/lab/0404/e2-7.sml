(*
What is the effect on a list of

reduce (op - , L);
*)

fun reduce (F,nil) =
    raise EmptyList
| reduce (F,[a]) =
    a
| reduce (F,x::xs) =
    F (x, reduce (F,xs))
;

(* Alternating difference: a_1 − a_2 + a_3 − a_4 *)

val L = [1,2,3,4];

reduce (op - , L);