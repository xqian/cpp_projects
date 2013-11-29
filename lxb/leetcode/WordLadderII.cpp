http://oj.leetcode.com/problems/word-ladder-ii/
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

Solution: 1. Super hard!!! 
	  2. How to build path in BFS? backtrace.

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       
       unordered_set<string> visited; //duplicate detection
       unordered_map<string, vector<string> > father; //trace 
       unordered_set<string> current, next; //BFS, visit per level.
       
       bool found = false;
       current.insert(start);
       dict.insert(end);  // this will greatly reduce the possible comparation.
       
       while(!current.empty() && !found)
       {
           for (auto word:current) visited.insert(word);  //mark this level
           
           for (auto word:current){
               for (int i=0; i<word.size(); i++){
                    string new_word = word;

                    //extend neighbor.
                    for (char c='a';c<='z'; c++){
                        if (c == new_word[i]) continue;
                        
                        swap(c, new_word[i]);
                        
                        if (new_word == end) found = true;
                        
                        if ( visited.find(new_word) == visited.end() && dict.find(new_word) != dict.end())
                        {
                            next.insert(new_word);
                            father[new_word].push_back(word);  //trace it!
                        }
                        
                        swap(c, new_word[i]);
                    }
               }
           }
           
           current.clear();
           swap(current, next);
       }
       
       //now build result.
       vector<vector<string> > res;
       
       if (found){
           vector<string> path;
           buildPath(father, path, start, end, res);
       }
       
       return res;
    }
    
private:
    //traceback
    void buildPath(unordered_map<string, vector<string> > &father, vector<string> &path, const string &start, const string &word, vector<vector<string> > &res)
    {
        //similary to DFS.
        path.push_back(word);
        
        if (word == start){
            //find one.
            res.push_back(path);
            reverse(res.back().begin(),res.back().end());
        }else{
            for (auto f: father[word]){
                buildPath(father, path, start, f, res);
            }
        }
        
        //recovery
        path.pop_back();
    }
};
