(* Write, in curried form, a function applyList that takes a list of functions and applies each function to the value, producing a list of the results *)

fun applyList nil _ =
    nil
| applyList (F::Fs) a =
    F(a)::(applyList Fs a)
;