/* The duty of main here is to interact with the user, take in input, and manage
    wrapping output and runtime.
 * Declar any NON-REQUIRED functions above main if needed (it is not likely that
    you'll need to)
 */

#include "maze.h"


int main()
{
    //Variables
    string my_id;
    string *matrix; //pointer
    int rows;
    int row,col,map = 0;

    //Get username
    get_identity(my_id);
  
    //The do while loop breaks once you input 0 in the rows.
    do
    {
       //Get number of rows
       std::cin >> rows;
       
       //If it hits the break statement, break the loop.
       if (rows == 0)
          break;
   
       //build the matrix 
       matrix = build_matrix(rows);
     
       //fill the matrix
       fill_matrix(matrix,rows);

       //find the Start location
       find_start(matrix,rows,row,col);

       //Call the recurisve function to find path
       if (find_exit(matrix,row,col))
       {
          //If it found a solution, print it out and say solution found
          cout << "Map " << map <<" -- Solution found:\n";
          print_matrix(matrix,rows);
       }
       else
       {
         //If it didn't find a solution, print it out and say solution not found
         cout << "Map " << map <<" -- No solution found:\n";
         print_matrix(matrix,rows);
       }
  
       //increment the map number
       map++;

       //Delete the matrix to make new ones
       delete_matrix(matrix);

    }while (rows !=0);
    return 0;
}
