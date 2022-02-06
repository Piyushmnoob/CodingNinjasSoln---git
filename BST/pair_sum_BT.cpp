Pair Sum Binary Tree

Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.

Output Format :
Print each pair in a new line, as described in the task. 

Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9


#include <vector>
#include <algorithm>

vector<int> BTNodeInArr(BinaryTreeNode<int> *root, vector<int> output) {
    if(root == NULL) {
        vector<int> v;
        return v;
    }
    
    vector<int> left = BTNodeInArr(root -> left, output); // left call
    
    // for(int i = 0; i < left.size(); i++) {
    //     output.push_back(left.at(i));
    // } 
    
// when we were doing somethinmg like the above then actually the elements from the left subtree pushes into the
// output for more than once hence, we were getting multiple ans so to prevent this we used the 'left' to 
// the whole time.
    
    left.push_back(root->data);
    
    vector<int> right = BTNodeInArr(root -> right, output); // right call
    
    for(int i = 0; i < right.size(); i++) {
        left.push_back(right.at(i));
    }
    
    output = left; // copying the elements of left vector into output vector.
    return output;
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // edge case
    if(root == NULL) {
        return;
    }
    
    vector<int> output;
    
vector<int> Arr = BTNodeInArr(root, output);
    
    sort(Arr.begin(), Arr.end());
    
    int i =0, j = Arr.size() - 1;
    
    while(i < j) {
        if(Arr.at(i) + Arr.at(j) == sum) {
            cout << Arr.at(i) << " " << Arr.at(j) << endl;
            i++;
            j--;
        } else if(Arr.at(i) + Arr.at(j) < sum) {
            i++;
        } else {
            j--;
        }
    }
    
    // T(N) = O(N*logN) + O(N), hence overall T(N) = O(NlogN)
        //        |        |
        //      sort()    searching
    
    // Auxilary Space = O(N)
    
}
