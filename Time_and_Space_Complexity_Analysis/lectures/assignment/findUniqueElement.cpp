Find the Unique Element

You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
 Note:
Unique element is always present in the array/list according to the given condition.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the unique element present in the array.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec

Sample Input 1:
1
7
2 3 1 6 3 6 2

Sample Output 1:
1

Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7

Sample Output 2:
4
10

//*********************************************************************************//

int findUnique(int *arr, int n) {
    // Write your code here
    
    int xorsum = 0;
    for(int i = 0; i < n; i++) {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}


// initially, xorsum = 0

/*
arr = 1 2 3 4 1 2 3

i = 0, xorsum = 0 ^ 1
i = 1 , xorsum = 0 ^ 1 ^ 2
i = 2, xorsum = 0 ^ 1 ^ 2 ^ 3
i = 3 , xorsum = 0 ^ 1 ^ 2 ^ 3 ^ 4
i = 4 , xorsum = 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 1    // 1 gets cancelled
i = 5 , xorsum = 0 ^ 2 ^ 3 ^ 4 ^ 2        // 2 gets cancelled
i = 6 , xorsum = 0 ^ 3 ^ 4 ^ 3           // 4 gets cancelled
--->>>
& finally xorsum = 0 ^ 4 = 4  (xor -->> property --->> 0 ^ n = n) where, n is any number.

*/


