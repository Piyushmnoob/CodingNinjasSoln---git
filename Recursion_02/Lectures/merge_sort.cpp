Merge Sort Code :-
Sort an array A using Merge Sort.
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
2 1 5 2 3

Sample Output 2 :
1 2 2 3 5 

//******************************** HINT **********************************//

1) Incorrect initialization in merge two sorted arrays function

   Runtime Error

This may be due to the fact that in function, which merges two sorted parts of an array, where you have been provided with the array and its start index and end index. You may have created a local array of size equivalent to the (end index - start index + 1). Let’s say ‘i’ be a local variable which traverses the first sorted half and ‘j’ be a local variable which traverses the second sorted half. Let ‘k’ be a local variable which traverses the local array. Runtime time occurs when you initialize ‘k’ with start index. To avoid this runtime error (segmentation fault), you must initialize ‘k’ with 0.

2) Unable to apply code with two parameters in function
   
  Implementation Issues 

You can use as many parameters as possible by creating a helper function, which is called in this function of two parameters. This helper function can have as many parameters as you like.

3) Incorrect base cases and wrong assumption about start index parameter in merge two sorted arrays function.

 Time Limit Exceed

1. This may be due to the fact that in function, which merges two sorted parts of an array, where you have been provided with the array and its start index and end index. You may have created a local array of size equivalent to the end index - start index + 1. Let’s say ‘i’ be a local variable which traverses the first sorted half and ‘j’ be a local variable which traverses the second sorted half. Let ‘k’ be a local variable which traverses the local array. Time Limit Exceeded occurs when you assume that the start index would always start with a zeroth index.

2. This may also be due to insufficient base cases. The main function of merge sort, which divides the array into two halves, should be terminated at the following base case: when the size of the array that you want to sort becomes less than or equal to one, then it is already sorted and should not be divided further. 

//*********************************************************************************//

#include <iostream>
#include "solution.h"
using namespace std;

void merge(int Arr[], int start, int mid, int end) {
	// create a temp array
	int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k ++;
            i ++;
		}
		else {
			temp[k] = Arr[j];
			k ++; 
            j ++;
		}
	}

	// add elements left in the first interval 
	while(i <= mid) {
		temp[k] = Arr[i];
		k ++; 
        i ++;
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k] = Arr[j];
		k ++;
        j ++;
	}

	// copy temp to original interval
	for(i = start; i <= end; i ++) {
		Arr[i] = temp[i - start];
	}
}


void helper(int input[], int s, int e) {
    int mid = s + (e - s) / 2;
    
    if(s >= e) {
       return;
    } //base case
    
    
    helper(input, s, mid);
    helper(input, mid + 1, e);
    merge(input, s, mid, e);
}



void mergeSort(int input[], int size){
	// Write your code here
    int s = 0;
    int e = size - 1;
    helper(input, s, e);
      
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
