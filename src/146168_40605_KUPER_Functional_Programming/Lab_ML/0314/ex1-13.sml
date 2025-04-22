(*
In the example

fun sumPairs (nil) =
    0
| sumPairs ((x,y)::zs) =
    x + y + sumPairs(zs)
;

How does ML figure out the type?
*)

(*
• Addition: default x and y are integers, as is the result of sumPairs
• Therefore (x,y) is a pair of integers, and the input is a list of such pairs
*)