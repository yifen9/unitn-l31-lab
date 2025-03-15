(*What is wrong with the following expressions? When possible, correct them*)

#4 (3,4,5);
(*
error: Type error in function application.
   Function: #4 : 'a * 'b * 'c * 'd -> 'd
   Argument: (3, 4, 5) : int * int * int
   Reason: Can't unify {4: 'a} to int * int * int (Field 4 missing)
Found near #4 (3, 4, 5)
Exception- Fail "Static Errors" raised
*)

hd([]);
(*
warning: The type of (it) contains a free type variable. Setting it to a unique
   monotype.
Exception- Empty raised
*)

#1 (1);
(*
error: Type error in function application.
   Function: #1 : {1: 'a, ...} -> 'a
   Argument: (1) : int
   Reason: Can't unify {1: 'a, ...} to int (Incompatible types)
Found near #1 (1)
Static Errors
*)

explode ["bar"];
(*
error: Type error in function application.
   Function: explode : string -> char list
   Argument: ["bar"] : string list
   Reason:
      Can't unify string (*In Basis*) with string list (*In Basis*)
         (Different type constructors)
Found near explode ["bar"]
Static Errors
*)

implode ( #"a", #"b");
(*
error: Type error in function application.
   Function: implode : char list -> string
   Argument: (#"a", #"b") : char * char
   Reason: Can't unify char list to char * char (Incompatible types)
Found near implode (#"a", #"b")
Static Errors
*)

["r"]::["a","t"];
(*
error: Type error in function application.
   Function: :: : string list * string list list -> string list list
   Argument: (["r"], ["a", "t"]) : string list * string list
   Reason:
      Can't unify string list (*In Basis*) with string (*In Basis*)
         (Different type constructors)
Found near ["r"] :: ["a", "t"]
Static Errors
*)

tl [];
(*
warning: The type of (it) contains a free type variable. Setting it to a unique
   monotype.
Exception- Empty raised
*)

1 @ 2;
(*
error: Type error in function application.
   Function: @ : 'a list * 'a list -> 'a list
   Argument: (1, 2) : int * int
   Reason:
      Can't unify int (*In Basis*) with 'a list (*In Basis*)
         (Different type constructors)
Found near 1 @ 2
Static Errors
*)