Rat In A Maze Problem

You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.

Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 

Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   

Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second

Sample Input 1 :
3
1 0 1
1 0 1
1 1 1

Sample Output 1 :
1 0 0 1 0 0 1 1 1 

Explanation :
Only 1 path is possible. The path is shown in the image below.
Alt Text

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1

Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 

Explanation:
As described in the Sample Output 2, four paths are possible.



/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

void ratInMaze(int row, int col, int n, vector<vector<int>> &arr, vector<vector<int>> &visited) {
    // base case
    if(row==n-1 && col==n-1) {
        visited[row][col] =1; // marking the pos.

        for(int i=0;i<visited.size(); i++) {
            for(int j=0;j<visited[0].size(); j++) {
                cout<<visited[i][j]<<" ";
            }
        }

        cout<<endl;

        // since we r going back hence we have to unmark the visited[row][col] pos. // backtrack step.
        visited[row][col]=0;

        return;
    }

        //top/up
    if(row-1>=0 && visited[row-1][col]!=1 && arr[row-1][col]==1) {
        visited[row][col]=1;
        ratInMaze(row-1, col, n, arr, visited); //call
        visited[row][col]=0;
    }

    //down
    if(row+1<n && visited[row+1][col]!=1 && arr[row+1][col]==1) {
        visited[row][col]=1;
        ratInMaze(row+1, col, n, arr, visited); //call
        visited[row][col]=0;
    }

    //left
    if(col-1>=0 && visited[row][col-1]!=1 && arr[row][col-1]==1){
        visited[row][col]=1;
        ratInMaze(row, col-1, n, arr, visited); //call
        visited[row][col]=0;
    }

    //right
     if(col+1<n && visited[row][col+1]!=1 && arr[row][col+1]==1) {
         visited[row][col]=1;
        ratInMaze(row, col+1, n, arr, visited); //call
        visited[row][col]=0;
     }


}

int main() {

    int n;
    cin>>n;

    vector<vector<int>> arr;
    for(int i=0; i<n;i++) {
         vector<int>helper;
     for(int j=0; j<n;j++) {
           int temp;
           cin>>temp;
           helper.push_back(temp);
        }
        arr.push_back(helper);
    }

    vector<vector<int>> visited(n, vector<int>(n, 0)); //visited array

    if(arr[0][0]==1) //this check means if the source pos. is not 0 then we have no parh to go to the destination.
    {
    ratInMaze(0, 0, n, arr, visited);
    }
	return 0;
}

