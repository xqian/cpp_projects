class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        //special case
        if (s == "") return true;
        
        stack<char> Stack;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')  {
                Stack.push(s[i]);
            }else{
                if (Stack.empty()) return false;
                
                char expect;
                switch(s[i]){
                    case '}':
                        expect = '{';
                        break;
                    case ']':
                        expect = '[';
                        break;
                    case ')':
                        expect = '(';
                        break;
                    default:
                        return false;
                        //wrong
                };
                
                if (Stack.top() != expect) return false;
                Stack.pop();
            }
        }
        
        if (Stack.empty()) return true;
        
        return false;
    }
};
