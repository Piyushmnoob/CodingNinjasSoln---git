Return subsets sum to K:-
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Constraints :
1 <= n <= 20

Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output :
3 3
5 1

//**************************************************** HITNTS **********************************************************************************************//

1) Unable to implement loops in the function

Implementation Issues

i) Let’s assume that you have made the recursive calls and the result of the first call, where you are selecting input[0], is stored in o1[][] and result of the second call is stored in o2[][]. Since, the order of subsets doesn’t matter, we can populate our output array with either o1 first and then o2 or vice versa.

 ii) Let us populate our output array with o1 first. For populating with o1, we have to make following changes:
For the zeroth column, output[i][0] = o1[i][0] + 1, as we are adding one more element to each row.
For the first column, output[i][1] = input[0]
For the remaining columns of output array, output[i][j] = o1[i][j-1]

iii) Let’s populate our output array with o2. For populating with o1, we have to make following changes:
o2 has to be copied exactly. For each row and column of output, output[i][j] = o2[i][j]

iv) After populating the output array, we have to return the number of rows populated in the output array. This will be equal to the sum of the rows in o1 and o2 2D arrays.


2) Small sized local 2D arrays
  
Wrong Answer

You may be getting wrong answers because of the small size of local 2D arrays: o1 and o2. It is suggested that o1 and o2 should have at least 1000 rows and 50 columns.


3) Initializing local 2D arrays

Time Limit Exceed

You may be getting time limit exceeded because you are initializing each element of the local 2D arrays to 0. This is consuming a lot of time and this in turn leads to time limit exceeded. Initialization of output arrays is not required here. In the main code, we’ll be accessing only those cells which are filled explicitly, so there is no need of filling other cells. You just need to fill the relevant cells only.

//*******************************************************************************************************************************************************************//

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Donât print the subsets, just save them in output.
// ***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
  	//base case
    if(n == 0) {
		if(k == 0) 
        {
         	output[0][0] = 0;
            return 1;
    	}
        else
        	return 0;
    }     
    int temp1[1000][50]; // to store all the subset of n.
    int temp2[1000][50];
    //recursive calls
    int smallAns1 = subsetSumToK(input+1, n-1, temp1, k); // 1st case while we consider input[0] to not be a part of that sum
    int smallAns2 = subsetSumToK(input+1, n-1, temp2, k - input[0]); // 2nd case considering out input[0] to be a part of the sum
    
    for(int i = 0; i < smallAns1; i++)
    {
        for(int j = 0; j <= temp1[i][0]; j++)
            output[i][j] = temp1[i][j];
    }

    //small calculation
    for(int i = smallAns1; i < smallAns1 + smallAns2; i++){
        output[i][0] = temp2[i - smallAns1][0] + 1;
        output[i][1] = input[0];
        for(int j = 1; j <= temp2[i - smallAns1][0]; j++)
        {
            output[i][j+1] = temp2[i - smallAns1][j];
        }
    }
    
    
  return smallAns1 + smallAns2;  
    
}

