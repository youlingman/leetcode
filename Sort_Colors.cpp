/* First Missing Positive

	Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

	Note:
	You are not suppose to use the library's sort function for this problem.

	Follow up:
	A rather straight forward solution is a two-pass algorithm using counting sort.
	First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

	Could you come up with an one-pass algorithm using only constant space?
	
	Use two int to store index for last 0 and last 1, just like the 'partition' in quick sort.
*/
class Solution {
public:
    void sortColors(int A[], int n) {
        int p1 = -1, p2 = -1;
        for(int i = 0; i < n; i++) {
            if(A[i] < 1) {
                p1++;
                p2++;
                swap(A[i], A[p2]);
                swap(A[p1], A[p2]);
            }
            else if(A[i] == 1) {
                p2++;
                swap(A[i], A[p2]);
            }
        }
    }
};