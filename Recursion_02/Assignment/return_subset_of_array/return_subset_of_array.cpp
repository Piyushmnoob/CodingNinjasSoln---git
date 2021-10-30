Return subset of an array:-
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 


//******************************************************** HINTS *********************************************************************//

1) Missing base case
  Wrong Answer
You may be getting wrong answers because the base case is not written properly.

Figure 1 :- missing_base_case_hint

The complete base case is written in following pseudocode:
if(size of array is 0)
    output[0][0]=0
    /*
    you have to return the number of rows populated. In case of base case, it is one.
    */
    return 1;

2) How to form the answer from the result of a recursive call
   
Implementation Issues

Figure 1 :- Implementation Issues_01_hint


Figure 2 :- Implementation Issues_02_hint

Since, the recursive result returns the number of rows populated in the output 2D array, which is 4 in this case. Since, the first 4 rows are the same in both the output 2D arrays, therefore, we will use the same output 2D arrays. The following pseudocode will populate the next 4 rows.

/*
 let the number of rows returned by recursive result be ans. The value of ans will be 4, in our case.
*/

for( i=0; i<ans; i++)
    number_of_columns = output[i][0]
    output[i+ans][0] = 1 + number_of_columns
    output[i+ans][1] = input[0]
    for( j=1; j<number_of_columns; j++)
        output[i+ans][j+1] = output[i+ans][j]


3) Small sized local arrays

Runtime Error

You may be getting runtime error because you may have used local 2D arrays and the size of those 2D arrays is too small to store all the results. This can be solved by creating large sized local 2D arrays, similar to the  2D arrays created in main function. Following are the lines of code used to create 2D array in main function:

int output[35000][20]; 

//*******************************************************************************************************************************************************************//

#include <iostream>
#include "solution.h"
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[35000][20]) {
    // Write your code here
   
    
    if(n == 0) {
         output[0] [0] = 0;
    return 1;
}
  int smallSize = subset(input + 1, n - 1, output); // reursive call --->> faith
    
    int subsetLength;
    
    for(int i = 0; i < smallSize; i++) {
         subsetLength = output[i] [0];
        output[i + smallSize] [0] = 1 + subsetLength;
        
        for(int j = subsetLength; j >= 1; j--)  // j++ -->> correction = j--
        {
            output[i + smallSize] [j + 1] = output[i] [j];   //  correction
            
        // Incorrect -  output[i + smallSize] [j] = output[i  + smallSize] [j + 1]
        }
        
        output[i + smallSize] [1] = input[0]; // input[i]  ---->>> correction = input[0];
    }
   
    
    return 2 * smallSize;
}


int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


