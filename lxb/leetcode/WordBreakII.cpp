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

Method 1: DP + DFS.
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

Method 2: DP make a judge whether existing one solution only. DFS to find all the solution.No DP involved in DFS.
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<string> res;
        if (!isBreakable(s, dict)) return res;
        
        vector<string> oneSol;
        DFS(s, 0, oneSol, dict, res);
        return res;
    }
    
    
private:
    void DFS(const string &s, const int index, vector<string> &sol, unordered_set<string> &dict, vector<string> &res)
    {
        if (index == s.size())
        {
            addOneResult(sol,res);
            return;
        }
        
        for (int i=index; i<s.size(); i++)
        {
            // DP[i] start from 1.
            if (dict.find(s.substr(index, i-index+1)) != dict.end()){
                sol.push_back(s.substr(index,i-index+1));
                DFS(s, i+1, sol, dict, res);
                sol.pop_back();
            }
        }
    }
    
    void addOneResult(const vector<string> &str, vector<string> &res){
        string s;
        for (auto &word:str)
        {
            s += word + ' ';
        }
        
        s.resize(s.size()-1);
        res.push_back(s);
    }
    
    bool isBreakable(const string &s, const unordered_set<string> &dict)
    {
        vector<bool> DP(s.size()+1,false); //DP[i] : 1..i is breakable
        DP[0] = true;
        
        for (int i=1; i<=s.size(); i++)
        for (int j=0; j<i; j++){
            if (DP[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                DP[i] = true;
                break;
            }    
        }
        
        return DP[s.size()];
    }
};

Method 3: Greatly simplified code. Removed push/pop with s+' ' stack variable.
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<string> res;
        if (!isBreakable(s, dict)) return res;
        
        string oneSol;
        DFS(s, 0, oneSol, dict, res);
        return res;
    }
    
    
private:
    void DFS(const string &s, const int index, string sol, unordered_set<string> &dict, vector<string> &res)
    {
        if (index == s.size())
        {
            sol.resize(sol.size()-1);
            res.push_back(sol);
            return;
        }
        
        for (int i=index; i<s.size(); i++)
        {
            // DP[i] start from 1.
            if (dict.find(s.substr(index, i-index+1)) != dict.end()){
                DFS(s, i+1, sol + s.substr(index,i-index+1) + ' ', dict, res);
            }
        }
    }
    
    bool isBreakable(const string &s, const unordered_set<string> &dict)
    {
        vector<bool> DP(s.size()+1,false); //DP[i] : 1..i is breakable
        DP[0] = true;
        
        for (int i=1; i<=s.size(); i++)
        for (int j=0; j<i; j++){
            if (DP[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                DP[i] = true;
                break;
            }    
        }
        
        return DP[s.size()];
    }
};
