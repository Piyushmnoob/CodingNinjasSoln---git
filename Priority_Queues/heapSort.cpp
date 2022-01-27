Code : In-place heap sort

Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

Note: Space complexity should be O(1).

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.

Constraints :
1 <= n <= 10^6
Time Limit: 1 sec

Sample Input 1:
6 
2 6 8 5 4 3

Sample Output 1:
8 6 5 4 3 2




#include <vector>
#include<climits>
#include <bits/stdc++.h>
using namespace std;
void heapSort(int pq[], int n) 
{
    // Build the heap in input array
    for(int i=1;i<n;i++) 
    {		
        int childIndex = i;
        while(childIndex > 0) 
        {
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] < pq[parentIndex]) 
                swap(pq[childIndex],pq[parentIndex]);
            else
                break;
            childIndex = parentIndex;
        }
    }
    // Remove elements
    int size = n;
    while(size > 1)
    {
        swap(pq[0],pq[size - 1]);
        size--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndx = 2 * parentIndex + 2;
        while(leftChildIndex < size) 
        {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]) 
                minIndex = leftChildIndex;
            if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) 
                minIndex = rightChildIndx;
            if(minIndex == parentIndex) 
                break;
            swap(pq[minIndex],pq[parentIndex]);
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndx = 2 * parentIndex + 2;
        }
    }
}

