/* Reverse Linked List II

	Reverse a linked list from position m to n. Do it in-place and in one-pass.

	For example:
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,

	return 1->4->3->2->5->NULL.

	Note:
	Given m, n satisfy the following condition:
	1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode * ans = head, *prev = NULL, *post = NULL;
        ListNode * current = head, * tail = NULL;
        n = n - m;
        while(m > 1) {
            prev = current;
            current = current->next;
            m--;
        }
        tail = current;
        head = current;
        post = current->next;
        while(n > 0) {
            head = post;
            if(post !=NULL) post = post->next;
            head->next = current;
            current = head;
            n--;
        }
        tail->next = post;
        if(prev == NULL) ans = head;
        else prev->next = head;
        return ans;
    }
};