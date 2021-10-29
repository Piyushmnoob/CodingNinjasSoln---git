Return Keypad Code :-
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf


//********************************** HINT *************************************//

1) Explain the stub to me
   
   Implementation Issues

Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

2) How to convert integers into associated string
   
  Implementation Issues

We need to create a mapping of integers to their associated strings manually. We can do this by creating an array like this - 

string mapping[] = {“”, “”, “abc”, “def”, “ghi”, “jkl”, “mno”, “pqrs”, “yuv”, “wxyz”}

In this array, index is the integer and value is the associated string.

3) Base case are not written properly

Wrong Answer

It may be due to an incorrect base case. Let us discuss with the help of an example: Let us suppose that the given number be 123, for which we have to print all possible keypad combinations. If you have followed the approach mentioned in the lecture video, then the stack frame will look something like this:


If we return the output array with a string with a space, then an extra space would be added in each string, which would result in a wrong answer.

4) Small sized local array of strings

Runtime Error

Segmentation fault comes when we are trying to access a memory location, which we are not allowed to. In this question, it may occur due to the small size of local array of strings. If you are creating a local array of strings in the function, then create an array of the same size of the array created in main function, i.e. of size 10000. 

//*******************************************************************************************************************************************************//

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

#include <string>
using namespace std;

int keypad(int num, string output[10000]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    if(num == 0) {
        output[0] = "";
        return 1;
    }
    // Base case.
    
    string arr[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
    
    // 234
                        // 23
    int smallNo = keypad(num / 10, output); // Recursive Call --->> Faith. 
// smallNo will give how much string inserted into the output array.             
    
    int remaining = num % 10; // 4
    string possible = arr[remaining];  //  4 -->> ghi
    int length1 = possible.length(); // length of string at arr[remaining] .
    
    
    string temp[1000];
    for(int k = 0; k < smallNo; k++) {
          temp[k] =  output[k];
        }
    
        for(int i = 0; i < length1; i++) {
        for(int j = 0; j < smallNo; j++) {
          output[j + (smallNo * i)] =  temp[j] + possible[i] ;
        }
     }
    
    return smallNo * length1;
    
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
