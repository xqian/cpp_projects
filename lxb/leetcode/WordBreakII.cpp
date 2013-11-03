http://oj.leetcode.com/problems/word-break-ii/

/* Note: Not passed yet. There is some problem in the DP boundary part, need further check */

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
        
        vector<bool> DP(s.size()+1, false);  //DP[i] means 0..i is breakable.
        vector<vector<bool> > S(s.size()+1,vector<bool>(s.size(),false)); //S[i..j] whether str[i..j] is breakable
        DP[0] = true;
        
        for (int i=1; i<s.size()+1; i++)
        for (int j=i-1;j>=0; j--)
        {
            if (DP[j] && dict.find(s.substr(j,i-j+1)) != dict.end()) {
                DP[i] = true;
                S[j][i] = true;
                break;
            }
        }
        
        //0 row unused
        for (int k=0;k<s.size();k++){
            S[k][0] = true;
        }
        
        
        DFS(s, 0, oneSolution, result, dict, DP, S);
        return result;
    }
    
private:
    void DFS(string s, int index, vector<string> &oneSolution, vector<string> &result, unordered_set<string> &dict,vector<bool> &DP, vector<vector<bool> > &S)
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
            if (S[index][i]  == false) continue;
            //cut branch
            if (dict.find(s.substr(index,i-index+1)) != dict.end()){
                oneSolution.push_back(s.substr(index,i-index+1));
                DFS(s, i+1, oneSolution, result, dict, DP, S);
                //recovery
                oneSolution.pop_back();
            }
        }
    }
};
