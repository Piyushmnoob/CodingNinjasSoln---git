Kth largest element

Given an array A of random integers and an integer k, find and return the kth largest element in the array.

Note: Try to do this question in less than O(N * logN) time.

Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following contains an integer, that denotes the value of k.

Output Format :
The first and only line of output contains the kth largest element

Constraints :
1 <= N, Ai, k <= 10^5
Time Limit: 1 sec

Sample Input 1 :
6
9 4 8 7 11 3
2

Sample Output 1 :
9

Sample Input 2 :
8
2 6 10 11 13 4 1 20
4

Sample Output 2 :
10

#include<vector>
#include<queue>
#include<climits>

int kthLargest(int* arr, int n, int k) {
    // Write your code here
        priority_queue<int, vector<int>, greater<int>> pq;   // inbuilt min priority queue

    vector<int> ans;
    
    // create -> heap (Min)
    for(int i=0;i<k;i++) {
        pq.push(arr[i]);
    }
    
    // we have to find the largest element from k-> n & swap it with the top of pq which is going to be min.
    
    for(int i= 0;i<k;i++) {
    int max=INT_MIN;
    int idx=k; // for swapping we need the idx of the arr from k -> n to replace it with the pq.
    
    for(int j=k;j<n;j++) {
        if(max<arr[j]) {
            max=arr[j];
            idx=j;
        }
    }
     // since we have to push the largest element in the vector hence all the element in the pq is largest.
    if(pq.top() < max) {
        arr[idx] = pq.top();
        pq.pop();
        pq.push(max);
    }
}
    
    for(int i=0;i<k;i++) {
        ans.push_back(pq.top());
        pq.pop();
    }
    
    // we are supposed to return the kth largest element in the array.
    // since in the vector we have all the k largest element then can we say that we are actually supposed to 
    // find the minimum elementfrom the vector???? ans is YES(logically).
    // hence we will return the minimum of vector 
    int Kthmin = INT_MAX;  
    for(int i=0;i<k;i++) {
        Kthmin=min(Kthmin, ans[i]);
    }
    
    return Kthmin;
}
