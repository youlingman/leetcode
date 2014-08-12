/* Rotate List

	Given a list, rotate the list to the right by k places, where k is non-negative.

	For example:
	Given 1->2->3->4->5->NULL and k = 2,
	return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        int size = 0;
        ListNode * tail = NULL, * current = head;
        // get size and tail node
        while(current != NULL) {
            size++;
            if(current->next == NULL) tail = current;
            current = current->next;
        }
        if(size <= 1) return head;
        // do rotate
        if(k % size == 0) return head;
        k = size - (k % size);
        current = head;
        while(k > 1) {
            current = current->next;
            k--;
        }
        tail->next = head;
        head = current->next;
        current->next = NULL;
        return head;
    }
};