(*Improve the powerset function by using a let and computing the powerset of the tail only once*)

fun powerSet(nil) = [nil]
| powerSet(x::xs) =
    let
        val L = powerSet(xs)
    in
        L @ insertAll(x,L)
    end
;