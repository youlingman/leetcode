/* Rotate Image

	Total Accepted: 14023 Total Submissions: 44699 My Submissions
	You are given an n x n 2D matrix representing an image.

	Rotate the image by 90 degrees (clockwise).

	Follow up:
	Could you do this in-place?
	
	First rotate by diagonal then rotate by vertical, or we can rotate every quad tuple
*/
// double rotate
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.size() <= 1) return;
        // rotate by diagonal first
        for(int i = 1; i < matrix.size(); i++)
        for(int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
        // then rotate by vertical
        for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[0].size() / 2; j++)
            swap(matrix[i][j], matrix[i][matrix[0].size() - j - 1]);
    }
};
// rotate every quad tuple, faster than double rotate
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int size = matrix.size() - 1;
        for(int i = 0; i < (matrix.size()/2); i ++) {
            for(int j = i; j < (matrix.size()-i-1); j ++)
            {
               // determine the matrix[i][j] quad
               int codinate_1[2] = {i, j}, codinate_2[2], codinate_3[2], codinate_4[2];
               if(i == j) {
                   codinate_2[0] = codinate_1[0], codinate_2[1] = codinate_1[1] + size;
                   codinate_3[0] = codinate_2[0] + size, codinate_3[1] = codinate_2[1];
                   codinate_4[0] = codinate_3[0], codinate_4[1] = codinate_3[1] - size;
               }
               else {
                   codinate_2[0] = codinate_1[0] + (j-i), codinate_2[1] = codinate_1[1] + size - (j-i);
                   codinate_3[0] = codinate_2[0] + size - (j-i), codinate_3[1] = codinate_2[1] - (j-i);
                   codinate_4[0] = codinate_3[0] - (j-i), codinate_4[1] = codinate_3[1] - size + (j-i);                   
               }
               // rotate the matrix[i][j] quad
               int tmp = matrix[codinate_1[0]][codinate_1[1]];
               matrix[codinate_1[0]][codinate_1[1]] = matrix[codinate_4[0]][codinate_4[1]];
               matrix[codinate_4[0]][codinate_4[1]] = matrix[codinate_3[0]][codinate_3[1]];
               matrix[codinate_3[0]][codinate_3[1]] = matrix[codinate_2[0]][codinate_2[1]];
               matrix[codinate_2[0]][codinate_2[1]] = tmp;
            }
            size -= 2;
        }
        return;
    }
};