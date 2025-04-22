(*
What can be inferred about the types in the following

fun f (a:int,b,c,d,e) =
    if a<b+c
    then d
    else e
;

fun f (a:int,b,c,d,e) =
    if a<b
    then c
    else d
;

fun f (a:int,b,c,d,e) =
    if a<b
    then b+c
    else d+e
;

fun f (a:int,b,c,d,e) =
    if a<b
    then b<c
    else d
;

fun f (a:int,b,c,d,e) =
    if b<c
    then a
    else c+d
;

fun f (a:int,b,c,d,e) =
    if b<c
    then d
    else e
;

fun f (a:int,b,c,d,e) =
    if b<c
    then d+e
    else d*e
;
*)

fun f (a:int,b,c,d,e) =
    if a<b+c
    then d
    else e
;
(* val f = fn: int * int * int * 'a * 'a -> 'a *)

fun f (a:int,b,c,d,e) =
    if a<b
    then c
    else d
;
(* val f = fn: int * int * 'a * 'a * 'b -> 'a *)

fun f (a:int,b,c,d,e) =
    if a<b
    then b+c
    else d+e
;
(* val f = fn: int * int * int * int * int -> int *)

fun f (a:int,b,c,d,e) =
    if a<b
    then b<c
    else d
;
(* val f = fn: int * int * int * bool * 'a -> bool *)

fun f (a:int,b,c,d,e) =
    if b<c
    then a
    else c+d
;
(* val f = fn: int * int * int * int * 'a -> int *)

fun f (a:int,b,c,d,e) =
    if b<c
    then d
    else e
;
(* val f = fn: int * int * int * 'a * 'a -> 'a *)

fun f (a:int,b,c,d,e) =
    if b<c
    then d+e
    else d*e
;
(* val f = fn: int * int * int * int * int -> int *)