/* Remove Nth Node From End of List

	Given a linked list, remove the nth node from the end of list and return its head.

	For example,

		Given linked list: 1->2->3->4->5, and n = 2.

		After removing the second node from the end, the linked list becomes 1->2->3->5.
	Note:
	Given n will always be valid.
	Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode * p1 = head, * p2 = NULL;
        while(n > 0) {
            p1 = p1->next;
            n--;
        }
        while(p1 != NULL) {
            p1 = p1->next;
            if(p2 == NULL) p2 = head;
            else p2 = p2->next;
        }
        ListNode * remove;
        if(p2 == NULL) {
            remove = head;
            head = head->next;
        }
        else {
            remove = p2->next;
            p2->next = remove->next;
        }
        if(remove != NULL) free(remove);
        return head;
    }
};