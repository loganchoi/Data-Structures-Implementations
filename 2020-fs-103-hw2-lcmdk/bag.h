/* TODO1: Create an abstract templated class 'Bag' which will serve as an
    interface to the two other derived bag implementations.
 * This is the ONE h file you CAN edit.
 * You must include the following *pure virtual* functions:
    - insert()
    - remove()
    - size()
    - remember, you do not need to have a implementation body for a PVF; thus,
        do you need a bag.hpp file?
 * The name of the templated abstract class (templated on T) should be Bag, look
    at the header files of the other two bag implementations for guidance
 * TODO2: Include a public member variable in your abstract class
    - std::string parent_variable = "this is from the abstract class";
 */

#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <string>
#include "my_exception.h"
using std::string;

/*
Writes to a std::string passed by reference, containing:
    * your (the student author's) Campus Username
TODO3: Put the definition for this in *bag_simple.hpp*
*/
void get_identity(string &my_id);


// implement your abstract class here:
template <typename T>
class Bag
{
  public:
    Bag(){}
    std::string parent_variable = "this is from the abstract class";
    virtual bool insert(const T &item) = 0;
    virtual bool remove(const T &item) = 0;
    virtual int size() const = 0;
};



#endif
