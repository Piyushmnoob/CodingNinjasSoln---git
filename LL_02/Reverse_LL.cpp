Code : Reverse LL (Recursive)

Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. You have to do this in O(N) time complexity where N is the size of the linked list.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1

Sample Output 1 :
8 7 6 5 4 3 2 1

Sample Input 2 :
2
10 -1
10 20 30 40 50 -1

Sample Output 2 :
10 
50 40 30 20 10 


Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    
   // base case
    
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    /*
   In base case, if we do not write  head -> next == NULL then we get a runtime error. Why???
   
   The reason is:- Assume, we do not write  head -> next == NULL then one more recursive call takes
   place & head now pointing to NULL which means when it returns after hitting the base case then
   NULL gets stored in smallAns. 
   then, 
   temp is also equal to NULL but since temp is NULL then temp -> next doesn't exist.
 That is the reason why we are getting a runtime error.
 
 That's why we are writing that extra condn.(head -> next == NULL) to ensure that head never points to NULL.
    
    */
    
    Node *smallAns = reverseLinkedListRec(head -> next);
    
    Node *temp = smallAns;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    
    temp -> next = head;
    head -> next = NULL;
    
   
    
    return smallAns;
}


//**************************************** iterative*****************************************************//

Node *reverseLinkedList(Node *head) {
    // Write your code here
    Node *temp = head;

    Node *previous = NULL;

    while(temp != NULL) {
        Node *nxt = temp -> next;
        temp -> next = previous;
        previous = temp;
        temp = nxt; // for traversing. we can't write temp = temp -> next because we have changed it above.
    }



    return previous;
}






