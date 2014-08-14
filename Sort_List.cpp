/* Sort List

	Sort a linked list in O(n log n) time using constant space complexity.
	
	Use merge sort.
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
    ListNode *sortList(ListNode *head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        // break the list in half
        ListNode * middle = get_middle(head);
        ListNode * second = middle->next;
        middle->next = NULL;
        // sort two half list
        ListNode * first = sortList(head);
        second = sortList(second);
        // merge two sorted list
        head = merge(first, second);
        return head;
    }
    
private:
    ListNode * get_middle(ListNode * head) {
        ListNode * first = head, * second = head;
        while(second != NULL) {
            second = second->next;
            if(second == NULL) break;
            else second = second->next;
            if(second == NULL) break;
            first = first->next;
        }
        return first;
    }
    
    ListNode * merge(ListNode * first, ListNode * second) {
        ListNode * ans = NULL, * current = NULL;
        while(first != NULL || second != NULL) {
            ListNode * tmp;
            if(first == NULL || (second != NULL && first->val > second->val)) {
                tmp = second;
                second = second->next;
            }
            else {
                tmp = first;
                first = first->next;
            }
            if(ans == NULL && current == NULL) ans = tmp;
            else current->next = tmp;
            current = tmp;
        }
        return ans;
    }
};