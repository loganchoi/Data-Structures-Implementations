Programming Assignment 1 (HW1)
==============================

#  Dynamically Allocated Two-Dimensional Arrays

---

## What is this repository?
The files listed here are the starting point for your assignment.
Only add source files (not compiled files) to the Git repository.

## Note (actually do this)!!
Thoroughly read the syllabus sections on "Programming assignments" and "Grading". These sections give good tips, tricks, hints, and instructions for programming assignments, including how to submit via Git.

## Assignment description
Finding patterns in data, like text files, or arrays of pixel values, is the basis of many more advanced methods, for example, image recognition in AI, or text processing. This week, you will write a program to input and store a 2D matrix of data of user-defined size, and then find a segment of data in that matrix that matches a search key, regardless of its orientation or direction.
- If there is no matching, still report that the pattern was not found.

![matrix](matrix.png)

## Input/Output
These are both specified in the sample_*.txt files provided in your repository.

* Input is all via C++ std::cin at the command prompt. Even though sample_input.txt is a file, input is not via fstream or file input; we re-direct via **standard input**: https://en.wikipedia.org/wiki/Standard_streams.
* The general form of input is here:
```
    <number of cases>

    <number of rows> <number of columns>
    <data set>
    <intended word to search>

    <number of rows> <number of columns>
    <data set>
    <intended word to search>
```

* sample_output.txt specifies exactly what your program should produce. We will use the Unix program **diff** to compare your output to this file, and if yours does not match, you will lose points.
  * Diff command in Linux: https://linuxize.com/post/diff-command-in-linux/

* Assuming your compiled program name is **my_matrix_search.exe**,
```
$ my_matrix_search <my_input.txt >my_output.txt
```
will take input from the input file and will output to the output file. 

## Grading
This assignment will be graded based on the successful implementation of the functions in the header file using unit testing, and the correct output of main. Each function's performance on its own unit test will be worth a certain subset of those points, and the output of main will as well.

## Due date
Please see the schedule for all due dates.
