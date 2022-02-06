Level wise linkedlist

Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9


/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public:
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/



vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // edge case
    if(root == NULL) {
       vector<Node<int>*>  nullVec;
        return nullVec;
    }

    vector <Node<int> *> arr;  // created a vector

    queue <BinaryTreeNode<int> *> pendingNodes; // queue

    pendingNodes.push(root);
    pendingNodes.push(NULL);

    // LL
    Node<int> *Head = NULL;
    Node<int> *Tail = NULL;


    while(pendingNodes.size() != 0) {

        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL) {

            if(pendingNodes.size() == 0) {
            arr.push_back(Head);  // correction
                break;
            }
           //******* correction **********//
            arr.push_back(Head);
            Head = NULL;
            Tail = NULL;
            //****************************//
          pendingNodes.push(NULL);
            continue; // if not continue then runtime error coz we r using front -> data to create LL node.
        }

       // creating LL
        Node<int> *newNode = new Node<int> (front -> data);

        if(Head == NULL) {
            Head = newNode;
            Tail = newNode;
        } else {
            Tail -> next = newNode;
            Tail = newNode;
        }


     //*********************** mistakes*******************//
        // arr.push_back(Head);

        // Head = NULL;
        // Tail = NULL;
    //****************************************************//

        // pushing the children into the queue
        if(front -> left != NULL) {
            pendingNodes.push(front -> left);
        }

        if(front -> right != NULL) {
            pendingNodes.push(front -> right);
        }

    }


    return arr;
}

