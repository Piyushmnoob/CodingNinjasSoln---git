Print Subsets of Array :-
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

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



#include <iostream>
using namespace std;
#include "solution.h"

#include<vector>

void helper(int input[], int size, vector<int> &ans) {
    if(size == 0) {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    helper(input + 1, size - 1, ans);
   
    int ch = input[0];
    ans.push_back(ch);
    helper(input + 1, size - 1, ans);
    ans.pop_back();
    
}

void printSubsetsOfArray(int input[], int size) {
	// By bit manipulation
    
//     int totalSubeset = pow(2, size);
//     int i = 0;
//     int j = 0;
    
//     for(i = 0; i < totalSubeset; i++) {
//         for(j = 0; j < size; j++) {
//             if(i & (1 << j)) {
//                 cout<<input[j] <<" ";
//             }
//         }
//         cout<<endl;
//     }
//**********************************************//    
    vector<int> v;
    
    helper(input, size, v);
    
    
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

