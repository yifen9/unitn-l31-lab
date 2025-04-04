(*Write a function to compute \dbinom{n}{m}, while printing n, m and the result*)

fun factorial(0) =
    1
| factorial(n) =
    n * factorial(n-1);

fun comb(n,m) = (
    print("n is ");
    print(Int.toString(n));
    print("\n");
    print("m is ");
    print(Int.toString(m));
    print("\n");
    print("Result is ");
    print(Int.toString(
        factorial(n) div (factorial(m)*factorial(n-m))
    ));
    print("\n")
);