fun identity(x) = x;

fun f(x) =
    if
        x < 10
    then
        identity
    else
        rev
;

fun rev1(L) =
    if
        L = nil 
    then
        nil
    else
        rev(tl(L)) @ [hd(L)]
;

fun rev2(nil) =
    nil
| rev2(x::xs) =
    rev2(xs) @ [x]
;

fun rev3(L) =
    if
        null(L)
    then
        nil
    else
        rev3(tl(L)) @ [hd(L)]
;

rev2 ([(rev1:int list -> int list),rev1]);

fun f(x,y,z) = (z(x) = y);

fun f(x,y,z) =
    if
        z = 0
    then
        (x,y)
    else
        (x,y)
;

fun f(x,y,z) = z::x;

fun f((x1,x2),y,z) = (y::x1,z::x2);

val L = [(1,2),(3,4)];

val M = (1,2);

val N = (3,4);

L = M::[N];

M::L = L @ [N];

[(1,2)] @ [N] = L @ nil;

N::L = (3,4)::M::N::nil;

fun f(nil) =
    nil
| f([x]) =
    [x]
| f(x::y::zs) =
    [x,y]
;

fun g(x,y) = (f(x),f(y));

fun h(x,y) =
    let
        val v = f(nil)
    in
        (x::v,y::v)
    end
;

g([1,2,3],["a"]);

g([1,2,3],nil);

g([f,f],[1]);

g([1],[1,0]);

h(1,2);

h(nil,nil);

h([1],nil);

fun trap(a,b,n,F) =
    if
        n <= 0 orelse b-a <= 0.0
    then
        0.0
    else
        let
            val delta = (b-a)/real(n)
        in
            delta*(F(a)+F(a+delta))/2.0 + trap(a+delta, b, n-1, F)
        end
;

fun square(x:real) = x * x;

trap(0.0,1.0,8,square);

map;

fun simpleMap(F,nil) =
    nil
| simpleMap(F,x::xs) =
    F(x)::simpleMap(F,xs)
;

simpleMap(square,[1.0,2.0,3.0]);

simpleMap(~,[1,2,3]);

simpleMap(fn(x) => x*x, [1.0,2.0,3.0]);

exception EmptyList;

fun reduce(F,nil) =
    raise EmptyList
| reduce(F,[a]) =
    a
| reduce(F,x::xs) =
    F(x,reduce(F,xs))
;

fun square(x:real) = x*x;

fun plus(x:real,y) = x+y;

length;

List.length;

fun variance(L) =
    let
        val n = real(length(L))
    in
        reduce(plus,simpleMap(square,L))/n - square(reduce(plus,L))
    end
;

variance [1.2,2.0,5.0,8.0];

reduce(+,[1,2,3]);

reduce(op +,[1,2,3]);

List.filter;

fun filter(P,nil) =
    nil
| filter(P,x::xs) =
    if
        P(x)
    then
        x::filter(P,xs)
    else
        filter(P,xs)
;

filter(fn(x) => x>=10, [1,10,23,5,16]);

fun tabulate(x,delta,0,F) =
    ()
| tabulate(x,delta,n,F) = (
    print(Real.toString(x));
    print("\t");
    print(Real.toString(F(x)));
    print("\n");

    tabulate(x+delta, delta, n-1, F)
);

tabulate(1.0, 0.1, 9, fn(x) => x*x);

fun trap(a,b,n,F) =
    if
        n<=0 orelse (b-a <= 0.0)
    then
        0.0
    else
        let
            val delta = (b-a)/real(n);
            fun trap1(x,0) =
                0.0
            | trap1(x,i) =
                delta*(F(x)+F(x+delta))/2.0 + trap1(x+delta, i-1)
        in
            trap1(a,n)
        end
;

trap(0.0,1.0,8,square);

exception badInput;

fun trap1(a,b,n,F) =
    if
        n<=0 orelse (b-a <= 0.0)
    then
        raise badInput
    else
        let
            val delta = (b-a)/real(n);
            fun trap1(x,0) =
                0.0
            | trap1(x,i) =
                delta*(F(x)+F(x+delta))/2.0 + trap1(x+delta, i-1)
        in
            trap1(a,n)
        end
;

fun trap(a,b,n,F) = trap1(a,b,n,F) handle badInput => (
    print("bad Input\n");

    0.0
);

trap(0.0,1.0,~1,square);

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

val L = [0,1,2,3];

simpleMap(fn(x) => x+1, L);

val L = [#"a",#"A",#"0",#"b"];

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

val L = ["abc","abcde","abcdefg"];

size;

substring;

(*
simpleMap(
    fn(c) =>
        if
            size()
);
*)