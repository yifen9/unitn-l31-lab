(*
Duplicate each element of a list.

That is, given the list [a_1, a_2, . . . , a_n] produce the list [a_1, a_1, a_2, a_2, . . . , a_n, a_n]
*)

fun duplicate L =
    if L=nil
    then nil
    else
        [hd(L)] @
        [hd(L)] @
        duplicate (tl(L))
;