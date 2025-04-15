(*Write an improved function to find the largest of a list of integers using a let*)

fun maxReals(nil) = 0.0
| maxReals(x::xs) =
    let
        val maxTail = maxReals (xs)
    in
        if
            x < maxTail
        then
            maxTail
        else
            x
    end
;