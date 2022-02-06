Second Largest Element In Tree

Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40


// // 1st data contains largest element & 2nd data contains 2nd largest element.
// #include<utility>

// pair<TreeNode<int>*, TreeNode<int>*> getSecondLargestNodeHelper(TreeNode<int>* root) {
     
//     pair <TreeNode<int>*, TreeNode<int>*> parent;  // this pair contains the treeNode.
//     parent = {root, NULL};
    
//     for(int i = 0; i < root -> children.size(); i++) {
        
//         pair<TreeNode<int>*, TreeNode<int>*> child = getSecondLargestNodeHelper(root -> children[i]); // call
        
//         TreeNode<int> *parentMax = parent.first;
//         TreeNode<int> *parentSecMax = parent.second;
        
//         TreeNode<int> *childMax = child.first;
//         TreeNode<int> *childSecMax = child.second;
    
//  // edge case
//         if(childMax -> data == parentMax -> data) {
            
//             if(childSecMax -> data > parentSecMax -> data) {
//                 parentSecMax = childSecMax;
//             }
            
//         } else {
       
//             // 1st case
//         int max0 = max(parentMax -> data, childMax -> data);
//         int min0 = min(parentMax -> data, childMax -> data);

//         if(max0 == childMax -> data) {
//             parentMax = childMax;
//         }
        
//             TreeNode<int> *discard = NULL;
//             if(min0 == parentMax -> data) {
//                 discard = parentMax;
//             } else {
//                 discard = childMax;
//             }
        
//       // 2nd case      
//         int max1 = max(parentSecMax -> data, discard -> data);
//         if(max1 == discard -> data) {
//             parentSecMax = discard;
//         }
            
//      // 3rd case.
//       int max2 = max(parentSecMax -> data, childSecMax -> data);
//             if(max2 == childSecMax -> data) {
//                 parentSecMax = childSecMax;
//             }   
            
//         }
        
//     }
    
//     return parent;
// }



// TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    
//   pair<TreeNode<int>*, TreeNode<int>*> ans = getSecondLargestNodeHelper(root);
    
// // 1st data contains largest element & 2nd data contains 2nd largest element.
    
//     return ans.second;
// }

class helper {
  public :
    TreeNode<int>*  m;
    TreeNode<int>* sm;
    
    helper (TreeNode<int>* m, TreeNode<int>* sm) {
        this->m = m;
        this->sm = sm;
    }
};

helper help (TreeNode<int>* root) {
    if(root==NULL){
        helper r(NULL,NULL);
        return r;
    }
    helper ans(root, NULL);
    for (int i = 0; i < root->children.size(); i++) {
            helper child = help (root -> children[i]);  
            if(child.m->data > ans.m->data){
                if(child.sm==NULL){
                    ans.sm=ans.m;
                    ans.m=child.m;
                }
                else{
                    if(child.sm->data > ans.m->data){
                        ans.sm=child.sm;
                        ans.m=child.m;
                    }
                    else{
                       ans.sm=ans.m;
                        ans.m=child.m; 
                    }
                }
            }
        else {
            if(ans.m->data!=child.m->data && (ans.sm==NULL || child.m->data > ans.sm->data)){
                ans.sm=child.m;
            }
        }
        }
    return ans;
}

TreeNode <int>* getSecondLargestNode(TreeNode<int> *root) {
    
    if (root == NULL) return NULL;
    helper ans = help (root);
    return ans.sm;
}
