(*Delete an element from a set delete(x,S)*)

fun delete(a,[]) = []
| delete(b,c::ys) =
    if b = c
    then ys
    else c::delete(b,ys)
;