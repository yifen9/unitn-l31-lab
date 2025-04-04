(*
Consider the following

val L = [(1,2),(3,4)];
val M = (1,2);
val N = (3,4);

Which of the following are true?

• L = M::[N]
• M::L = L@[N]
• [(1,2)]@[N] = L@nil
• N::L = (3,4)::M::N::nil
*)

L = M::[N];
(*val it = true: bool*)

M::L = L@[N];
(*val it = false: bool*)

[(1,2)]@[N] = L@nil;
(*val it = true: bool*)

N::L = (3,4)::M::N::nil;
(*val it = true: bool*)