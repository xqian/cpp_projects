http://oj.leetcode.com/problems/median-of-two-sorted-arrays/

/*Question:
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

Solution:
1. binary search idea, narrow down scope.
2. Handle boundary case.
3. pa = min(m, k/2), pb = k-pa

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if ((m+n) & 1){
            return findMedian(A,m, B,n, (m+n)/2+1);
        }else{
            return (findMedian(A,m, B,n ,(m+n)/2) + findMedian(A,m, B,n , (m+n)/2+1) ) /2.0;
        }
    };

    double findMedian(int A[], int m, int B[], int n, int k) {
        if (m > n) return findMedian(B,n, A,m, k);

        // handle special case
        if (m==0) return B[k-1];
        if (k==1) return min(A[0],B[0]);

        int pa = min (m, k/2);
        int pb = k-pa;

        if (A[pa-1] < B[pb-1]){
            return findMedian(A+pa,m-pa, B, n ,k-pa);
        }else if (A[pa-1] > B[pb-1]){
            return findMedian(A, m , B+pb, n-pb, k-pb);
        }else{
            return A[pa-1];
        }
    }
};
