/* Populating Next Right Pointers in Each Node II

	Follow up for problem "Populating Next Right Pointers in Each Node".

	What if the given tree could be any binary tree? Would your previous solution still work?

	Note:

	You may only use constant extra space.
	For example,
	Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
	After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        if(root->left != NULL)
            connect_next(root->left, root);
        if(root->right != NULL)
            connect_next(root->right, root->next);
        connect(root->right);
        connect(root->left);
    }
private:
    void connect_next(TreeLinkNode *root, TreeLinkNode *head) {
        TreeLinkNode * target = NULL;
        while(head != NULL) {
            if(head->left != NULL && head->left != root) target = head->left;
            else if(head->right != NULL && head->right != root) target = head->right;
            if(target != NULL) {
                root->next = target;
                return;
            }
            head = head->next;
        }
    }
};