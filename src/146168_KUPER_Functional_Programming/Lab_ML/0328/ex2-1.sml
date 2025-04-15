(*
Write expressions to

1. Open a file zap for reading
2. Close the file whose instream is in1
3. Read 5 characters from the instream in2
4. Read a line of text from the instream in3
5. Read the entire file from instream in4
6. Find the first character waiting on the in1, without consuming it
*)

(*Open a file zap for reading*)
val IN = TextIO.openIn("zap")

(*Close the file whose instream is in1*)
TextIO.closeIn(in1);

(*Read 5 characters from the instream in2*)
TextIO.inputN(in2,5);

(*Read a line of text from the instream in3*)
TextIO.inputLine(in3);

(*Read the entire file from instream in4*)
TextIO.input(in4);

(*Find the first character waiting on the in1, without consuming it*)
TextIO.lookahead(in1);