/* Binary Tree Preorder Traversal

	Given a binary tree, return the preorder traversal of its nodes' values.

	For example:
	Given binary tree {1,#,2,3},
   1
    \
     2
    /
	3
	return [1,2,3].

	Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> nodes;
        vector<int> ans;
        if(root != NULL) nodes.push(root);
        while(!nodes.empty()) {
            TreeNode* current = nodes.top();
            nodes.pop();
            ans.push_back(current->val);
            if(current->right != NULL) nodes.push(current->right);
            if(current->left != NULL) nodes.push(current->left);
        }
        return ans;
    }
};