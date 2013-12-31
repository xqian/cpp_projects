http://oj.leetcode.com/problems/gray-code/
/*
Question:
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
/*Method  1*/
class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        int N = 1<<n;
        for (int i=0; i<N; i++){
            result.push_back(i ^ (i>>1));
        }
        
        return result;
    }
};

/*Method 2: Not PASS!??*/
#include <iostream>
#include <vector>
using namespace std;

/* it report one bug
Submission Result: Wrong Answer

Input:	1
Output:	[0,0]
Expected:	[0,1]
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<int> result;
        if (n==0) return result;
        
        assert(n>=1);
        
        vector<int> s(n,0);
        grayCodeHelper(0, n, s, result);
        
        return result;
    }
    
    void process(const vector<int> &s, vector<int> &result){
        int sum = 0;
        for (int i=0; i<s.size();i++)
        {
            sum = sum<<2+s[i];
        }
        
        result.push_back(sum);
    }
    
    
    void grayCodeHelper(int k, int n, vector<int> &s, vector<int> &result){
        //base
        if (k == n){
            process(s,result);
            return;
        }
    
        grayCodeHelper(k+1,n,s,result);
        s[k] = 1 - s[k];
        grayCodeHelper(k+1,n,s,result);
    }
};

int main()
{
	Solution S;
	vector<int> r = S.grayCode(1);
	for (int i=0; i<r.size();i++){
		cout<< "\t" << r[i];
	}
}
