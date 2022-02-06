Code: BST Class

Implement the BST class which includes following functions -

1. search
Given an element, find if that is present in BST or not. Return true or false.

2. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.

3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.

4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.




#include <climits>

class BST {
    // Define the data members
    BinaryTreeNode<int> *root; // there is only one data member i.e; root.

    
    private:
    // in this we are going to create some helper funcn for each member funcn.
    
// 1) insert() ---> we have to return the root of the BST created.
    BinaryTreeNode<int> *insertHelper( BinaryTreeNode<int> *root, int data) {
        // base case
        if(root == NULL) {
            // we will create the newTreeNode and update the root and then return.
            BinaryTreeNode<int> *newTN = new BinaryTreeNode<int> (data);
            root = newTN;
            return root;
        }
        
       // since, we are inserting element the BST hence we can know when we have to call for the left or when for the right.
        
        if(data <= root -> data)  // given in the question.
        {
            BinaryTreeNode<int> *left = insertHelper(root -> left, data);
            root -> left = left;
            return root;
        } else {
            BinaryTreeNode<int> *right = insertHelper(root -> right, data);
            root -> right = right;
            return root;
        }
    }
    
// 2) search()
    bool searchH(int data, BinaryTreeNode<int> *node) {
        // base case
        if(node == NULL) {
            return false;
        } 
        
        if(node -> data == data) {
            return true;
        } 
        
        if(data < node -> data) {
            return searchH(data, node -> left);
        } else {
            return searchH(data, node -> right);
            
        }
    }
    
    
// 3) delete
    
    //***** creating min funcn
    int minimum( BinaryTreeNode<int> *root) {
        if(root == NULL) {
            return INT_MAX;
        }
        
        int left = minimum(root -> left);
        int right = minimum(root -> right);
        
        return min(root -> data, min(left, right));
    }
    
    // helper funcn
    BinaryTreeNode<int> *deleteNode( BinaryTreeNode<int> *root, int data) {
    // base case
        if(root == NULL) {
            return NULL;
        }
        
        
        if(root -> data == data) {
            // 3 cases
            if(root -> left == NULL && root -> right == NULL)  // leaf Node
            {
               delete root;
                return NULL;
            }
            else if(root -> left != NULL && root -> right != NULL) {
                
                int rightMin = minimum(root -> right); // funcn call
                
    // rightMin is the replacement for root and before replacing we delete that node from left subtree
               root -> data = rightMin;
                
       // here we r deleting the node from the right subtree. hence, right subtree changes.         
            BinaryTreeNode<int> *right = deleteNode(root -> right, rightMin); // call 
                
                root -> right = right; // updating the root -> right with the new changes.

                return root;   
            } 
            else {
                if(root -> left != NULL && root -> right == NULL)  // only left child 
                {
                   BinaryTreeNode<int>* temp = root->left;
				root->left = NULL;
				delete root;
				return temp;
                    
                } else {           // only right child.
                     BinaryTreeNode<int>* temp = root->right;
				root->right = NULL;
				delete root;
				return temp;
                }
            }
        }
        
        
        // recursive calls
        if(data < root -> data) {
            BinaryTreeNode<int> *left = deleteNode(root -> left, data);
            root -> left = left;
            return root;
        } else {
            BinaryTreeNode<int> *right = deleteNode(root -> right, data);
            root -> right = right;
            return root;
        }
    }
    
  
    
// 4) print
    void printH(BinaryTreeNode<int> *root) {
        if(root == NULL) {
            return;
        }
        
        cout << root -> data <<":";
        if(root -> left != NULL) {
            cout << "L:" << root -> left -> data << ",";
        }
         if(root -> right != NULL) {
            cout << "R:" << root -> right -> data;
        }
        
        cout << endl;
        printH(root -> left);
        printH(root -> right);
        
    }
   public:
    BST() { 
        // Implement the Constructor
        root = NULL; 
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
      BinaryTreeNode<int> *root1 = deleteNode(root, data);
        root = root1;
        
    }

    void print() { 
        // Implement the print() function
        printH(root);
    }

    void insert(int data) { 
        // Implement the insert() function 
    BinaryTreeNode<int> *root1 = insertHelper(root, data);
        
        root = root1;
        
    }

    bool search(int data) {
		// Implement the search() function 
      return searchH(data, root);
    }
};
