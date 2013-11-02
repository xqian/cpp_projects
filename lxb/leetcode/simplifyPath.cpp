http://oj.leetcode.com/problems/simplify-path/
/*
 Question:

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
class Solution {
public:
    string simplifyPath(string path) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<string> tokens;
        tokens = split(path, '/');
        stack<string> S;
        
        //put to stack.
        for (int i=0; i< tokens.size(); i++){
            if (tokens[i] == "..") {
                if (!S.empty()) S.pop();
            }
            
            else if (tokens[i] == "." || tokens[i] == "") continue;
            else S.push(tokens[i]);
        }
        
        string result="";
        if (S.empty()) return "/";
        
        while (!S.empty()){
            result = "/" + S.top() + result;
            S.pop();
        }
        
        return result == "" ? "/" : result;
    }
    
    vector<string> split(string str, char ch)
    {
        int start = 0;
        int end;
        vector<string> result;
        int i = 0;
        for (; i<str.size(); i++)
        {
            if (str[i] == '/'){
                //start..i-1
                result.push_back(str.substr(start,i-start));
                start=i+1;
            }
        }
        
        //posible last one.
        result.push_back(str.substr(start,i-start));
        
        return result;
    }
};
