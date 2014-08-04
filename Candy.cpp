/* Candy

	There are N children standing in a line. Each child is assigned a rating value.

	You are giving candies to these children subjected to the following requirements:

	Each child must have at least one candy.
	Children with a higher rating get more candies than their neighbors.
	What is the minimum candies you must give?
	
	Scan from left to right to satisfy every child compare to their left neighbor, then scan from right to left to satisfy them compare to their right neighbor, then you get the minimum candies to give.
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        int candy[size];
        candy[0] = 1;
        for(int i = 1; i < size; i++) {
            if(ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
            else candy[i] = 1;
        }
        for(int i = size - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) candy[i] = max(candy[i + 1] + 1, candy[i]);
        }
        int ans = 0;
        for(int i = 0; i < size; i++) ans += candy[i];
        return ans;
    }
};