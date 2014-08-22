/* First Missing Positive

	Given an unsorted integer array, find the first missing positive integer.

	For example,
	Given [1,2,0] return 3,
	and [3,4,-1,1] return 2.

	Your algorithm should run in O(n) time and uses constant space.
	
	Use bucket sort to reach O(n) time and constant space.
*/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n;) {
            if(A[i] > 0 && A[i] < n && A[i] != i && A[A[i]] != A[i])
                swap(A[i], A[A[i]]);
            else i++;
        }
        for(int i = 1; i < n; i++)
            if(A[i] != i) return i;
        if(A[0] == n) return n + 1;
        else return n;
    }
};