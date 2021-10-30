Return Permutations - String :-
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba


#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){ 
    
    // i = 0
    
    // input --->> abc   length = 3
    
    // 1st call --->>> input --> bc  length = 2
    // 2nd call --->> input --> c  length = 1
    // 3rd call --->> input --> ""  length 0;
   //*******************************************************//
    
    // i = 1
    
    if(input.empty()) // true.
    {
        output[0] = "";
        return 1;
    }
    
    int length = input.length();
    
    int m=0;
    string smallOutput[1000];
    int smallSize=0;
    for( int i= 0; i < length; i++) {
        // m = 0;
        // int smallSize = 0;
        if(i == 0)  // true  // 1st call -->> true
        
        {                                                                    // ^         ^
            smallSize = returnPermutations(input.substr(1), smallOutput); // bc |   // c  |   // ""
                // 1                                             ""
        
        } 
        
        
        else if(i < length - 1){
            smallSize = returnPermutations(input.substr(0, i) + input.substr(i + 1), smallOutput);
        }else {
            smallSize = returnPermutations(input.substr(0, i), smallOutput);
        }
        
        // to populate in output array.
        
        for(int j = 0; j < smallSize; j++){
            output[j + m] = input[i] + smallOutput[j]; // output[0] = 'a' + "" = a 
        }
        
        m += smallSize;  // m = 1 // i = 0
    }
    
    return m;
    
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

