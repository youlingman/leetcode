/* Search for a Range

	Given a sorted array of integers, find the starting and ending position of a given target value.

	Your algorithm's runtime complexity must be in the order of O(log n).

	If the target is not found in the array, return [-1, -1].

	For example,
	Given [5, 7, 7, 8, 8, 10] and target value 8,
	return [3, 4].
	
	Binary search for lower and upper bond.
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = binary_search(A, n, target, 0);
        int upper = binary_search(A, n, target, 1);
        vector<int> ans;
        ans.push_back(lower);
        ans.push_back(upper);
        return ans;
    }
private:
    int binary_search(int A[], int n, int target, int type) {
        int head = 0, tail = n - 1;
        while(head <= tail) {
            int mid = head + (tail - head) / 2;
            if(A[mid] > target) tail = mid - 1; 
            else if(A[mid] < target) head = mid + 1;
            else if(type == 0) tail = mid - 1;
            else if(type == 1) head = mid + 1;
        }
        if(type == 0 && A[head] == target) return head;
        else if(type == 1 && A[tail] == target) return tail;
        else return -1;
    }
};