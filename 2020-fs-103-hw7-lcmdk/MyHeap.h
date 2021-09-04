// Declare your templated heap class here
//  The actual implementation should go into MyHeap.hpp
// Hint: if you are having a hard time figuring out how to start, look at the
//  past assignments and the example lecture code
// Reference:
//  http://en.cppreference.com/w/cpp/container/priority_queue

/* You will need to implement the following for MyHeap:
 *   1.   default constructor - starts with an empty array
 *   2.   parameterized constructor - takes two parameters, one templated array,
 *          and an integer size of the array.
 *          The constructor should build the internal heap using the heapify
 *          operation we learned. Note the syntax of this constructor differs
 *          from the std:: constructor
 *   3.   copy constructor
 *   4.   destuctor
 *   5.   operator =
 *   6.   top
 *   7.   pop
 *   8.   push
 *   9.   empty
 *   10.  size
 *   others: any additional internal functions that are needed or desired
 *             (i.e. reserve, shrink_to_fit, build_heap (heapify), sift_down(),
 *             etc.)
 *
 * Note 1:
 *  The behavior, return types, and parameters of the top, pop, push, empty,
 *  and size functions should be congruent with those of the std::priority_queue
 *
 * Note 2:
 *  Don't forget the get_identity function
 */
#ifndef MYHEAP_H
#define MYHEAP_H

#include <iostream>
#include <string>
using namespace std;

void get_identity(string &my_id);

template <typename T>
class MyHeap
{
    public:
        //Default Constructor
        MyHeap();
    
        //Destructor
        ~MyHeap();
    
        //Parameter Constructor
        MyHeap(T *arr, int size);
    
        //Copy Constructor
        MyHeap(const MyHeap<T> &source);
    
        //Equals operator
        MyHeap<T> & operator = (const MyHeap<T> &source);
    
        //Top Function
        T & top();
    
        //Pop Function
        void pop();
    
        //Push Function
        void push(const T &x);
    
        //Empty Function
        bool empty();
    
        //size Function
        int size();
    
        //Reserve Function
        void reserve(int new_cap);
    
        //shrink function
        void shrink_to_fit();
    
        //clear function
        void clear();
    
        //Build Heap Function
        void build_heap();
    
        //Sift Function
        void sift_down(int i);
    
        //Operator [] Function
        T & operator[](int i);
    
        //isLeaf
        bool isLeaf(int i);
    
        //left child Function
        int leftchild(int i);
    
        //right child function
        int rightchild(int i);
    
        //parent function
        int parent(int i);

    private:
        T * m_data = nullptr;
        int reserved_size;
        int data_size;
    
};

#include "MyHeap.hpp"
    
#endif
