Matrix Chain Multiplication

Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.

Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].

Output Format:
The first and only line of output prints the minimum number of multiplication needed.

Constraints :
1 <= n <= 100
Time limit: 1 second

Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000

Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 



#include<climits>
#include<vector>
/*  Aditya Verma:- DP

To solve the MCM there is 4 rules:-
-->> given:- string or arr & we feel to get the ans it must break at some Kth pos.
-->> identify i & j
--> identify the right base condn. (in this case, think of invalid input.)
->> we ahve to traverse k from i-> j
// we have to find from where we will take the Kth pos. & move until which pos. 

*/

int solve(int* &arr, int i, int j,  vector<vector<int>> &dp) {
    if(i>=j) return 0;  //base case
    
    if(dp[i][j]!=-1) return dp[i][j];
    
                                       //  number of multiplications needed to multiply the chain.        
    int ans= INT_MAX;                                 //             |
    for(int k=i; k<j; k++) {                          //             |
     int smallAns = solve(arr, i, k,dp) + solve(arr,k+1,j,dp) + (arr[i-1]*arr[k]*arr[j]);
        
        ans=min(ans, smallAns);  //  minimum number of multiplications needed to multiply the chain.
    }
    
    return dp[i][j]=ans;
}

