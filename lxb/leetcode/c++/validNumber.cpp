http://oj.leetcode.com/problems/valid-number/
/*Question
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

Solution: finite automata. Refer http://discuss.leetcode.com/questions/241/valid-number
	  there is one finite automata png saved in the github.

class Solution {
public:
    bool isNumber(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
    enum InputType {
        INVALID,    // 0
        SPACE,      // 1
        SIGN,       // 2
        DIGIT,      // 3
        DOT,        // 4
        EXPONENT,   // 5
        NUM_INPUTS  // 6
    };
    int transitionTable[][NUM_INPUTS] = {
        -1,  0,  3,  1,  2, -1,     // next states for state 0
        -1,  8, -1,  1,  4,  5,     // next states for state 1
        -1, -1, -1,  4, -1, -1,     // next states for state 2
        -1, -1, -1,  1,  2, -1,     // next states for state 3
        -1,  8, -1,  4, -1,  5,     // next states for state 4
        -1, -1,  6,  7, -1, -1,     // next states for state 5
        -1, -1, -1,  7, -1, -1,     // next states for state 6
        -1,  8, -1,  7, -1, -1,     // next states for state 7
        -1,  8, -1, -1, -1, -1,     // next states for state 8
    };
    
    int state = 0;
    while (*s){
        InputType type = INVALID;
        
        char c = *s;
        if (isspace(c)) type = SPACE;
        else if (isdigit(c)) type = DIGIT;
        else if (c =='.') type =DOT;
        else if (c == 'e' || c =='E') type = EXPONENT;
        else if (c == '+' || c == '-') type = SIGN;
        
        state = transitionTable[state][type];
        if (state == -1) return false;
        
        ++s;
    }
    
    return state == 1 || state == 4 || state ==7 ||state == 8;
    }
};
