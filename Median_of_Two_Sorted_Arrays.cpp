/* Median of Two Sorted Arrays

	There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
	
	Need some binary search to reach O(log (m+n)). The problem can be rewrite as 'find the kth elem in two sorted arrays', then we can compare the k/2 th elem from each array and reduce the problem size(k) by half.
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m + n) % 2 == 1) return (double) findK(A, m, B, n, (m + n) / 2 + 1);
        else return ((double)findK(A, m, B, n, (m + n) / 2) + (double)findK(A, m, B, n, (m + n) / 2 + 1)) / 2;
    }
    
private:
    int findK(int A[], int m, int B[], int n, int k) {
        if(m == 0) return B[k - 1];
        if(n == 0) return A[k - 1];
        if(k == 1) return min(A[0], B[0]);
        
        int pa = min(m, k / 2), pb = min(n, k - pa);
        if(A[pa - 1] == B[pb - 1]) return A[pa - 1];
        else if(A[pa - 1] < B[pb - 1]) return findK(A + pa, m - pa, B, n, k - pa);
        else return findK(A, m, B + pb, n - pb, k - pb);
    }
};