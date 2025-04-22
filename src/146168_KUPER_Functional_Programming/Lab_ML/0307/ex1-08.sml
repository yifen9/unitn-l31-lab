(* Given three integers, produce a list of them in sorted order *)

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

fun sort (a,b,c) = 
    [min3(a,b,c)] @
    [
        if a<b
        then 
            if b<c
            then b
            else
                if a<c
                then c
                else a
        else
            if c<b
            then b
            else
                if a<c
                then a
                else c
    ] @
    [max3(a,b,c)]
;