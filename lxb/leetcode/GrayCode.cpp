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
