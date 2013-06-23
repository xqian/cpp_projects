//This is amazing. Did made some compiling mistakes but the code pass firs time
class Solution {
private:
    enum {
        PartLength = 3,
        IPV4PartNum = 4,
        MaxLength = 15
    };
    
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        char * buf = new char[MaxLength+1];
        parseIpAddress(s, 0, res, buf, 0, IPV4PartNum );
        delete [] buf;
        return res;
    }
    
    void parseIpAddress(const string & s, int cur1, vector<string> & res, char * buf, int cur2, int blocksNeed) {
        if ( blocksNeed * 3 < s.length() - cur1) {
            return;
        }
        if( blocksNeed > s.length() - cur1) {
            return;
        }
        
        for(int i=1; i <= PartLength; ++i) {
            if ( isValidWithLength(s,cur1,i)) {
                strncpy(buf+cur2,s.c_str()+cur1, i);
                if (blocksNeed != 1) {
                   buf[cur2+i] = '.';
                   parseIpAddress(s, cur1+i, res, buf, cur2+i+1, blocksNeed-1);
                }             
                else if ( cur1+i == s.length()) {
                    res.push_back(string(buf, cur2+i));
                }
           }
        }
        
    }
    
    bool isValidWithLength(const string & s, int cur, int len) {
        if( cur+len > s.length()) return false;
        if ( len == 1) return true;
        else if ( len == 2) {
            if( s[cur] == '0') return false;
            else return true;
        }
        else if ( len == 3) {
            if( s[cur] == '0' || s[cur] >= '3') return false;
            if( s[cur] == '1') return true;
            if( s[cur+1] <='4') return true;
            if( s[cur+1] >='6') return false;
            if( s[cur+2] <= '5') return true;
        }
        return false;
    }
};