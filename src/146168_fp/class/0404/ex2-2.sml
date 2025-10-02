(* At the cost of some roundoff errors, it is possible to compute δ in the trapezoidal function once at the begining. Reimplement trap in this way *)

fun trap(a,b,n,F) =
    if
        n<=0 orelse b-a<=0.0
    then
        0.0
    else
        let
            val delta = (b-a)/real(n);

            fun trap1(x,0) = 0.0
            | trap1(x,i) = delta*(F(x)+F(x+delta))/2.0 + trap1(x+delta,i-1)
        in
            trap1(a,n)
        end
;