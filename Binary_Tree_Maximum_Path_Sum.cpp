/* Binary Tree Maximum Path Sum

	Given a binary tree, find the maximum path sum.

	The path may start and end at any node in the tree.

	For example:
	Given the below binary tree,

       1
      / \
     2   3
	Return 6.
	
	Solve it in simple recursive way at last!
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
    int maxPathSum(TreeNode *root) {
        int path = INT_MIN;
        return maxPathSum(root, path);
    }
private:
    int maxPathSum(TreeNode *root, int &path) {
        if(root == NULL) {
            return INT_MIN;
        }
        int l_path = INT_MIN, r_path = INT_MIN;
        int l_ans = maxPathSum(root->left, l_path);
        int r_ans = maxPathSum(root->right, r_path);
        path = max(max(l_path, r_path), 0) + root->val;
        return max(max(l_ans, r_ans), max(l_path, 0) + max(r_path, 0) + root->val);
    }
};