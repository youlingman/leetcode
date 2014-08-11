/* Linked List Cycle

	Given a linked list, determine if it has a cycle in it.

	Follow up:
	Can you solve it without using extra space?
	
	Use two pointer from head, one incr one step and the other incr two step each time,
	if two pointer encounter then the linked list has cycle.
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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode * p1 = head, * p2 = head;
        while(p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(!p2) return false;
            p2 = p2->next;
            if(p1 == p2) return true;
        }
        return false;
    }
};