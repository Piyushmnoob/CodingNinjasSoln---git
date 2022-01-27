Code : K largest elements

You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.

Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.

Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k

Output Format :
k largest elements

Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output :
12
16
20
25




#include<queue>
#include<climits>
vector<int> kLargest(int arr[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
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
    
    return ans;
}

