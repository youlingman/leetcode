/* Trapping Rain Water

	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

	For example, 
	Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
	
	The water the ith bar can trap is determined by the highest bar in left and right and the height itself. 
*/
class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0) return 0;
        int right_bond[n], left_bond[n];
        left_bond[0] = A[0];
        right_bond[n - 1] = A[n - 1];
        for(int i = 1; i < n; i++) {
            left_bond[i] = max(A[i], left_bond[i - 1]);
            right_bond[n - i - 1] = max(A[n - i - 1], right_bond[n - i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += max(min(left_bond[i], right_bond[i]), A[i]) - A[i];
        }
        return ans;
    }
};