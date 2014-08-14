/* Copy List with Random Pointer

	A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

	Return a deep copy of the list.
	
	A tricky way to solve it with copying a shadow list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return head;
        // copy shadow list
        RandomListNode * current = head;
        while(current != NULL) {
            RandomListNode * tmp = new RandomListNode(current->label);
            tmp->next = current->next;
            current->next = tmp;
            current = tmp->next;
        }
        // add random to shadow list
        current = head;
        while(current != NULL) {
            if(current->random != NULL) current->next->random = current->random->next;
            else current->next->random = NULL;
            current = current->next->next;
        }
        // break shadow list apart
        RandomListNode *ans = head->next;
        current = ans;
        while(current != NULL) {
            head->next = current->next;
            head = head->next;
            if(head == NULL) current->next = NULL;
            else current->next = head->next;
            current = current->next;
        }
        return ans;
    }
};