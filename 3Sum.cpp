/* 3Sum

	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

	Note:
	Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
	The solution set must not contain duplicate triplets.
	
	Sort the array first and do a 2sum for every element, n the duplicate triples. The complexity is O(n^2).
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size() < 3) return ans;
        // sort the array
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i = 0; i <= n - 3; i++) {
            if(i != 0 && num[i] == num[i - 1]) continue;
            // 2sum search below
            int head = i + 1, tail = n - 1;
            while(head < tail) {
                int sum = num[head] + num[tail] + num[i];
                if(sum == 0) {
                    // pack a triple
                    vector<int> tmp(3);
                    tmp[0] = num[i];
                    tmp[1] = num[head];
                    tmp[2] = num[tail];
                    ans.push_back(tmp);
                    head++;
                    while(head < tail && num[head - 1] == num[head]) head++;
                }
                else if(sum > 0) tail--;
                else head++;
            }
        }
        return ans;
    }
};