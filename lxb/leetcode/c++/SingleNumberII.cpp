http://oj.leetcode.com/problems/single-number-ii/

// Method 2: O(1) extra space
// Refer http://www.mitbbs.com/article_t/JobHunting/32547143.html
class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int count[32]={0};
        int result = 0;
        
        for (int i=0; i<32; i++)
        {
            for (int j=0; j<n; j++){
                if (A[j] >> i & 1) {
                    count[i] = (count[i] + 1) % 3;
                }
            }
            
            result |= count[i] << i;    
        }
        
        return result;
    }
};

//Method 1
class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        map<int,int> S;
        for (int i=0;i<n;i++){
            if (S.find(A[i]) == S.end())  S[A[i]] = 1; 
            else S[A[i]]++;
        }
        
        for (int i=0; i<n;i++){
            if (S[A[i]] == 1) return A[i];
        }
        
    }
};
