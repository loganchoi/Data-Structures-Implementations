/* Templated implementations of dynamically allocated bag
 * Note the lack of including the h file!
 * The h file includes the hpp at the bottom!
 * TODO1: Implement the occurences function.
 * TODO2: Find and fix the memory leak in this file (there is at least one such
    occurrence)
 */

template <typename T>
DynamicBag<T>::DynamicBag(int initial_cap)
{
    data = new T [initial_cap];
    capacity = initial_cap;
    used = 0;
}

// This is a deep copy
template <typename T>
DynamicBag<T>::DynamicBag(const DynamicBag &other_bag)
{
    //allocate memory equal to other_bag.capacity number of Ts.
    data = new T[other_bag.capacity];

    //set capacity value.
    capacity = other_bag.capacity;

    //set “used” value.
    used = other_bag.used;

    //copy Ts.
    for(int i = 0; i < used; i++)
        data[i] = other_bag.data[i];
}

// This is a deep copy
template <typename T>
void DynamicBag<T>::operator=(const DynamicBag &other_bag)
{
    if(capacity != other_bag.capacity)
    {
        //deallocate old memory
        delete[] data;
        //allocate new memory
        data = new T[other_bag.capacity];
        capacity = other_bag.capacity;
    }

    for(int i = 0; i < other_bag.used; i++)
        data[i] = other_bag.data[i];

    used = other_bag.used;
}


template <typename T>
void DynamicBag<T>::resize(int new_cap)
{
    if(capacity == new_cap)
        return;

    if(new_cap < used) // don't risk losing data items when resizing
        new_cap = used;

    //allocate new memory
    // new_handler gets called in case of failure..
    T *new_data = new T[new_cap];

    //copy old items to new memory.
    for(int i = 0; i < used; i++)
        new_data[i] = data [i];

    //free old memory.
    delete[] data;

    data = new_data;

    capacity = new_cap;
}


template <typename T>
bool DynamicBag<T>::insert(const T &entry)
{
    //check if we have space to insert in existing data array.
    if(used == capacity)
        resize(capacity + 1);

    //insert the T entry.
    data[used] = entry;
    used++;

    return true; // successful insertion
}


template <typename T>
bool DynamicBag<T>::remove(const T &target)
{
    int i;
    // Better style as a while loop (don't worry about changing)
    for(i = 0; (i < used) && (data[i] != target); i++);

    //if target is not present, i == used.
    if(i == used)
        return false;

    //overwrite at the index of target.
    data[i] = data[used-1];
    used--;

    return true;
}


template <typename T>
int DynamicBag<T>::occurrences(const T &target) const
{
   int total = 0;
   for (int i = 0; i < capacity; i++)
   {
      if (data[i] == target)
	total++;
   }
   return total;
}


template <typename T>
void DynamicBag<T>::print_bag() const
{
    std::cout << "Members of the bag: " << std::endl;
    for(int i = 0; i < used; i++)
        std::cout << data[i] << std::endl;
}

template <typename T>
DynamicBag<T>::~DynamicBag()
{
    delete[] data;
    data = nullptr;
    return;
}
