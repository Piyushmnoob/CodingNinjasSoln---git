String to Integer :-
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
00001231

Sample Output 1 :
1231

Sample Input 2 :
12567

Sample Output 2 :
12567

#include <iostream>
#include "solution.h"

#include<string.h>

int stringToNumber(char input[]) {
    // Write your code here
    // int size = strlen(input);
    if(input[0] == '\0') {
        return 0;
    }
    
    int smallOutput = stringToNumber(input + 1);
      smallOutput = atoi(input);
    return smallOutput;
}

using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
