/* Set Matrix Zeroes

	Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

	Follow up:
	Did you use extra space?
	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space, but still not the best solution.
	Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() == 0) return;
        // store the set_zero flag to first row and column
        // use two extra int to store set_zero flag for first row / column
        int first_row = 1, first_column = 1;
        for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 0) {
                if(i == 0) first_row = 0;
                else matrix[i][0] = 0;
                if(j == 0) first_column = 0;
                else matrix[0][j] = 0;
            }
        }
        // set zero for non-first row
        for(int i = 1; i < matrix.size(); i++)
            if(matrix[i][0] == 0)
            for(int j = 1; j < matrix[0].size(); j++) matrix[i][j] = 0;
        // set zero for non-first column
        for(int j = 1; j < matrix[0].size(); j++)
            if(matrix[0][j] == 0)
            for(int i = 1; i < matrix.size(); i++) matrix[i][j] = 0;
        // set zero for first row / column
        if(first_column == 0)
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        if(first_row == 0)
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        return;
    }
};