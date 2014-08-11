/* Remove Duplicates from Sorted List II

	Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

	For example,
	Given 1->2->3->3->4->4->5, return 1->2->5.
	Given 1->1->1->2->3, return 2->3.
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
        ListNode * prev = NULL, * current = head;
        while(current) {
            if(current->next && current->val == current->next->val) {
                ListNode * d_head = current;
                while(current && current->val == d_head->val) current = current->next;
                if(!prev) {
                    head = current;
                }
                else {
                    prev->next = current;
                }
                while(d_head != current) {
                    ListNode * tmp = d_head;
                    d_head = d_head->next;
                    free(tmp);
                }
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        
        return head;
    }
};