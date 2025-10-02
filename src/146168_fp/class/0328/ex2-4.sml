(* Read a file of characters, treating it as a sequence of words (consecutive, non-white space characters). Return a list of the words in the file *)

(* test if a character is white space *)
fun white(" ") = true
| white("\t") = true
| white("\n") = true
| white(_) = false;

fun getWord(file) = (* read one word *)
    if
        TextIO.endOfStream(file)
    then
        ""
    else
        let
            val c = TextIO.inputN(file,1)
        in
            if
                white(c)
            then
                ""
            else
                c ^ getWord(file)
        end
;

fun getList1(file) = (* read all words from an instream *)
    if
        TextIO.endOfStream(file)
    then
        nil
    else
        getWord(file) :: getList1(file)
;

(* read all words from a file given the file name *)
fun getList(filename) = getList1(TextIO.openIn(filename));

