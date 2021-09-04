/* Define all your MyMap-related functions here, including the get_identity
    function
 * You do not need to include MyMap.h in this hpp header file. It includes
    this file at the bottom.
 */

void get_identity(std::string &my_id)
{
    my_id = "lcmdk";
    return;
}

//Private Functions
template<typename K, typename V>
V & MyMap<K,V>::at_helper(TreeNode<MyPair<K,V>> *&rt, const K & key)
{
    //Using count_helper, check to see if the key exists.
    if (count(key)==1)
        return find_helper(rt,key)->second;
    
    //Otherwise throw error
    throw std::out_of_range("MyMap::at\n");
}

template<typename K, typename V>
int MyMap<K,V>::size_helper(TreeNode<MyPair<K,V>> *rt) const
{
    if (rt != nullptr)
    {
        //Get total using recursion
        int total = size_helper(rt->left) + size_helper(rt->right) + 1;
        
        //Return the total
        return total;
    }
    
    else
        return 0;//If the node is a nullptr, then it's zero.
    
}

template<typename K, typename V>
void MyMap<K,V>::insert_helper(TreeNode<MyPair<K, V>> *&rt, const MyPair<K, V> &init_pair)
{
    //If the position is a nullptr, then it will finally insert the node
    if (rt == nullptr)
    {
        //The new node is set.
        rt = new TreeNode<MyPair<K,V>>(init_pair,nullptr,nullptr);
    }
    
    //Otherwise you move left of the tree from the current node
    else if (init_pair.first < rt->data.first )
        insert_helper(rt->left,init_pair);
    
    //Otherwise you move right of the tree from the current node
    else if (init_pair.first > rt->data.first)
        insert_helper(rt->right,init_pair);

    //Return once done with the recursion.
    return;
}


template<typename K, typename V>
void MyMap<K,V>::clear_helper(TreeNode<MyPair<K, V>> *&rt)
{
    //If there is something to delete, make sure you get the kids
    if (rt != nullptr)
    {
        //This gets the left and right kids
        clear_helper(rt->right);
        clear_helper(rt->left);
        
        //This deletes the parent after the kids
        delete rt;
        
        //Set it to null
        rt = nullptr;
        return;
    }
    
    //Otherwise just return
    return;
}

template<typename K, typename V>
TreeNode<MyPair<K, V>> * MyMap<K,V>::get_min(TreeNode<MyPair<K, V>> *rt)
{
    //Check if the furthest lefty is a nullptr, because it is ordered
    if (rt->left == nullptr)
        return rt;
    else
    {
        //Recursively call the function to get to the furthest left.
        return get_min(rt->left);
    }
}

template<typename K, typename V>
void MyMap<K,V>::erase_helper(TreeNode<MyPair<K, V>> *&rt, const K &key)
{
    //If the position is a nullptr, return
    if (rt == nullptr)
        return;
    
    //If key is leess than the current node key, then move left
    else if (key < rt->data.first)
        erase_helper(rt->left,key);
    
    //Otherwise if key is greater than the current node key, move right
    else if (key > rt->data.first)
        erase_helper(rt->right,key);
    
    //If it hits the key, then you delete it.
    else
    {
        //Get the node to delete
        TreeNode<MyPair<K,V>> * delNode = rt;
        
        //Reset the pointers
        
        //If right is empty, then the new "parent" node
        //is the left one
        if (rt->right == nullptr)
        {
            rt = rt->left;
            
            //Delete that node now
            delete delNode;
        }
        
        //If left is empty, then the new node is the right kid.
        else if (rt->left == nullptr)
        {
            rt = rt->right;
            //Delete that node
            delete delNode;
        }
        else //Node has two kids
        {
            //Get a node that gets the min of the right side
            TreeNode<MyPair<K,V>> * delNode = get_min(rt->right);

            //Reset the data MyPair
            rt->data.first = delNode->data.first;
            rt->data.second = delNode->data.second;

            //Recursively Call to reset the nodes,so you can delete
	    //This maintains the BST property of the left<rt<right
           //Reorganizes the BST
            erase_helper(rt->right,delNode->data.first);

	    //Do I delete delNode?
            //delete delNode; NOPE
        }
        
        //Set delNode to null
        delNode = nullptr;
    }
    
}

template<typename K, typename V>
MyPair<K, V> * MyMap<K,V>::find_helper(TreeNode<MyPair<K, V>> *rt,const K &key) const
{
    //If the position is a nullptr, then it's nothing. Base Case
    if (rt == nullptr)
        return nullptr;
    
    //If the key is found, then return the data by reference.Base Case
    if (rt->data.first == key)
    {
        return &(rt->data);
    }
    //Recursive below
    //Check the left side of the node
    else if(key < rt->data.first)
        return find_helper(rt->left,key);
    
    //Check the right side of the node
    else
        return find_helper(rt->right,key);
}

template<typename K, typename V>
void MyMap<K,V>::print_helper(TreeNode<MyPair<K, V>> *rt, std::string indent) const
{
    //Print out empty if the node holds nothing.
    if (rt == nullptr)//Base Case
    {
        cout << indent << "   [empty]" << endl;
        return;
    }
    
    //Print the right side first;
    print_helper(rt->right,indent = indent +"  ");
    
    //after printing the right side, print the data it holds.
    cout << indent << " [" << rt->data.first <<"]=" << rt->data.second<< endl;
    
    //Print the left side next
    print_helper(rt->left,indent);
}

template <typename K, typename V>
int MyMap<K,V>::count_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const
{
    //Returns a boolean, but converts the boolean to an int
    return (find(key)!=nullptr);

}

template <typename K, typename V>
TreeNode<MyPair<K, V>> * MyMap<K,V>::clone(const TreeNode<MyPair<K, V>> *rt)
{
    //Check to see if that node has data, if so then copy it
   if (rt != nullptr)//Base Case?
   {
       //Gets the data from the left side and right side of the root, adds it
       //Then returns the whole tree.

       //These recursively call
       TreeNode<MyPair<K, V>> * left = clone(rt->left);
       TreeNode<MyPair<K, V>> * right = clone(rt->right);
       TreeNode<MyPair<K, V>> * newElements = new TreeNode<MyPair<K,V>> (rt->data,left,right);
       return newElements;
   }

    //Otherwise return nullptr
    return nullptr;
}

//Public Functions

template<typename K,typename V>
MyMap<K,V>::MyMap()
{
    //The constructor should just make a nullptr.
    root = nullptr;
}

template<typename K, typename V>
MyMap<K,V>::~MyMap()
{
    //Call the clear_helper function to recursively delete
    clear_helper(root);
}

template<typename K, typename V>
MyMap<K,V>::MyMap(const MyMap<K,V> &source)
{
    //Make sure there is nothing in the root
    clear_helper(root);
    
    //Use the clone
    root = clone(source.root);
}

template<typename K, typename V>
MyMap<K,V> & MyMap<K,V>::operator=(const MyMap<K,V> &source)
{
    //Make sure there is nothing in the root
    clear_helper(root);
    
    //Call the clone function to actually copy.
    root = clone(source.root);
    return (*this);
}

template<typename K,typename V>
V & MyMap<K,V>::at(const K &key)
{
    //Call the at_helper function
    return at_helper(root, key);
}

template<typename K,typename V>
V & MyMap<K,V>:: operator[](const K &key)
{
    //Check to see if the key exists
    if (count(key)==1)
    {
        //If so use at_helper function
        return at_helper(root,key);
    }
    
    //Otherwise create new pointer of type MyPair
    MyPair<K,V> *letter = new MyPair<K,V> (key);
    
    //Insert the data pointer
    insert(*letter);
    
    //delete the letter because it is now inserted
    delete letter;
    
    //The return the at_helper function
    return at_helper(root,key);
}


template<typename K,typename V>
bool MyMap<K,V>::empty() const
{
    //check if the root has nothing in it
    if (root == nullptr)
        return true;
    
    //Otherwise there is something in there so return false
    return false;
}

template<typename K, typename V>
int MyMap<K,V>::size() const
{
    //Call size helper function
    return size_helper(root);
}

template<typename K,typename V>
void MyMap<K,V>::clear()
{
    //Call clear helper function
    clear_helper(root);
}

template<typename K,typename V>
void MyMap<K,V>::insert(const MyPair<K, V> &init_pair)
{
    //Call insert helper function
    insert_helper(root,init_pair);
    return;
}

template<typename K, typename V>
void MyMap<K,V>::erase(const K &key)
{
    //Call erase helper function
    erase_helper(root, key);
    return;
}

template<typename K, typename V>
MyPair<K,V> * MyMap<K,V>::find(const K &key) const
{
    //Call find helper function.
    return find_helper(root,key);
}

template<typename K, typename V>
void MyMap<K,V>::print() const
{
    //Check to see if the root has something in it
    if (root != nullptr)
    {
        //Call printer helper function
        print_helper(root,"");
        return;
    }
    
    
    //Otherwise just print empty/
    cout << "[empty]" << endl;
    
    return;
}

template<typename K, typename V>
int MyMap<K,V>::count(const K &key) const
{
    //Call the count helper function.
    return count_helper(root,key);
}

//Other Function to do
void get_letter_frequency(MyMap<char, int> &in_tree)
{
    //Get the textFile
    std::string txtFile;

    //Loop through the txtFile until eof.
    //Collects one line from txtFile
    while (std::getline(std::cin,txtFile))
    {
        //Get the length of that line
        int txtLen = txtFile.length();
        
        //Loop through that line
        for (int i = 0; i < txtLen; i++)
        {
            //Make sure you don't count newLine characters
            if (txtFile[i] != '\n')
            {
                //If there isn't an element in there, create a myPair, and insert
                if (in_tree.count(txtFile[i]) == 0)
                {
                    MyPair<char,int> letter(txtFile[i],1);
                    in_tree.insert(letter);
                }
                //Otherwise just increment the value by 1;
                else
                {
                    in_tree.at(txtFile[i]) = in_tree.at(txtFile[i]) + 1;
                }
            }
         }
     }
    
    return;
}


