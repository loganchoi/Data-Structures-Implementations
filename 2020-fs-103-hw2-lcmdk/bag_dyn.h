/* This is a bag that grows dynamically when items are added.
 * Please read and play with this code until you understand it.
 * It wil serve as the framework for later assignments, and there are some key
    elements here we will build on.
 * Note that the hpp file is included at the bottom.
 * DO NOT edit this h file. You'll implement the changes in the bag_dyn.hpp file
 * Do not ever #include cpp files.
 */

#include "bag.h"

#ifndef BAG_DYN_H
#define BAG_DYN_H

template <typename T>
class DynamicBag: public Bag<T>
{
    private:
        //our dynamic array.
        T *data = nullptr;

        //how much of the “data” array is currently being used.
        int used;

        //what is the current (max) capacity of the “data” array.
        int capacity;

    public:
        static const int DEFAULT_CAP = 30;

        //parameterized constructor, which can also act as default constructor.
        DynamicBag(int initial_cap = DEFAULT_CAP);

        //copy constructor needed since we use dynamic memory in class.
        DynamicBag(const DynamicBag<T> &other_bag);

        //MODIFICATION MEMBER FUNCTIONS

        //overloaded assignment operator needed since we use dynamic memory in class.
        //deep-copy is preferred than shallow-copy
        void operator=(const DynamicBag<T> &other_bag);

        ~DynamicBag(); // destructor needed since we use dynamic memory in class.

        bool insert(const T &entry);

        bool remove(const T &target);

        void resize(int new_cap); // modify the capacity of the dynamic bag

        //CONSTANT MEMBER FUNCTIONS

        int size() const {return used;}

        //returns how many times target appears in the bag.
        int occurrences(const T &target) const;

        void print_bag() const;
};

#include "bag_dyn.hpp"

#endif
