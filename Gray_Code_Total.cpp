/* Gray Code Total

	The gray code is a binary numeral system where two successive values differ in only one bit.

	Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

	For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

	00 - 0
	01 - 1
	11 - 3
	10 - 2
	Note:
	For a given n, a gray code sequence is not uniquely defined.

	For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

	For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
	
	Reverse gray code sequence of n bit, add a '1' to the highest bit, append them to the origin sequence, this can make a gray code sequence of n + 1 bit.
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1;
        for(int i = 0; i < n; i++) size *= 2;
        vector<int> ans(size);
        size = 1;
        for(int i = 0; i < n; i++) {
            if(i == 1) ans[0] = 0;
            for(int j = size; j < 2 * size; j++) ans[j] = ans[2 * size - j - 1] + size;
            size *= 2;
        }
        return ans;
    }
};