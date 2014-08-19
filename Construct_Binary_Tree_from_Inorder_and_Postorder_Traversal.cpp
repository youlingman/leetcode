/* Construct Binary Tree from Inorder and Postorder Traversal 

	Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode *buildTree(vector<int> &in, int i_head, int i_tail, vector<int> &post, int p_head, int p_tail) {
        if(i_head > i_tail || p_head > p_tail) return NULL;
        int size = i_tail - i_head + 1;
        TreeNode * root = new TreeNode(post[p_tail]);
        
        int index;
        for(index = 0; index < size; index++)
            if(in[index + i_head] == post[p_tail]) break;
            
        // build left child
        root->left = buildTree(in, i_head, i_head + index - 1, post, p_head, p_head + index - 1);
        // build right child
        root->right = buildTree(in, i_head + index + 1, i_tail, post, p_head + index, p_tail - 1);
        
        return root;
    }
};