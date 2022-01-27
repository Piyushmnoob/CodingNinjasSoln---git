Code : Balanced Parenthesis

For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.

Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.

Note:
The input expression will not contain spaces in between.
Input Format:
The first and the only line of input contains a string expression without any spaces in between.

Output Format:
The only line of output prints 'true' or 'false'.

Note:
You don't have to print anything explicitly. It has been taken care of. Just implement the function. 

Constraints:
1 <= N <= 10^7
Where N is the length of the expression.

Time Limit: 1sec

Sample Input 1 :
(()()())

Sample Output 1 :
true

Sample Input 2 :
()()(()

Sample Output 2 :
false

Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.



#include <stack>

bool isBalanced(string expression)
{
    // Write your code here
    bool ans = true;  // assume -> because if string is empty then we don't go inside the loop. hence, stack is also empty hence return true.

    stack <char> s1;

    int size = expression.size();

    for(int i = 0; i < size; i++) {

        if(expression[i] == '{' || expression[i] == '(') {
            s1.push(expression[i]);
            continue;
        }

        if(s1.empty()) // we have our the edge case which is if closing bracket is present at first then
                            // at that time our stack is empty because no element gets inserted into stack
        {
            return false;
        }

        else  // it means our stack is not empty and hence contains some opening brackets.
        {

            // reversing the closing bracket into opening bracket so that we can check it with top element.
             if(expression[i] = '}') {
                expression[i] = '{';
            }

             if(expression[i] = ')') {
                expression[i] = '(';
            }


           char ch = s1.top();

            if(s1.top() == expression[i]) {
                ans = true;
                s1.pop();
                continue;
            }
            else {
                return false;
            }


        }

    }

    // coming out from the loop we have to check if stack is empty or not.
    // if stack is empty then it means all the brackets are balanced or you can say there is no extra opening brackets.
      if(s1.empty()) {
          ans = true;
      } else {
          ans = false;
      }
    return ans;
}
