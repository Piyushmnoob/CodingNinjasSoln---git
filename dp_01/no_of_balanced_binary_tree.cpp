Code : No. of balanced BTs

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.

Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :
1 <= h <= 24
Time Limit: 1 sec

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315

#include <cmath>

#define mod ((int) (pow(10, 9)) + 7)

int balancedBTs(int h) {
    
    if(h<=1){
        return 1;
    }
    
    int x=balancedBTs(h-1);
    int y=balancedBTs(h-2);
    
    int temp1= (int) (((long) (x)*x) % mod);
    int temp2=(int) (((2*(long)(x)*y)) %mod);
    
    int ans=  (temp1+temp2) % mod;
    
    return ans;
}



//*****************dp*****************//
#include<cmath>
#include<vector>

#define mod ( (int) (pow(10,9)) + 7 )


int balancedBTs(int n, vector<int>& dp) {
    // base case
    if(n<=1)  // means when h==1 then only one possible ways to get a balanced BT.
    {
     return 1;   
    }
    
    // step 2 -> checking if dp[n-1] equals to -1 or not if it is not equal to -1 then we will return the value
    // actually, this is step where we are avoiding the overlapping of sub problem.
    if(dp[n-1] !=-1) {
        return dp[n-1];
    }
    
    // calls
    int x=balancedBTs(n-1, dp);
    int y=balancedBTs(n-2, dp);
    
    //                  |*****************|
                    //  |                 |   
    int temp1 = (int) ( ((long)(x)*x) % mod );
    int temp2 = (int) ( (2*(long)(x)*y) % mod );
    
    int ans= (temp1+temp2) % mod;
    
    return dp[n-1]=ans; // this is step 3 where we are storing the value of the sub problems
}

int balancedBTs(int n) {
  
    // declaring the dp array -> step 1.
    vector<int> dp(n,-1);
    
    return balancedBTs(n, dp);
    
    
}



