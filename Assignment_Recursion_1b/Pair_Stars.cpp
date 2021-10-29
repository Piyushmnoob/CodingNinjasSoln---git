Pair Star :-
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
aaaa

Sample Output 2 :
a*a*a*a


#include <iostream>
#include "solution.h"

// Change in the given string itself. So no need to return or print the changed string.
#include<string.h>

void helper(char input[], int s, int next) {
    int size = strlen(input);
    
    if(input[next] == '\0') {
        return;
    } //Base case
    
    //Small Work
   if (input[s] == input[next])
    {

      for (int i = strlen (input); i >= s + 1; i--)
	{
	  input[i + 1] = input[i];

	}
      input[s] = input[s];
      input[s + 1] = '*';
      input[s + 2] = input[s + 2];
    }
    
    //Recursive Call
    helper(input, s + 1, next + 1);
}
void pairStar(char input[]) {
    // Write your code here
      int s = 0;
     helper(input,s, s + 1);
}


using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

