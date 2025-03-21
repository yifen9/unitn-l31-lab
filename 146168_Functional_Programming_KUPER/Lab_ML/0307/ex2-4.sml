(*Compute the length of a list*)

fun length L =
    if L = nil
    then 0
    else 1 + length(tl(L))
;