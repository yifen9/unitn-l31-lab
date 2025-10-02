(* Give a type definition for a list of triples, the first two components of which have the same type, and the third is some (possibly) different type *)

type (’a, ’b) newMapping = (’a * ’a * ’b) list;