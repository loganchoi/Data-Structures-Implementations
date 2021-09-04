/* Sample tester (for debugging, add the -g flag if you want to use gdb)
 * We've included std::list below to show you how your types should behave.
 * Test all your MyList functions here or in multiple mains.
 * Hint: Build and test one function at a time!!
 */

// USE THIS TO TEST, BUT REMOVE LATER TO VALIDATE YOUR OWN IMPLEMENTAION
#include <list>
#include <iostream>
using namespace std;

// Uncomment this to test with your own list implementation
 #include "MyList.h"

int main()
{
    // Uncomment this to test with your own list implementation
   MyList<int> l;
   // std::list<int> l;

    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    //l.erase(3);
    cout << l.front() << endl;
    l.front() = 33;
    cout << l.front() << endl;
    cout << l.back() << endl;

    cout << l.size() << endl;

    l.push_front(423);

    cout << l.front() << endl;

    // Uncomment this to test with your own list implementation
    cout << "Hit assign" << endl;
    MyList<int> sink = l;
    //std::list<int>sink = l;
    cout << sink.front() << endl;
    cout << sink.back() << endl;

    l.push_front(3);
    //l.remove(200);
    cout << "Hit insert" << endl;
    l.insert(l.end(), 20);
    l.push_front(20);
    l.pop_front();
    l.remove(20);
    //l.reverse();
    cout << "SIZE: " << l.size() << endl;
    int f = l.size();
    //l.erase(2);
    //l.erase(10);
  
    for(int i = 0; i < f; i++)
    {
        cout << l.back() << endl;
        l.pop_back();

    }

    return 0;
}
