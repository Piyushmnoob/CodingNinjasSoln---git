Code : Pair Sum to 0

Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.

Note: Array A can contain duplicate elements as well.

Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 

Constraints :
0 <= N <= 10^4
Time Limit: 1 sec

Sample Input 1:
5
2 1 -2 2 3

Sample Output 1:
2


// #include<unordered_map>

// int pairSum(int *arr, int n) {
// 	// Write your code here
    
//     int count =0; // to count the pair sum
    
//     unordered_map<int,int> mymap;
    
//     // inserted all the arr[i] element in the hashmap with their frequency.
//     for(int i=0;i<n;i++) {
        
//         mymap[arr[i]]++;
//     }
    
//     // traverse the array.
//     for(int i=0;i<n;i++) {
        
//         if(mymap.count(0) > 0) {
//             count+=(mymap[0]*(mymap[0]-1))/2;
//             return count;
//         }
        
//         int frequency1= mymap[arr[i]];
        
//         int num= 0-arr[i]; // since pair sum equals to 0 hence we will find for the -ve number.
        
//         if(mymap.count(num) > 0)  // -ve is present
//         {
//            int frequency2 = mymap[num];
//             count = count+(frequency1*frequency2);
//             mymap[arr[i]] =0;
//             mymap[num] =0;
            
//         }   
//     }
    
//     return count;
// }


#include<unordered_map>
int pairSum(int *a, int n) 
{
    int pairs=0;
    unordered_map<int,int> m;
    for( int i=0 ; i<n ; ++i )
        m[a[i]]+=1;
    for( int i=0 ; i<n ; ++i )
        if( m.count(a[i])>0 && m.count(-a[i])>0 && a[i]!=0 )
        {
            pairs += m[a[i]]*m[-a[i]];
            m.erase(a[i]); // by this key gets deleted hence if while traversing if we again get the same key we will insert it & its value is automatically equals to 0.
        }
    // edge case
    if( m.count(0)>0 )
        pairs+= (m[0]*(m[0]-1))/2;
    return pairs;
}

