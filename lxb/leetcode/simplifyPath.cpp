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
