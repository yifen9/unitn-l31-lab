(* Given a curried function with n parameters, write a function uncurry that is the reverse of the previous exercise *)

fun uncurry F(x1,x2,x3) = F x1 x2 x3;