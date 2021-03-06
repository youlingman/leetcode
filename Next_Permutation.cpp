/* Next Permutation

	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

	The replacement must be in-place, do not allocate extra memory.

	Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
	1,2,3 → 1,3,2
	3,2,1 → 1,2,3
	1,1,5 → 1,5,1
	
	Use algorithm from wiki: http://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int i, j;
        // find the largest index i which num[i] < num[i + 1]
        for(i = n - 2; i >= 0; i--)
            if(num[i] < num[i + 1]) break;
        if(i == -1) {
            reverse(num.begin(), num.end());
            return;
        }
        // get the largest index j which num[j] > num[i]
        for(j = n - 1; j > i; j--)
            if(num[j] > num[i]) break;
        // swap and reverse
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
    }
};