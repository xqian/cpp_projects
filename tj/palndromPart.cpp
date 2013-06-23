//Make some stupid mistakes
class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( s.length() <=1) return 0;
        vector<vector<int> > palLens(s.length(), vector<int>(1,1)); //palLens[i] is the lengths of palindrome start with i;
        checkPal(s, palLens); //forget to call this function!!!
        //TRY TO COMPLETE CODE IN THE FIRST TIME
        vector<int> numSeg(s.length(), 0); //number of palindrom segmentations
        calSeg(s.length(), numSeg, 0, palLens);
        return numSeg[0]-1;
    }
    
    void calSeg(int totalLen, vector<int> & numSeg, int cur, const vector<vector<int> > & palLens) {
        if ( numSeg[cur] != 0) return;
        int t = INT_MAX;
        for(int i=0; i < palLens[cur].size(); ++i) {
            if ( cur + palLens[cur][i] < totalLen ) {
                calSeg(totalLen, numSeg, cur + palLens[cur][i], palLens);
                t = min(t, 1+numSeg[cur+palLens[cur][i]]);
            }
            else {
                t = 1;
                break;
            }
        }
        numSeg[cur] = t;
    }
    
    void checkPal(const string & s, vector<vector<int> > & palLens) {
        for(int pivot = 1; pivot < s.length()-1; ++pivot) {
            int halfLen = getEqlSubLen(s, pivot-1, pivot+1);
            if ( halfLen > 0) {
                for(int i=1; i <=halfLen;++i) {
                    palLens[pivot-i].push_back(i*2 + 1);
                }            
            }
        }    
        for(int pivot = 0; pivot < s.length()-1; ++pivot) {
            int halfLen = getEqlSubLen(s, pivot, pivot+1);
            if( halfLen > 0) {
                for(int i=1; i <= halfLen; ++i) {
                    palLens[pivot-i+1].push_back(i*2); //BUG: missing this loop
                }
            }
        }
    }
    
    int getEqlSubLen(const string & s, int left, int right) {
        int len = 0;
        while( left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            len++;
        }
        return len;
    }
};