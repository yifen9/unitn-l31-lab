(*
Give definitions of f(x,y,z) where the argument has the following types

• 'a * ''b * ('a->''b)
• 'a * 'a * int

• 'a list * 'b * 'a
• ('a list * 'b list) * 'a * 'b
*)

(* 'a * ''b * ('a->''b) *)
fun f(x,y,z) = (z(x)=y);

(* 'a * 'a * int *)
fun f(x,y,z) = (x, y, z+1);

(* 'a list * 'b * 'a *)
fun f(x,y,z) = z::x;

(* ('a list * 'b list) * 'a * 'b *)
fun f ((x1,x2),y,z) = (y::x,z::x);