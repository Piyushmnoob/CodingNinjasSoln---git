Code : Find height

Given a generic tree, find and return the height of given tree.

Input Format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  

Output Format :
The first and only line of output prints the height of the given generic tree.

Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3

/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

int getHeight(TreeNode<int>* root) {
    // Write your code here
    
    
    int height = 0; // initially, height of root Treenode is 0.
    
      int max = height;  // max = current height i.e; root level
    
    for(int i = 0; i < root -> children.size(); i++) {
        
      int smallHeight = getHeight(root -> children[i]); // recursive call.
        
        if(smallHeight > max) {
            max = smallHeight;
        }
        
    }
    
    // assume a situation when only one treeNode is present. in that case we have no children which means 
    // no for loop will run. after the for loop we have added 1 in it. if initially, we set height = 1 then 
    // after adding 1  it will return 2 which is wrong.
    
    
    height = 1 + max;
    
    return height;
}
