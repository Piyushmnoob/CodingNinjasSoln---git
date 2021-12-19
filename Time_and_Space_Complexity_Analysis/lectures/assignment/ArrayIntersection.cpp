
Array Intersection

You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 

Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10

Sample Output 1 :
2 3 4
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
1 2 2

Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.

//*************************************************************************************//

HINT:-

1) Non optimized approach

Time Limit Exceed

Time limit exceeded comes whenever you try to use an approach which is taking more time than the expected time, so, try to use an optimized approach. In this problem if you are using 2 nested loops, then that would result in time complexity of O(N^2). So, to optimize the solution, you can use sorting. After sorting the array, you can use the approach of merge two sorted arrays to find the intersection. This solution will have time complexity of O(N log N).

2) Getting time limit exceeded even after using Sorting

Time Limit Exceed

As we know, to optimize the time complexity you have to use a sorting algorithm. Please ensure that you are using either merge sort or quick sort algorithm because they are having O(N log N) time complexity. 
You can’t use other sorting algorithms like the bubble sort, insertion sort as they have a worst-case time of O(N^2), which will not optimize your solution.
Instead of writing the whole code for either quick sort or merge sort, you can also use the inbuilt sort function available. By default, this sorts in ascending order.


3) Wrong answer while using hashmap
  Wrong Answer

  You may be getting wrong answers because you have not applied the approach correctly. In the hashmap approach, first, we store count of all the elements present in the first array in a hashmap and then, we will start finding whether the elements of the second array are present in the hashmap or not. If yes, then we will print that particular element and while printing we generally forget to decrement the count of that element from the hashmap which will give you wrong answers in case of duplicate elements. After decrementing the count of that element from the hashmap, if the count reaches 0, then we have to also remove that element from the hashmap.

Note: The hashmap approach is discussed in Hashmaps lecture. We would recommend you to solve this question using the sorting and merging approach discussed in hint video. 

//*************************************************************************************//

void intersection(int *arr1, int *arr2, int n, int m)
{
    //Write your code here

    sort(arr1, arr1 + n); // O(NlogN)
    sort(arr2, arr2 + m); // O(NlogN)

    // O(N^2)

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr1[i] == arr2[j]) {
                cout << arr2[j] << " ";
                arr2[j] = 0;
                break;
            }
            }
    }

    // Overall time complexity :- O(NlogN + NlogN + N^2) :- O(N^2)
}


