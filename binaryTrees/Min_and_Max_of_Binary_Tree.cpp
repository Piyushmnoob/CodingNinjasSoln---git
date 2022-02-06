Min and Max of Binary Tree

For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.

Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints two integers denoting the minimum and the maximum data values respectively. A single line will separate them both.

Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 14

Sample Input 2:
10 20 60 -1 -1 3 50 -1 -1 -1 -1 
Sample Output 2:
3 60


/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/

#include <climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// base case 
    if(root == NULL) {
        pair<int, int> p1;
        p1 = {INT_MAX, INT_MIN};  // we are including INT_MIN, INT_MAX coz we have to return the min & max value of tree.
                                  //  we can't set NULL for the min value coz if this happens then for each test
        // case we get the min value as 0. that's why we r using the INT_MIN, INT_MAX.
        return p1;
    }
    
    pair <int, int> root1 = {root -> data, root -> data};  
    
    pair <int, int> left = getMinAndMax(root -> left); // recursive call.
    
    if(left.first < root1.first) {
        root1.first = left.first;
    }
    
    if(left.second > root1.second) {
        root1.second = left.second;
    }
    
    pair <int, int> right = getMinAndMax(root -> right); // recursive call.
    
    if(right.first < root1.first) {
        root1.first = right.first;
    }
    
    if(right.second > root1.second) {
        root1.second = right.second;
    }
    
    
    return root1;
}
