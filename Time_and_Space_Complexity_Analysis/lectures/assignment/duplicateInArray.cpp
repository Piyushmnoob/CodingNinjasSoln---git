Duplicate in array

You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.

Note :
Duplicate number is always present in the given array/list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the duplicate element in the array/list.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec

Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6

Sample Output 1:
7

Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2

Sample Output 2:
1
3

//*************************************************************************************//

int findDuplicate(int *arr, int n)
{
    //Write your code here
    
    // logic
/*
-->> sum of the first n natural no (S1) = n * (n + 1) / 2

-->> we have been given an integer array(ARR) of size N which contains numbers from 0 to (N - 2)
-->> number = n - 2 
-->> S1 = (n-2) * (n - 2 + 1) / 2 = (n - 2) * (n - 1) / 2

-->> if we find the sum of the array element then we got S1 + duplicate number.
-> ex:- n = 6 , S1 = 0 + 1 + 2 + 3 + 4 = 10
and array elements are from 0 to n - 2 (i.e; 0 to 4) with a single integer that is present twice.
so sum = S1 + duplicate.

O(N) time complexity.

*/
  
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
  int S1 = (n - 2) * (n - 1) / 2;
    
    int duplicate = sum - S1;
    
    return duplicate;
    
}


