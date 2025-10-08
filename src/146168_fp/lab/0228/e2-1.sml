(*
    Write expressions to

    • Convert 123.45 to the next lower integer
    • Convert -123.45 to the next lower integer

    • Convert 123.45 to the next higher integer
    • Convert -123.45 to the next higher integer

    • Convert #"Y" to an integer
    • Convert 120 to a character

    • Convert #"N" to an real
    • Convert 97.0 to a character
    • Convert #"Z" to an string
*)

floor 123.45;
floor ~123.45;

ceil 123.45;
ceil ~123.45;

ord #"Y";
chr 120;

real (ord #"N");
chr (ceil 97.0);
str #"Z";