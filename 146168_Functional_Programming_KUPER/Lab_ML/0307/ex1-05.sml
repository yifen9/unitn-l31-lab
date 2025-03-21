(*Find the third character of a string (it doesn’t have to work properly on shorter strings)*)

fun third (l) = hd (tl(tl(l)));

fun thirdchar(s) = third(explode s);