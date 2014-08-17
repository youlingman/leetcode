/* Balanced Binary Tree

	Given a binary tree, determine if it is height-balanced.

	For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
	
	Use a int reference as parameter to store the height through the recursive process.
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
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalanced(root, height);
    }
    
private:
    bool isBalanced(TreeNode *root, int &height) {
        if(root == NULL) return true;
        int left = 0, right = 0;
        if(!isBalanced(root->left, left)) return false;
        if(!isBalanced(root->right, right)) return false;
        if(abs(left - right) > 1) return false;
        height = max(left, right) + 1;
        return true;
    }
};