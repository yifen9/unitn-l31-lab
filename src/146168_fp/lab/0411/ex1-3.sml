(*
Write a function substring that takes two parameters and checks whether the first is a substring of the second

Hint: test for sublists, then use explode
*)

(* ss1(L,M) tests whether list L is a prefix of list M *)

fun ss1(nil, _) =
    true
| ss1(_, nil) =
    false
| ss1(x::xs, y::ys) =
    (x=y andalso ss1(xs,ys))
;

(* ss2(L,M) tests whether list L is a sublist of list M *)

fun ss2(x, nil) =
    ss1(x,nil)
| ss2(x, y::ys) =
    ss1(x,y::ys) orelse ss2(x,ys)
;

(* substring converts strings to lists and applies ss2 *)

fun substring x y = ss2(explode(x),explode(y));