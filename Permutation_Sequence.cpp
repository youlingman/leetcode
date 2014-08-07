/* Permutation Sequence

	The set [1,2,3,…,n] contains a total of n! unique permutations.

	By listing and labeling all of the permutations in order,
	We get the following sequence (ie, for n = 3):

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"
	Given n and k, return the kth permutation sequence.

	Note: Given n will be between 1 and 9 inclusive.
	
	Solve it recursively. Use (k - 1) / sum + 1 to get the head char first, then get the tail string for (n - 1, (k - 1) % sum + 1),
	keep the order in tail string but incr every char bigger or equal to head, then connect head and tail to get the ans.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        if(n == 0) return ans;
        if(n == 1) return "1";
        int sum = 1;
        for(int i = 1; i < n; i++) sum *= i;
        int head = (k - 1) / sum + 1;
        string tail = getPermutation(n - 1, (k - 1) % sum + 1);
        for(int i = 0; i < tail.size(); i++)
            if(tail[i] >= head + '0') tail[i]++;
        ans += (head + '0');
        ans += tail;
        return ans;
    }
};