Print Level Wise

For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.

Note: There is no space in between while printing the information for each node.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
Information of all the nodes in the Binary Tree will be printed on a different line where each node will follow a format of D:L:X,R:Y, without any spaces in between.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1


/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

void printLevelWise(BinaryTreeNode<int> *root) {
	
    queue<BinaryTreeNode<int> *> printPendingNodes;
    
    printPendingNodes.push(root);
    
    while(printPendingNodes.size() != 0) {
        
       BinaryTreeNode<int> *front = printPendingNodes.front();
        printPendingNodes.pop();
        
        cout << front -> data << ":";
     
        // left node
        if(front -> left != NULL) {
            cout << "L:" << front -> left -> data << ",";
            
            printPendingNodes.push(front -> left);
        }
        
         if(front -> left == NULL) {
            cout << "L:-1" << ",";
            
        }
        
        // right node
        
         if(front -> right != NULL) {
            cout << "R:" << front -> right -> data;
            
            printPendingNodes.push(front -> right);
        }
        
                 if(front -> right == NULL) {
            cout << "R:-1";
            
        }
        
        cout << endl;
    }
    
}
