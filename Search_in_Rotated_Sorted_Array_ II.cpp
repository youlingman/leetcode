/* Search in Rotated Sorted Array II

	Follow up for "Search in Rotated Sorted Array":
	What if duplicates are allowed?

	Would this affect the run-time complexity? How and why?

	Write a function to determine if a given target is in the array.
	
	Follow up for "Search in Rotated Sorted Array", incr the head when you can't judge which half the mid index locate.
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n == 0) return -1;
        
        int head = 0, tail = n - 1;
        while(head <= tail) {
            int mid = head + (tail - head) / 2;
            if(A[mid] == target) return mid;
			// can't judge which half the mid locate
            else if(A[head] == A[mid] && A[mid] == A[tail]) head++;
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