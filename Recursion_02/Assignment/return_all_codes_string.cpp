Return all codes - String:-
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

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


int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    string temp1[1000];
    string temp2[1000];
    
    if(input.length() == 0) {
        output[0] = "";
        return 1;
    }
    

    
    int num = input[0] - 48;  // '0' -->> ascii Value = 48
    char ch = 'a' + (num - 1);  // gives character of num.
          
    
    int ans1 = getCodes(input.substr(1), temp1); // recursive call
    
    for(int i = 0; i < ans1; i++) {
        output[i] = ch + temp1[i];
    }
    
    int ans2 = 0;  // because if num > 26 then no call & since we have to return ans1 + ans2.
    
     if(input[1] != '\0') {
    
     int num1 = num * 10 + input[1] - 48; // since num already obtained.
     char ch2 = 'a' + (num1 - 1);
         
    if(num1 >= 10 && num1 <= 26) {
   
        ans2 =  getCodes(input.substr(2), temp2);  // recursive call
        
        for(int j = 0; j < ans2; j++) {
            output[j + ans1] = ch2 + temp2[j];
        }
    }
    
    
    
}
     return ans1 + ans2;
    
    

}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

