Programming assignment 8 (PA08)
===============================

Congratulations on making it this far -- the semester is almost over!

## Assignment Overview
**Help Tank identify the amount of viruses in code!**

![matrix](matrix.png)

You will implement a dictionary (abstract data type) using a **hash table**
data structure that will have similar functionality to `std::unordered_map`.
  * https://en.cppreference.com/w/cpp/container/unordered_map
  * https://www.cplusplus.com/reference/unordered_map/unordered_map/

### Assignment Description
Your main goal is to help Tank tracking down the amount of viruses in the code file.  Your tasks are:

1. Implement the `MyUnorderedMap` class, which should implement a hash table of `MyPair` objects. (MyUnorderedMap.h is already provided to you to start with)

  * Write the `MyUnorderedMap` class functions in the hpp file
  * You should choose a type of in-table **closed-hashing** for collision management
    * this include the **probing function** as well. It's up to you to choose using the simple linear probing or other ones
  * You should also choose how to manage the delete function properly (e.g., with the help of using special placement indicators, such as a *tombstone marker*)


2. Write a function called `get_virus_frequency()` that accepts an
arbitrary number of lines from standard input and builds a MyUnorderedMap
containing the **number** of occurrences for every word containing the word **"Virus"** in it.

  * For example, if the word "CryptoLockerVirus" appears 15 times in the input,then `map["CryptoLockerVirus"]` should return 15. For more detail, see the example of the behavior of this function at the end of pa08.cpp, which expects standard input during runtime.

```example
# This is how you'd run your main file

g++ pa08.cpp

./a.out < sample_input.txt
```

**Hint**: you can't just define word boundaries by spaces during word extraction, because the sample input file resembles that of an actual code file. Which means
that you will need to define word boundaries by special characters too. For
example, how would you extract `spAceFiLLervirUs` from `if (!spAceFiLLervirUs)`?

## Deliverable
You must submit the file `MyUnorderedMap.hpp` that contains the implementations of
1. all of your MyUnorderedMap functions and
2. get_virus_frequency() and
3. your name function

## General notes
The files listed here are the starting point for your assignment. Only add
source files (not compiled files) to the Git repository.

Thoroughly read the Canvas page **How to: Homework Submissions** for good tips,
tricks, hints, and instructions on programming assignments, including how to
submit via Git.

## Due date
Please see the canvas assignment schedule for all due dates.
