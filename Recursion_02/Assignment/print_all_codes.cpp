Print all Codes - String :-
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw


#include <iostream>
#include "solution.h"
using namespace std;

#include <string.h>
using namespace std;

void helper(string input, string output) {
    
    if(input.empty()) {
        cout << output << endl;
        return;
    }
    
  
    
   // 1st call 
    int num = input[0] - '0'; // '2' -> 2
    char ch = 'a' + (num - 1);
    
     helper(input.substr(1), output + ch);
    

 //***********************************************//
    
    int ans2 = 0; // if 2nd call won't exist thenm we need this.
    
    int num1 = num * 10 + input[1] - '0';
    if(input[1] != '\0') {
    if(num1 >= 10 && num1 <= 26) {
        
    char ch2 = 'a' + (num1 - 1);
    
       helper(input.substr(2), output + ch2);

    
    }
    }
    

    
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string s = input;
    helper(s, "");
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
