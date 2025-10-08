(* Write a program to return the third element of a list of integers *)

exception shortList of int list;

fun returnThird1(L) =
    if
        length(L) < 3
    then
        raise shortList(L)
    else
        hd(tl(tl(L)))
;

fun returnThird(L) = returnThird1 L handle shortList L => (
    print("List too short\n");

    0
);