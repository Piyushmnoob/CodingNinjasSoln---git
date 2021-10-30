Staircase :-
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.

Input format :
Integer N

Output Format :
Integer W

Constraints :
1 <= N <= 30

Sample Input 1 :
4

Sample Output 1 :
7

Sample Input 2 :
5

Sample Output 2 :
13


#include <iostream>
#include "solution.h"
using namespace std;

int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n == 0) {
        return 1;
    } // Base Case --->> we are at ground position & to be in ground position there is one way
    
    if(n < 0) {
        return 0;
    } // Another Base case ---->>> we are not on the stairs. so no position.
    
    int x = staircase(n - 1); // 1 step at a time
    int y = staircase(n - 2); // 2 steps
    int z = staircase(n - 3); // 3 steps
    
    return x + y + z;
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
