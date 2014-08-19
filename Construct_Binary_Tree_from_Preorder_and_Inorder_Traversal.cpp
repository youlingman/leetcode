/* Construct Binary Tree from Preorder and Inorder Traversal

	Given preorder and inorder traversal of a tree, construct the binary tree.

	Note:
	You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size()  -1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode *buildTree(vector<int> &preorder, int p_head, int p_tail, vector<int> &inorder, int i_head, int i_tail) {
        if(p_head > p_tail || i_head > i_tail) return NULL;
        int size = p_tail - p_head + 1;
        TreeNode * root = new TreeNode(preorder[p_head]);
        
        int index;
        for(index = 0; index < size; index++)
            if(inorder[index + i_head] == preorder[p_head]) break;

        // build left child
        root->left = buildTree(preorder, p_head + 1, p_head + index, inorder, i_head, i_head + index - 1);
        // build right child
        root->right = buildTree(preorder, p_head + index + 1, p_tail, inorder, i_head + index + 1, i_tail);

        return root;
    }
};