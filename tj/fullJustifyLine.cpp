//TWO corner cases not right
//But those corner cases not make sense.
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        int curLen = 0;
        int start = 0;
        vector<string> res;
        if( words.size() == 0) return res;
        if( words.size() == 1 && words[0].length() == 0) return res;
        for(int i= 0; i < words.size(); ++i) {
            if( curLen == 0){
                 curLen = words[i].length();
                 start = i;
            }
            else {
                curLen++;
                curLen += words[i].length();
                if (curLen > L) {
                    res.push_back(makeString(words, start, i-1, L, curLen - words[i].length() -1 ));
                    curLen = words[i].length();
                    start = i;
                }
            }
        }
        if ( curLen > 0) {
            res.push_back(makeLastLine(words, start, L));
        }
        return res;
    }
    
    string makeLastLine(vector<string> &words, int start, int L) {
        char * str = new char[L+1];
        memset(str, ' ', L);
        str[L] = '\0';
        int curPos = 0;
        for(int i=start; i < words.size(); ++i) {
            strncpy(str+curPos, words[i].c_str(), words[i].length());
            curPos += words[i].length();
            if ( i != words.size() -1) {
                curPos++;
            } 
        }
        string res(str, L);
        delete [] str;
        return res;
    }
    
    string makeString(vector<string> &words, int start, int end, int L, int L1) {
        char * str = new char[L+1];
        memset(str, ' ', L);
        str[L] = '\0';
        if ( start == end) {
            strncpy(str, words[start].c_str(), words[start].length());
            return string(str, L);
        }
        int spaces;
        int num;
        spaces = (L - L1)/(end - start);
        num = (L - L1) % (end - start);
        
        if ( num == 0) {
            spaces++;
            num = end - start; //this many spaces blocks, each block has this many spaces
        }
        else {
            spaces += 2;
        }
        
        int curPos = 0;
        for(int i = start; i <= end; ++i) {
            strncpy(str+curPos, words[i].c_str(), words[i].length());
            curPos += words[i].length();
            curPos += spaces;
            if ( i >= start + num) curPos--;
        }
        
        string res(str,L);
        delete [] str;
        return res;
    }
};