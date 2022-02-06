LCA of Binary Tree

Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 

Note:
It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.

Note:
1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains two integers, denoting the value of data of two nodes of given binary tree.

Output Format:
The first and only line of output contains the data associated with the lowest common ancestor node.
Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10
Sample Output 1:
10

Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
Sample Output 2:
5

Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78
Sample Output 3:
-1




int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // base case
    if(root == NULL) {
        return -1;
    }
    
    // case when a or b matches with root -> data then that is going to be the LCA.
    if(root -> data == a || root -> data == b) {
        return root -> data;
    }
    
    int x = getLCA(root -> left, a, b);
    int y = getLCA(root -> right, a, b);
    
    if(x == -1 && y == -1)  // this is the case when a & b is not present in the BT
    {
        return -1;
    } 
    else if(x != -1 && y != -1)  // this is the case when we get LCA from each each subtrees then root-> data is ans.
    {
        return root -> data;
    } 
    else {
        if(x == -1) {
            return y;
        } else {
            return x;
        }
    }

}
