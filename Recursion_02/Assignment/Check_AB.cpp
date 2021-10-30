Check AB :-
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.

Input format :
String S

Output format :
'true' or 'false'

Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
abb

Sample Output 1 :
true

Sample Input 2 :
abababa

Sample Output 2 :
false

//****************************************** HINTS ***********************************************************************//

1) Missing corner cases

Wrong Answer

You may be getting wrong answers because you have not handled the case where the string starts with character b. You should return false for such a case.

Pseudocode:

if(input[0]=='b'):
    return false;
You may be getting wrong answers because you have not handled the case where the string is of size 1 and starts with character a, which means the first character is ‘a’ and next character is Null character. You should return true for such a case.
Pseudocode:
if(input[0]=='a' and input[1]=='\0'):
    return true;

//********************************************************************************************************************//

#include <iostream>
#include "solution.h"
using namespace std;

bool checkAB(char input[]) {
	// Write your code here
    bool ans;

     if(input[0] == 'a') {
        if(input[1] == '\0') {
            ans = true;
            return ans;
        } else if(input[1] == 'a') {
          ans = true;
          ans = checkAB(input + 1); // Recursive Call ---->>> faith
            return ans;
            
        } else if(input[1] == 'b' && input[2] == 'b') {
           if(input[3] == '\0') {
               ans = true;
               return ans;
           } else if(input[3] == 'a') {
               ans = true;
            ans = checkAB(input + 3);    // Recursive Call ---->>> faith
               return ans;
           } else {
               ans = false;
               return ans;
           }
            
        } else {
            return false;
        }
    } else {
        return false;
    }
 
    //Base Case.
    
if(input[0] == '\0') {
    return ans;
} 
    
}


int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}

