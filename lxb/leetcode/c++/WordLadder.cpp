http://oj.leetcode.com/problems/word-ladder/

Note: which words are the neighbor of 'hot'? just change one letter on each possible location.
/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (start.size() != end.size() || start.size() == 0) return 0;
        
        set<string> visited; //handle duplicate visit
        
        //BFS
        queue<string> Q;
        Q.push(start);
        int level = 0;
        
        while(!Q.empty()){
            level++;
            int levelSize = Q.size();
            
            // visit all node in that level
            for (int i=0; i<levelSize; i++){
                string curr = Q.front(); Q.pop();
                if (curr == end){
                    //find it
                    return level;
                }
            
                //mark it.
                visited.insert(curr);
            
                // handle neighbour
                for (int index=0; index<curr.size(); index++){
                    for (char ch='a'; ch <= 'z'; ch++){
                        if (ch == curr[index]) continue;
                        char oldChar = curr[index];
                        curr[index] = ch;
                    
                        // whether it's a possible target
                        if (dict.find(curr) != dict.end() && visited.find(curr) == visited.end()){
                            Q.push(curr);
                            visited.insert(curr);
                        }
                        
                        //recover back
                        curr[index] = oldChar;
                }
            }
        }//end for
        }//end while
        
        // not find a valid solution.
        return 0;
    }
};
