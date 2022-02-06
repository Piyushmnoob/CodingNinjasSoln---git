Code: Merge Sort

 Given a singly linked list of integers, sort it using 'Merge Sort.'

 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
 3 4 5 6 7 8 9 10 

 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90 



Node *midPoint(Node *head)
{

    if(head == NULL || head -> next == NULL) { 
		return head; 
	} 
    
	Node *slow = head, *fast = head -> next; 
	while(fast!= NULL && fast -> next != NULL) { 
		slow = slow -> next; 
		fast = fast -> next -> next; 
	} 
	return slow; 
    
}


Node *merge(Node *head1, Node *head2) {
  // one corner case is if one LL is empty means, no node is present.
    if(head2 == NULL) {
        return head1;
    }
    
    if(head1 == NULL) {
        return head2;
    }
 //*******************************************************************************//   
    //crawlers  
  Node *temp1 = head1;
   Node *temp2 = head2; 
    
    // now the only thing we have to do is creating a new LL to put the values of merged sorted LL.
    Node *newHead = NULL;
    Node *newTail = NULL;
    
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 -> data <=temp2 -> data) {
            Node *newNode = new Node(temp1 -> data);
            
            if(newHead == NULL) {
                newHead = newNode;
                newTail = newNode;   
            } 
            else {
                newTail -> next = newNode;
                newTail = newNode;
            }
            
            temp1 = temp1 -> next;
        }
        else {
            Node *newNode = new Node(temp2 -> data);
            
            if(newHead == NULL) {
                newHead = newNode;
                newTail = newNode;   
            } 
            else {
                newTail -> next = newNode;
                newTail = newNode;
            }
             
            temp2 = temp2 -> next; 
            
        }
    }
    
    
    // if temp1 == NULL then we come out of the loop
    while(temp2 != NULL) {
        Node *newNode = new Node(temp2 -> data);
        newTail -> next = newNode;
        newTail = newNode;
        temp2 = temp2 -> next;
    }
    
    // if temp2 == NULL then we come out of the loop
    while(temp1 != NULL) {
        Node *newNode = new Node(temp1 -> data);
        newTail -> next = newNode;
        newTail = newNode;
        temp1 = temp1 -> next;
    }
    
    return newHead;
    
}



Node *mergeSort(Node *head)
{
  // base case 
    if(head == NULL || head -> next == NULL) {
    // i) if no node is present 
        
     // ii)   // that means only one node is present 
        //and we know that merge sort is divide & conquer algo. hence we can't break it into more smaller LL.
        
        return head;
    }
    
    
    Node *head1 = head; 
    
  Node *mid = midPoint(head); // address of mid point.
    
    Node *head2 = mid -> next; // it is simply pointing to mid + 1.
    
    mid -> next = NULL; // breaking the whole LL into two parts.
  
 // head1 & head2 are the head of the two smaller LL when they are not sorted.   
    
    
// newHead1 is the head of left LL (upto mid) when gets sorted.    
Node *newHead1 = mergeSort(head1);     // Recursive call -> left call.
    
// newHead2 is the head of right LL (after mid) when gets sorted.    
Node *newHead2 = mergeSort(head2);   // Recursive call -> right call.
   
// so after the recursive calls we can assume that we get the two sorted LL. 
 
// so the only work now we have to do is merging the two sorted LL.
  
Node *sortedHead = merge(newHead1, newHead2);    
    
  
    return sortedHead;
    
}
// by  the above code test case 6 has failed. 

// code which is commented below is passing all the test cases.





// Node* merge(Node *head1, Node *head2) { 
// 	if(head1 == NULL) { 
// 		return head2; 
// 	} 
// 	if(head2 == NULL) { 
// 		return head1; 
// 	} 
// 	Node *head = NULL, *tail = NULL; 
// 	if(head1 -> data < head2 -> data) { 
// 		head = head1; 
// 		tail = head1; 
// 		head1 = head1 -> next; 
// 	} 
// 	else { 
// 		head = head2; 
// 		tail = head2; 
// 		head2 = head2 -> next; 
// 	}
	
// 	while(head1 != NULL && head2 != NULL) { 
// 		if(head1 -> data < head2 -> data) { 
// 			tail -> next = head1; 
// 			tail = head1; 
// 			head1 = head1 -> next; 
// 		} 
// 		else { 
// 			tail -> next = head2; 
// 			tail = head2; 
// 			head2 = head2 -> next; 
// 		} 
// 	} 
// 	if(head1 != NULL) { 
// 		tail -> next = head1; 
// 	} 
// 	if(head2 != NULL) { 
// 		tail -> next = head2; 
// 	} 
// 	return head;
// }


// Node* mergeSort(Node *head) { 
// 	if(head == NULL || head -> next == NULL) { 
// 		return head; 
// 	}
// 	Node *mid = midPoint(head); 
// 	Node *half1 = head; 
// 	Node *half2 = mid -> next; 
// 	mid -> next = NULL; 
// 	half1 = mergeSort(half1); 
// 	half2 = mergeSort(half2); 
// 	Node *finalHead = merge(half1, half2); 
// 	return finalHead; 
// }
