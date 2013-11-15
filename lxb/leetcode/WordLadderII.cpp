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

/* Super hard!!! How to build path in BFS? One failed try code listed here */
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<vector<string> > res;
        if (start.size() != end.size() || start.size() == 0) return res;
        
        queue<string> Q;
        Q.push(start);
        int level = 0;
        
        vector<string> solution;
        set<string> visited; //handle duplicate
        
        //bfs
        while(!Q.empty()){
            level++;
            int levelSize = Q.size();
            
            for (int i=0; i< levelSize; i++){
                string curr = Q.front(); Q.pop();
                solution.push_back(curr);
                if (curr == end){
                    //find one.
                    res.push_back(solution);
                }
                
                //handle neighbor
                for (int i=0; i<curr.size(); i++)
                {
                    for (char ch='a'; ch <='z'; ch++)
                    {
                        if (ch == curr[i]) continue;
                        
                        char tmp = curr[i];
                        curr[i] = ch;
                        if (dict.find(curr) != dict.end() && visited.find(curr) == visited.end()){
                            Q.push(curr);
                            visited.insert(curr);
                        }
                        
                        curr[i] = tmp;
                    }
                }
                
                //clean up
                solution.pop_back();
            }
        }
        
    }
};
