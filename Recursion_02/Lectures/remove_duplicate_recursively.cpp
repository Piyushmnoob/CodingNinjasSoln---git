Remove Duplicates Recursively :-
Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba

Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz

Sample Output 2 :
xyzwz


#include <iostream>
using namespace std;
#include "solution.h"

#include<string.h>

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

    int size = strlen(input);   //gives the size of input character array.

    
    if(input[0] == '\0') {
        return;
    } //Base Case
    
    //Small Work
    
    if(input[0] == input[1]) {
        for(int i = 0; i < size; i++) {
            input[i] = input[i + 1];
        }
    }
    
    removeConsecutiveDuplicates(input + 1);
    
    if(input[0] == input[1]) {
        
           for(int j = 0; j < size; j++) {
            input[j] = input[j + 1];
        }
        
    }
    
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}

