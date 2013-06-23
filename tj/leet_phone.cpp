class Solution {
private:
    static const char *m[10];
    static int len[10];
    
    void combination(vector<string> & res, string digits, char * buf, char * loc, int pos) {
        if( pos == digits.length()) {
            *loc = '\0';
            res.push_back(string(buf));            
            return; //BUG 1 ---- forget to return
        }
        
        int cur = digits[pos] - '0'; //BUG 2 ---- '\0'
        assert(cur < 10 && cur >= 0);
        
        for(int i = 0; i < len[cur]; ++i) {
            *loc = m[cur][i];
            combination(res, digits, buf, loc+1, pos+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        int slen = digits.length();
        //if (slen == 0) return res;
        char * buf = new char[slen+1];
        buf[slen] = '\0';

    
        combination(res, digits, buf, buf, 0);
        return res;
    }
};

const char * Solution::m[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int Solution::len[10] = {1, 0, 3, 3,3,3,3,4,3,4};

