Loot Houses

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

Output format :
Print the the maximum money that can be looted.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90

Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.



#include <vector>

int tab(int idx, vector<int> &houses, int n, vector<int> dp) {
    //base case
    dp[n]=0;
    
    for(int i=n-1; i>=0; i--) {
        if(i+2>n)  // when we are at nth pos let's say, then neither i+1 th
            //  or i+2 th going to work coz it will be out of bound.
            //from recursive soln we have seen when idx>=n then return 0;
        {
            int ans1 = houses[i];
            int ans2;
         if(i+1>n) {
            ans2=0;
        } else {
              ans2 = dp[i+1];
            }
            dp[i] = max(ans1, ans2); 
        }  
        
        else {
        int ans1 = houses[i] + dp[i+2];
        int ans2 = dp[i+1];
         dp[i] = max(ans1, ans2);   
       }
    }
    
    return dp[0];
}


int mem(int idx, vector<int> &houses, int n, vector<int> dp) {
     if(idx>=n) {
        return 0;
    }
     //check condn
     if(dp[idx]!=-1) return dp[idx];
     
      int ans1 = houses[idx] + mem(idx+2, houses, n,dp);
    //not pick
    int ans2=mem(idx+1, houses, n,dp);
    
    return dp[idx]= max(ans1, ans2);
 }

// brute force recursive solution.
int helper(int idx, vector<int> &houses, int n) {
    if(idx>=n) {
        return 0;
    }
    
    //pick 
    int ans1 = houses[idx] + helper(idx+2, houses, n);
    //not pick
    int ans2=helper(idx+1, houses, n);
    
    return max(ans1, ans2);
}


int maxMoneyLootedH(vector<int> &houses, int n)
{
    
    vector<int> dp(n+1, -1);
	return tab(0, houses, n,dp);
}



int maxMoneyLooted(int *arr, int n)
{
	vector<int> houses;
    for(int i=0; i<n;i++) {
        houses.push_back(arr[i]);
    }
    
    return maxMoneyLootedH(houses, n);
}
