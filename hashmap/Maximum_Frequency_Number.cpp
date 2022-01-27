Code : Maximum Frequency Number

You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains most frequent element in the given array.

Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 

Sample Output 1 :
2

Sample Input 2 :
3
1 4 5

Sample Output 2 :
1



#include<unordered_map>

#include<climits>


int highestFrequency(int arr[], int n) {

   unordered_map<int, int> mymap;

    

    for(int i=0;i<n;i++) {

        

    // we will check if key is present or not

        if(mymap.count(arr[i]) > 0) {

            mymap[arr[i]] ++;

            continue;

        }

        

  // if key is not present we will insert the key in hashmap & initialise the value by 1.
	
        mymap[arr[i]] = 1;

    }

    

    int max=INT_MIN;

    int number = 0;

    for(int i=0;i<n;i++) {

        if(mymap[arr[i]] > max) {

            max= mymap[arr[i]];

            number = arr[i];

        }

    }

    return number;

}
