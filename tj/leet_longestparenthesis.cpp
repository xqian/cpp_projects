class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> len(s.length(),0);
        int i=0;
        while(i < s.length()) {
            if ( s[i] == '(') {
                i = calLen(s,i, len);
            }
            else {
                i++;
            }
        }
        int res = 0;
        i=0; 
        while(i < len.size()) {
            int t = 0;
            while ( i < len.size() && len[i] > 0) { //BUG: miss i < len.size()
                t += len[i];
                i += len[i];
            }
            if ( t != 0) res = max(res, t);
            else ++i;            
        }
        return res;
    }
    
    int calLen(const string & s, int cur, vector<int> & len) {
        if ( cur >= s.length() -1) return cur+1;
        int next = cur+1;
        while( next < s.length()) {
            if ( s[next] == ')') {
                len[cur] = next - cur + 1;
                return next+1;
            }
            next = calLen(s, next, len);
        }
        return next;
    }
    
};