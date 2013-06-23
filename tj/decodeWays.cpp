//Miss a scenario 12
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( s.length() == 0) return 0;
        vector<int> num(s.length(), -1);
        getNum(s, num, 0);
        return num[0];
    }
    
    void getNum(const string & s, vector<int> & num, int cur) {
        if ( num[cur] != -1) return;
        if ( s[cur] == '0') {
            num[cur] = 0;
            return;
        }
        if ( cur == s.length()-1) {
            num[cur] = 1;
            return;
        }
        getNum(s, num, cur+1);
        int t = num[cur+1];

        if ( isValid(s[cur], s[cur+1]) )
        {    
            if ( cur < s.length() -2 ) {
                getNum(s, num, cur+2);
                t += num[cur+2];
            }
            else {
                t++;
            }
        }
        num[cur] = t;
    }
    
    bool isValid(char ch1, char ch2) {
        if ( ch1 == '1' ) return true;
        if ( ch1 == '2' && ch2 <= '6') return true;
        return false;
    }
};