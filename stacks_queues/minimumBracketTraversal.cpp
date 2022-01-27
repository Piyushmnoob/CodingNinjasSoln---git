Minimum bracket Reversal

For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.

Note:
You don't have to print anything. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec

Sample Input 1:
{{{

Sample Output 1:
-1

Sample Input 2:
{{{{}}

Sample Output 2:
1


#include <stack>

int countBracketReversals(string input) {
	// Write your code here
    
    stack <char> s1;
    
    int size = input.size();
    int count = 0; // counts the minimum bracket reversal.
    
    if(size % 2 != 0)  // means if string is odd then we never get the balanced expression. 
                       // ex :- {{} 
    {
        return -1;
    } 
    else {
        
        for(int i = 0; i < size; i++) {
            
            if(input[i] == '{') {
                s1.push(input[i]);
                continue;
            } 
        else  // we get the closing bracket
            {
                
            if(s1.empty())  // means we got  }{ 
            {
                s1.push(input[i]);
                continue;
                    
                } 
            else  // stack is not empty
            {
              
                if(s1.top() == '{')  // like if we have {}. opening bracket -> into the stack & '}' is at ith pos
                {
                    s1.pop();
                } 
                else  // means at the top we have the closing bracket.
                {
                    s1.push(input[i]);
                    continue;
                }
                   
            }
                
            }
            
            
        } // end of for loop
        
        int stackSize = s1.size(); 
        
        for(int j = 0; j < stackSize; j++) {
            char ch1 = s1.top();
            s1.pop();
            char ch2 = s1.top();
            s1.pop();
            
            if(ch1 == ch2) {
                count++;
            } 
            else  // that means we have  }{ . in that case we have to reverse both the brackets.
            {
              count = count + 2;  
                
            }
            
            // since we have poped the two element at once hence we have to update our stack size.
            stackSize = s1.size(); 
            j = 0; // it is necessary to reset the 'j' value because size is reducing as we are poping out the value. 
                   // hence, it is necesasary to reset j. if stack gets empty then condn will be 0 < 0.
                   // so get comes out from the loop.
        }
        
    } // end of else condn.
    
    return count;
    
}
