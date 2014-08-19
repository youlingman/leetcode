/* Path Sum II

	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
	return
	[
		[5,4,11,2],
		[5,8,4,5]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        pathSum(root, sum, ans, path);
        return ans;
    }
private:
    void pathSum(TreeNode *root, int sum, vector<vector<int> > &ans, vector<int> &path) {
        if(root == NULL) return;
        path.push_back(root->val);
        // reach a leaf node
        if(root->left == NULL && root->right == NULL) {
            if(sum == root->val)
                ans.push_back(path);
            path.pop_back();
            return;
        }
        pathSum(root->left, sum - root->val, ans, path);
        pathSum(root->right, sum - root->val, ans, path);
        path.pop_back();
    }
};