(*
Given a function F that takes a parameter of product type with n components, curry applied to F should produce a function such that

G x_1 ... x_n = F (x_1, ..., x_n)

n should be fixed
*)

fun curry F x1 x2 x3 = F(x1,x2,x3);