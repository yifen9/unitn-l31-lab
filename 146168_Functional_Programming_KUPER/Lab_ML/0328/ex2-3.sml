(*
What are the types of the following expressions

1. SOME()
2. SOME 123
3. SOME NONE
4. fun f() = SOME true;
5. fun f(NONE) = 0
    | f(SOME i) = 1
    ;
*)

SOME();
(*unit option*)

SOME 123;
(*int option*)

SOME NONE;
(*'a option option*)

fun f() = SOME true;
(*fn:unit -> bool option*)

fun f(NONE) = 0
| f(SOME i) = 1
;
(*fn : 'a option -> int*)