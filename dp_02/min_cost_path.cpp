Code : Min Cost Path

An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.

Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.

Output format :
Print the minimum cost to reach the destination.

Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec

Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13

Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76

Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18





// similar to rat in maze problem.

int minCostPathH(int row, int col, vector<vector<pair<int, bool>>> &vis, int **input, int m, int n) {
	//base case
    if(row==m-1 && col==n-1) {
        
        vis[row][col].second=1;
        
        int sum=0;
        for(int i=0; i<vis.size(); i++) {
            for(int j=0;j<vis[0].size(); j++) {
                if(vis[i][j].second==true) {
                    sum+=vis[i][j].first;
                }
            }
        }
        
        vis[row][col].second=0;
        
        return sum;
    }
    
    int minCost=INT_MAX; // to get the min cost path.
    
    //down
    if(row+1<m && vis[row+1][col].second!=1){
        vis[row][col].second=1;
        int smallMinCost=minCostPathH(row+1, col, vis, input, m,n); //call
        minCost=min(minCost, smallMinCost);
        vis[row][col].second=0; // bactrack step
        
    }
    
    
    //right
    if(col+1<n && vis[row][col+1].second!=1) {
         vis[row][col].second=1;
        int smallMinCost=minCostPathH(row, col+1, vis, input, m,n); //call
        minCost=min(minCost, smallMinCost);
        vis[row][col].second=0; // bactrack step
    }
    
    // diagonal
    if(row+1<m && col+1<n && vis[row+1][col+1].second!=1) {
         vis[row][col].second=1;
        int smallMinCost=minCostPathH(row+1, col+1, vis, input, m,n); //call
        minCost=min(minCost, smallMinCost);
        vis[row][col].second=0; // bactrack step
    }
    
    return minCost;
}



int minCostPath(int **input, int m, int n)
{
    // since here we have to find the path hence we have to maintain a visited array so that we reach to the
    // destination.
    
    vector<vector<pair<int, bool>>> vis;
    
    for(int i=0;i<m;i++) {
        vector<pair<int, bool>> arr;
        for(int j=0;j<n;j++) {
            pair<int, bool> p1={input[i][j], 0};
            arr.push_back(p1);
        }
        
        vis.push_back(arr);
    }
    
    return minCostPathH(0, 0, vis, input, m, n);
    
    // T(N)= O(m*n)   & S(N)= O(m*n)
    
}
