Code: BST to Sorted LL

Given a BST, convert it into a sorted linked list. You have to return the head of LL.

Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   

Output Format:
The first and only line of output prints the elements of sorted linked list.

Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10




#include <utility> // to use the pair class.

pair<Node<int>*, Node<int>*> constructLinkedListHelper(BinaryTreeNode<int>* root) {
// base case 
    if(root == NULL) {
        pair<Node<int>*, Node<int>*> p;
        p = {NULL, NULL};
        
        return p;
    }
    
pair<Node<int>*, Node<int>*> left = constructLinkedListHelper(root -> left); // 1st call
    
    Node<int> *lh = left.first;
    Node<int> *lt = left.second;
    
    Node<int> *root1 = new Node<int> (root -> data);
    // connections
    if(root -> left != NULL) {
        lt -> next = root1;
     } 
    
    
pair<Node<int>*, Node<int>*> right = constructLinkedListHelper(root -> right); // 2nd call
    
     Node<int> *rh = right.first;
    Node<int> *rt = right.second;
    
    // connections
        root1 -> next = rh; // here we r not writing the condition coz there is no need to do that.
    
   
    
    pair<Node<int>*, Node<int>*> p1;
    
    if(root -> left == NULL && root -> right == NULL) {
        p1 = {root1, root1};
    } else if(root -> left == NULL) {
        p1 = {root1, rt};
    } else if(root -> right == NULL) {
        p1 = {lh, root1};
    } else {
        p1 = {lh, rt};
    }
    
   
   return p1; 
}


Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    
pair<Node<int>*, Node<int>*> P = constructLinkedListHelper(root); 
 
   Node<int> *head = P.first;
    
    return head;
}
