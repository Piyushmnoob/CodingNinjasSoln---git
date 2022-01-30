Palindrome LinkedList

You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
9 2 3 3 2 9 -1

Sample Output 1 :
true

Sample Input 2 :
2
0 2 3 2 5 -1
-1

Sample Output 2 :
false
true

Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.


/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int length(Node *head)
{
    //Write your code here
    
    Node *temp = head; 
    int count = 0;
    
    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    return count;
}

Node *tail(Node *head, int size) {
    Node *temp = head;
    for(int i = 0; i < size - 1; i++) {
        temp = temp -> next;
    }
    
    return temp;
}

bool isPalindrome(Node *head)
{
    bool ans = true;  // if 0 node or 1 node is present then it will return true.
    
   int size = length(head); 
    
    Node *temp = head;
    Node *lo = temp;  // this is a pointer just like we take two pointers "lo & hi" to check the palindrome.
   
    Node *hi = tail(head, size); //function call.
// since this function is always returning something it means it is taking constant time to execute.
    
    while(lo < hi) { 
        
        if(lo -> data == hi -> data) {
           ans = true;
        } else {
            ans = false;
            break;
        }
        
        temp = temp -> next;
        lo = temp;
        size--;
        hi = tail(head, size); // updating hi pointer. it is same like hi--
    }
    
  return ans;  
}
