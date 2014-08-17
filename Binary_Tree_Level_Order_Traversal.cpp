/* Binary Tree Level Order Traversal

	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

	For example:
	Given binary tree {3,9,20,#,#,15,7},
		3
		/ \
		9  20
		/  \
		15   7
	return its level order traversal as:
	[
		[3],
		[9,20],
		[15,7]
	]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        deque<TreeNode *> current_level;
        current_level.push_back(root);
        while(!current_level.empty()) {
            deque<TreeNode *> next_level;
            vector<int> tmp;
			// use reserve save half time
            tmp.reserve(current_level.size());
            for(auto node : current_level) {
                tmp.push_back(node->val);
                if(node->left != NULL) next_level.push_back(node->left);
                if(node->right != NULL) next_level.push_back(node->right);
            }
            ans.push_back(tmp);
            current_level = next_level;
        }
        return ans;
    }
};