Construct Tree from Postorder and Inorder

For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements. 

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 

Sample Input 2:
6
2 9 3 6 10 5 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 

// search the root element in the inorder traversal array.
int search(int *inorder, int inLength, int key) {
    
    int ans = -1;
    
    for(int i = 0; i < inLength; i++) {
        if(key == inorder[i]) {
            ans = i;
        }
    }
    
    return ans;
}





BinaryTreeNode<int>* buildTreeHelper(int *postorder, int *inorder, int size, int postS, int postE, int inS, int inE) {
 // base case
   if(postS > postE) {
       return NULL;
   }
    
    
    int rootData = postorder[postE];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);
    
    int rootIdx = search(inorder, size, rootData); // search the idx of rootData in Inorder traversal array.
    
    int LpostS = postS; // left post order start.
    
    int RpostE = postE - 1;
    int LinS =  inS;
    int LinE =  rootIdx - 1;
    int RinS =  rootIdx + 1;
    int RinE =  inE;
        
    int LpostE = LinE - LinS + LpostS;
     int RpostS = LpostE + 1;
    
    
    root -> left = buildTreeHelper(postorder, inorder, size, LpostS, LpostE, LinS, LinE);
    root -> right = buildTreeHelper(postorder, inorder, size, RpostS, RpostE, RinS, RinE);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    
    return buildTreeHelper(postorder, inorder, inLength, 0, postLength - 1, 0, inLength - 1);
}
