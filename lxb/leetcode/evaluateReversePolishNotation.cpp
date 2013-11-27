http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

Solution: stack. If meet operatnum, put into stack. otherwise, pop two number for compute.
	  2. detail. atoi(str1.c_str()), enum

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<int> S;
        
        for (auto &token:tokens){
            switch (tokenType(token)){
                case NUMBER:
                    S.push(atoi(token.c_str()));
                    break;
                case OPERATOR:
                {
                    int op2 = S.top();S.pop();
                    int op1 = S.top();S.pop();
                    int res;
                    if (token == "*"){
                        res = op1*op2;
                    }else if (token == "+"){
                        res = op1 + op2;
                    }else if (token == "-"){
                        res = op1 - op2;
                    }else if (token == "/"){
                        res = op1 / op2;
                    }
                    
                    S.push(res);
                }
                    break;
                    
                default:
                    ;
            }
        }
        
        return S.top();
    }
    
private:
    enum TOKENTYPE{
        NUMBER,
        OPERATOR
    };
    
    TOKENTYPE tokenType(const string &token)
    {
        if ( token == "*" || token == "+" || token == "-" || token == "/" ){
            return OPERATOR;
        }else{
            return NUMBER;
        }
    };
};
