(* What are the type errors in the following expressions, and how can we fix them? *)

ceil 4;
(*
error: Type error in function application.
   Function: ceil : real -> int
   Argument: 4 : int
   Reason:
      Can't unify int (*In Basis*) with real (*In Basis*)
         (Different type constructors)
Found near ceil 4
Static Errors
*)

if true then 5+6 else 7.0;
(*
error: Type mismatch between then-part and else-part.
   Then: 5 + 6 : int
   Else: 7.0 : real
   Reason: Can't unify int to real (Incompatible overloadings)
Found near if true then 5 + 6 else 7.0
Static Errors
*)

chr 256;
(* Exception- Chr raised *)