Rotate array

You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
 Note:
Change in the input array/list itself. You don't need to return or print the elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of 'D' by which the array/list needs to be rotated.

Output Format :
For each test case, print the rotated array/list in a row separated by a single space.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N
Time Limit: 1 sec

Sample Input 1:
1
7
1 2 3 4 5 6 7
2

Sample Output 1:
3 4 5 6 7 1 2

Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2

Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2

//------------------------------------------------------------------------------------//

void rotate(int *input, int d, int n)
{
    //Write your code here
//     int count = 0;
//     int j;

//  for(int i = 0; i < d; i++) {

//      count = input[0];

//      for(j = 0; j < n - 1; j++) {

//          input[j] = input[j + 1];

//      }

//      if(j == n - 1) {
//              input[j] = count;
//          }
//  }
//     //O(N ^ 2)

 //*********************************************************************************//

    int arr[n]; // n -> 6    &   d -> 4
    // Auxilary Space :- O(N)

    int count = n - d; // 2
    // count is found to put the value of input array from count idx to n - 1 in arr.

    //crawler to traverse over input array
    int k = 0;

             // 2th index
    for(int i = count; i < n; i++)  // Time Complexity :- O(N)
    {
        arr[i] = input[k];
        k++;
    } // this loop put the value of input array from 0 -> < d (i.e; 0 -> 3 (< 4) )
      // k = 4;

    for(int j = 0; j < count; j++)  // Time Complexity :- O(N)
    {
        arr[j] = input[k];
        k++;
    }
  /* one more loop to put the value of input array from d -> n - 1 (i.e; 4 -> 5 (< n = 6)) in
     arr from idx 0 -> (< count) (i.e; 0 -> 1 (< 2)). */


     // copy elements in input array.
    for(int l = 0; l < n; l++)  // Time Complexity :- O(N)

    {
        input[l] = arr[l];
    }

    // Overall Time Complexity = O(N), Auxilary Space :- O(N)

    // Overall Space Complexity = Input Size +  Auxilary Space
                                  // O(N)    +    O(N)   = O(N)
}





