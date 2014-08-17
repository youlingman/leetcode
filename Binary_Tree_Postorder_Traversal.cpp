/* Binary Tree Postorder Traversal

	Given a binary tree, return the postorder traversal of its nodes' values.

	For example:
	Given binary tree {1,#,2,3},
	   1
		\
		 2
		/
	   3
	return [3,2,1].

	Note: Recursive solution is trivial, could you do it iteratively?
	
	The trick is to handle left and right return separately.
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode *> nodes;
        while(root != NULL || !nodes.empty()) {
            if(root != NULL) {
                nodes.push(root);
                root = root->left;
            }
            else {
                root = nodes.top();
                // left return
                if(root->right != NULL) root = root->right;
                // handle consecutive right return
                else {
                    ans.push_back(root->val);
                    nodes.pop();
                    while(!nodes.empty() && nodes.top()->right == root) {
                        root = nodes.top();
                        nodes.pop();
                        ans.push_back(root->val);
                    }
                    root = NULL;
                }
            }
        }
        return ans;
    }
};