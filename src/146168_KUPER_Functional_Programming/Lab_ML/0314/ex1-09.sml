(*Write a function that takes an element a and a list of lists L and inserts a at the front of each of these lists*)

fun insertAll(a,nil) =
    nil
| insertAll(a,L::Ls) =
    (a::L)::insertAll(a,Ls)
;