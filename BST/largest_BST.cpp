Largest BST

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format:
The first and only line of output contains the height of the largest BST.

Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2



#include <utility>
#include <climits>
#include <vector>

// check BST funcn
// -------   leftMax, Rightmin 
pair<bool, pair<int, int>> checkBST(BinaryTreeNode<int> *root) {
    // base case
    if(root == NULL) {
        pair<bool, pair<int, int>> p1 = {true, {INT_MIN, INT_MAX}};
        return p1;
    }
    
    // calls
    pair<bool, pair<int, int>> left = checkBST(root -> left);
    pair<bool, pair<int, int>> right = checkBST(root -> right);
    
    bool isBSTleft = left.first;
    int leftMax = left.second.first;
    int leftMin = left.second.second;
    
    bool isBSTright = right.first;
    int rightMax = right.second.first;
    int rightMin = right.second.second;
    
    bool output = (root -> data > leftMax) && (root -> data < rightMin) && isBSTleft && isBSTright;
    int MAX = max(root -> data, max(leftMax, rightMax));
    int MIN = min(root -> data, min(leftMin, rightMin));
    
    
    pair<bool, pair<int, int>> p = {output, {MAX, MIN}};
    
  return p;
}

// height funcn
int getHeight(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return 0;
    }
    
    int left = getHeight(root -> left);
    int right = getHeight(root -> right);
    
    int Max = max(left, right);
    
    return 1 + Max;
}


// helper funcn
vector<BinaryTreeNode<int> *> largestBSTSubtreeHelper(BinaryTreeNode<int> *root, vector<BinaryTreeNode<int> *> v) {
    // base case
    if(root == NULL) {
        vector<BinaryTreeNode<int> *> v1;
        return v1;
    }
    
    // small Work -> we are checking if the given BT is BST or not.
     pair<bool, pair<int, int>> P = checkBST(root);
    bool ans = P.first;
    if(ans == true)  // means, given BT is the BST hence it is going to be the largest BST no matter if any other BST is present or not.
    {
        v.push_back(root);
        return v;
    } else {
        // calls  -> we r assuming if any BST is present either present in left or right, the root node of that BST will pushed into the vector v.
        vector<BinaryTreeNode<int> *> left = largestBSTSubtreeHelper(root -> left, v);
        vector<BinaryTreeNode<int> *> right = largestBSTSubtreeHelper(root -> right, v);
        
        v = left; // copying the data from 'left' vector to 'v'
        
        // then copying the data from 'right' into 'v'
        for(int i = 0; i < right.size(); i++) {
            v.push_back(right[i]);
        }
        // v = right; // this is not appropriate as u can visualize.
        
    }
    
    
// basically, if the given BT is BST then we will simply push the root of BT into 'v' & return but if it is not
// then, it means there r chances that we will get the BST in the left or right subtree. if any BST will present
// then the node will pushed into the vector but if it is not then empty vector will return by funcn.    
    
    return v;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    
    vector<BinaryTreeNode<int> *> v;
    
   vector<BinaryTreeNode<int> *> Vec = largestBSTSubtreeHelper(root , v); // to get the rootNode of BST's in BT
    
    int maxHeight = INT_MIN; // initially.
    
    for(int i = 0; i < Vec.size(); i++) {
        BinaryTreeNode<int> *node = Vec[i];
        
        int H = getHeight(node);  // we have called the height funcn to get the height of ith BST.
        
        maxHeight = max(maxHeight, H);
    }
    
    return maxHeight;
}
