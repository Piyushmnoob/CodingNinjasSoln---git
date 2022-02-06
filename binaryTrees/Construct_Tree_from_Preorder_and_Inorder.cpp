Code: Construct Tree from Preorder and Inorder

For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements. 

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

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
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 

Sample Input 2:
6
5 6 2 3 9 10 
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



BinaryTreeNode<int>* buildTreeHelper(int *preorder, int *inorder, int size, int inS, int inE, int preS, int preE) {

    // base case
    if(preS > preE) {
        return NULL;
    }
    
    int rootData = preorder[preS];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);   
    
    
    int rootIdx = search(inorder, size, rootData); // return the idx of rootPosition in inOrder traversal Array.
    
    
    
    int LinS = inS;   // left inorder start
    int LinE = rootIdx - 1; // left inorder end
    int LpreS = preS + 1; // left preorder start
    int RinS = rootIdx + 1; // right inorder start
    int RinE = inE;  // right inorder end
    int RpreE = preE;  // right preorder end
    int LpreE =  LinE - LinS + LpreS;       // left preorder end
    int RpreS =  LpreE + 1;      // right preorder start
     
    
    BinaryTreeNode<int> *newLeft = buildTreeHelper(preorder, inorder, size, LinS, LinE, LpreS, LpreE);
    BinaryTreeNode<int> *newRight = buildTreeHelper(preorder, inorder, size, RinS, RinE, RpreS, RpreE);
    
    root -> left = newLeft;
    root -> right = newRight;
    
 return root;   
}



BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
  
  return  buildTreeHelper(preorder, inorder, inLength, 0, inLength - 1, 0, preLength - 1);
    
    
}
