kReverse

Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.

 Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'k'.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= k <= M

Time Limit:  1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9

Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4
Sample Output 2 :
1 2 3 4 5 
40 30 20 10 



Node *reverseLL(Node *head) {
    
    if(head == NULL || head -> next == NULL) {
        return head;
    }
 // head == NULL means list is empty or if head -> next == NULL then it means we have one node present.   
    
    Node *x = reverseLL(head -> next); // recursive call -> faith
    
    Node *tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    
    head = x;
    
    return head;    
}

Node *kReverse(Node *head, int k)
{
    if(head == NULL || head -> next == NULL) {
        return head;
    } // base Case
    
    //SmallWork
	Node *temp = head;
    int count = 0;
    
    while(count < k - 1 && temp -> next != NULL) {
        temp = temp -> next;
        count++;
    }
    
    Node *head2 = temp -> next; //pass during recursive call.
    
    temp -> next = NULL;
    
    // Normal function calling 
    Node *smallerLL = reverseLL(head);
    
//*************************************************************//  
    
    //recursive call
    Node *smallAns = kReverse(head2, k);
    
    //SmallWork 
    head -> next = smallAns;
    
    head = smallerLL;
    
    return head;
    
}
