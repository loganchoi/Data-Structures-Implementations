/* This is your h file. DO NOT edit it!
 *
 * TODO 1: implement the MyMap-related functions in MyMap.hpp
 * TODO 2: implement the get_letter_frequency() functionin MyMap.hpp
 * TODO 3: implement the get_identity function in MyMap.hpp
 * TODO 4: thoroughly test your MyMap class to ensure proper functional
    behaviors
*/

#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include "Dictionary.h"
#include "TreeNode.h"

using std::cout;
using std::endl;
using std::cerr;
using std::cin;

/*
* Same as before
*/
void get_identity(std::string &my_id);


template <typename K, typename V>
class MyMap: public Dictionary<K, V>
{
    private:
        TreeNode<MyPair<K, V>> *root = nullptr;

        V & at_helper(TreeNode<MyPair<K, V>> *&rt, const K &key);

        int size_helper(TreeNode<MyPair<K, V>> *rt) const;

        void clear_helper(TreeNode<MyPair<K, V>> *&rt);

        void insert_helper(TreeNode<MyPair<K, V>> *&rt,
          const MyPair<K, V> &init_pair);

        TreeNode<MyPair<K, V>> * get_min(TreeNode<MyPair<K, V>> *rt);

        void erase_helper(TreeNode<MyPair<K, V>> *&rt, const K &key);

        MyPair<K, V> * find_helper(TreeNode<MyPair<K, V>> *rt,
          const K &key) const;

        void print_helper(TreeNode<MyPair<K, V>> *rt, std::string indent) const;

        int count_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const;

        // This is a helper function for the copy constructor and operator=
        // It should recursively clone the whole tree, by using new to make a
        //  new tree node, whose left and right children are clones of the left
        //  and right children...
        // Take inspiration from the recursive "count" function presented in
        //  class for counting the number of nodes in a binary tree
        TreeNode<MyPair<K, V>> * clone(const TreeNode<MyPair<K, V>> *rt);

    public:
        MyMap();

        ~MyMap();

        MyMap(const MyMap<K, V> &source);

        MyMap<K, V> & operator=(const MyMap<K, V> &source);

        V & at(const K &key);

        V & operator[](const K &key);

        bool empty() const;

        int size() const;

        void clear();

        void insert(const MyPair<K, V> &init_pair);

        void erase(const K &key);

        MyPair<K, V> * find(const K &key) const;

        void print() const;

        int count(const K &key) const;
};

// Should accept a text file (for example a book) via std in (standard input),
//  for example: ./yourprogram < sample_input.txt
// Should build a dictionary of the counts of the characters in that file
// Do not add newlines (\n) to the dictionary (they'll mess up print, so ignore
//  them) 
void get_letter_frequency(MyMap<char, int> &in_tree);


#include "MyMap.hpp"
#endif
