(*
Assume that we have a file with the following contents

abd
de
f

What does each command return, if issued repeatedly

val x = input(infile);
val x = input1(infile);
val x = inputN(infile,2);
val x = inputN(infile,5);
val x = inputLine(infile);
val x = lookahead(infile);
*)

val x = input(infile);
(*First time abc\nde\nf\n, Subsequent times, the empty string*)

val x = input1(infile);
(*a, b, c, \n, d, e, \n, f, then empty string*)

val x = inputN(infile,2);
(*ab, c\n, de, \nf, enpty string*)

val x = inputN(infile,5);
(*abc\nd, e\nf then empty string*)

val x = inputLine (infile);
(*abc\n, de\n, f\n, then empty string*)

val x = lookahead (infile);
(*Always a*)