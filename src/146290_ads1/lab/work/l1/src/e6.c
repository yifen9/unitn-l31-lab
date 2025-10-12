/*
Student scoring system

Write a C program able to dynamically allocate an array of struct containing
MAX_SIZE = 20 uninitialised elements.

The struct, called student, must contain the following fields:
score (an integer ∈ [0, MAX_SCORE]) and studentId (an integer ∈ [0, MAX_ID]).

Write a function insert() that takes as input the array of struct, a position in
the array (an integer ∈ [0, MAX_SIZE − 1]), one integer (the score) and one
other integer (the studentId), read from STDIN with the scanf() function.

Write a function read() that takes as input a position in the array of struct
and prints the data within that index.

The program must loop infinitely, waiting for one of three commands:
i for insert, r for read, or q to quit and terminate the program.

When selecting insert or read,
the program must ask the user for the respective arguments of the internal
function call.
*/