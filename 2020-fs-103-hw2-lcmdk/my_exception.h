/* This header file implements (by overriding) a custom exception function here
    which follows the standard std exception class style for including an error message.
 * When we call that standard message function, it should return an error
    message: "Custom error has occurred"
 * The std::exception documentation:
    http://www.cplusplus.com/reference/exception/exception/
 * Lecture code examples: Exceptions16.cpp - Exceptions18.cpp
    from the documentation and examples on the std expection, you should be able
    to figure out *what* we are asking for ;)
 * DO NOT edit this h file. You'll implement the changes in the my_exception.cpp
 */

#ifndef MY_EXCEPT_H
#define MY_EXCEPT_H

#include <exception>

class MyException: public std::exception
{
    public:
        // C++98: throw(); C++11: noexcept
        // Put the implementation in my_exception.cpp
        virtual const char * what() const noexcept;
};

#endif
