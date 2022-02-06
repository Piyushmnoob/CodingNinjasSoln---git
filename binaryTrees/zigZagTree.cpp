ZigZag tree

Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9


#include <stack>

void zigZagOrder(BinaryTreeNode<int> *root) {
    stack <BinaryTreeNode<int> *> oddL;
    stack <BinaryTreeNode<int> *> evenL;

    oddL.push(root);
  while(oddL.size() != 0)  // this while loop indicates we will work until first stack gets empty.
  {
    while(oddL.size() != 0)  // this loop is to print the data for the odd level.
    {

        BinaryTreeNode<int> *top = oddL.top();
        oddL.pop();

        cout << top -> data << " ";
        if(oddL.size() == 0) {
            cout << endl;
        }

        if(top -> left != NULL) {
            evenL.push(top -> left);
        }
        if(top -> right != NULL) {
            evenL.push(top -> right);
        }

    }

        while(evenL.size() != 0)  // this loop is to print the data for the even level.
        {
           BinaryTreeNode<int> *evenTop = evenL.top();
            evenL.pop();

            cout << evenTop -> data << " ";
            if(evenL.size() == 0) {
                cout << endl;
            }

            if(evenTop -> right != NULL) {
            oddL.push(evenTop -> right);
            }

              if(evenTop -> left != NULL) {
            oddL.push(evenTop -> left);
            }

        }

}

}
