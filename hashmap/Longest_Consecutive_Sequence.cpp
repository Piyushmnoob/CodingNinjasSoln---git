Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.

Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.

Constraints :
0 <= n <= 10^6
Time Limit: 1 sec

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 

Sample Output 1 :
8 12 

Sample Input 2 :
7
3 7 2 1 9 8 41

Sample Output 2 :
7 9

Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.

Sample Input 3 :
7
15 24 23 12 19 11 16

Sample Output 3 :
15 16



//************ take you forward -> longest consecutive sequence **********//
                                    // better intution
// after seeing video there r high chances u will solve the problem

#include<unordered_set> // to use hashset
#include<vector>
#include<utility> // to use pair
#include<climits>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {

    unordered_set<int> myset;  // created a hashset

    // inserting each element in the hashset
    for(int i=0;i<n;i++) {
        myset.insert(arr[i]);
    }

    vector< pair<int, pair<int,int>> > output;  // store Length of Consecutive Sequence & start, end of Consecutive Sequence
          //     |          |    |
          //   length of  start end
          //   LCS

    for(int i=0;i<n;i++) {

        int num=arr[i];

        int before =num-1;
        // will check if no. less than arr[i] exist in hashset or not.
        if(myset.count(before)>0) {
            continue;
        } else {

            int maxLength=1; // length of consecutive sequence. we ahve taken 1 coz starting element is also in CS
           pair<int, pair<int,int>> p;
            p.second.first=num; // starting element of particular consecutive sequence.

            int next = num+1;
            while(myset.count(next) > 0) {

                    maxLength++;
                     p.second.second=next; // will update the ending element of Consecutive Sequence till the loop continue.
                                           // this will give the last element of consecutive sequence.
                     next++;

            }
            // after coming from the loop we will get the length of the particular consecutive sequence.
            p.first = maxLength;

            output.push_back(p);  // pushing the pair in the output vector.
            // this output vector contains all the consecutive sequence of the array.
        }
    }

    int Max = INT_MIN; // contains the length of LCS.
        pair<int,int> ans = {0,0}; // initially.
    // this ans will contain the start & end of the LCS

        for(int i=0;i<output.size(); i++) {
           pair<int, pair<int,int>> p1 = output[i];

            if(Max<p1.first) {
                Max=p1.first;
                ans={p1.second.first, p1.second.second};
            }
        }  // coming out from this loop we will get the start & end of the LCS stored in the pair

        vector<int> result;     // final answer
    result.push_back(ans.first);
    result.push_back(ans.second);

  return result;
}
