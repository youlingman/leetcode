/* Partition List

	Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

	You should preserve the original relative order of the nodes in each of the two partitions.

	For example,
	Given 1->4->3->2->5->2 and x = 3,
	return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        if(!head) return head;
        ListNode * head_1 = NULL, * tail_1 = NULL, * head_2 = NULL, * tail_2 = NULL;
        while(head) {
            if(head->val < x) {
                if(head_1 == NULL) {
                    head_1 = head;
                    tail_1 = head;
                }
                else {
                    tail_1->next = head;
                    tail_1 = head;
                }
            }
            else {
                if(head_2 == NULL) {
                    head_2 = head;
                    tail_2 = head;
                }
                else {
                    tail_2->next = head;
                    tail_2 = head;
                }
            }
            head = head->next;
        }
        if(head_1 == NULL) head_1 = head_2;
        else tail_1->next = head_2;
        if(head_2 != NULL) tail_2->next = NULL;
        return head_1;
    }
};