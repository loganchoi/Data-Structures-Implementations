// Mimic the std:: version in simpler form 
#ifndef MY_IS_SORTED_H
#define MY_IS_SORTED_H

template <typename T>
bool my_is_sorted(T arr[], int length)
{
    //Variables
    T next;
    T prev;
    
    //Traverse through the array.
    for (int i =0;i<length-1;i++)
    {
        //Get prev and next
        prev = arr[i];
        next = arr[i+1];
        
        //Check to see if the next index is greater than prev
        //But since it is non-ascending it means it is not sorted.
        if (prev < next)
            return false;
    }
    
    //Otherwise it is sorted in a non-ascending order
    return true;
    
}

#endif
