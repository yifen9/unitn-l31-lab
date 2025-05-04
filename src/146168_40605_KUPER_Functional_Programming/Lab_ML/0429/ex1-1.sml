(* In the following exercises, use `map`, `foldr` and `foldl` *)

fun map F =
    let
        fun M nil    = nil
          | M(x::xs) = F x :: M xs
    in
        M
    end
;

fun foldr F y nil     = y
  | foldr F y (x::xs) = F (x, foldr F y xs)
;

fun foldl F y nil     = y
  | foldl F y (x::xs) = foldl F (F (x, y)) xs
;

(* Turn a list of integers into a list of `reals` with the same values *)

val f = map real;

(* Define a function that turns an integer list $L$ into a list of reals, each of which is the absolute value of the element in $L$ *)

val f = map (real o abs);

(* The function `implode` *)

val f = (foldr (op ^) "") o (map str);

(* The function `concat` *)

val concat = foldr (op ^) "";

(* A function that takes a list of integers $[a_1, ..., a_n]$ and produces the alternating sum $a_1 − a_2 + a_3 − · · · $ *)

val f = foldr (op -) 0;

(* Compute the logical AND of a list of Booleans *)

val f = foldr (fn (x, y) => x andalso y) true;

(* Compute the logical OR of a list of Booleans *)

val f = foldr (fn (x, y) => x orelse y) false;

(* Compute the exclusive OR of a list of Booleans *)

val f = foldr (
        fn (a, b) => (a orelse b)
    andalso
        not (a andalso b)
) false;