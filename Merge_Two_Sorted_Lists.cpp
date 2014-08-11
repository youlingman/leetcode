/* Merge Two Sorted Lists

	Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode * head = NULL, * current = NULL;
        while(l1 != NULL || l2 != NULL) {
            ListNode * tmp;
            if(l1 == NULL || (l2 != NULL && l1->val > l2->val)) {
                tmp = l2;
                l2 = l2->next;
            }
            else {
                tmp = l1;
                l1 = l1->next;
            }
            if(head == NULL && current == NULL) head = tmp;
            else current->next = tmp;
            current = tmp;
        }
        return head;
    }
};