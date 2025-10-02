(* Write a function sumPairs that takes a list of pairs of integers, and returns a pair of the sum of each component *)

fun sumPairs(nil) = (0,0)
| sumPairs((x,y)::zs) =
    let
        val (z1,z2) = sumPairs(zs)
    in
        (x+z1, y+z2)
    end
;