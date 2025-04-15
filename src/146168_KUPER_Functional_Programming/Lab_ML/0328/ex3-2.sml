(*Write a factorial function that produces 1 when its argument is 0, 0 for a negative argument, with an error message*)

exception Negative of int;

fun fact1(0) = 1
| fact1(n) =
    if
        n > 0
    then
        n * fact1(n-1)
    else
        raise Negative(n)
;

fun fact(n) = fact1(n) handle Negative(n) => (
    print("Warning: negative argument ");
    print(Int.toString(n));
    print(" found\n");

    0
);