/* Templated implementations of a simple bag
 * Note the lack of including the h file!
 * The h file includes the hpp at the bottom!
 */


// TODO1: Define your name function here:
void get_identity (string &my_id)
{
  my_id = "lcmdk";
  return;
}

// TODO2: Fix this function to throw a MyException when the bag is FULL
template <typename T>
bool SimpleBag<T>::insert(const T &myItem)
{
    if(size() >= CAPACITY)
    {   
        //Throw the custom exception
        throw MyException();
        return false;
    }

    data[used] = myItem;
    used++;

    return true;
}

template <typename T>
bool SimpleBag<T>::remove(const T &myItem)
{
    if(used == 0) // empty SimpleBag.
        return false;

    int index = 0;

    while(index < used && data[index] != myItem)
        index++;

    //if myItem is not present, index would be == used.
    if(index == used)
        return false;

    // myItem is now removed.
    // we overwrite data[index] with data[used - 1] and decrement used by 1.
    data[index] = data[used - 1];
    used--;

    return true;
}
