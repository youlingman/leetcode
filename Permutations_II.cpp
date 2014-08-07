/* Permutations II

	Given a collection of numbers that might contain duplicates, return all possible unique permutations.

	For example,
	[1,1,2] have the following unique permutations:
	[1,1,2], [1,2,1], and [2,1,1].
	
	Use dfs with some pruning to avoid duplicate leaf.
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> >  ans;
        if(num.size() <= 0) return ans;
        dfs(num, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    void dfs(vector<int> &num, vector<vector<int> > &ans, int head) {
        if(head >= num.size()) {
            ans.push_back(num);
            return;
        }
        dfs(num, ans, head + 1);
        for(int i = head + 1; i < num.size(); i++) {
            bool coti = false;
            for(int j = head; j < i; j++) if(num[j] == num[i]) coti = true;
            if(coti) continue;
            swap(num[i], num[head]);
            dfs(num, ans, head + 1);
            swap(num[i], num[head]);
        }
        return;
    }
};