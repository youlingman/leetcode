/* Search Insert Position

	Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

	You may assume no duplicates in the array.

	Here are few examples.
	[1,3,5,6], 5 → 2
	[1,3,5,6], 2 → 1
	[1,3,5,6], 7 → 4
	[1,3,5,6], 0 → 0
	
	Upper bond binary search.
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int head = 0, tail = n - 1;
        while(head < tail) {
            int mid = head + (tail - head) / 2;
            if(A[mid] == target) return mid;
            else if(A[mid] > target) tail = mid - 1;
            else head = mid + 1;
        }
        if(A[head] < target) return head + 1;
        else return head;
    }
};