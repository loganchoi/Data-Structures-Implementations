 /* Define all your MyList-related functions here, including the get_identity
    function
 * You do not need to include MyList.h in this hpp header file. It includes
    this file at the bottom.
 */

//4000, 33, 100, 3 ,423, HI, 20, 100, 200
void get_identity(std::string &my_id)
{
    my_id = "lcmdk";
    return;
}


template <typename T>
MyList<T>::MyList()
{
    //Make size 0
    m_size = 0;
    
    //Initialize the node pointer with the prev and next equal to null
    m_sentinel = new Node<T> (nullptr,nullptr);
    
    //Make the m_next and m_prev of the node equal to itself because
    //there is nothing to attach yet. It is a circular linked list.
    m_sentinel->m_next = m_sentinel;
    m_sentinel->m_prev = m_sentinel;
}

template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
    //Get the source for now.
    Node<T> * temp = source.m_sentinel;
   
    //Reset size;
    m_size = 0;

    //Make a new starting node
    m_sentinel = new Node<T> (nullptr,nullptr);

    //Make the pointers equal to it's own node for now
    m_sentinel->m_next = m_sentinel;
    m_sentinel->m_prev = m_sentinel;
    
    for (int i = 0;i < source.m_size; i++)
    {
        //Move to next node
        temp = temp->m_next;
        
        //Insert from back, and it should increment size
        push_back(temp->m_element);
    }

    //I don't delete temp because those are the nodes being added
    //delete temp;
}

template <typename T>
MyList<T>::~MyList()
{
    //Get the starting node.
    Node<T> * temp = m_sentinel;
    
    //Within the while loop,
    for (int i = 0; i < m_size; i++)
    {
        //Move to next node
        //Can I use the pop_back function?
        temp = temp->m_next;
        //delete the node  pointer
        delete temp;
    }
    //The size is now zero again
    m_size = 0;
    //Delete the whole thing
    delete m_sentinel;
     
}

template <typename T>
MyList<T> & MyList<T>:: operator=(const MyList<T> &source)
{
    //Get the starting node
    Node<T> * temp = source.m_sentinel;
    
    clear();
    m_size = 0; //Just to make sure
	
    for (int i = 0;i < source.m_size; i++)
    {
        //Move to next node
        temp = temp->m_next;
        
        //Add the element from the back
        push_back(temp->m_element);
    }
    
    //I believe I delete temp here or am i just dumb
    //delete temp;
    
    return (*this);
}

template <typename T>
T & MyList<T>::front()
{   
    //Return the front element
    return (m_sentinel->m_next->m_element);
}

template <typename T>
T & MyList<T>::back()
{
    //Return the back element
    return (m_sentinel->m_prev->m_element);
}

template <typename T>
void MyList<T>::assign(int count, const T &value)
{
    //Get rid of the existing nodes and everything
    if (m_size>0)
    	clear();
  
    //size should already be zero.
    m_size = 0;//Just in case
    

    //Add the new elements  
    for (int i = 0; i < count;i++)
    {
        push_front(value);
    }
    
    return;
}

template <typename T>
void MyList<T>::clear()
{

    //Get the starting node.
    //Node<T> * temp = m_sentinel;
    
    //cout << "Hit clear function" << endl;
    //Basically does what destructor does.
  	
    int forSize = m_size;

    for (int i = 0; i < forSize; i++)
	pop_back();

    //Make the pointers equal itself again
    m_sentinel->m_next = m_sentinel;
    m_sentinel->m_prev = m_sentinel;
    return;
}

template <typename T>
void MyList<T>::push_front(const T &x)
{
    //These are new nodes that need to be attached
    Node<T> * temp = new Node<T> (x,m_sentinel,m_sentinel->m_next);
    Node<T> * temp2 = new Node<T> (x,m_sentinel,m_sentinel);
    
    //Check to see ify ou only have sentinel node
    if (m_size == 0)
    {    
        //Delete the unused node then
        delete temp;
        //Increment
        m_size++;
        
        //Set the new pointers
        m_sentinel->m_next = temp2;
        m_sentinel->m_prev = temp2;
        return;
    }
    
    //Delete the unused node then
    delete temp2;
    //Increment
    m_size++;
    
    //Set the new pointers
    m_sentinel->m_next->m_prev = temp;
    m_sentinel->m_next = temp;

    return;
}

template <typename T>
void MyList<T>::push_back(const T &x)
{
    //These are new nodes that need to be attached
    Node<T> * temp = new Node<T> (x,m_sentinel->m_prev,m_sentinel);
    Node<T> * temp2 = new Node<T> (x,m_sentinel,m_sentinel);
    
    //Check to see if you only have sentinel node
    if (m_size == 0)
    {   
        //Delete unused node
        delete temp;
	//Increment
        m_size++;
        
        //set new pointers
        m_sentinel->m_next = temp2;
        m_sentinel->m_prev = temp2;
        return;
    }
    
    //Delete unuysed node
    delete temp2;
    //Increment
    m_size++;
    //Set new pointers
    m_sentinel->m_prev->m_next = temp;
    m_sentinel->m_prev = temp;

    return;
}

//Fix POP FUNCTIONS
template <typename T>
void MyList<T>::pop_back()
{
    //Check if there is nothing to pop
    if (m_size == 0)
        return;
    
    //Decrement
    m_size--;
   
    //Get the node that is from the back
    Node<T> * temp = m_sentinel->m_prev;

    //Reset the pointers
   
    m_sentinel->m_prev->m_prev->m_next = m_sentinel;
    m_sentinel->m_prev = m_sentinel->m_prev->m_prev;
    
    //cout << "Hit pop_back() functions" << endl;
    //Delete that node
    delete temp;
    
    return;
}

template <typename T>
void MyList<T>::pop_front()
{
    //Check if there is nothing to pop
    if (m_size == 0)
        return;
   
    //Decrement
    m_size--;

    //Get the node that is from the front
    Node<T> * temp = m_sentinel->m_next;

    //Reset the pointers
    m_sentinel->m_next->m_next->m_prev = m_sentinel;
    m_sentinel->m_next = m_sentinel->m_next->m_next;
    
    //Delete that node
    delete temp;
    
    return;
}

template <typename T>
void MyList<T>::insert(int i,const T &x)
{
    //Check if it is in range
    if (i> m_size)
        return;
    
    //Get the starting node
    Node<T> * temp = m_sentinel;
    
    //Get to that node
    for (int j = 0; j <= i;j++)
        temp = temp->m_next;
    
    //Increment the size
    m_size++;

    //Create a new Node and add it
    Node<T> * newNode = new Node<T> (x,temp->m_prev,temp);
    newNode->m_prev->m_next = newNode;
    newNode->m_next->m_prev = newNode;
  
    return;
}

template <typename T>
void MyList<T>::remove(T value)
{
    //Get the starting node
    Node<T> * temp = m_sentinel;

    //Variables
    int i, size = m_size;

    for (i = 0; i< size;i++)
    {
        temp = temp->m_next;
        if (temp == m_sentinel)
            break;
        //As you move along the linked list, delete if element is value
        if (temp->m_element == value)
        {
            //Basically doing what erase does, but I somehow can't call it.
            erase(i);
        }
    } 
    
    return;
}

template <typename T>
void MyList<T>::erase(int i)
{
    //Check for range
    if (i>=m_size)
        return;
   
    //Get starting area
    Node<T> * temp = m_sentinel;
    
     //Get to that node
    for (int j =0;j <= i;j++)
    {
        temp = temp->m_next;
    }

    m_size--;
    //Reset the pointers
    temp->m_next->m_prev = temp->m_prev;
    temp->m_prev->m_next = temp->m_next;
    delete temp;
    
    return;
}

template <typename T>
void MyList<T>::reverse()
{
    //Get the front and back nodes
    Node <T> * head = m_sentinel->m_prev;
    Node<T> * tail = m_sentinel->m_next;
    
    for (int i = 0; i< m_size/2 ; i++)
    {   
        //Swap the elements in the respective node
        std::swap(head->m_element,tail->m_element);

        //Move along the linked list
        head = head->m_prev;
        tail = tail->m_next;
    }
  
    //Delete the head and tial pointers
    head = tail = nullptr;
    
    delete head;
    delete tail;
    return;
}

template <typename T>
bool MyList<T>::empty()
{
    //If m_size is positive number, it is not empty
    if (m_size >0)
        return false;
    return true;
}

template <typename T>
int MyList<T>::size()
{
    //Return number of nodes in linked list excluding dummy node.
    return m_size;
}
