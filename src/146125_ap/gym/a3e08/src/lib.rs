/*
Create a module called `sentence` that has a struct `Sentence` with a field `words: Vec<String>`.
Create the following methods for the struct `Sentence`:

  - `new_default` that initializes the field `words` with nothing in it.
  - `new` that takes a `&str`, splits it by whitespaces and inserts every `word` inside the words field.
    Create another module `test` with the function `magic_sentence`
    that mutually borrows a `HashMap<i32, Sentence>`, a `i: i32` and a `j: i32` and returns a `Result<Sentence, &str>`
    The function checks if the sentences at the two indexes exist and if so,
    creates a `Sentence` with all the equal words in the same position (same index) present in the `Sentence` s.
    If no words are found or if the indexes are not present in the HashMap, reutrn an `Err(&str)`.

Ex. the sentence "Hello my name was cool yesterday" and the sentence "Hi my name is cool" should result in the sentence "my name cool".
*/

mod r#mod;
