/**
Implement the main here to match input and output. 
**/

#include "matrix_search.h"

//Constants
const int BAD_ANS = -1;
const int COORDS = 4;


int main()
{
    //Variables
    int rows,cols,cases,sol[COORDS];
    string word, my_id;
    char **matrix = nullptr;   

    //Get identity
    get_identity(my_id);

    //Get input for number of cases
    std::cin >> cases;
    
    for (int i = 0; i < cases; i++)
    {
       //get matrix size (rows,cols)
       std::cin >> rows;
       std::cin >> cols;

       //Initiate the matrix using build_matrix function
       matrix = build_matrix(rows,cols);

       //Fill in the matrix with data
       fill_matrix(rows,cols,matrix);

       //Get word
       std::cin >> word;
       
       //Print filled matrix
       //print_matrix(rows,cols,matrix);
     

       //Find the indexes of the word
       matrix_search(sol,word,rows,cols,matrix);

       //If -1 is in the array, there is no solution, otherwise print
       //the starting and ending location
       if (sol[0] == BAD_ANS)
       {
         cout << "Searching for \"" << word << "\" in matrix "
  	     << i << " yields:\n" << "The pattern was not found.\n\n"; 
       }
       else 
       {
	 cout << "Searching for \"" << word << "\" in matrix "
              << i << " yields:\n" << "Start pos:(" << sol[0]
              <<", " << sol[1] << ") to End pos:(" << sol[2]
              <<", " << sol[3] << ")\n\n";
       }
       
       //delete the matrix and set the pointers to null or newptr
       delete_matrix(rows, matrix);
    }
    
    return 0;
}

