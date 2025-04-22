(*
• After the following definitions
    val a=2;
    fun f(b)=a*b;
    val b=3;
    fun g(a) = a+b;
• What does the following produce do
    f(4);
    f(4)+b;
    g(5);
    g(5)+a;
    f(g(6));
    g(f(7));
*)

val a=2;
fun f(b)=a*b;
val b=3;
fun g(a) = a+b;

f(4);
(* val it = 8: int *)

f(4)+b;
(* val it = 11: int *)

g(5);
(* val it = 8: int *)

g(5)+a;
(* val it = 10: int *)

f(g(6));
(* val it = 18: int *)

g(f(7));
(* val it = 17: int *)