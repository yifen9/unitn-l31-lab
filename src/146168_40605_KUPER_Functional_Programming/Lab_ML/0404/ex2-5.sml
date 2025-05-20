(* Use reduce for the following *)

fun reduce (F,nil) =
    raise EmptyList
| reduce (F,[a]) =
    a
| reduce (F,x::xs) =
    F (x, reduce (F,xs))
;

(* Find the maximum of a list of reals *)

val L = [1.1,2.2,4.4,3.3];

reduce(
    fn(x,y) =>
        if
            x < y
        then
            y
        else
            x
,
    L
);

(* Find the minimum of a list of reals *)

val L = [1.1,2.2,4.4,3.3];

reduce(
    fn(x,y) =>
        if
            x > y
        then
            y
        else
            x
,
    L
);

(* Find the logical OR of a list of booleans *)

val L = [true,false,true];

reduce(
    fn(x,y) => x orelse y
,
    L
);