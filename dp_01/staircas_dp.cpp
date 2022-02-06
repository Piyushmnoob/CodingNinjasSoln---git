Code : Staircase using Dp

A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.


Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.

Output format :
Print the total possible number of ways.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7

Sample Input 2:
10
Sample Output 2:
274


#include<vector>
long long int staircaseH(int n, vector<long long int>&dp){
    if(n<0) {
        return 0;
    }    
    // base case
    if(n==0) {
        return 1;
    }
    
    if(dp[n]!=-1) {
        return dp[n];
    }
    
   long long int x=staircaseH(n-1, dp);
  long long int y=staircaseH(n-2, dp);
    long long int z=staircaseH(n-3, dp);
    
    return dp[n]=x+y+z;
}


long staircase(int n)
{
    
//     if(n<0) {
//         return 0;
//     }
// 	//base case                             //****** Brute Force Recursive Solution*************//
//     if(n==0){
//         return 1;
//     } 
    
//     int x=staircase(n-1);
//     int y=staircase(n-2);
//     int z=staircase(n-3);
    
//     return x+y+z;
    
    vector<long long int>dp(n+1, -1);

    long long int ans= staircaseH(n, dp);
    
    return ans;
}
