/* This is a simple bag that has a limit on its size.
 * Note that the hpp file is included at the bottom since it's a templated class
 * DO NOT edit this h file. You'll implement the changes in the bag_simple.hpp file
 * Do not ever #include cpp files.
 */

#ifndef BAG_SIMPLE_H
#define BAG_SIMPLE_H

#include "bag.h"

template <typename T>
class SimpleBag: public Bag<T>
{
    private:
        int used; // keeps track of the current number of items in the bag
        static const int CAPACITY = 10; // the max # of Items "data" can hold.
        T data[CAPACITY];

    public:
        //constructor
        SimpleBag(){used = 0;}

        //Modification member functions
        bool insert(const T &myItem);

        bool remove(const T &myItem);

        //constant member function.
        int size() const {return used;}
};

#include "bag_simple.hpp"

#endif
