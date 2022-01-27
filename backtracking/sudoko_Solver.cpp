Sudoku Solver

Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.

Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 

Note:
Input are given in a way that backtracking solution will work in the provided time limit.

Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

Sample Output 1:
true


#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int **arr, int num) {
    for(int i=0;i<9;i++) {
        
        // column check -> row consistently changed & col -> fixed
        if(arr[i][col] == num) {
            return false;
        }
        
        // row check -> col consistently changed & row -> fixed
        if(arr[row][i]==num) {
            return false;
        }
        
        // submatrix[3][3] check 
        if(arr[3*(row/3) + i/3] [3*(col/3) + i%3] == num) {
            return false;
        }
    }
    
    return true;
}



// bool sudokoSolver(int board[9][9]) {
    
//     for(int i=0;i<9; i++)   // row
//      {
//         for(int j=0;j<9; j++)  // col --->> traverse the col to get the empty box
//         {
            
//             if(board[i][j]==0)  // is empty
//             {
//                 for(int num=1;num<=9;num++)  // we can store from 1->9
//                 {
//                     if(isValid(i, j, board, num))  // checks whether given num can be filled or not.
//                     {
//                         board[i][j]=num;  // if it's valid we will put the num.
                        
//                         sudokoSolver(board);  // call
                        
//                         if(sudokoSolver(board)==true) {
//                             return true; // if we can successfully fill the number then we don't move forward.
//                         } else {
//                             // backtrack step
//                         board[i][j]=0; // but if num is not valid then we will try for another num
//                         }
//                     }
//                 }
                
//                 // if at the given pos we r not able fill any num from 0-9 then we will return faLse.
//                 return false;
//             }
//         }
//     }
    
//     // this is the case when no empty palce is present hence will return true.
//    return true; 
// }


int n=9;
bool find_empty_location(int **arr, int &row, int &col)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j]==0)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}


bool solveSudoku(int **arr)
{
	int row=0, col=0; // initially 
	if(!find_empty_location(arr, row, col))  // if we get the empty location then row & col gets updated.
	{
		return true;
	}
	for(int i=1; i<=n; i++)
	{
		if(isValid(row, col, arr, i))
		{
			arr[row][col] = i;
			if(solveSudoku(arr))
			{
				return true;
			}
			else
			{
				arr[row][col] = 0; // backtracking step.
			}
		}
	}
	return false;
}
bool sudokuSolver(int board[9][9])
{
    int **arr=new int *[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=new int [n];
        for(int j=0; j<n; j++)
        {
            arr[i][j]=board[i][j];
        }
    }
    return solveSudoku(arr);
}

int main(){
    
    
    int board[9][9];
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cin>>board[i][j];
        }
    }
    
    bool ans=sudokuSolver(board);
    
    if(ans==true) {
        cout<<"true";
    } else {
        cout<<"false";
    }
    
    return 0;
}
