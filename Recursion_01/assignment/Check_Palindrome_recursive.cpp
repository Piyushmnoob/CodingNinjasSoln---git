/*
 Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar
Sample Output 1:
true

Sample Input 2 :
ninja
Sample Output 2:
false

 */

#include <iostream>
#include "solution.h"
using namespace std;

#include <string.h>



bool helper(char input[], int s, int e){
if(e == 0 || e == 1) {
    return true;
}

if(input[s] != input[e - 1]) {
    return false;
} else {
    bool answer = helper(input, s + 1, e - 1);
    return answer;
}
}


bool checkPalindrome(char input[]) {
    // Write your code here
    int s = 0;
   int e = strlen(input);
    
   bool ans =  helper(input, s, e);
    return ans;

}

int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
