http://oj.leetcode.com/problems/regular-expression-matching/

/*
 Question:
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.  
        if (*p == '\0') return (*s == '\0');
        
        if (*(p+1) != '*'){
            if (*s == *p || ( *p == '.' && *s != '\0')) return isMatch(s+1,p+1);
            return false;
            
        }else{
            while ( *s == *p || *p == '.' && *s !='\0' ){
                if ( isMatch(s,p+2) == true ) return true;
                s++;
            }
            
            return isMatch(s,p+2);
        }
        
    }
};
