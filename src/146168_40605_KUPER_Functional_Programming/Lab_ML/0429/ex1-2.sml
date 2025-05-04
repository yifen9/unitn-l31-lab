(* Write a definition of `foldl` similar to our definition of `foldr` *)

fun foldl F y nil     = y
  | foldl F y (x::xs) = foldl F (F (x, y)) xs
;