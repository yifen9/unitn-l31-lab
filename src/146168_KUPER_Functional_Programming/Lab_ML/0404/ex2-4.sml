(*Use simpleMap to do the following*)

fun simpleMap(F,nil) =
    nil
| simpleMap(F,x::xs) =
    F(x) :: simpleMap(F,xs)
;

(*Replace every negative element of a list of reals by 0*)

val L = [0.0,1.0,~2.1,~2.3];

simpleMap(
    fn(x) =>
        if
            x < 0.0
        then
            0.0
        else
            x
,
    L
);

(*Add 1 to every element of an integer list*)

val L = [0,1,2,3];

simpleMap (fn(x) => x+1, L);

(*Change every lower-case letter in a list of characters to the corresponding upper-case one*)

val L = [#"a", #"A", #"0", #"b"];

simpleMap(
    fn(c) =>
        if
            c >= #"a" andalso c <= #"z"
        then
            chr(ord(c)-32)
        else
            c
,
    L
);

(*
Truncate every string in a list of strings so that it is no more than 5 characters long

size(c) gives the length of a string

substring (s,i,j) is the substring from position i to j
*)

val L = ["abc","abcde","abcdefgh",""];

simpleMap(
    fn(c) =>
        if
            size(c) <= 5
        then
            c
        else
            substring(c,0,5)
,
    L
);