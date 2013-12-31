http://oj.leetcode.com/problems/valid-parentheses/
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

Solution: stack + table

Method 2: using table to replace the switch. More readable, easy to maintain
class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        //special case
        if (s == "") return true;
        map<char,char> table;
        table['}'] = '{';
        table[']'] = '[';
        table[')'] = '(';
        
        stack<char> Stack;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')  {
                Stack.push(s[i]);
            }else{
                if (Stack.empty()) return false;
                
                if (Stack.top() != table[s[i]]) return false;
                Stack.pop();
            }
        }
        
        if (Stack.empty()) return true;
        
        return false;
    }
};

Method 1:
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

