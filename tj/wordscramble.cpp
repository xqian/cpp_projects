class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( s1.length() != s2.length() ) return false;
        if ( s1.length() == 0) return true;
        return isScramble(s1, 0, s2, 0, s1.length()); //BUG s1.length()-1             
    }
    
    bool isScramble(const string & s1, int start1, const string & s2, int start2, int len) {
        if ( !isAnagram(s1,start1, s2, start2, len) ) return false;
        if( len == 1) return true;
        for(int i=1; i <len; ++i) {
            if ( isAnagram(s1, start1, s2, start2, i) ) {
                if ( isScramble(s1, start1, s2, start2, i) && isScramble(s1, start1+i, s2, start2+i, len-i)) {
                    return true;
                }
            }
            else if ( isAnagram(s1, start1, s2, start2 + len - i, i) ) {
                if(isScramble(s1, start1, s2, start2 + len - i, i) && 
                   isScramble(s1, start1+i, s2, start2,len-i))             
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isAnagram(const string & s1, int start1, const string & s2, int start2, int len) {
        unordered_multiset<char> s; //BUG: forget multi
        for(int i=0; i < len; ++i) {
            s.insert(s1[start1+i]);
        }
        for(int i=0; i < len; ++i) {
            auto iter = s.find(s2[start2+i]);
            if (iter == s.end()) {
                return false;
            }
            else {
                s.erase(iter);
            }
        }
        return true;
    }
};