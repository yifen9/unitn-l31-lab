(*Write a function that takes a list of integers and returns a pair of the sum of the even positions and the sum of the odd positions*)

fun sumList(nil) = (0,0)
| sumList([x]) = (0,x)
| sumList(x::y::zs) =
    let
        val (sumEven,sumOdd) = sumList(zs)
    in
        (y+sumEven, x+sumOdd)
    end
;