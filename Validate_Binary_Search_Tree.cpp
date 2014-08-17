/* Validate Binary Search Tree

	Given a binary tree, determine if it is a valid binary search tree (BST).

	Assume a BST is defined as follows:

	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
private:
    bool isValidBST(TreeNode *root, int lower, int upper) {
        if(root == NULL) return true;
        if(root->val >= upper || root->val <= lower) return false;
        return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};