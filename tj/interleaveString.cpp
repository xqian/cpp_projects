class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if( s1.length() + s2.length() != s3.length()) return false;
        if( s1.length() == 0) return s2 == s3;
        if( s2.length() == 0) return s1 == s3;
            
        vector<vector<int> > isInter(s1.length()+1, vector<int>(s2.length()+1, -1));
        isInter[s1.length()][s2.length()] = 1;
        checkInter(s1,s2,s3,isInter,0,0);
        if( isInter[0][0] == 1) return true;
        else return false;
    }
    
    void checkInter(const string & s1, const string & s2, const string & s3, vector<vector<int> > & isInter,
            size_t start1, size_t start2) {
            if ( isInter[start1][start2] != -1) return;  
            if ( start1 < s1.length() &&  s1[start1] == s3[start1+start2]) {
                checkInter(s1, s2, s3, isInter, start1+1, start2);
                if( isInter[start1+1][start2] == 1) {
                    isInter[start1][start2] = 1;
                    return;
                }
            }
            if ( start2 < s2.length() && s2[start2] == s3[start1+start2]) {
                checkInter(s1, s2, s3, isInter, start1, start2+1);
                if ( isInter[start1][start2+1] == 1) {
                    isInter[start1][start2] = 1;
                    return;
                }
            }
            
            isInter[start1][start2] = 0;
            return;
         }
    
};