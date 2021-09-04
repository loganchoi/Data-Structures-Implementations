/**
Here in the .cpp you should define and implement the functions that are declared in the .h file.
It is not recommended to add extra functions on this assignment.
**/

#include "matrix_search.h"


// We're giving you this one the first time, and you should copy it into all future assignments.
// Change the information to your own email handle (S&T username)
void get_identity(string &my_id)
{
    my_id = "lcmdk";
    return;
}


char ** build_matrix(int rows, int cols)
{
    //Initialize the double pointer to a pointer of an array
    char **matrix = new char *[rows];

    //Create the dynamically allocated array
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = new char[cols];
    }
    return matrix;
}


void fill_matrix(int rows, int cols, char **matrix)
{
    //In a nested for loop fill in the matrix with data
    for (int i = 0; i< rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        std::cin >> matrix[i][j];
      }
    }
    return;
}


void print_matrix(int rows, int cols, char **matrix)
{
   //In a nested for loop print out the matrix data
   for (int i = 0; i < rows; i++)
   {
     for (int j = 0; j < cols; j++)
     {
       cout << matrix[i][j] << " ";
     }
     cout << "\n";
   }

   return;
}


void delete_matrix(int rows, char **matrix)
{
    //Delete each sub array
    for (int i = 0; i < rows; i++)
    {
      delete[] matrix[i];
    }
    
    //Delete entire array, and set it to null
    delete[] matrix;
    matrix = nullptr;

    return;
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
   //Variables
   int totalLetters, wordLen = word.length();
   bool isWord;

   //Find the first letter of the word first
   for (int i = 0 ; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
	if (matrix[i][j] == word[0])
	{
           //Reset Values
	   totalLetters = 0;
           isWord = true;

           //Search Down
           for (int k = 0; k< wordLen; k++)
           {
             //If the index equals the number of rows,
	     //It is out of index, so break and set isWord to false
             if (k + i == rows)
             {
               isWord = false;
               break;
             }

             //If the next matrix letter does not equal to
             //the next word letter, it isn't word so break.
             if (matrix[i+k][j] != word[k])
             {
               isWord = false;
               break;
             }

             //Increment total letters
             totalLetters++;
	   }

           //If it isWord and the total increments equal to word length
           //Solution is found
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i + (wordLen - 1);
             sol[3] = j;
             return;
           }

           //Reset Values
           totalLetters = 0;
           isWord = true;

           //Search Right
           for (int k = 0; k < wordLen; k++)
           {
             //If the index equals to the number of columns,
             //It is out of index, so break
             if (k + j == cols)
             {
               isWord = false;
               break;
             }

             //If the indexes do not match, break
             if (matrix[i][j+k] != word[k])
             {
                isWord = false;
                break;
             }

             //Increment total letters
             totalLetters++;
           }

           //If it isWord and the total increments equal to word length
           //Solution is found
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i;
             sol[3] = j + (wordLen -1);
             return;
           }

           //Reset Values
           totalLetters = 0;
           isWord = true;

           //Search Up
           for (int k = 0; k< wordLen; k++)
           {
             //If the index becomes negative, it is out of index
             //so break
             if (i-k < 0)
             {
               isWord = false;
               break;
             }

             //If the indexes do not match, break
             if (matrix[i-k][j] != word[k])
             {
               isWord = false;
               break;
             }

             //Increment total letters
             totalLetters++;
           }

           //If it isWord and the total increments equal to word length
           //Solution is found
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i - (wordLen-1);
             sol[3] = j;
             return;
           }

           //Reset Values
           totalLetters = 0;
           isWord = true;

           //Search Left
           for (int k = 0; k<wordLen; k++)
           {
             //If the index becomes negative, it is out of index,
             //So break
	     if (j-k < 0)
             {
               isWord = false;
               break;
             }

             //If the indexes do not match, break
             if (matrix[i][j-k] != word[k])
             {
               isWord = false;
               break;
             }

             //Increment total letters
             totalLetters++;
           }

           //If totalLetters equal to word length and isWord,
           //Solution is found and return
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i;
             sol[3] = j - (wordLen-1);
             return;
           }

   	   //Reset Values
           totalLetters = 0;
           isWord = true;

           //Search Down & Right
           for (int k = 0; k < wordLen; k++)
           {
             //If the rows or columns are out of index,
             //break
             if (j+k == cols  || i+k == rows)
             {
               isWord = false;
               break;
             }

             //If the indexes don't match, break
             if (matrix[i+k][j+k] != word[k])
             {
               isWord = false;
               break;
             }

             //Increment total letters
             totalLetters++;
           }

           //If isWord and total letters equal to word length,
           //solution is found
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i + (wordLen-1);
             sol[3] = j + (wordLen-1);
             return;
           }
           
           //reset Values
           totalLetters = 0;
           isWord = true;
          
           //Search Down & Left
           for (int k = 0; k < wordLen; k++)
           {
             //If the rows or columns are out of index,
             //break
             if (i+k == rows || j-k < 0)
             {
               isWord = false;
               break;
             }
  
             //If indexes don't match, break
             if (matrix[i+k][j-k] != word[k])
             {
               isWord = false;
               break;
             }
     
             //Increment total letters
             totalLetters++;
           }

           //If total Letters equal to word length and isWord,
           //Solution is found
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i + (wordLen-1);
             sol[3] = j - (wordLen-1);
             return;
           }

           //Reset Values
           totalLetters = 0;
           isWord = true;

           //Search Up & Left
           for (int k = 0; k < wordLen; k++)
           { 
             //if rows or columns are out of index, break
             if (i-k < 0 || j-k < 0)
             {
               isWord = false;
               break;
             }
  
             //If indexes don't match, break
             if (matrix[i-k][j-k] != word[k])
             {
               isWord = false;
               break;
             }

             //INcrement total letters
             totalLetters++;
           }

           //If total letters equal to word length and isWord,
           //Solution is found
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i - (wordLen-1);
             sol[3] = j - (wordLen-1);
             return;
           }
     
           //Reset Values
           totalLetters = 0;
           isWord = true;

           //Search Up  & Right
           for (int k = 0; k < wordLen; k++)
           {
             //If row or col are out of index, break
             if (i-k < 0 || j+k == cols)
             {
               isWord = false;
               break;
             }
 
             //If indexes don't match, break
             if (matrix[i-k][j+k] != word[k])
             {
               isWord = false;
               break;
             }
 
             //increment total letters
             totalLetters++;
           }

           //If total Letters equal to word length and isWord,
           //Solution is found
           if (totalLetters == wordLen && isWord)
           {
             sol[0] = i;
             sol[1] = j;
             sol[2] = i - (wordLen-1);
             sol[3] = j + (wordLen-1);
             return;
           }
	}	
      }
   }
   
   //If no solution was found, set all values to -1
   sol[0] = -1;
   sol[1] = -1;
   sol[2] = -1;
   sol[3] = -1;
   return;
}

