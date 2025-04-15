(*
Write a function that takes a list of characters and returns true if the first element is a vowel
*)

fun vowel(#"a"::ys) = true
    | vowel(#"e"::ys) = true
    | vowel(#"i"::ys) = true
    | vowel(#"o"::ys) = true
    | vowel(#"u"::ys) = true
    | vowel(_) = false;