(* Given a list, remove the second element. It doesn’t need to work on lists shorter than 2 *)

fun rem l = hd(l) :: tl(tl(l));