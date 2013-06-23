class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> stk;
        for(int i=0; i < s.length(); ++i) {
            if ( s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else if (!stk.empty() && match(stk.top(), s[i]) ) {
                stk.pop();
            }
            else {
                return false;
            }
        }
        return stk.empty();
    }
    
    bool match(char ch1, char ch2) {
        if ( ch1 == '(' && ch2 == ')') return true;
        if ( ch1 == '{' && ch2 == '}') return true;
        if ( ch1 == '[' && ch2 == ']') return true;
        return false;
    }
};
