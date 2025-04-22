(* Given 3 integers, produce a pair consisting of the smallest and the largest *)

fun min3 (a,b,c) =
    if a<b 
    then
        if a<c
        then a
        else c
    else
        if c<b
        then c
        else b
;

fun max3 (a,b,c) =
    if a>b 
    then
        if a>c
        then a
        else c
    else
        if c>b
        then c
        else b
;

fun query (a,b,c) = (min3(a,b,c),max3(a,b,c));