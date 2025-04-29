datatype ('a, 'b) element =
    P of 'a * 'b |
    S of 'a
;

P ("a", 1);

P (1.0, 2.0);

S(["a", "b"]);

fun sumElist (nil) = 0
  | sumElist (S(x)::L) = sumElist (L)
  | sumElist (P(x,y)::L) = y + sumElist(L)
;

sumElist [P("in", 6), S("function"), P("as", 2)];

datatype 'label btree =
Empty |
Node of 'label * 'label btree * 'label btree;

Node ("ML",
    Node ("as",
        Node ("a", Empty, Empty),
        Node ("in", Empty, Empty)
    ),
    Node ("types", Empty, Empty)
);

datatype 
    'label evenTree = Empty
    | Enode of 'label * 'label oddTree * 'label oddTree
and
    'label oddTree =
      Onode of 'label * 'label evenTree * 'label evenTree
;

val t1 = Onode( 1, Empty, Empty);
val t2 = Onode (1, Empty, Empty);
val t3 = Enode (3, t1, t2);
val t4 = Onode (4, t3, Empty)

structure IntLT = struct
    type t = int
    val lt = (op <)
    val eq = (op =)
end;

structure IntDiv = struct
    type t = int
    fun lt (m,n) = (n mod m = 0)
    val eq = (op =)
end;

IntLT.lt;
IntDiv.lt;
IntLT.lt(3,4);
IntDiv.lt(3,4);


signature ORDERED = sig
    type t
    val lt : t * t -> bool
    val eq : t * t -> bool
end;

signature QUEUE = sig
    type 'a queue
    exception QueueError
    val empty : 'a queue
    val isEmpty : 'a queue -> bool
    val singleton : 'a -> 'a queue
    val insert : 'a * 'a queue -> 'a queue
    val peek : 'a queue -> 'a
    val remove : 'a queue -> 'a * 'a queue
end;

structure TwoListQueue :> QUEUE = struct
    type 'a queue = 'a list * 'a list
    exception QueueError
    val empty = ([],[])
    fun isEmpty([],[]) = true
      | isEmpty(_) = false
    fun singleton a = ([],[a])
    fun insert(a, ([],[])) = ([],[a])
      | insert(a, (ins,outs)) = (a::ins,outs)
    fun peek(_,[]) = raise QueueError
      | peek(ins,a::outs) = a
    fun remove(_,[]) = raise QueueError
      | remove ([], [a]) = (a, ([], []))
      | remove ([], outs) = remove (rev outs, [])
      | remove (a::ins, outs) = (a, (ins, outs))
end;