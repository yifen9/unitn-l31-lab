(*Write an efficient program to compute x^(2^i), for real x and nonnegative i, making only one recursive call*)

fun doubleExp(x:real, 0) = x
| doubleExp(x,i) =
    let
        val y = doubleExp(x, i-1)
    in
        y * y
    end
;