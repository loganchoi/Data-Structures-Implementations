/* Here in the .cpp you should define and implement everything declared
    in the .h file
 */

#include "maze.h"


void get_identity(string &my_id)
{
  //Get username
  my_id = "lcmdk";
  return;

}


string * build_matrix(int rows)
{
  //Build the matrix as a string array with number of rows
  string *matrix = new string[rows];
  return matrix;
  
}


void fill_matrix(string *matrix, int rows)
{
  //Variables
  string line;

  //This will essentially ignore the rest of the first line
  cin.ignore();

  //In a for loop, fill the matrix with data
  for(int i = 0; i < rows; i++)
  {
    getline(cin,line);
    matrix[i] = line;
  }

  return;
}


void print_matrix(string *matrix, int rows)
{
  //Print out the matrix
  for (int i = 0; i< rows; i++)
  {
    cout << matrix[i] << "\n";
  }
  cout << "\n";
  
  return;
 
}


void delete_matrix(string *&matrix)
{
  //Delete the pointer array
  delete[] matrix;
  matrix = nullptr;
  return; 
}


void find_start(string *matrix, int rows, int &row, int &col)
{
  //Constats:
  const char START = 'N';

 
  //in a nested for loop, find the starting location
  for (int i = 0; i < rows; i++)
    {
       for (int j = 0; j<matrix[i].length();j++)
       {
           if (matrix[i][j] == START)
           {
               row = i;
               col = j;
               return;
           }
       }
    }
  return;
}


bool find_exit(string *matrix, int row, int col)
{
  //Constants:
  const char MOVE = '@';
  const char EMPTY = ' ';

  //Local Varibles
  int tempRow,tempCol;
    
  //Hold the current spot
  tempRow = row;
  tempCol = col;

  //NEWS: North, East, West, South
  const string NEWS[] = {"NORTH","SOUTH","WEST","EAST"};
    
  //Check if you are at the end:
  if (at_end(matrix,row,col))
     return true;

  //Recursive Calls
  for (int d = 0; d< 4; d++)
  {
     row = tempRow;
     col = tempCol;
     if (valid_move(matrix,row,col,NEWS[d]))
     {   
        //Depending on the direction, make the move
	if (NEWS[d] == "NORTH")
	{
            matrix[row-1][col] = MOVE;
            row = row-1;
        }
        else if (NEWS[d] == "SOUTH")
        {
            matrix[row+1][col] = MOVE;
            row = row + 1;
        }
        else if (NEWS[d] == "WEST")
        {
            matrix[row][col-1] = MOVE;
            col = col-1;
        }
        else if (NEWS[d] == "EAST")
        {
            matrix[row][col+1]= MOVE;
            col = col+1;
        }

        //Recursive Call
        if (find_exit(matrix,row,col))
            return true;
           
        matrix[row][col] = EMPTY;
    }
        
    }
    return false;
}


bool at_end(string *matrix, int row, int col)
{
    //Constants:
    const char END = 'E';

    //Check Down For End
    if (matrix[row+1][col] == END)
        return true;
 
    //Check up For End
    else if (matrix[row-1][col] == END)
        return true;
    
    //Check Right for End
    else if (matrix[row][col+1] == END)
        return true;

    //Check Left for End
    else if (matrix[row][col-1]== END)
        return true;    

    //Otherwise you aren't at the end, so return false.
    return false;

}


bool valid_move(string *matrix, int row, int col, string direction)
{
    //Constants:
    const char EMPTY = ' ';


    //Depending on the direction, check to see if it is an empty space.
    if (direction == "NORTH")
    {
        if (matrix[row-1][col] == EMPTY)
            return true;
        else
            return false;
    }
    else if (direction == "SOUTH")
    {
        if (matrix[row+1][col] == EMPTY)
            return true;
        else
            return false;
    }
    else if (direction == "WEST")
    {
        if (matrix[row][col-1] == EMPTY)
            return true;
        else
            return false;
    }
    else if (direction == "EAST")
    {
        if (matrix[row][col+1] == EMPTY)
            return true;
        else
            return false;
    }
    return false;
 
}
