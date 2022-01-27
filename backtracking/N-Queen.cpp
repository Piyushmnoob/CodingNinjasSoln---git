N-Queen Problem

You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

Note: Don't print anything if there isn't any valid configuration.

Input Format:
The first line of input contains an integer, that denotes the value of N.     

Output Format :
In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.

Constraints :
1 <= N <= 10
Time Limit: 1 second

Sample Input 1:
4

Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 

Explanation:
The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other. 



// #include<bits/stdc++.h>
// using namespace std;

// bool isSafe(int row, int col, vector<string> &board, int n) {
//     int duprow=row;
//     int dupcol=col;

//     while(row>=0 && col>=0) {
//         if(board[row][col]=='1') {
//             return false;
//         }

//         row--;
//         col--;
//     }

//       row=duprow;
//       col=dupcol;

//     while(col>=0) {
//      if(board[row][col]=='1') {
//             return false;
//         }
//         col--;
//     }

//     while(row<n && col>=0) {
//         if(board[row][col]=='1') {
//             return false;
//         }
//         row++;
//         col--;
//     }

//     return true;

// }

// void solve(int col, vector<string> &board,vector<vector<string>> &ans,  int n) {
//     // base case
//     if(col==n) {
//         ans.push_back(board);
//         return;
//     }



//     for(int row=0;row<n;row++) {
//         if(isSafe(row, col,board, n)) {
//             board[row][col]='1';
//             solve(col+1, board, ans,  n); // calls
//             board[row][col]='0';
//         }
//     }

// }

// vector<vector<string>> Nqueens(int n) {

//     vector<vector<string>> ans;
//     vector<string> board(n);
//     string s(n, '0');

//     for(int i=0;i<n;i++) {
//         board[i]=s;
//     }

//      solve(0,board,ans, n);

//     return ans;
// }

// int main(){

//     int n;
//     cin>>n;

//    vector<vector<string>> ans= Nqueens(n);
//     int k = ans.size();
//    for(int i=0;i<ans.size();i++) {
//        vector<string> a=ans[i];
//        for(int j=0;j<a.size(); j++) {
//            cout<<a[j]<<" ";
//        }
//        cout<<endl;
//    }

//     return 0;
// }


#include<iostream>
using namespace std;
void printer(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
	}
}
bool checker(int** arr, int i, int j, int n)
{
	for (int p = 0; p < n; p++)
	{
		if (arr[p][j] == 1 && p!=i)
		{
			return false;
		}
	}
	for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++)
	{
		if (arr[row][col] == 1)
		{
			return false;
		}
	}
	for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; col--, row--)
	{
		if (arr[row][col] == 1)
		{
			return false;
		}
	}

	return true;
}
void zero_converter(int **arr, int n, int row)
{
	for(int i=row; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j] = 0;
		}
	}
}
void placer(int** arr, int row, int col, int n)
{
	if (row == n)
	{
		printer(arr, n);
		cout << endl;
		return;
	}
	int i = col;
	for (; i < n; i++)
	{
		zero_converter(arr, n, row);
		if (checker(arr, row, i, n))
		{
			arr[row][i] = 1;
			placer(arr, row + 1, col, n);
			continue;
		}
	}
}
void placeNQueens(int n)
{
	int** arr = new int* [n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	placer(arr, 0, 0, n);
    for(int i=0; i<n; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}

int main(){

    int n;
    cin>>n;
placeNQueens(n);

    return 0;
}
