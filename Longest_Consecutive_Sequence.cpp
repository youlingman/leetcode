/* Longest Consecutive Sequence

	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

	For example,
	Given [100, 4, 200, 1, 3, 2],
	The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

	Your algorithm should run in O(n) complexity.
	
	Use a mapping<key, value> to store consecutive ranges, the value is the farthest bond(upper or lower) to key. For every new key, merge the adjacent consecutive range if possible by update the mapping, and update the ans afterwards.
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int ans = 0;
        if(num.size() == 0) return ans;
        unordered_map<int, int> mapping;
        for(int i = 0; i < num.size(); i++) {
            if(mapping.count(num[i])) continue;
			// the init range is itself only
            int lower_bond = num[i], upper_bond = num[i];
            if(mapping.count(num[i] - 1)) lower_bond = mapping[num[i] - 1];
            if(mapping.count(num[i] + 1)) upper_bond = mapping[num[i] + 1];
            mapping[num[i]] = num[i];
			// merge adjacent consecutive range
            mapping[lower_bond] = upper_bond;
            mapping[upper_bond] = lower_bond;
			// update ans
			ans = max(ans, upper_bond - lower_bond + 1);
        }
        return ans;
    }
};