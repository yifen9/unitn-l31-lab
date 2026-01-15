(* prefixes : string -> string list
   Return all non-empty prefixes of s, from shortest to longest. *)
fun prefixes s =
  let
    val n = String.size s  (* length of s *)
    fun loop k =
      if k > n then []
      else String.substring (s, 0, k) :: loop (k + 1)
  in
    loop 1
  end

fun strict_prefixes s =
  let
    val n = String.size s
    fun loop k =
      if k >= n then []
      else String.substring(s, 0, k) :: loop (k + 1)
  in
    loop 1
  end

(* suffixes : string -> string list
   Return all non-empty suffixes of s, from longest to shortest. *)
fun suffixes s =
  let
    val n = String.size s
    fun loop i =
      if i >= n then []
      else String.extract (s, i, NONE) :: loop (i + 1)
  in
    loop 0
  end

fun strict_suffixes s =
  let
    val n = String.size s
    fun loop i =
      if Int.>=(i, n) then []
      else String.extract (s, i, NONE) :: loop (i + 1)
  in
    loop 1
  end

(* sum_binary : int list * int list -> int list
   Binary sum of two bit-lists (MSB-first), without using +. *)
fun sum_binary (xs, ys) =
  let
    (* full adder: (x,y,carry) -> (sum, carry') *)
    fun addBit (x, y, c) =
      case (x, y, c) of
          (0,0,0) => (0,0)
        | (0,0,1) => (1,0)
        | (0,1,0) => (1,0)
        | (1,0,0) => (1,0)
        | (0,1,1) => (0,1)
        | (1,0,1) => (0,1)
        | (1,1,0) => (0,1)
        | (1,1,1) => (1,1)
        | (_,_,_) => (0,0)

    (* process LSB-first lists *)
    fun loop ([], [], c) =
          if c = 0 then []
          else [1]
      | loop (x::xs, [], c) =
          let val (s, c') = addBit (x, 0, c)
          in s :: loop (xs, [], c') end
      | loop ([], y::ys, c) =
          let val (s, c') = addBit (0, y, c)
          in s :: loop ([], ys, c') end
      | loop (x::xs, y::ys, c) =
          let val (s, c') = addBit (x, y, c)
          in s :: loop (xs, ys, c') end

    val rx = List.rev xs
    val ry = List.rev ys
  in
    List.rev (loop (rx, ry, 0))
  end

fun s_prefixes s =
    let
        val n = String.size s
        fun loop i =
            if Int.>(i, n)
            then []
            else
                String.substring (s,0,i) :: loop (i+1)
    in
        loop 1
    end

fun s_suffixes s =
    let
        val n = String.size s
        fun loop i =
            if Int.>=(i, n)
            then []
            else
                String.substring (s,i,n-i) :: loop (i+1)
    in
        loop 0
    end

fun sum_binary (xs,ys) =
    let
        fun abit (x,y,c) =
            case (x,y,c) of
                (0,0,0) => (0,0)
              | (0,0,1) => (1,0)
              | (0,1,0) => (1,0)
              | (0,1,1) => (0,1)
              | (1,0,0) => (1,0)
              | (1,0,1) => (0,1)
              | (1,1,0) => (0,1)
              | (1,1,1) => (1,1)
              | (_,_,_) => raise Fail "not a bit"
        fun loop ([],[],c) =
                if c = 0
                then []
                else [1]
          | loop ([],y::ys,c) =
                let
                    val (s,c') = abit (0,y,c)
                in
                    s :: loop ([],ys,c')
                end
          | loop (x::xs,[],c) =
                let
                    val (s,c') = abit (x,0,c)
                in
                    s :: loop (xs,[],c')
                end
          | loop (x::xs,y::ys,c) =
                let
                    val (s,c') = abit (x,y,c)
                in
                    s :: loop (xs,ys,c')
                end
        val rx = List.rev xs
        val ry = List.rev ys
    in
        List.rev (loop (rx,ry,0))
    end

fun inc_binary xs =
    sum_binary (xs,[1])

datatype ctree = Empty
               | Leaf of char
               | Node of char * ctree * ctree

fun get_words_rev t =
    case t of
        Empty => ("","")
      | Leaf c => (String.str c, "")
      | Node (v,l,r) =>
            let
                val (lc,ln) = get_words_rev l
                val (rc,rn) = get_words_rev r
            in
                (rc ^ lc, ln ^ rn ^ String.str v)
            end

datatype Ptree = Empty
               | PLeaf of int * string
               | PNode of int * string * Ptree * Ptree

fun count_even t =
    let
        fun ie n =
            if (n mod 2 = 0)
            then 1
            else 0
    in
        case t of
            Empty => 0
          | PLeaf (i,s) => ie i
          | PNode (i,s,l,r) =>
                let
                    val le = count_even l
                    val re = count_even r
                in
                    ie i + le + re
                end
    end

fun count_even_strict t =
    case t of
        Empty => 0
      | PLeaf (i,s) => 0
      | PNode (i,s,l,r) =>
            count_even l + count_even r

fun prefix_sums xs =
  let
    fun loop ([], acc) = []
      | loop (x::xs, acc) =
          let
            val acc' = acc + x
          in
            acc' :: loop (xs, acc')
          end
  in
    loop (xs, 0)
  end

fun abls s =
    let
        val n = String.size s
        fun loop i =
            if Int.>=((i+1), n)
            then []
            else
                String.extract (s,i,NONE) :: loop (i+1)
    in
        loop 0
    end

fun all_but_last_suffixes s = abls s

fun f filename =
  let
    val ins = TextIO.openIn filename
    fun loop () =
      if TextIO.endOfStream ins then [""]
      else
        let
          val _    = TextIO.inputN (ins, 2)   (* drop 2 *)
          val keep = TextIO.inputN (ins, 2)   (* keep 2 *)
        in
          keep :: loop ()
        end
    val res = loop ()
    val _ = TextIO.closeIn ins
  in
    res
  end

fun g filename =
  let
    val ins = TextIO.openIn filename
    fun loop acc =
      if TextIO.endOfStream ins then acc
      else
        let
          val a = TextIO.inputN (ins, 1)
          val b = TextIO.inputN (ins, 1)
          val c = TextIO.inputN (ins, 1)
        in
          if Int.<((String.size a), 1) orelse Int.<((String.size b), 1) orelse Int.<((String.size c), 1)
          then acc
          else loop (acc ^ b)
        end
    val res = loop ""
    val _ = TextIO.closeIn ins
  in
    res
  end

fun h filename =
  let
    val ins = TextIO.openIn filename

    fun loop () =
      let
        val a = TextIO.inputN (ins, 1)
      in
        if Int.<((String.size a), 1) then []
        else
          let
            val _ = TextIO.inputN (ins, 1)
          in
            String.sub (a, 0) :: loop ()
          end
      end

    val res = loop ()
    val _ = TextIO.closeIn ins
  in
    res
  end