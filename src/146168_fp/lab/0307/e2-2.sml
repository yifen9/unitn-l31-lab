(* Given an integer i and a list L = [a_1, . . . , a_n], cycle L i times, i.e., produce [a_{i+1}, a_{i+1}, . . . , a_n, a_1, . . . , a_i] *)

fun cycle (l) = tl(l) @ [hd(l)];

fun i_cycle (i,L) =
    if i=0
    then L
    else i_cycle (i-1,cycle(L))
;