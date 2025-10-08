(*
Consider the pattern

(x::y::xs,w)

Does it match the following expressions? If so, give the variable bindings
• (["a","b","c"],["d","e"])
• (["a","b"],4.5)
• ([5],[6,7])
*)

(*
• Yes; x="a", y="b", zs=["c"], and w=["d","e"]
• Yes; x="a", y="b", zs=[], and w=4.5
• No; the expression y::zs must match the empty list
*)