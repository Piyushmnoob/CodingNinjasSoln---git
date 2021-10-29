Print Keypad Combinations Code :-
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

#include <iostream>
#include <string>
using namespace std;

void print(int num, string output) {
     if(num == 0) {
         cout << output << endl;
         return;
    } //Base Case.
    
    string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
    
    int remaining = num % 10;
    string possible = mapping[remaining];
    int length = possible.length();
    
    for(int i = 0; i < length; i++) {
        print(num / 10, possible[i] + output); // Recursive Call.
    } 
    
    
}


void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
     print(num, output); 
    return;
} 


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

