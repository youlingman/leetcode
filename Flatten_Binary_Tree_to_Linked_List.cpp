/* Flatten Binary Tree to Linked List

	Given a binary tree, flatten it to a linked list in-place.

	For example,
	Given

         1
        / \
       2   5
      / \   \
     3   4   6
	The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void flatten(TreeNode *root) {
        flat(root);
    }
private:
    TreeNode * flat(TreeNode * root) {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;
        if(root->left == NULL) return flat(root->right);
        TreeNode * tail = flat(root->left);
        tail->right = root->right;
        root->right = root->left;
        root->left = NULL;
        if(tail->right == NULL) return tail;
        else return flat(tail->right);
    }
};