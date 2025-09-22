(* Write a function that prints a list of integers *)

fun printList(nil) = ()
| printList(x::xs) = (
    print(Int.toString(x));
    print("\n");
    printList(xs)
);