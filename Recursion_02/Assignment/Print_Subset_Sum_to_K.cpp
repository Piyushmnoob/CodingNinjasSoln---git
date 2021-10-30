Print Subset Sum to K:-
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:
3 3
5 1


#include <iostream>
using namespace std;
#include "solution.h"

#include<vector>

void helper(int input[], int size, vector<int> &ans, int k) {
    if(size == 0) {
        int sum = 0;
        for(int i = 0; i < ans.size(); i++) {
            sum += ans[i];
            // cout << ans[i] << " ";
           
        }
        
         if(sum == k) {
                for(int j = 0; j < ans.size(); j++) {
                    cout << ans[j] << " ";
                }
                cout<<endl;
            }
        
        return;
    }
    helper(input + 1, size - 1, ans, k);
   
    int ch = input[0];
    ans.push_back(ch);
    helper(input + 1, size - 1, ans, k);
    ans.pop_back();
    
}


void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> v;
    
    helper(input, size, v, k);
    
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}

