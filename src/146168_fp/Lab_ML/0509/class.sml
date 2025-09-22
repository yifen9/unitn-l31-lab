signature Stack = sig
    val empty : 'a list
    val pop : 'a list -> 'a option
    val push : 'a * 'a list -> 'a list
    eqtype 'a stack
end;

structure Stack = struct
    type 'a stack = 'a list
    val empty = []
    val push = op ::
    fun pop [] = NONE
      | pop (tos::rest) = SOME tos
end :> Stack;

Stack.push(1, Stack.empty);

structure S = Stack;

S.push(1, S.empty);

structure LS = Stack :> Stack;

LS.push(1, LS.empty);

signature TREE = sig
    datatype 'a T = Br of 'a * 'a T * 'a T | Lf
    val count : 'a T -> int
    val depth : 'a T -> int
    val reflect : 'a T -> 'a T
end;

structure Tree = struct
    datatype 'a T = Br of 'a * 'a T * 'a T | Lf
    fun count Lf = 0
      | count (Br(v, t1, t2)) = 1 + count(t1) + count(t2)
    ;
    fun depth Lf = 0
      | depth (Br(v, t1, t2)) = 1 + Int.max(depth(t1), depth(t2))
    ;
    fun reflect Lf = Lf
      | reflect (Br(v, t1, t2)) = Br(v, reflect(t2), reflect(t1))
    ;
end :> TREE;

fun lower(nil) = nil
  | lower(c::cs) = (Char.toLower c) :: lower(cs)
;

fun strLT(x, y) = implode(lower(explode x)) < implode(lower(explode y));

datatype 'a btree = Empty | Node of 'a * 'a btree * 'a btree;

fun lookup lt Empty x = false
  | lookup lt (Node(y, left, right)) x =
        if
            lt(x, y)
        then
            lookup lt left x
        else
            if
                lt(y, x)
            then
                lookup lt right x
            else
                true
;

val t = Node("ML",
    Node("as",
        Node("a", Empty, Empty),
        Node("in", Empty, Empty)
    ),
    Node("types", Empty, Empty)
);

lookup strLT t "function";

lookup strLT t "ML";

fun insert lt Empty x = Node(x, Empty, Empty)
  | insert lt (T as Node(y, left, right)) x =
        if
            lt(x, y)
        then
            Node(y, (insert lt left x), right)
        else
            if
                lt(y, x)
            then
                Node(y, left, (insert lt right x))
            else T
;

insert strLT t "function";

exception EmptyTree;

fun deletemin(Empty) = raise EmptyTree
  | deletemin(Node(y, Empty, right)) = (y, right)
  | deletemin(Node(w, left, right)) =
        let
            val (y, L) = deletemin(left)
        in
            (y, Node(w, L, right))
        end
;

fun delete lt Empty x = Empty
  | delete lt (Node (y, left, right)) x =
        if
            lt(x, y)
        then
            Node(y, (delete lt left x), right)
        else
            if
                lt(y, x)
            then
                Node(y, left, (delete lt right x))
            else
                case(left, right) of
                    (Empty, r) => r |
                    (l, Empty) => l |
                    (l, r) =>
                        let
                            val (z, rl) = deletemin(r)
                        in
                            Node(z, l, rl)
                        end
;

fun sum(Empty) = 0
  | sum(Node(a, left, right)) = a + sum(left) + sum(right)
;

fun preOrder(Empty) = nil
  | preOrder(Node(a, left, right)) = [a] @ preOrder(left) @ preOrder(right)
;

fun postOrder(Empty) = nil
  | postOrder(Node(a, left, right)) = postOrder(left) @ postOrder(right) @ [a]
;

fun inOrder(Empty) = nil
  | inOrder(Node(a, left, right)) = inOrder(left) @ [a] @ inOrder(right)
;

type('d, 'r) mapTree = ('d * 'r)btree;

val t1 = Node(("a", 1), Empty, Empty): (string, int) mapTree;