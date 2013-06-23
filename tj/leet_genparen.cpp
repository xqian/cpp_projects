class Solution {
private:
    
    
    void generate(vector<string> & res, char * buf, int numLeft, int numRight, int pos) {
        if ( numLeft == 0 && numRight == 0) {
            res.push_back(buf);
    
            return;
        }
        if( numLeft > 0) {
            buf[pos] = '(';
            generate(res, buf, numLeft -1, numRight, pos+1);
        }
        if( numRight > numLeft) {
            buf[pos] = ')';
            generate(res, buf, numLeft, numRight-1, pos+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       char * buf = new char[2 * n +1];
       buf[2*n] = '\0';
       
       int numLeft = n;
       int numRight = n;
       vector<string> res;
       generate(res, buf, numLeft, numRight, 0);
       return res;
    }
};
