/* This is a simple main, which is here for you to mess with and to verify your
    code (not as a graded component of the assignment)
 * This should serve as a starting point for your unit testing.
 *
 * Assignment:
 * The bag is one of the simplest data structures.
 * Read: https://en.wikipedia.org/wiki/Set_(abstract_data_type)#Multiset

 * Task 1
 *  - implement the custom exception in the my_exception.cpp file

 * Task 2
 *  - implement an abstract tempated class in bag.h

 * Task 3
 *  - read and understand the simple bag class
 *  - edit bag_simple.hpp to make the insert item throw our custom exception

 * Task 4
 *  - read and understand the dynamic bag class
 *  - implement the occurrences function in the hpp file
 *  - fix the memory leak in bag_dyn.hpp
 */

#include "bag.h"
#include "bag_simple.h"
#include "bag_dyn.h"
#include "my_exception.h"

int main()
{
    SimpleBag<int> my_bag;
    my_bag.insert(4);
    string my_id;
  
    get_identity(my_id);
    std::cout << my_id << std::endl;

    //for (int x=0; x < 11; x++) This matches exception and aborts the program
	//my_bag.insert(6);

    DynamicBag<int> my_dynamic_bag;
    for(int x = 0; x < 35; x++)
        my_dynamic_bag.insert(4);

    DynamicBag<int> copy_of_bag;
    copy_of_bag = my_dynamic_bag;

    std::cout << my_bag.parent_variable << std::endl;

    // Polymorphism
    Bag<int> *pBag;
    pBag = &my_dynamic_bag;
    pBag->insert(5);

    my_dynamic_bag.print_bag();

    // Do extensive testing of your code additions here:
    // you should test using a polymorphic pointer to the parent class when
    //  calling the functions (e.g. insert, remove, size)
    for (int i = 0; i< 4;i++)
       my_dynamic_bag.insert(10);

    my_dynamic_bag.print_bag();

    for (int i=0; i< 3; i++)
       my_dynamic_bag.remove(10);
    
    my_dynamic_bag.resize(1000);

    std::cout << "Number of 4s: " << copy_of_bag.occurrences(4) << "\n";
    // This should crash the program:
    //throw MyException();

    return 0;
}
