Longest Increasing Subsequence

Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.

Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.

Output Format
The first and only line of output contains the length of longest subsequence.

Constraints
1 <= N <= 10^3
Time Limit: 1 second
Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3

Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2 :
3
1 2 2
Sample Output 2 :
2



#include<vector>
#include<climits>

vector<int> LIS_tab(vector<int> &dp,int *&arr, int n) {
    dp[0] = 1; //base case
    
    for(int i=0;i<n;i++) {
        if(i==0) continue; 
    
        int Max=INT_MIN;
        for(int j=i-1;j>=0;j--) {
             int count=1;   // count =1 coz we are picking the ith idx element hence, subseq increased by 1.
            if(arr[j]<arr[i]) {
                count+=dp[j];
                Max= max(Max, count);
            } else {
                Max= max(Max, count);     //ex:-  2 1 if we r at 1 then LIS -> length=1 which is 1 itself.
            }
        }
        
        dp[i]=Max;
    }
    
    return dp;
}


int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    
    vector<int> dp(n, -1);
    
    vector<int> ans= LIS_tab(dp, arr,n);

    int output=INT_MIN;
    for(auto it: ans) {
        output=max(output, it);
    }
    return output;
}

// T(N) = O(N*N)
// S(N) = O(N)  



