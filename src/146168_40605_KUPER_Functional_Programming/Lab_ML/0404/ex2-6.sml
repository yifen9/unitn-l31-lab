(* Use filter for the following *)

fun filter (P,nil) =
    nil
| filter (P,x::xs) =
    if
        P(x)
    then
        x::filter(P,xs)
    else
        filter (P,xs)
;

(* Find the elements of a list or reals that are greater than 0 *)

val L = [1.1,~1.2,~1.3,1.4];

filter(
    fn(x) => x>0.0
,
    L
);

(* Find those elements of a list of reals that are between 1 and 2 *)

val L = [1.0,1.5,1.8,2.1];

filter(
    fn(x) => 1.0<x andalso x<2.0
,
    L
);

(* Find those elements of a list of strings that start with the character #"a" *)

fun init_a("") =
    false
| init_a(s) =
    (hd(explode(s)) = #"a")
;

val L = ["abc","abcd","bcd"];

filter(init_a,L);

(* Find those elements of a list of strings that are at most 3 characters long *)

val L = ["ab","","abcd","ac"];

filter(
    fn(x) => size (x) <= 3
,
    L
);