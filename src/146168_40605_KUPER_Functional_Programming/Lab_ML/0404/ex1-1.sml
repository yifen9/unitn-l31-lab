(*
Let rev1 and rev2 be as above. What are the results of the following calls

• rev1([(rev1:int list -> int list),rev1])
• rev2([(rev1:int list -> int list),rev1])
• rev1([rev1,rev1])
• rev2([rev2,rev2])

• rev1([chr,chr])
• rev2([chr,chr])
• rev1([chr,ord])
• rev2([chr,ord])
*)

rev1([(rev1:int list -> int list),rev1]);
(*
error: Type error in function application.
    Function: rev1 : ’’a list -> ’’a list
    Argument: ([(rev1 : int list -> int list), rev1]) :
        (int list -> int list) list
    Reason: Can’t unify ’’a to int list -> int list (Requires equality type)
*)

rev2([(rev1:int list -> int list),rev1]);
(* val it = [fn, fn]: (int list -> int list) list *)

rev1([rev1,rev1]);
(*
error: Type error in function application.
    Function: rev1 : ’’a list -> ’’a list
    Argument: ([rev1, rev1]) : (’’a list -> ’’a list) list
    Reason: Can’t unify ’’a to ’’a list -> ’’a list (Requires equality type)
*)

rev2([rev2,rev2]);
(* val it = [fn, fn]: (_a list -> _a list) list *)

rev1([chr,chr]);
(*
error: Type error in function application.
    Function: rev1 : ’’a list -> ’’a list
    Argument: ([chr, chr]) : (int -> char) list
    Reason: Can’t unify ’’a to int -> char (Requires equality type)
*)

rev2([chr,chr]);
(* val it = [fn, fn]: (int -> char) list *)

rev1([chr,ord]);
(*
error: Elements in a list have different types.
    Item 1: chr : int -> char
    Item 2: ord : char -> int
*)

rev2([chr,ord]);
(*
error: Elements in a list have different types.
    Item 1: chr : int -> char
    Item 2: ord : char -> int
*)