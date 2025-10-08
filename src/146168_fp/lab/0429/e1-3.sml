(* Given the following definitions *)

fun comp F G =
    let
        fun C x = G (F (x))
    in
        C
    end
;

fun add1 x = x + 1;

(* Determine the type and result of the following expressions. Assume all unknown types are integers *)

val compA1 = comp add1;
(* val compA1 = fn: (int -> _a) -> int -> _a *)

val compCompA1 = comp compA1;
(* val compCompA1 = fn: ((int -> _a) -> _a) -> (int -> _a) -> _a *)