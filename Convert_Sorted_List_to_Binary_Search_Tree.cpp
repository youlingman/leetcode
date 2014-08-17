/* Convert Sorted List to Binary Search Tree

	Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode * mid = get_mid(head);
        if(mid == NULL) {
            return new TreeNode(head->val);
        }
        else {
            ListNode * tmp = mid->next;
            mid->next = NULL;
            mid = tmp;
        }
        TreeNode * root = new TreeNode(mid->val);
        if(mid != NULL) mid = mid->next;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid);
        return root;
    }
private:
    ListNode* get_mid(ListNode *head) {
        ListNode * p1 = NULL, * p2 = head;
        while(p2 != NULL) {
            p2 = p2->next;
            if(p2 == NULL) break;
            if(p1 == NULL) p1 = head;
            else p1 = p1->next;
            p2 = p2->next;
            if(p2 == NULL) break;
        }
        return p1;
    }
};