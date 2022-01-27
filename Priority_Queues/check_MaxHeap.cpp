Check Max-Heap

Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.

Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec

Sample Input 1:
8
42 20 18 6 14 11 9 4

Sample Output 1:
true


bool isMaxHeap(int arr[], int n) {
    // Write your code here

    bool ans = false;

    for(int i=0;i<n;i++) {
        int pi=i;
        int lci=(2*pi)+1;
        int rci=(2*pi)+2;

        if(lci>=n) {
            ans=true;
            continue;
        } else {
            if(arr[pi] > arr[lci]) {
                ans=true;
                continue;
            } else {
                return false;
            }
        }

        if(arr[pi]> arr[lci] && arr[pi] > arr[rci]) {
            ans=true;
        } else {
            return false;
        }
    }
    return ans;
}
