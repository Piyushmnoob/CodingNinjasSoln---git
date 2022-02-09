Code : Knapsack

A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?

Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.

Output Format :
Print the maximum value of V that the thief can steal.

Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13

Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51



// intuition:- pick/not pick
int helper(int idx, int *weights, int *values, int n, int maxWeight) {
    
    // base case
    if(idx==n) {
        if(maxWeight==0) {
            return 0;
        } else {
            return 0;
        }
    }
    
    //edge case
    if(weights[idx]> maxWeight) {
        // then we will not pick that weights[idx].
        return helper(idx+1, weights, values, n, maxWeight);
    }
    
    // picking the 0th idx elemnt
    int ans1= helper(idx+1, weights,values, n, maxWeight-weights[idx]) + values[idx];
        
      // not pick  
    int ans2= helper(idx+1, weights,values, n, maxWeight);
    
    
    return max(ans1,ans2);
}



int knapsack(int *weights, int *values, int n, int maxWeight)
{
	
    return helper(0,weights, values, n, maxWeight);
}


//*************************** memoization ************************************//
#include<vector>
int mem(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>> dp) {
    int p=w;
    int q=n;
    
    // base case
    if(n==0 || w==0) // n=0 no items less than w or w==0 knapsack capacity=0
    {return 0;}
    
    //check condn
    if(dp[p][q]!=-1) {
        return dp[p][q];
    }
    
    if(weights[n-1]<=w) {
        //pick
        int ans1=mem(values,weights, n-1,w-weights[n-1],dp) + values[n-1];
//      not pick
        int ans2=mem(values,weights,n-1, w, dp);
        
        return dp[p][q]=max(ans1,ans2);
    }
    
    else if(weights[n-1]>w) {
        //one choice of not pick
        return dp[p][q] = mem(values,weights,n-1, w, dp);
    }
}

int tab(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>>dp) {
    
    int p= w; //row -> knapsack capacity
    int q=n; //col // size
    
    // filling the 0th row -> w==0 i.e; knapsack capacity = 0
    for(int j=0;j<=q;j++) {
        dp[0][j]=0;
    }
    
    // filling the 0th col -> n ==0 -> no item <= w
    for(int i=0;i<=p;i++) {
        dp[i][0]=0;
    }
    
    // remaining cells
    for(int i=1;i<=p;i++) {
        for(int j=1;j<=q;j++) {
           if(weights[j-1]<=i) {
               int ans1=values[j-1] + dp[i-weights[j-1]] [j-1];
               int ans2= dp[i][j-1];
               dp[i][j] = max(ans1,ans2);
           }  
            else if(weights[j-1]>i) {
                dp[i][j]= dp[i][j-1];
            }
        }
    }
    
    return dp[p][q];
    }

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
//*************************recursive code*********************//
//     //base case
//     if(n==0 || w==0)  // n=0 no items less than w or w==0 knapsack capacity=0
//     {return 0;}  
    
//     if(weights[n-1]<=w) {
//         //pick
//         int ans1=maxProfit(values, weights,n-1, w-weights[n-1]) + values[n-1];
//         //not pick
//         int ans2=maxProfit(values, weights,n-1, w);
        
//         return max(ans1,ans2);
//     } 
//     else if(weights[n-1]>w) {
//         // only one choice -> not pick
//         return maxProfit(values, weights,n-1, w);
//     }
    
    vector<vector<int>>dp(w+1, vector<int>(n+1, -1));
//     memset(dp, -1, sizeof(dp));
    return tab(values,weights,n, w, dp);
}




int knapsack(int* weight, int* value, int n, int maxWeight) {
    vector<int> weights;
    for(int i=0;i<n;i++) {
        weights.push_back(weight[i]);
    }
    
    vector<int> values;
     for(int i=0;i<n;i++) {
        values.push_back(value[i]);
    }
    
	return maxProfit(values, weights, n, maxWeight);
}
