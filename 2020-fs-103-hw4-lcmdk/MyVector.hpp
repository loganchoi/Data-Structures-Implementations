/* Define all your MyVector-related functions here, including the swap and the
    get_identity functions.
 * You do not need to include MyVector.h in this hpp header file. It includes
    this file at the bottom.
 */

void get_identity(string &my_id)
{
  my_id = "lcmdk";
  return;
}

template <typename T>
void MySwap(T &a, T &b)
{
  //Variables
  T temp; //temp holds a value

  //Switch the two values
  temp = a;
  a = b;
  b = temp;

  return;
}

template <typename T>
MyVector<T>::MyVector()
{
  //Default constructor
  m_data = nullptr;
  reserved_size = 0;
  data_size = 0;
}

// We're giving you this one for freenand as a guide for the syntax.
template <typename T>
MyVector<T>::~MyVector()
{
    //Delete
    delete[] m_data;
}

template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
{
  //Overloads the equal sign and is basically copy constructor 
  //Gets all the info then transfers it
  data_size = source.data_size;
  reserved_size = source.reserved_size;

  //Make sure the m_data is not empty so you don't delete a nullptr
  if (m_data != nullptr)
      delete [] m_data;

  //Set the array first
  m_data = new T [reserved_size];

  //Copy each element
  for (int i = 0; i < data_size; i ++)
	m_data[i] = source.m_data[i];
  //Return the new vector
  return (*this);
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
  //Copy Constructor
  //Gets all the info then transfers it
  data_size = source.data_size;
  reserved_size = source.reserved_size;
  
  if (m_data != nullptr)
     delete [] m_data;
  //set the array first
  m_data = new T [reserved_size];
  
  //Copy each element
  for (int i = 0; i < data_size; i ++) 
        m_data[i] = source.m_data[i];

}

template <typename T>
T & MyVector<T>::operator[](int i)
{
  //Return element at position i in array
  return m_data[i];
}

// Another example: remember when writing an implementation in hpp,
// return type first, then scope just before the function name.
template <typename T>
T & MyVector<T>::at(int index)
{  
  //Check to see if index is within range
  if (index < 0 || index >= data_size)
     throw std::out_of_range("Not Valid Index");

  //otherwise return the element at index
  return m_data[index];
}

template <typename T>
T & MyVector<T>::front()
{
  //Return first element
  return m_data[0];
}  

template <typename T>
T & MyVector<T>::back()
{
  //Return last element used
  return m_data[data_size-1];
}

template <typename T>
int MyVector<T>::capacity()
{
  //Return how much the array can hold
  return reserved_size;
}

//Finish below
template <typename T>
void MyVector<T>::reserve(int new_cap)
{
  //Check to see if the new capacity is larger
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
        MySwap(m_data,copy);
 
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

template <typename T>
void MyVector<T>::shrink_to_fit()
{
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
  MySwap(m_data,copy);

  //Delete copy
  delete [] copy;
  copy = nullptr;
  

  return;  
}

template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
  
  //Change the data_size
  data_size = count;
  reserved_size = count * 2;

  //Delete the pointer if there is something in there
  if (m_data != nullptr)
  	delete [] m_data;

  m_data = nullptr;  

  //Set the pointer again
  m_data = new T [reserved_size];
  
  //cout << "Second loop" << endl;
  //Put the value into the vector
  for (int i = 0; i < data_size;i++)
     m_data[i] = value;

  return;
}

template <typename T>
void MyVector<T>::clear()
{
  //Clear all the vector info
  data_size = 0;
  reserved_size = 0;
  delete [] m_data;
  m_data = nullptr;
  return;
}

template <typename T>
void MyVector<T>::push_back(const T &x)
{  
  //Increment data size
  data_size++;

  //If data_size is greater, need more space 
  if (data_size >= reserved_size)
  {
    //If reserve size is zero, that means you need to pass in one
    if (reserved_size ==0)
	reserve(reserved_size +1);
    //otherwise just multiply by 2
    else
    	reserve(reserved_size * 2);
  }
 
  //Just in case someone reserves waaay too much space
  if (reserved_size/4 > data_size)
	shrink_to_fit();

  //set the value in
  m_data[data_size-1] = x;
  return;
}

template <typename T>
void MyVector<T>::pop_back()
{
  //Check to see if there is nothing to pop_back
  if (data_size == 0)
	return;

  //Decrement data_size;
  data_size--;

  //Check to see if there is too much space
  if ((reserved_size/4) > data_size)
     shrink_to_fit();

  return;
}

template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
  //INcrement data size
  data_size +=1;
  
  //Check to see if there is enough space
  if (data_size >= reserved_size)
  {
      //Increment one if reserve size is zero
      if (reserved_size == 0)
	  reserve(reserved_size + 1);
      //Otherwise multiply by 2
      else
      	  reserve(data_size * 2);
  }
  //Just in case someone reserves waaaaay too mjuch space
  if (reserved_size/4 > data_size)
	shrink_to_fit();

  //Swap the data starting from the back
  for (int num = data_size; num > i; num--)
      MySwap(m_data[num],m_data[num-1]);
  
  m_data[i] = x;
  return;
}

template <typename T>
void MyVector<T>::erase(int i)
{
  //Check to see if there is some data
  if (data_size == 0)
      return;
  
  //Check to see if there is enough space
  if (reserved_size == data_size)
      reserve(data_size*2);

  //Decrement dataSize
  data_size-=1;
  
  //Check to see if there is too much space
  if (reserved_size/4 > data_size)
      shrink_to_fit();
  
  //Starting from the position, swap
  for (int num = i; num < data_size; num++)
      MySwap(m_data[num],m_data[num+1]);
  
  return;
}

template <typename T>
int MyVector<T>::size()
{
  //Return used data elements
  return data_size;
}

