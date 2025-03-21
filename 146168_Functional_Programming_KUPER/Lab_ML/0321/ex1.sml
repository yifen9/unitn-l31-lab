fun member (_,nil) = false
    | member (x,y::ys) =
            x = y
        orelse
            member (x,ys)
;

fun delete (x,nil) = nil
    | delete (x,y::ys) =
        if
            x = y
        then
            delete (x,ys)
        else
            y :: delete(x,ys)
;

fun insert (x,nil) = [x]
    | insert (x,S as y::ys) = 
        if member(x,S)
        then S
        else x::S
;

fun insertAll (x,nil) = nil
    | insertAll (x,y::ys) = insert(x,y) :: insertAll(x,ys)
;

fun powerSet (nil) = [nil]
    | powerSet (x::xs) = powerSet(xs) @ insertAll(x,powerSet(xs))
;

fun prodDiff1 (_,nil) = 1.0
    | prodDiff1 (a,b::bs) = (a-b) * prodDiff1(a,bs)
;

fun prodDiff (nil) = 1.0
    | prodDiff (b::bs) = prodDiff1(b,bs) * prodDiff(bs)
;

fun emptyList (nil) = true
    | emptyList (_) = false
;

fun sumPairs (nil) = 0
    | sumPairs ((x,y)::zs) = x + y + sumPairs(zs)
;

fun hundredthPower (x:real) =
    let
        val four = x*x*x*x;
        val twenty = four*four*four*four*four
    in
        twenty*twenty*twenty*twenty*twenty
    end
;

fun hundredthPower (x:real) =
    let
        val x = x*x*x*x;
        val x = x*x*x*x*x;
    in
        x*x*x*x*x
    end
;

fun split (nil) = (nil,nil)
    | split ([a]) = ([a],nil)
    | split (a::b::cs) =
        let
            val (M,N) = split (cs)
        in
            (a::M,b::N)
        end
;

(*
fun merge (nil,nil) = nil
    | merge (x,nil) = x
    | merge (nil,y) = y
    | merge (x::xs,y) = x::xs @ y
    | merge (x,y::ys) = x @ y::ys
    | merge (x::xs,y::ys) = x @ merge(xs,y)
;

fun mergeSort (nil) = nil
    | mergeSort ([a]) = [a]
    | mergeSort (L) =
        let
            val (M,N) = split L;
            val M = mergeSort (M);
            val N = mergeSort (N);
        in
            merge (M,N)
        end
;
*)

fun thousandthPower (x:real) =
    let
        val x = x*x*x*x*x;
        val x = x*x*x*x*x;
        val x = x*x*x*x*x;
    in
        x*x*x*x*x*x*x*x*x*x
    end
;

(*
fun split (nil) = (nil,nil)
    | split ([a]) = ([a],nil)
    | split (a::b::cs) =
        let
            val x = split(cs);
            val M = #1 cs;
            val N = #2 cs;
        in
            (M,N)
        end
;
*)

fun powerSet (nil) = [nil]
    | powerSet (x::xs) =
        let
            val L = powerSet(xs)
        in
            L @ insertAll(x,L)
        end
;

fun maxReals (nil) = 0.0
    | maxReals (x::xs) =
        let
            val maxTail = maxReals(xs)
        in
            if
                x < maxTail
            then
                maxTail
            else
                x
        end
;

fun testZero (0) = print ("zero\n")
    | testZero (_) = print ("not zero\n")
;

val infile = TextIO.openIn("test");
TextIO.inputLine(infile);
TextIO.inputLine(infile);
TextIO.inputLine(infile);

val infile = TextIO.openIn("test");
TextIO.input(infile);
TextIO.input1(infile);
TextIO.input1;
TextIO.input1(infile);
TextIO.input1(infile);
TextIO.lookahead(infile);
TextIO.canInput(infile,10);