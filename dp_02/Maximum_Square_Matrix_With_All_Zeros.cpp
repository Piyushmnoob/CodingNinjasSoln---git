Maximum Square Matrix With All Zeros

Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).

Output Format:
Print the size of maximum square sub-matrix.

Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec

Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1

Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4


#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int **dp = new int *[row];
    for(int i = 0; i < row; i++){
        dp[i] = new int[col];
    }

    for(int i = 0; i < row; i++){
        dp[i][0] = (arr[i][0] == 1) ? 0 : 1;
    }

    for(int j = 1; j < col; j++){
        dp[0][j] = (arr[0][j] == 1) ? 0 : 1;
    }

    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(arr[i][j] == 0){
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
            else dp[i][j] = 0;
        }
    }

    int max = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(dp[i][j] > max) max = dp[i][j];
        }
    }

    return max;    
}
