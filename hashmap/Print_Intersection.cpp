Code : Print Intersection

You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first sorted array/list (ARR1).


Input format :
The first line of input contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Output format :
Print the intersection elements. Each element is printed in a separate line.

Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 

Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 

Sample Output 1 :
2
3 
4

Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
1 
2 
2


#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here

//     for(int i=0;i<n;i++) {

//         for(int j=0;j<m;j++) {
//             if(arr1[i] == arr2[j]) {
//                 cout << arr1[i] << endl;
//                 arr2[j]=0;
//                 break;
//             }
//         }
//     }
    // T(N) = O(N*M)
//////////////////////////////////////////////////////////////////////////////////////////////////////////
    unordered_map<int,int> mymap;

    // pushing arr1 value in the hashmap T(N) = O(N), Auxilary Space = O(N)
    for(int i=0;i<n;i++) {
       if(mymap.count(arr1[i]) >0){
           mymap[arr1[i]]+=1;
           continue;
       }
        mymap[arr1[i]] = 1;
    }

    // traverse the arr2 & check if the key of arr2[element] is present in hashmap or not
    // T(N) = O(M)
    for(int i=0;i<m;i++) {
        // if key of arr2[element] is present in hashmap then we wil print the number
        // but there is one case where :-
        // a1 = {7 7 7} , a2={7 7 7 7}

        if(mymap.count(arr2[i]) > 0 && mymap[arr2[i]] > 0) {
            cout << arr2[i] << endl;
            mymap[arr2[i]] -=1; // after printing one arr2[i] we will decrement the value of mymap[arr2[i]] by 1
                                // so that we can know exactly how much common duplicates r present
    // if mymap[arr2[i]] values becomes 0 and after then arr2[i] has same element then that is the extra element
            // which we will not print it
        }



        // T(N) = O(N+M)
        // Auxilary Space = O(N)
    }
}
