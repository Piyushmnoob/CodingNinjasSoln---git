Longest subset zero sum

Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.

Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output 1:
5

Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 


//******************** take you forward ***********************//
//******************** better intution ************************//

#include<unordered_map>
#include<climits>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> mymap;   // key-> sum & value -> curr idx
    int sum=0;  // prefix sum
    int Max = INT_MIN;


    // traversing
    for(int i=0;i<n;i++) {
        sum+=arr[i];

        // after adding we have 2-3 things to check.
        //1)
        if(sum==0)  // it means we got our subarray
        {
            int length = i+1; // length of the subarray.
            Max = max(Max, length);
        }


        //2)
        if(mymap.count(sum)>0) // sum exist or not in the hashmap
        {

            // then we will put out the mymap[sum] value from the hashmap & we will find the diff. b/w
            // curr Idx & mymap[sum] value.
    // since, currIdx > mymap[sum] value

            int a = mymap[sum];
            int b = i;

            int length = b-a; // since, b > a alwa

            Max = max(Max, length);

        } else  // if this doesn't exist
        {
           mymap[sum] = i;  // we will insert the sum into the map along with the curr. Idx
        }
    }

    return Max;
}
