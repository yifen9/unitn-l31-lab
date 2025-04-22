(* What are the errors in the following expressions? *)

8/4;
(*
error: Type error in function application.
   Function: / : real * real -> real
   Argument: (8, 4) : int * int
   Reason: Can't unify real to int (Incompatible overloadings)
Found near 8 / 4
Static Errors
*)

if 2<3 then 4;
(*
error: else expected but ; was found
error: Expression expected but ; was found
Static Errors
*)

1<2 and 5>3;
(*
error: ; expected but and was found
Static Errors
*)

6+7 DIV 2;
(*
error: Type error in function application.
   Function: 7 : int
   Argument: DIV : bad
   Reason: Value being applied does not have a function type
Found near 6 + 7 DIV 2
Static Errors
*)

4. + 3.5;
(*
error: malformed real number: 4.
Static Errors
*)

1.0<2.0 or 3>4;
(*
error: Type error in function application.
   Function: 2.0 : real
   Argument: or : bad
   Reason: Value being applied does not have a function type
Found near 1.0 < 2.0 or 3 > 4
error: Type error in function application.
   Function: > : 'a * 'a -> bool
   Argument: (1.0 < 2.0 or 3, 4) : bool * 'a
   Reason:
      Can't unify int (*In Basis*) with bool (*In Basis*)
         (Different type constructors)
Found near 1.0 < 2.0 or 3 > 4
Static Errors
*)

#"a" ^ #"b";
(*
error: Type error in function application.
   Function: ^ : string * string -> string
   Argument: (#"a", #"b") : char * char
   Reason:
      Can't unify string (*In Basis*) with char (*In Basis*)
         (Different type constructors)
Found near #"a" ^ #"b"
Static Errors
*)

123.;
(*
error: malformed real number: 123.;
Static Errors
*)

1.0 = 2.0;
(*
error: Type error in function application.
   Function: = : ''a * ''a -> bool
   Argument: (1.0, 2.0) : ''a * ''b
   Reason: Can't unify ''a to ''a (Requires equality type)
Found near 1.0 = 2.0
Static Errors
*)