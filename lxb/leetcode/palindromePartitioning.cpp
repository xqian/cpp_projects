http://oj.leetcode.com/problems/palindrome-partitioning/
Question:
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string> > result;
        
        if (s.size() == 0) return result;
        
        vector<int> index;
        index.push_back(-1);
        
        partitionDFS(s, 0 , result, index);
        return result;
    }
    
    void partitionDFS(string &s,int start, vector<vector<string> > &result, vector<int> &index)
    {
        if (start == s.size()){
            //extract subset and add into result
            vector<string> tempResult;
            for (int j=0;j<index.size()-1;j++){
                //tricky
                tempResult.push_back(s.substr(index[j]+1,index[j+1]-index[j]));
            }
            
            result.push_back(tempResult);
            return;
        }
        
        for (int i=start; i<s.size();i++){
            if (isPalindrome(s, start, i)){
                index.push_back(i);
                partitionDFS(s,i+1, result, index);
                
                //clean
                index.pop_back();
            }
        }
        
        return;
    }
    
    bool isPalindrome(string &s,int l, int r)
    {
        int i=l;
        int j=r;
        while (i<=j && s[i]==s[j]) {i++,j--;}
        
        return (i>j);
    }
};
