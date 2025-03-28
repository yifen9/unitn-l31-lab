fun doubleExp(x:real,0) = x
| doubleExp(x,i) =
    let
        val y = doubleExp(x,i-1)
    in
        y * y
    end
;

fun sumPairs(nil) = (0,0)
| sumPairs((x,y)::zs) =
    let
        val (z1,z2) = sumPairs(zs)
    in
        (x+z1,y+z2)
    end
;

fun sumList(nil) = (0,0)
| sumList([x]) = (0,x)
| sumList(x::y::zs) =
    let
        val (a,b) = sumList(zs)
    in
        (y+a,x+b)
    end
;

fun printList(nil) = ()
| printList(x::xs) = (
    print(Int.toString(x));
    print("\n");
    printList(xs)
);

fun factorial 0 =
    1
| factorial n =
    n * factorial(n-1);

fun comb n m = (
    print("n is ");
    print(Int.toString(n));
    print("\n");
    print("m is ");
    print(Int.toString(m));
    print("\n");
    print("Result is ");
    print(Int.toString(
            factorial(n)
        div(
            factorial(m) * factorial(n-m)
    )));
    print("\n")
);

fun makelist 1 =
    "X"
| makelist n =
    makelist(n-1) ^ makelist(n-1)
;

fun printXs n = print(makelist n);

val x = TextIO.openIn("test");
TextIO.input1(x);
TextIO.inputN(x,5);
TextIO.inputLine(x);
TextIO.lookahead(x);

SOME();
SOME 123;
SOME NONE;

fun f() = SOME true;

fun f(NONE) = 0
| f(SOME i) = 1
;

fun white(" ") = true
| white("\t") = true
| white("\n") = true
| white(_) = false
;

fun getWord(file) =
    if
        TextIO.endOfStream(file)
    then
        ""
    else
        let
            val c = TextIO.inputN(file,1)
        in
            if
                white(c)
            then
                ""
            else
                c ^ getWord(file)
        end
;

fun getList1(file) =
    if
        TextIO.endOfStream(file)
    then
        nil
    else
        getWord(file)::getList1(file)
;

fun getList(filename) = getList1(TextIO.openIn(filename));

exception BadN;

fun comb(n,m) =
    if
        n < 0
    then
        raise BadN
    else
        if
            m < 0 orelse m > n
        then
            raise BadN
        else
            if
                m = 0 orelse m = n
            then
                1
            else
                comb(n-1,m) + comb(n-1,m-1)
;

exception Foo of string

exception OutOfRange of int * int;

fun comb1(n,m) =
    if
        n <= 0
    then
        raise OutOfRange(n,m)
    else
        if
            m < 0 orelse m > n
        then
            raise OutOfRange(n,m)
        else
            if
                m = 0 orelse m = n
            then
                1
            else
                comb(n-1,m) + comb(n-1,m-1)
;

fun comb(n,m) =
    comb1(n,m) handle
        OutOfRange(0,0) => 1
        | OutOfRange(n,m) => (
            print("out of range: n=");
            print(Int.toString(n));
            print(" m=");
            print(Int.toString(m));
            print("\n");

            0
        )
;

exception shortList of int list;

fun returnThird1 L =
    if
        length(L) < 3
    then
        raise shortList(L)
    else
        hd(tl(tl(L)))
;

fun returnThird L =
    returnThird1 L handle
        shortList L => (
            print("List too short\n");

            0
        )
;

exception Negative of int;

fun fact1(n) =
    if
        n < 0
    then
        raise Negative(n)
    else
        if
            n = 0
        then
            1
        else
            n * fact1(n-1)
;

fun fact(n) =
    fact1(n) handle
        Negative(n) => (
            print("negative argument ");
            print(Int.toString(n));
            print("\n");

            0
        )
;

fun identity(x) = x;

fun f(x) =
    if
        x < 10
    then
        identity
    else
        rev
;