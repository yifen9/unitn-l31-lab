(*
Write a function tabulate that takes an initial value a, an increment δ, a number of points n, and a function F from reals to reals

Print a table with columns corresponding to x and F(x), where x = a, a + δ, a + 2δ, . . . , a + (n − 1)δ
*)

fun tabulate(x,delta,0,F) = ()
| tabulate(x,delta,n,F) = (
    print(Real.toString(x));
    print("\t");
    print(Real.toString(F(x)));
    print("\n");
    tabulate(x+delta, delta, n-1, F)
);