/* Linked List Cycle II

	Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

	Follow up:
	Can you solve it without using extra space?
	
	Use two pointer algorithm from "Linked List Cycle" to get the encounter point p, then start from head and p together to get another encounter point p2, p2 is where the cycle begins.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode * p1 = head, * p2 = head;
        while(p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(!p2) break;
            p2 = p2->next;
            // get the encounter point
            if(p1 == p2) {
                while(head != p1) {
                    head = head->next;
                    p1 = p1->next;
                }
                return head;
            }
        }
        return NULL;
    }
};