#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>

//#define debug_print(...) do { std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_print(...)
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector< vector<int> > positions(s.size()+1,vector<int>(26,0));
        for(size_t i=1;i<=s.size();i++)
        {
            copy(positions[i-1].begin(),positions[i-1].end(),positions[i].begin());

            positions[i][s[i-1]-'a']++;
            debug_print( "i:"<<i<<
                         "  a:"<<positions[i][0]<<
                         ", b:"<<positions[i][1]<<
                         ", c:"<<positions[i][2]<<
                         endl
                       );
        }
        size_t result=0;
        for(size_t i=0;i<=s.size();i++)
            for(size_t j=i+1;j<=s.size();j++)
            {
                bool nonrepeating=true;
                for(size_t k=0;k<26 && nonrepeating;k++)
                {
                    if (positions[j][k]-positions[i][k]>1)
                            nonrepeating=false;
                }
                debug_print("i:"<<i<<", j:"<<j<<", n-rep:"<<nonrepeating<<", r:"<<result<<endl);
                if (nonrepeating && (j-i)>result )
                    result=j-i;
            }
        return result;
    }
};

int main()
{
    Solution s;
    assert(s.lengthOfLongestSubstring("abcabcbb")==3);
    assert(s.lengthOfLongestSubstring("bbbb")==1);
    assert(s.lengthOfLongestSubstring("abcabcdd")==4);
}