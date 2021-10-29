Quick Sort Code :-
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 5 2 7 3

Sample Output 2 :
1 2 3 5 7 



#include<iostream>
#include "Solution.h"
using namespace std;

/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/
int partition(int input[],int size){
    int s=input[0],cnt=0;
    for(int i=1;i<size;i++){
        if(input[i]<s){
            cnt++;
        }
    }
    input[0]=input[cnt];
    input[cnt]=s;
    return cnt;
}

void quickSort(int input[], int size) {
    if(size<=1){
        return;
    }
	int c = partition(input,size);
    int i=0,j=size-1;
    while(i<c && j>c){
        if(input[i]>=input[c]){
            if(input[j]<input[c]){
                int temp=input[i];
                input[i]=input[j];
                input[j]=temp;
                i++;
                j--;
            }else{
                j--;
            }
        }else{
            i++;
        }
    }
    quickSort(input,c);
    quickSort(input+(c+1),size-c-1);
}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}
