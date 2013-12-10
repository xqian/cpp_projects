http://oj.leetcode.com/problems/restore-ip-addresses/

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

Solution: 1) DFS
	  2) Only 4 parts for ip address. 
	  3) Credit to: https://github.com/AnnieKim/LeetCode/blob/master/RestoreIPAddresses.h

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        string ip;
        DFS(s,0,0,ip,result);
        return result;
    }
    
    //DFS
    void DFS(string s, int index, int part, string ip, vector<string> &result)
    {
        //base
        if (index == s.size() && part == 4){
            result.push_back(ip);
        }
        
        if (part == 4) return;
        
        //extenstion
        string tmp = ip;
        
        if (ip.size() != 0 ) ip += '.';
        
        int num = 0;
        for (int i=index; i<s.size(); i++){
            num = num * 10 + s[i]-'0';
            if (num > 255) break;
            
            ip += s[i];
            DFS(s, i+1, part+1, ip, result);
            
            if (num == 0) break;
        }
        
        //recover
        ip = tmp;
    }
};


Method 2: cut branch by size. And use pass string by value (vs reference) to reduce code complexity.
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
     vector<string> res;
     dfs(s,0,0,"",res);
     return res;
    }
    
    void dfs(const string &s, int index, int part, string ip, vector<string> &res){
        //cut
        if (s.size() - index > (4-part)*3) return;
        if (s.size() - index < 4 - part) return;
        
        //base
        if (index == s.size() && part == 4){
            ip.resize(ip.size()-1);
            res.push_back(ip); //remove last '.'
            return;
        }
        
        //extension
        int num = 0;
        for (int i=index;i<s.size();++i){
            num = num * 10 + s[i] - '0';
            if (num > 255) break;
            
            dfs(s,i+1, part+1, ip + s.substr(index,i-index+1) + '.',res);
            if (num==0) break; //allow only one 0 in each part and not leading 0.
        }
     }
};
