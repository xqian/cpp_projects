/*Though this is the best sulution I can think of, I still do not feel confident to 
  write it in an interview. Too easy to make mistakes
  
  And there are some tricks I should rembmer, 
  e.g., how to map, how to return substr
  
  However, this problem also expose my weaknesses
  1) I sledom use size_t before, so just size_t < 0
  2) == is higher than &, actually == is higher than &&, & is a little bit higher than &
     similarly, > is higher than &&, so >> is higher than &
     actually >> is higher than >
  */
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        /*
        s[0], s[1], xxx s[n-1] 
        0, s[0], 0, s[1], 0 ... s[n-1], 0
        total length is 2n+1
        
        map: 1, 3, 5 .. 2n-1 is original char
        0, 2, ....2n are imaginary char
        
        xxxxxaxx, suppose pal is 3, then first is a - 2
        
        BUG: after first I map to
        s[0] 0 s[1] 0 s[2] 0 ... s[n-1]
        */
        size_t len = s.length();
        vector<size_t> palLen(2 * len + 1, -1);
        palLen[0] = palLen[2*len] = 1;
        size_t longestpalLenPivot = 0;
        size_t pivot = 0;
        
        for(size_t i=1; i < 2*len;++i) {
            int posToCmp = palLen[pivot] + pivot;
            if ( posToCmp <= i+1) {
                posToCmp = i+1;
            }
            else {
                if (pivot - (i-pivot) >=0 && posToCmp > i + palLen[ pivot - (i-pivot)]) {
                    palLen[i] = palLen[pivot - (i-pivot)];
                    continue; //BUG:break!!!
                }
            }
            palLen[i] = getPalLen(s, i, posToCmp);
            if ( palLen[longestpalLenPivot] < palLen[i]) {
                longestpalLenPivot = i;
            }
            pivot = i;
        }
        
        return s.substr( (longestpalLenPivot - palLen[longestpalLenPivot] +1)/2, palLen[longestpalLenPivot] -1); //BUG: I write length palLen[longestpalLenPivot] -1.
        
        
    }
    
private:
    int getPalLen(const string & s, size_t pivot, size_t start) {
        int leftEdge = pivot - (start - pivot);
        
        while( isEqual(s, leftEdge, start)) {
            leftEdge--;
            start++;
        }
        return start - pivot;
    }
    
    bool isEqual(const string & s, size_t left, size_t right) {
        if ( (int)left < 0 || right  > 2 * s.length()) return false; //Use left < 0. Notice before I use int, now use size_t
        //cout << (right - left) & 0x1; //BUG: missing (), << is higher than &
    	assert( ((left - right) & 0x1) == 0); //BUG: missing () == is higher than &

        if ( (left & 0x1) == 0 ) return true;
        return s[left >> 1] == s[right >> 1];
    }
};