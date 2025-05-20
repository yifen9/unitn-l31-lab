(*
Write a function that takes a list of reals $[a_0, . . . , a_{n−1}]$ and produces a function that takes an argument b and computes

\sum_{i = 0}^{n - 1} a_i b^i
*)

fun f aList b = foldr (fn (y, z) => y + z * b) (0.0) aList;