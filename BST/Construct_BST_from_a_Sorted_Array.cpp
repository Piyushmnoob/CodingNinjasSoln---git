Code: Construct BST from a Sorted Array

Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.

Note: If array size is even, take first mid as root.

Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.

Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second

Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 


// when an array is passed as an argment it behaves like a pointer. sizeof(input), ans -> 8 
BinaryTreeNode<int>* constructTreeHelper(int *input, int n, int s, int e) {
    
    // base case
    if(s > e || n == 0)  // if size of array is 0 then no data is given to make the BST
                        // &, if s > e then no data left to make the treeNode.
    {
        return NULL;
        
    }
    
    int mid = s + (e - s) / 2;
    
    int rootData = input[mid];
    
    BinaryTreeNode<int> *root1 = new BinaryTreeNode<int> (rootData);
    
    // recursive calls
    BinaryTreeNode<int> *Left = constructTreeHelper(input, n, s, mid - 1);
    BinaryTreeNode<int> *Right = constructTreeHelper(input, n, mid + 1, e);
    
    root1 -> left = Left;
    root1 -> right = Right;
    
   return root1; 
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
	
    int s = 0;
    int e = n - 1;
    
    BinaryTreeNode<int> *root = constructTreeHelper(input, n, s, e);
    
  return root;  
}
