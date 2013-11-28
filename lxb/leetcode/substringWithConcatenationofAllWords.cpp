http://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/

/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

Solution: use unordered_map for word query. 

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string,int> need;
        unordered_map<string,int> found;
        
        vector<int> res;
        
        for (auto &str:L)   need[str]++;
        
        int wordSize = L[0].size();
        int patternSize = wordSize * L.size();
        
        if (S.size() < patternSize) return res;
        
        for (int i=0; i<=S.size()-patternSize; ++i)
        {
            found = need;

            for (int j=i; j<i+patternSize; j+=wordSize)
            {
                string word = S.substr(j,wordSize);
                auto it = found.find(word);
                if (it == found.end() || it->second == 0) break;

                if (--found[word]==0) found.erase(it);
            }
            
            if (found.size() == 0){
                res.push_back(i);
            }
        }
        
        return res;
    }
};
