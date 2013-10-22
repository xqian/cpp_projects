http://oj.leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.  
        if (*p == '\0') return (*s == '\0');
        
        if (*(p+1) != '*'){
            if (*s == *p || ( *p == '.' && *s != '\0')) return isMatch(s+1,p+1);
            return false;
            
        }else{
            while ( *s == *p || *p == '.' && *s !='\0' ){
                if ( isMatch(s,p+2) == true ) return true;
                s++;
            }
            
            return isMatch(s,p+2);
        }
        
    }
};
