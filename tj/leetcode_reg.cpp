//Leetcode
//Notice: isMatch(char, char)
//. can not match \0

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s == NULL && p == NULL) return true;
        if (s == NULL || p == NULL) return false;
        if ( *s == '\0' && *p == '\0') return true;
        if ( *p == '\0') return false;
        if ( *(p+1) == '*') {
            return isMatchStar(s, *p, p+2);
        }
        else if (isMatch(*s, *p)) {
            return isMatch(s+1, p+1);
        }
        else {
            return false;
        } 
    }
    
    bool isMatchStar(const char *s, char ch, const char *p) {
        if ( isMatch(s, p)) return true;
        if ( isMatch(*s, ch)) {
            return isMatchStar(s+1, ch, p);
        }
        else {
            return false;
        }
    }
    
    bool isMatch(char ch1, char ch2) {
        if ( ch2 == '.' && ch1 != '\0' || ch1 == ch2) return true;
        else return false;
    }
};