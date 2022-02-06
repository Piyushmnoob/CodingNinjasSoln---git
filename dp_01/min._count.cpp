Code : Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Input format :
The first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3

Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9
Sample Output 2 :
1


int minCountH(int n, vector<int> &dp) {
    
    // base case
    if(n==0 || n==1) {
        return n;
    }
    
    // check
    if(dp[n]!=-1) {
        return dp[n];
    }
    
    int ans=INT_MAX;
    for(int i=1;i<=sqrt(n); i++) {
        ans=min(ans, minCountH(n-(i*i), dp));
    }
    
    return dp[n]=1+ans;  // stoing the value of sub problems
}


int minCount(int n) {
//     *****************************Brute Force Recursive Solution*********************//
//     if(n==0) {
//         return 0;
//     }
//     if(n<=1)  // if n==1 then 1 = (1*1) i.e; only 1 count
//     {
//         return 1;
//     }
    
    
//     int ans=INT_MAX;
//     for(int i=1;i<=sqrt(n);i++) {
       
//         ans=min(ans, minCount(n-(i*i))); // call
       
//     }
//     return 1+ans;
    
    vector<int> dp(n+1, -1); 
    
    return minCountH(n, dp);
}

