Eliminate duplicates from LL

You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1

Sample Output 1 :
1 2 3 4 5 7 

Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1

Sample Output 2 :
10 20 30 40 50
10


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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    Node *temp = head;
    Node *previous = head;
    Node *check = NULL;
    
  
    
    while(temp != NULL) {
     
        Node *nxtnode = temp -> next;
        
        if(temp -> data == nxtnode -> data) {
            
            if(check == NULL) {
                head = nxtnode;
                check = NULL;  // if first 3 nodes have same data then we have to remove the first 2 nodes
            }
               
           temp -> next = NULL;             // breaking the right link.
            previous -> next = nxtnode;    // breaking the left link.
             delete temp;                 // delteing unlinked node.
            temp = nxtnode;
            
            
        } else {
             
            
            check = head;  // if it is not enter in if condn at first then no need to check again even if duplicates are present.
            previous = temp;
        temp = temp -> next;
            
        }
        
        if(temp -> next == NULL)  // this is to check if NULL is present at temp -> next or not if it 
                                  // is present then it means that no node is present after temp and if this is so then
                                  // it means we have no nxtnode to check data with temp.
        {
            break;
        }
        
    }
    
    return head;
}
