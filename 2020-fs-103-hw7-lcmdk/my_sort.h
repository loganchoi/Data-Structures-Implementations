// Mimic the std:: version in simpler form
#ifndef MY_SORT_H
#define MY_SORT_H

//FIX HEAP SORT
template <typename T>
void my_sort (T arr[], int len)
{
    //This heapifys the array by making a heap
    MyHeap<T> heap(arr,len);
    
    // cout << "SORT HIT" << endl;
    //Get the top in the heap array and pop
    for (int i = 0; i <len;i++)
    {
        //Get the max of the heap
        arr[i] = heap.top();

        //cout << "what" << arr[i] << endl;
        //Pop that top, and get the next max essentially
        heap.pop();
        //cout << "Hit pop: " << i << endl;
    }
    
   // cout << "finish sort" << endl;
    return;
}

#endif
// Mimic the std:: version in simpler form
