/* Remove Duplicates from Sorted List

	Given a sorted linked list, delete all duplicates such that each element appear only once.

	For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return head;
        ListNode * prev = head, * current = head->next;
        while(current) {
            if(current->val != prev->val) {
                prev = current;
                current = current->next;
            }
            else {
                ListNode * tmp = current;
                current = current->next;
                prev->next = current;
                free(tmp);
            }
        }
        return head;
    }
};