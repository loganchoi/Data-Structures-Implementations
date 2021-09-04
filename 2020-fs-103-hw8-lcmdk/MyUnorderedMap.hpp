// Implement all of your MyUnorderedMap functions and other related functions
//  here 
//I did not do well

void get_identity(std::string &my_id)
{
    my_id = "lcmdk";
    return;
}

template <typename K, typename V>
int MyUnorderedMap<K,V>::hash(const K &key) const
{
    //Variable
    int total = 0;
    
    //Add the ascii value of the char.
    for (int i =0; i < key.length();i++)
        total = total + static_cast<int>(key[i]);

    //std::cout << total << "Total ascii" << endl;
    //std::cout << reserved_size << "Reserved Size is" << endl;
    
    //return modulo result WHY DO I KEEP GETTING THIS ERROR
    if (reserved_size == 0)
        throw std::out_of_range("Dividing by zero");
    
    return (total % reserved_size);
}

template <typename K, typename V>
MyUnorderedMap<K,V>::MyUnorderedMap()
{
    //Set variables to null and zeroes
    m_data = nullptr;
    reserved_size = 0;
    data_size = 0;
}

template <typename K, typename V>
MyUnorderedMap<K,V>::~MyUnorderedMap()
{
    //Call clear() function and set to nullptr;
    clear();
    m_data = nullptr;
    return;
}

template <typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap(const MyUnorderedMap<K,V> &source)
{
    //clear the data first.
    clear();
    
    //Reset the variables
    m_data  = nullptr;
    data_size = source.data_size;
    reserved_size  =  source.reserved_size;
    
    m_data = new MyPair<K,V> [reserved_size];
    
    //Copy the variables.
    for (int i = 0; i < data_size; i++)
        m_data[i] = source.m_data[i];
    
}

template <typename K,typename V>
MyUnorderedMap<K, V> & MyUnorderedMap<K,V>::operator=(const MyUnorderedMap<K,V> &source)
{
    //Clear data first
    clear();
    
    //reset variables
    m_data  = nullptr;
    data_size = source.data_size;
    reserved_size  =  source.reserved_size;
    
    m_data = new MyPair<K,V> [reserved_size];
    
    //Copy from source
    for (int i = 0; i < data_size; i++)
        m_data[i] = source.m_data[i];

    //Return it.
    return *this;
}

template <typename K,typename V>
V & MyUnorderedMap<K,V>::at(const K &key)
{
    //If you get a nullptr, it is out of range
    //Otherwise return the value.
    if (find(key) != nullptr)
        return find(key)->second;
    
    throw std::out_of_range("Not in map");
}

template <typename K, typename V>
V & MyUnorderedMap<K,V>::operator[](const K &key)
{
    //Just reused my MyMap code
    //Check to see if the key exists
    
    std::cout << "Hit count function" << endl;
    if (count(key)==1)
    {
        //If so use at function
        return at(key);
    }
    std:: cout << "Hit count (key)" << endl;
    
    //Otherwise create new pointer of type MyPair
    MyPair<K,V> *letter = new MyPair<K,V> (key,1);
    
    std::cout << "HIt operator insert" << endl;
    
    //Insert the data pointer
    insert(*letter);
    
    std::cout << "Hit operator insert after" << endl;
    
    //delete the letter because it is now inserted
    delete letter;
    
    //The return the at_helper function
    return at(key);

}

template <typename K,typename V>
bool MyUnorderedMap<K,V>::empty() const
{
    //Check to see if it is empty
    if (data_size == 0)
        return true;
    return false;
}

template <typename K, typename V>
int MyUnorderedMap<K,V>::size() const
{
    //return data_size;
    return data_size;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::clear()
{
    //Delete data and set everything to zeroes.
    delete []m_data;
    m_data = nullptr;
    reserved_size = 0;
    data_size = 0;
    return;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::insert(const MyPair<K,V> &init_pair)
{
    //These are flags
    K EMPTY = "EMPTY";
    K TOMB = "TOMB";
    
    //Increment size
    data_size++;
    
    std::cout<< "HIt insert funct";
    //Check if you need to rehash
    if (data_size == 1)
        reserve(2);
    else if (data_size >= reserved_size * 6/10)
        reserve(reserved_size*2);
    
    //Get the probing sequence initialized
    
    int home;
    int pos = home = hash(init_pair.first);
    std::cout << "Hit hash" << endl;
    
    //keep incrementing position until you hit one of the flags.
    for (int i = 1; EMPTY != m_data[pos].first && TOMB != m_data[pos].first; i++)
    {
        //This checks if  a duplicate is found.
        if (init_pair.first == m_data[pos].first)
            throw std::out_of_range("Duplicate found");
        pos = (home+i) % reserved_size;
    }
    
    //Set the position to
    m_data[pos] = init_pair;
    std::cout << "Hit returned insert " << endl;
    return;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::erase(const K &key)
{
    //Set the flags
    K EMPTY = "EMPTY";
    K TOMB = "TOMB";
    
    //Initialize probe sequence.
    int home;
    int pos = home = hash(key);
    int i = 1;
    
    //Increment until you find the position.
    while (key!= m_data[pos].first && m_data[pos].first != EMPTY )
    {
        pos = (home + i) % reserved_size;
        i++;
    };
    
    //make the  new position a flag
    if (m_data[pos].first != EMPTY)
    {
        m_data[pos].first = TOMB;
        
        //decrement and check if you need to rehash
        data_size--;
        if (data_size <= reserved_size * 1/10)
            reserve(reserved_size *3/10);
    }
    
    return;
}

template <typename K, typename V>
MyPair<K,V> * MyUnorderedMap<K,V>::find(const K &key) const
{
    //Set a flag
    K EMPTY = "EMPTY";
    
    if (reserved_size ==0)
        return nullptr;
    
    //Initialize probe
    int home;
    int pos = home = hash(key);
    
    //increment pos until you find the key or EMPTY is found
    for (int i = 1; key != m_data[pos].first && EMPTY != m_data[pos].first;i++)
        pos = (home + i) % reserved_size;
    
    //If it is found return it
    if (key == m_data[pos].first)
        return &m_data[pos];
    
    //otherwise return null
    return nullptr;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::print() const
{
    //Print
    std::cout << "(";
    for ( int i = 0; i < data_size; i ++)
    {
        std::cout << "[" << m_data[i].first << "]=" << m_data[i].second;
        if (i != data_size -1)
            std:: cout << "," << endl;
    }
    std::cout << ")";
    return;
}

template <typename K, typename V>
int MyUnorderedMap<K,V>::count(const K &key) const
{
    //This will return a 1 or 0 because it is a true false statement.
    return find(key) != nullptr;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::reserve(int new_cap)
{
    std::cout << "Hit reserve func with " << new_cap << endl;
    
    if (reserved_size == 0)
    {
        std::cout << "HIt first one" << endl;
        clear();
        reserved_size = new_cap;
        m_data = new MyPair<K,V> [reserved_size];
        std::cout << "Hitting return" << endl;
        return;
    }
    std::cout << "Hit reserve func" << endl;
    //This will make a copy array.
    MyPair<K,V> * copy = new MyPair<K,V> [data_size];
    int copy_data = data_size;
    //Deep copy it.
    for (int i = 0; i < data_size; i++)
    {
        copy[i] = m_data[i];
    }
    
    //Delete the information
    clear();
    
    //Reset
    reserved_size = new_cap;
    data_size = copy_data;
    m_data = new MyPair<K,V> [reserved_size];
    
    //Insert it all back in and will rehash itself due to the different reserved size
    for (int i = 0; i < data_size;i ++)
        insert(copy[i]);
    
    return;
}

void get_virus_frequency(MyUnorderedMap<std::string,int> &in_tree)
{
    //Variables
    std::string txtFile;
    std::string word;
    std::string lowercase;
    std::string virus = "virus";
    int ascii;
    
    //Loop
    while(std::cin >> txtFile)
    {
        //Make  an  empty string
        word ="";
        
        //This will take away anything that is not a letter.
        for (int i = 0; i < txtFile.length();i++)
        {
            ascii = static_cast<int>(txtFile[i]);
            if ((ascii >= 65 && ascii <=90)||(ascii>=97 && ascii<=122))
            {
                word = word + static_cast<char>(ascii);
            }
        }
        
        lowercase = "";
        //This will make a lowercase version
        for (int i =0; i <word.length();i++)
        {
            ascii = static_cast<int>(word[i]);
            if (ascii >= 65 && ascii <=90)
                lowercase = lowercase + static_cast<char>(ascii+32);
            else
                lowercase = lowercase + static_cast<char>(ascii);
        }
        
        //Check if it has a substring that is "virus"
        if (lowercase.find(virus) != std::string::npos)
        {
            //If the word is not in the map, insert it
            //otherwise  just increment it by one
            if (in_tree.count(word) == 0)
            {
                MyPair<std::string,int> str(word,1);
                in_tree.insert(str);
            }
            else
                in_tree.at(word)++;
        }
        
    };
    
    return;
}
