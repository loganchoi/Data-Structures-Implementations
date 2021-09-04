void get_identity(string &my_id)
{
    my_id = "lcmdk";
    return;
}

template <typename T>
MyHeap<T>::MyHeap()
{
    //Set the pointer to null and the size to zeros
    m_data = nullptr;
    reserved_size = 0;
    data_size = 0;
}

template <typename T>
MyHeap<T>::~MyHeap()
{
    //Delete the pointer and set the values to zero
    delete [] m_data;
    reserved_size = 0;
    data_size = 0;
    m_data = nullptr;
}

template <typename T>
MyHeap<T>::MyHeap(T *arr, int size)
{
    
    //Reset the variables
    delete [] m_data;
    m_data = nullptr;

    data_size = size;
    reserved_size = size * 2;

    m_data = new T[reserved_size];    
    //Copy from array
    for (int i = 0; i < data_size; i++)
       m_data[i] = arr[i];
    
    //Heapify the array.
    build_heap();
}

template <typename T>
MyHeap<T>::MyHeap(const MyHeap<T> &source)
{
    //Delete the data
    delete [] m_data;
    m_data = nullptr;
    
    //Reset data
    data_size = source.data_size;
    reserved_size = source.reserved_size;
    m_data = new T [reserved_size];
    
    //Copy from copy array
    for (int i = 0; i < data_size; i++)
        m_data[i] = source.m_data[i];
    
}

template <typename T>
MyHeap<T> & MyHeap<T>::operator = (const MyHeap<T> &source)
{
    //Delete the data
    delete [] m_data;
    m_data = nullptr;
    
    //reset data
    data_size = source.data_size;
    reserved_size = source.reserved_size;
    m_data = new T [reserved_size];
    
    //Copy from copy array
    for (int i = 0; i < data_size; i++)
        m_data[i] = source.m_data[i];
    
    return(*this);
}

template<typename T>
T & MyHeap<T>::top()
{
    //return the first index which should be the max
    return m_data[0];
}

//FIX POP FUNCTION
template <typename T>
void MyHeap<T>::pop()
{
    if (empty() == true)
       return;
    
    //Check if it not empty
    if (empty()==false)
    {
        //Swap the first and last
        std::swap(m_data[0],m_data[data_size-1]);
        //Decrement
        data_size--;
        //Swap back the first and last but the last should be a diffrent index
        if (empty()==false)
            std::swap(m_data[0],m_data[data_size-1]);
    }

    //Check if you have too much space
    if (reserved_size/4 > data_size)
        shrink_to_fit();
    
    //heapify array.
    if (data_size !=0)
       build_heap();
    return;
}

template <typename T>
void MyHeap<T>::push (const T &x)
{
    //Increment data size
    data_size ++;
    
    //Check if you need more space
    if (data_size>=reserved_size)
    {
        if (data_size >= reserved_size)
        {
            //If reserve size is zero, that means you need to pass in one
            if (reserved_size ==0)
                reserve(reserved_size +1);
            //otherwise just multiply by 2
            else
                reserve(reserved_size * 2);
        }
    }
    //Set the data
    m_data[data_size-1] = x;
    //heapify the array
    build_heap();
    return;
}

template <typename T>
bool MyHeap<T>::empty()
{
    //Check to see if the data_size has nothing
    if (data_size == 0)
        return true;
    
    return false;
}

template <typename T>
int MyHeap<T>::size()
{
    //return the data_size.
    return data_size;
}

template <typename T>
void MyHeap<T>::reserve(int new_cap)
{
    //I just resued my code for the vector assignment
    if (new_cap > reserved_size)
    {
        //Set the new reserve size
        reserved_size = new_cap;
        
        //If new _cap is not one that means it was not a nullptr
        if (m_data != nullptr)
        {
            //Make a copy array
            T *copy = new T [reserved_size];
            
            //Copy the data that is used only
            for (int i = 0; i < data_size; i++)
            {
                copy[i] = m_data[i];
            }
            
            //Delete the old data for reallocation
            delete [] m_data;
            m_data = nullptr;
            
            //Set the pointer array again
            //Set the pointer array again
            m_data = new T [reserved_size];
            
            //Copy from the copy array
            for (int i = 0; i < data_size; i++)
            {
                m_data[i] = copy[i];
            }
            
            //Delete the copy array
            delete [] copy;
            copy = nullptr;
        }
        else
        {
            //if the new_cap is one, then just make a new array;
            m_data = new T [reserved_size];
        }
    }
    return;

}

template<typename T>
void MyHeap<T>::shrink_to_fit()
{
    //I just resued my code for the vector assignment
    //Set the new reserved size
    reserved_size = data_size * 2;
    
    //In case the m_data is not set
    if (m_data == nullptr)
    {
        return;
    }
    
    //Another check
    if (reserved_size == 0)
        return;
    
    //Make a copy array
    T *copy = new T [reserved_size];
    
    //copy the data that is used only
    for (int i = 0; i < data_size; i++)
    {
        copy[i] = m_data[i];
    }
    
    //Delete the old data for reallocation
    delete [] m_data;
    m_data = nullptr;
    
    //Set the pointer array again
    m_data = new T [reserved_size];
    
    //Copy from the copy array
    for (int i = 0; i < data_size; i++)
    {
        m_data[i] = copy[i];
    }
    
    //Delete copy
    delete [] copy;
    copy = nullptr;
    
    
    return;

}

template<typename T>
void MyHeap<T>::build_heap()
{
    //heapify the array
    for (int i = parent(data_size-1); i >=0; i--)
        sift_down(i);
    return;
}

template <typename T>
void MyHeap<T>::sift_down(int i)
{
    //Moving across the "tree" recursively
    int left = leftchild(i);
    int right = rightchild(i);
    int bigBoi = i;
    
    if (left < data_size && m_data[left] > m_data[i])
        bigBoi = left;
    
    if (right < data_size && m_data[right] > m_data[bigBoi])
        bigBoi = right;
    
    if (bigBoi != i)
    {
        std::swap(m_data[i],m_data[bigBoi]);
        sift_down(bigBoi);
    }
    
    return;
}

template <typename T>
T & MyHeap<T>::operator[](int i)
{
    //just returns the index
    return m_data[i];
}

template <typename T>
bool MyHeap<T>::isLeaf(int i)
{
    //Cheks to see if it is a leaf.
    return ((i>=data_size/2) && (i < data_size));
}

template <typename T>
int MyHeap<T>::leftchild(int i)
{
    //get the left child index
    return (2*i + 1);
}

template <typename T>
int MyHeap<T>::rightchild(int i)
{
    //get the right child index
    return (2*i + 2);
}

template <typename T>
int MyHeap<T>::parent(int i)
{
    //get the parent child index.
    return ((i-1)/2);
}
