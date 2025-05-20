(*
Consider the following definitions

fun f(nil)= nil
| f([x])= [x]
| f(x::y::zs) = [x,y];

fun g(x,y) = (f(x),f(y));

fun h(x,y) =
    let
        val v = f(nil)
    in
        (x::v, y::v)
    end
;

Are the following expressions legal?

• g([1,2,3],["a"])
• g([1,2,3],nil)
• g([f,f],[1])
• g([1],[1.0])

• h(1,2)
• h(1,"a")
• h(nil,nil)
• h([1],nil)
*)

g([1,2,3],["a"]);
(* val it = ([1,2],["a"]): int list * string list *)

g([1,2,3],nil);
(* warning: The type of (it) contains a free type variable *)

g([f,f],[1]);
(* warning: The type of (it) contains a free type variable *)

g([1],[1.0]);
(* val it = ([1],[1.0]): int list * real list *)

h(1,2);
(* val it = ([1],[2]): int list * int list *)

h(1,"a");
(*
error: Type error in function application.
    Function: h : int * int -> int list * int list
    Argument: (1, "a") : int * string
*)

h(nil,nil);
(* warning: The type of (it) contains a free type variable *)

h([1],nil);
(* val it = ([[1]], [[]]): int list list * int list list *)