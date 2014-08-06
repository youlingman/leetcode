/* Single Number II

	Given an array of integers, every element appears three times except for one. Find that single one.

	Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
	
	Use ternary bit adding without carrying to reach O(n) time and O(1) space. The truth table for ternary adding as below.
	
	num    high low    next_high next_low
	0         0   0            0        0
	0         0   1            0        1
	0         1   0            1        0
	1         0   0            0        1
	1         0   1            1        0
	1         1   0            0        0
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        // ternary add without carrying
        int high = 0, low = 0;
        for(int i = 0; i < n; i++) {
            int next_low = (~A[i] & ~high & low) | (A[i] & ~high & ~low);
            int next_high = (~A[i] & high & ~low) | (A[i] & high & ~low);
            low = next_low;
            high = next_high;
        }
        return low;
    }
};