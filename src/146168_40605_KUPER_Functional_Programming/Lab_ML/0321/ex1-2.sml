(* Write the split program without using a pattern in the val declaration *)

fun split(nil) = (nil,nil)
| split([a]) = ([a],nil)
| split(a::b::cs) =
    let
        val x = split(cs);
        val M = #1 x;
        val N = #2 x;
    in
        (a::M,b::N)
    end
;