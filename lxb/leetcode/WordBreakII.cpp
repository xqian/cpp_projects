http://oj.leetcode.com/problems/word-break-ii/

/* Question
 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
Discuss
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> oneSolution;
        vector<string> result;
        
        vector<bool> DP(s.size()+1, false);  //DP[i] means 1..i is breakable.
        
        //Can't make any
        if (wordBreakable(s, dict,DP) == false) return result;
        
        DFS(s, 0, oneSolution, result, dict, DP);
        return result;
    }
    
private:
    bool wordBreakable(string s, unordered_set<string> &dict, vector<bool> &DP)
    {
        DP[0] = true;
        
        for (int i=1; i<=s.size(); ++i)
        for (int j=0; j<i; ++j)
        {
            if (DP[j] && dict.find(s.substr(j,i-j)) != dict.end()) {
                DP[i] = true;
                break;
            }
        }
        
        return DP[s.size()];
    }
    
    void DFS(string s, int index, vector<string> &oneSolution, vector<string> &result, unordered_set<string> &dict,vector<bool> &DP)
    {
        //base
        if (index == s.size()){
            string str="";
            for (int i=0; i<oneSolution.size(); i++){
                str += oneSolution[i] + ' ';
            }
            
            //remove last ' ' by resize.
            str.resize(str.size()-1);
            
            result.push_back(str);
            return;
        }
        
        //extension
        for (int i=index ; i<s.size(); i++){
            // DP[i] means iTH character. so mapping to i+1.
            if (DP[i+1] == false) continue; 
            
            string word = s.substr(index,i-index+1);
            if (dict.find(word) != dict.end())
            {
                oneSolution.push_back(word);
                DFS(s, i+1, oneSolution, result, dict, DP);
                //recovery
                oneSolution.pop_back();
            }
        }
    }
};
