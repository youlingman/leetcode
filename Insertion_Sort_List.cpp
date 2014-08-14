/* Insertion Sort List

	Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL) return head;
        ListNode * current = head, * prev = NULL;
        while(current != NULL) {
            ListNode * after = head, * before = NULL;
            while(after != current) {
                // reach the insert point
                if(current->val < after->val) {
                    prev->next = current->next;
                    current->next = after;
                    // insert to the head
                    if(before == NULL) {
                        head = current;
                    }
                    // insert in the middle
                    else {
                        before->next = current;
                    }
                    current = prev->next;
                    break;
                }
                // check next point
                else {
                    before = after;
                    after = after->next;
                }
            }
            // current item already in right place, sort next item
            if(after == current) {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};