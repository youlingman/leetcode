/* Merge k Sorted Lists

	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
	
	Use a k-size heap to reach O(n * log(k)) time complexity.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp > heap;
        ListNode * head = NULL, * current = NULL;
        for(int i = 0; i < lists.size(); i++)
            if(lists[i] != NULL) heap.push(lists[i]);
        while(!heap.empty()) {
            ListNode * tmp = heap.top();
            heap.pop();
            if(tmp->next != NULL) heap.push(tmp->next);
            if(head == NULL && current == NULL) head = tmp;
            else current->next = tmp;
            current = tmp;
        }
        return head;
    }

private:
    struct cmp{
        bool operator() ( ListNode * a, ListNode * b ){
            return a->val > b->val;
        }
    };
};