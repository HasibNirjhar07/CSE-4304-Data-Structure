//  Given the root of a binary tree, determine if it is a valid binary search tree
//  (BST).A valid BST is defined as follows:
//  ● The left subtree of a node contains only nodes with keys less than the node's
//  key.
//  ● The right subtree of a node contains only nodes with keys greater than the
//  node's key.
//  ● Both the left and right subtrees must also be binary search trees.
//  Sample Input Sample output Explanation
//  root = [2,1,3]
//  true


//  root = [5,1,4,null,null,3,6]

//  false


#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
   
    TreeNode *left;
   
    TreeNode *right;
   
    TreeNode(int x) :
   
     val(x),
   
     left(NULL),
    
     right(NULL) {}
};

bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left != NULL && root->left->val >= root->val)
        return false;
    if (root->right != NULL && root->right->val <= root->val)
        return false;
    return isValidBST(root->left) && isValidBST(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    if (isValidBST(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
