(* What are the values of the following expressions? *)

#2 (3,4,5);
(* val it = 4: int *)

hd [3,4,5];
(* val it = 3: int *)

tl [3,4,5];
(* val it = [4, 5]: int list *)

explode ("foo");
(* val it = [#"f", #"o", #"o"]: char list *)

implode ([#"f", #"o", #"o"]);
(* val it = "foo": string *)

"c" :: ["a", "t"];
(* val it = ["c", "a", "t"]: string list *)