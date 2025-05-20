(* What is the response of ML to the following (without using ML. . . )? *)

1+2*3;
(* val it = 7: int *)

5.0-4.2/1.4;
(* val it = 2.0: real *)

11 div 2 mod 3;
(* val it = 2: int *)

"foo" ^ "bar" ^ "";
(* val it = "foobar": string *)

3>4 orelse 5<6 andalso not (7<>8);
(* val it = false: bool *)

if 6<10 then 6.0 else 10.6;
(* val it = 6.0: real *)

0xab + 123;
(* val it = 294: int *)

0xab < 123;
(* val it = false: bool *)