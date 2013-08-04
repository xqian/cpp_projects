
#include "common.h"

using namespace std;

//#define debug_print(...)


class Solution {
public:
    bool canBeIgnore(char c)
        {
            if(   (c>='A'&&c<='Z')
               || (c>='a'&&c<='z')
               || (c>='0'&&c<='9')
              )
                return false;
            else
                return true;
        }
    
    char compareChar(char c)
        {
            if (c>='A' && c<='Z')
                return c-'A'+'a';
            //debug_print("c:"<<c<<endl);
            return c;
        }

    bool isPalindrome(string s) 
        {
            for(int b=0,e=s.size()-1;b<e;b++,e--)
            {
                debug_print("1b:"<<b<<", e:"<<e<<", sb:"<<s[b]<<", se:"<<s[e]<<endl);
                while( canBeIgnore(s[b]) && b<(int)s.size()) {b++;};
                while( canBeIgnore(s[e]) && e>0) {e--;};
                if (b>=e) break;
                debug_print("2b:"<<b<<", e:"<<e<<", sb:"<<s[b]<<", se:"<<s[e]<<endl);
                debug_print("cb:"<<compareChar(s[b])<<", ce:"<<compareChar(s[e])<<endl);
                if (compareChar(s[b])==compareChar(s[e]))
                    continue;
                else
                    return false;
            }
            return true;
        }
    
};

void test()
{
    Solution s;
    debug_print("================"<<endl);
    assert(s.isPalindrome("A man, a plan, a canal: Panama")!=false);
    debug_print("================"<<endl);
    assert(s.isPalindrome("")!=false);
    debug_print("================"<<endl);
    assert(s.isPalindrome(".,")!=false);
    debug_print("================"<<endl);
    assert(s.isPalindrome("abc")==false);
    debug_print("================"<<endl);
    assert(s.isPalindrome("race a car")==false);
    debug_print("================"<<endl);
    assert(s.isPalindrome("!!!")!=false);
}

int debug_level=1;

int main()
{
    test();

}
