Merge K sorted arrays

Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).

Hint : Use Heaps.

Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.

Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.

Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second

Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234




#include <algorithm>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // We have given k different arrays.
    // each array is sorted in the ascending order
    // we have to create a new array where we merge all the given arrays such that output array should be sorted
    // (in ascending order).
    // that simply means is we have to insert the element in the heaps.
    // to use heaps we don't need to include queues.
    // Acoording to given test cases we can understand we have to create the min heap.i.e;
    // parent < lc && rc

    vector<int> output;

    for(int i=0;i<input.size();i++) {
        vector<int> *Karr=input[i];

        for(int j=0;j<Karr->size();j++) {
            output.push_back(Karr->at(j));
        }
    }

    sort(output.begin(), output.end());

    // this is one way to solve the problem
    // T(N) = O(N*M)
    // O(N) = input.size(), O(M) = size for all the K array

    // up-heapify
//     for(int i=0;i<output.size();i++) {
//          //up-heapify
//             int ci=i;
//             int pi=(ci-1) /2;
//             while(ci>0) {
//                 if(output[pi]>output[ci]) {
//                     //swap
//                     output[pi]=output[pi]^output[ci];
//                     output[ci]=output[pi]^output[ci];
//                     output[pi]=output[pi]^output[ci];


//                 } else {
//                     break;
//                 }

//                 ci=pi;
//             }
//     }


    return output;
}
