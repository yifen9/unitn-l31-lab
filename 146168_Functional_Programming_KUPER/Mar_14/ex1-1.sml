(*Write the following functions using patterns*)

(*The factorial function*)
fun fact(1) = 1
    | fact(n) = n*fact(n-1);

(*
Cycle a list by one position.

If the list is empty, return the empty list
*)
fun cycle (nil) = nil
    | cycle (x::xs) = xs @ [x];

(*Cycle a list L i times*)
fun cycle_i (L,0) = L
    | cycle_i (L,i) = cycle_i (cycle(L),i-1);

(*Duplicate each element of a list*)
fun duplicate(nil) = nil
    | duplicate(x::xs) = x::x::duplicate(xs);

(*Compute x^i*)
fun power (x,0) = 1
    | power (x,i) = x * power (x,i-1);

(*Compute the largest of a list of reals*)
fun maxList([x:real]) = x
    | maxList(x::y::zs) =
        if x<y
        then maxList(y::zs)
        else maxList(x::zs);

(*
Flip alternate elements of a list.

[a_1, a_2, . . . , a_{n−1}, a_n] should become [a_2, a_1, . . . , a_n, a_{n−1}]. If n is odd, leave a_n at the end
*)
fun flip ([]) = []
    | flip ([x]) = [x]
    | flip (x::y::zs) = y::x::flip(zs);

(*Given a list L and an integer i, return L with the ith element deleted. If the length of L is less than i, return L*)
fun remove ([],m) = []
    | remove (x::xs,1) = xs
    | remove ([x],n) = [x]
    | remove (x::ys,i) = x:: remove (ys,i-1);