(*What are the types of the following expressions?*)

(1.5, ("3",[4,5]));
(*val it = (1.5, ("3", [4, 5])): real * (string * int list)*)

[[1,2],nil,[3]];
(*val it = [[1, 2], [], [3]]: int list list*)

[ (2,3.5), (4,5.5), (6,7.5)];
(*val it = [(2, 3.5), (4, 5.5), (6, 7.5)]: (int * real) list*)

([#"a", #"b"], [nil,[1,2,3]]);
(*val it = ([#"a", #"b"], [[], [1, 2, 3]]): char list * int list list*)