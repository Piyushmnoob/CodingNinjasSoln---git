Delete every N nodes

You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= P <= 10^5
Where P is the size of the singly linked list.
0 <= M <= 10^5
0 <= N <= 10^5 


Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2
Sample Output 1 :
1 2 5 6

Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3

Sample Output 2 :
1 2 6 7
Explanation of Sample Input 2 :
For the first query, we delete one node after every zero elements hence removing all the items of the list. Therefore, nothing got printed.

For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7


int length(Node *head) {
    
    int count = 0;
    while(head != NULL) {
        count++;
        head = head -> next;
    }
    
    return count;
    
}



Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    
    
    Node *temp = head;
    
    int size = length(head);
    
    int max = (M > N) ? M : N;
     int looptimes = size / max;
     
    
    int count = 1; 
    int reset = M;
    
    // actually, M = count * M 
    // Initially, M = 1 * 2 for a case -> 1 2 3 4 5 6 7 8 9 10 11 -1 M = 2, N = 2
    
    while(looptimes--) {
        
        if(M == 0)  // it means we do not have to skip(or retain) any Node. hence, all node will gets deleted.
        {
            return NULL;
        }
        
        if(N == 0)  // it means we do not have to delete any Node. hence, we simply return head.
        {
            return head;
        }
        
        for(int i = 0; i < M - 1; i++) {
           
            if(temp -> next != NULL) {
            temp = temp -> next;
            }
        }
        
        M = reset; // once we get the exact position of temp, we will reset to its default value.
        
       
        Node *curr = temp -> next; // 300
        temp -> next = NULL;
        Node *address = NULL; // to store the address of the Nth -> next.
        
        for(int j = 0; j < N; j++) {
            if(curr != NULL) {
           address = curr -> next; 
            curr -> next = NULL;
        delete curr; //after deleting curr it becomes dangling pointer therfore re-initialise.
            
            curr = address;
        }
        }
        
        
        temp -> next = address;
        
        temp = head;
        count++; // incrementing
        M = count * M; 
        
    }
    
    return temp;
    
}
