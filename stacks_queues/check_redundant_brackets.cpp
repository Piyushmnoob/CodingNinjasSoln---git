Check redundant brackets

For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.

Note:
You are not required to print the expected result. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second

Sample Input 1:
a+(b)+c 

Sample Output 1:
true

Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.

Sample Input 2:
(a+b)

Sample Output 2:
false



#include <stack>

bool checkRedundantBrackets(string S) {
	// Write your code here
    bool ans = true;

    stack <char> s1;

    int size = S.size();

    int count = 0; // whenever we put characters in the stack except closing bracket then count shuold be incremented by 1.


    for(int i = 0; i < size; i++) {

        if(S[i] != ')')  // closing bracket is our point to check the count value.
        {
            s1.push(S[i]);

            continue;
        }
        else {
            while(s1.top() != '(') // No doubt we are pushing all the characters in the stack including the opening bracket but the truth is opening bracket is not be included in a useful information.
            {
                count++;
                s1.pop();
            }

            s1.pop(); // after coming out from the loop we have removed all the characters except the opening brackets
            // so we have to remove that opening bracket due to which we come out from the while loop.


            if(count > 1) {
                ans = false; // means brackets are not redundant
            }
            else {
                ans = true; // returning because now the given expression has atleast one redundant bracket.
               break;
            }
        }

                count = 0; // reset the value.

    }

    return ans;
}
