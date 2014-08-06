/* 4Sum

	Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

	Note:
	Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
	The solution set must not contain duplicate quadruplets.
	
	Sort the array first and do a 3sum for every element, n the duplicate triples. The complexity is O(n^2).
*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if(num.size() < 4) return vector<vector<int> >();
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        for(int i = 0; i < num.size() - 3; i++) {
            if(i != 0 && num[i] == num[i - 1]) continue;
            for(int j = i + 1; j < num.size() - 2; j++) {
                if(j != (i + 1) && num[j] == num[j - 1]) continue;
                int head = j + 1, tail = num.size() - 1;
                while(head < tail) {
                    int sum = num[i] + num[j] + num[head] + num[tail];
                    if(sum == target) {
                        vector<int> tmp(4);
                        tmp[0] = num[i];
                        tmp[1] = num[j];
                        tmp[2] = num[head];
                        tmp[3] = num[tail];
                        ans.push_back(tmp);
                        head++;
                        while(head < tail && num[head] == num[head - 1]) head++;
                    }
                    else if(sum > target) tail--;
                    else head ++;
                }
            }
        }
        return ans;
    }
};