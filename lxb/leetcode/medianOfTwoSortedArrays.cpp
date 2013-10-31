http://oj.leetcode.com/problems/median-of-two-sorted-arrays/

Note: Not pass
Submission Result: Wrong Answer

Input:	[1,2], [1,2]
Output:	1.00000
Expected:	1.50000

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if ((m+n) % 2 == 0){
            //even
            return (findMedian(A,m, B,n ,(m+n)/2) + findMedian(A,m, B,n , (m+n)/2+1) ) /2.0;
        }else{
            return findMedian(A,m, B,n, (m+n)/2+1);
        }
    }
    
    double findMedian(int A[], int m, int B[], int n, int k) {
        // handle special case
        if (m<=0) return B[k-1];
        if (n<=0) return A[k-1];
        if (k<=1) return min(A[0],B[0]);
        
        // two important factors: (m+n)/2+1 vs k, A[m/2] vs B[n/2]
        // Detail: http://fisherlei.blogspot.com/2012/12/leetcode-median-of-two-sorted-arrays.html
        // A[m/2] and B[n/2] divide A and B into 4 section
        // Section 1. A[0..m/2]    Section 2: A[m/2+1..m-1]
        // Section 3: B[0..n/2]    Section 4: B[n/2+1..n-2]
        
        if (m/2 +n/2 + 1> k){
            if (A[m/2] > B[n/2]){
                //drop Section 2.
                return findMedian(A,m/2, B, n , k-m/2);
            }else{
                //drop Section 4
                return findMedian(A,m, B,n/2, k-n/2);
            }
        }else{
            if (A[m/2] > B[n/2]){
                //drop Section 3
                return findMedian(A,m, B+n/2+1, n-(n/2+1), k-(n/2+1));
            }else{
                //drop Section 1
                return findMedian(A+m/2+1, m-(m/2+1), B,n, k-(m/2+1));
            }
        }
    }
};
