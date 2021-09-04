Programming assignment 6 (PA06)
===============================

## Assignment Description
Help Tank find Morpheus and the others in The Matrix by creating a
**dictionary** to automate the deciphering of known symbols in code!

![matrix](tank_matrix.jpg)

You will implement a dictionary (abstract data type) using a **binary search tree** (BST)
data structure that will have similar functionality to std::map.
  - https://en.cppreference.com/w/cpp/container/map

Your tasks are:

1. to write the **MyMap** functions

2. to write a function, **get_letter_frequency()**, that accepts an
arbitrary number of characters from standard input and builds a MyMap containing the
number of occurrences for each character in the input, i.e., if the letter 'a' occurs
43 times in the input, map['a'] should return 43.
  - an example of the behavior of this function is at the end of pa06.cpp.

## Notes
The files listed here are the starting point for your assignment. Only add source files (not compiled files) to the Git repository.

Thoroughly read the Canvas page **How to: Homework Submissions** for good tips, tricks, hints, and instructions on programming assignments, including how to submit via Git.

## Due date
Please see the canvas assignment schedule for all due dates.

* We give you a working pa06.cpp and its output (pa06_output.txt)
* We also give you a similar file pa06_std.cpp with the std:: versions of the map functions
*
* Note: map/dictionary does NOT allow duplicates.
* If you insert an item already in the map, overwrite the old one.
