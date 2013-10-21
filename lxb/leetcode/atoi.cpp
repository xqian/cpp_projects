http://oj.leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // special case
        if (!str || strlen(str) == 0) return 0;
        
        // skip white space in the beginning
        while (*str != '\0' && isspace(*str)) str++;
        if (*str == '\0') return 0;
        
        // sign
        bool negative = false;
        if (*str == '-') {
            negative = true;   
            str++;
        }else if (*str == '+'){ 
            str++;
        }
        
        // convert
        int result = 0;
        int sum = 0;
        while (*str != '\0' && isdigit(*str)){
            // overflow
            if ( result == 214748364 && *str > '7' || result >214748364){
                return negative ? INT_MIN:INT_MAX;
            }
            
            result = result*10 + *str - '0';
            str++;
        }
        
        
            
        return negative ? -result : result;
    }
};
