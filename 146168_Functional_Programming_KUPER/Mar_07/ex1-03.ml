(*Find the third element of a list (it doesn’t have to work properly on shorter lists)*)

fun third (l) = hd (tl(tl(l)));