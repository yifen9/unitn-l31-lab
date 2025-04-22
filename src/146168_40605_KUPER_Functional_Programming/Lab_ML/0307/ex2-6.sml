(*
Compute the largest element (lexicographic order) of a list of strings

It doesn’t need to work for empty lists
*)

fun maxList(L:string list) =
    if tl(L)=nil
    then hd(L)
    else
        if hd(L)>hd(tl(L))
        then maxList(hd(L)::tl(tl(L)))
        else maxList(tl(L))
;