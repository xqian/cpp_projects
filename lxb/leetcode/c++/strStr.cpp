http://oj.leetcode.com/problems/implement-strstr/
/*
Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (!needle) return haystack;
        if (!haystack) return NULL;
        
        //special case
        if (strlen(needle) == 0) return haystack;
        
        char *pStr = haystack;
        
        while(*pStr){
            char *pre = pStr;
            char *pPatten = needle;
            
            while(*pPatten && *pStr && *pPatten == *pStr) 
            {
                pPatten++; pStr++;
            };
            
            if (*pPatten=='\0'){
                //find one
                return pre;
            }else if (*pStr == '\0'){
                //not find
                return NULL;
            }else{
                //not a match!
                pStr = pre + 1;
            }
        }
        
        return NULL;
    }
};
