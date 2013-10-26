http://oj.leetcode.com/problems/anagrams/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        map<string,vector<string> > dict;
        vector<string> result;
        
        for (int i=0; i<strs.size();i++){
            //compute hash
            string t = strs[i];
            sort(t.begin(),t.end());
            dict[t].push_back(strs[i]);
        }
        
        //output
        for (map<string,vector<string> >::iterator it = dict.begin();it != dict.end(); it++){
            if (it->second.size() > 1) {
                for (int k=0; k <it->second.size(); k++)
                {
                    result.push_back(it->second[k]);   
                }
            }
        }
        
        return result;
    }
};
