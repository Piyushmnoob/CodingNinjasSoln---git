Ways To Make Coin Change

For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.

Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.

Output Format
Print the total total number of ways i.e. W.

Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4

Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903


#include<vector>

long tabulation(int idx, int *denominations, int n, int value, vector<vector<long>> &dp)
{
    //base case
    dp[n][0]=1; // idx==n & value=0

    //filling the last row
    for(int j=1;j<=value; j++) {
        dp[n][j]=0;
    }

    //filling the first col
    for(int i=0;i<n;i++) {
        dp[i][0]=1;
    }

    //filling the remaining cells
    //if we look into the table then we can see we will fill the
    //cells from last row but fill each col from  0 till value.
    for(int i=n-1; i>=0;i--) {
        for(int j=1;j<=value; j++) {
            //pick
            long ans1=0;
            if(j>=denominations[i]) {
                ans1 = dp[i][j-denominations[i]];
            }
            //not pick
            long ans2=dp[i+1][j];

            dp[i][j]=ans1+ans2;

        }
    }


    return dp[idx][value];
}

//memoization & brute force recursive soln
long countWaysToMakeChange(int idx, int *denominations, int n, int value, vector<vector<long>> &dp)
{
    int p=idx;
    int q=value;
    //base case
    if(idx==n) {
        if(value==0) {
            return 1;
        } else {
            return 0;
        }
    }

    //check condn.
    if(dp[p][q]!=-1) return dp[p][q];

    //pick
    long ans1=0;
    if(value>=denominations[idx]) {
     ans1 = countWaysToMakeChange(idx, denominations, n, value-denominations[idx], dp);
}
    //not pick
    long ans2=countWaysToMakeChange(idx+1, denominations, n, value, dp);

    return dp[p][q]=ans1+ans2;

    //****************************recursive code************************//
    //     //base case
//     if(idx==n) {
//         if(value==0) {
//             return 1;
//         } else {
//             return 0;
//         }
//     }
//     //pick
//     long ans1=0;
//     if(value>=denominations[idx]) {
//      ans1=countWaysToMakeChange(idx, denominations, n, value-denominations[idx]);
// }
//     //not pick
//     long ans2=countWaysToMakeChange(idx+1,denominations, n, value);

//     return ans1+ans2;
}


long countWaysToMakeChangeH(int *&denominations, int n, int value)
{
    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));

  return tabulation(0,denominations, n, value, dp);
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here

    return countWaysToMakeChangeH(denominations, numDenominations, value);
}
