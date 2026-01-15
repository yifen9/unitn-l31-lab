datatype intonil = Nil | Int of int

type ambiente = string -> intonil

(* empty environment: every lookup fails *)
val vuoto : ambiente =
  fn _ => Nil

(* bind/extend environment: override on the given name, otherwise delegate *)
fun lega (e, name, value) : ambiente =
  fn k => if k = name then Int value else e k

(* lookup *)
fun cerca (e, name) : intonil =
  e name

val e0 = vuoto;
val e1 = lega (e0, "alice", 10);
val e2 = lega (e1, "bob", 20);
val e3 = lega (e2, "alice", 99);

cerca (e3, "alice");  (* Int 99 *)
cerca (e3, "bob");    (* Int 20 *)
cerca (e3, "carol");  (* Nil *)

fun conta_duplicati xs =
  let
    fun count (x, []) = 0
      | count (x, y::ys) = (if x = y then 1 else 0) + count (x, ys)

    fun mem (x, []) = false
      | mem (x, y::ys) = (x = y) orelse mem (x, ys)

    fun loop ([], seen) = []
      | loop (x::rest, seen) =
          if mem (x, seen) then
            loop (rest, seen)
          else
            (x, count (x, xs)) :: loop (rest, x::seen)
  in
    loop (xs, [])
  end
