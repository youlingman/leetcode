/* Search in Rotated Sorted Array

	Suppose a sorted array is rotated at some pivot unknown to you beforehand.

	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

	You are given a target value to search. If found in the array return its index, otherwise return -1.

	You may assume no duplicate exists in the array.
	
	Try to solve it with binary search, the trick to clarify the problem is to judge which half the mid index locate.
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n == 0) return -1;
        
        int head = 0, tail = n - 1;
        while(head <= tail) {
            int mid = head + (tail - head) / 2;
            if(A[mid] == target) return mid;
            // mid in left half
            else if(A[mid] >= A[head]) {
                if(target < A[mid] && target >= A[head]) tail = mid - 1;
                else head = mid + 1;
            }
            // mid in right half
            else {
                if(target > A[mid] && target < A[head]) head = mid + 1;
                else tail = mid - 1;
            }
        }
        return -1;
    }
};