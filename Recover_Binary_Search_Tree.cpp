/* Recover Binary Search Tree

	Two elements of a binary search tree (BST) are swapped by mistake.

	Recover the tree without changing its structure.

	Note:
	A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
	
	Use three reference of pointer in inorder traversal to reach constant space.
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
    void recoverTree(TreeNode *root) {
        if(root == NULL) return;
        TreeNode * prev = NULL, *first = NULL, *second = NULL;
        inorder(root, prev, first, second);
        swap(first->val, second->val);
        return;
    }
private:
    void inorder(TreeNode *root, TreeNode * &prev, TreeNode * &first, TreeNode * &second) {
        if(root == NULL) return;
        inorder(root->left, prev, first, second);
        if(prev != NULL) {
            if(root->val < prev->val && first == NULL) first = prev;
            if(root->val < prev->val) second = root;
        }
        prev = root;
        inorder(root->right, prev, first, second);
    }
};