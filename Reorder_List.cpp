/* Reorder List

	Given a singly linked list L: L0→L1→…→Ln-1→Ln,
	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

	You must do this in-place without altering the nodes' values.

	For example,
	Given {1,2,3,4}, reorder it to {1,4,2,3}.
	
	Break the list in half, reverse the second half and merge two half to reach O(n) time and O(1) space complexity.
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
    void reorderList(ListNode *head) {
        if(head == NULL) return;
        // get size of the list
        int size = get_size(head);
        // reverse the second_half list
        ListNode * current = head;
        for(int i = 0; i < size / 2; i ++) current = current->next;
        ListNode * second = reverse(current->next);
        current->next = NULL;
        // merge first half and second half
        ListNode * first = head;
        while(first != NULL && second != NULL) {
            ListNode * next_first = first->next, * next_second = second->next;
            first->next = second;
            second->next = next_first;
            first = next_first;
            second = next_second;
        }
    }

private:
    ListNode * reverse(ListNode * head) {
        if(head == NULL) return NULL;
        ListNode * prev = head, * current = head->next, * tail = NULL;
        prev->next = NULL;
        while(current != NULL) {
            tail = current->next;
            current->next = prev;
            prev = current;
            current = tail;
        }
        return prev;
    }
    
    int get_size(ListNode * head) {
        int size = 0;
        while(head != NULL) {
            size++;
            head = head->next;
        }
        return size;
    }
};