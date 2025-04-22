(* Write a short program to compute x^1000 *)

fun thousandthPower(x:real) =
    let
        val x = x*x*x*x*x;
        val x = x*x*x*x*x;
        val x = x*x*x*x*x;
    in
        x*x*x*x*x*x*x*x
    end
;