(*Given n, print 2^n X’s*)

fun makelist(1) =
    "X"
| makelist(n) =
    makelist(n-1) ^ makelist(n-1)
;

fun printXs(n) = print(makelist(n));