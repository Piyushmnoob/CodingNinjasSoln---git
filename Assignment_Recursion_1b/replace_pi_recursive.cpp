Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

Sample Input 3 :
pip

Sample Output :
3.14p

Constraints:-
1<=|S|<=50


//************** HINTS **************//

1) The return type of given function is void and the main code is printing the output. How is this possible?

Logical Issue in Problem :-

The reference of the input character array is passed as an argument to the given function. As there is only one copy of the input character array, any changes to the input character array made in a given function will be reflected in the input character array in the main function. So, you don’t have to return anything. All you have to do is make required changes in the input character array passed as argument.

2) How to shift characters in the array?

Implementation Issues :-

For understanding shift of characters, let's assume that the input string is “pipix” and assume that you have shifted some part of the input string and the input string is now: pi3.14x. Now, all you have to do is to replace the front part: pi3.14x. For this, you have to add 2 places to the input string first, so, we have to shift “3.14x” by 2 places and this will change the give string to pi_ _ 3.14x ( _ represents added 2 places of characters). Now, appropriate places can be replaced by 3.14 and hence, the string will become 3.143.14x.

Pseudocode:

if (input[0] == 'p' and input[1] == 'i')  // replacement should only be done if first 2 characters are 'p' and 'i'
    initialize count=0
    initialize i=0

    while(input[i]!='\0') //loop to count characters in string
        count++
        i++

    // shifting loop
    for (initialize i = count+1 condition: i >= 2 decrement: i--) 
            input[i + 2] = input[i]; //shifting

    //Replacement
    input[0] = '3'; 
    input[1] = '.'; 
    input[2] = '1'; 
    input[3] = '4'; 

3) Incorrect Shifting

Time Limit Exceed :-

You may be getting the time limit exceeded because you have not shifted the characters properly. A detailed explanation to shift the characters is given in earlier FAQ.    
4) Incorrect shifting of null character and shifting of characters initiated from front

Wrong Answer :- 

You may be getting wrong answers because in the shifting step, you have not shifted the ‘\0’, i.e. null character properly. 
Another possible reason for the wrong answers could be that you are shifting from forward to null character. This will lead to overwriting of input string and will in turn lead to wrong answer. Please make sure that you are shifting from backwards, starting from null character and shift each character by two characters.

//*********************************************************************************************************************//

#include <iostream>
#include "solution.h"
using namespace std;

// Change in the given string itself. So no need to return or print anything
#include <string.h>

void replacePi(char input[]) {
	// Write your code here
     int s = 0;
    int size = strlen(input);
    if(input[s] == '\0' || input[s + 1] == '\0') {
        return;
    }
    
    if(input[s] == 'p' && input[s + 1] == 'i') {
        for (int i = strlen(input); i >= s + 2; i--) {
            input[i + 2] = input[i];
        }
        // don't be confused by thinking that i + 2 means 10000 + 2 = 10002.
        // strlen -> it will give the length excluding all the null vaues.
        // ex :- char ch[8] = "abc"   -> 5 null values but the length is only 3.
        input[s] = '3';
        input[s + 1] = '.';
        input[s + 2] = '1';
        input[s + 3] = '4';
    }
    
    //since the input array is of size 10000 thats why we are able to shift the elements towards the right side.
    
    replacePi(input + 1);
    
}


int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

