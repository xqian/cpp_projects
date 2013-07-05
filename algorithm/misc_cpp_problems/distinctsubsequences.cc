#include <string>
#include <iostream>
#include <map>
#include <cassert>

//#define debug_print(...) do { std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_print(...)
using namespace std;

//n and m is the current processing string length
int disct(const string& s1, const string& s2, size_t n, size_t m, 
          map<pair<size_t,size_t>,int >& result_map)
{
    int r1=-1;
    int r2=-2;

    if (result_map.find(pair<size_t,size_t>(n,m))!=result_map.end())
    {
        return result_map[pair<size_t,size_t>(n,m)];
    }

    if (n==0 && m>0)
    {
        return -1;
    }
    else if (m==0 && n>0)
    {
        return 1;
    }
    else if (n==0 && m==0)
    {
        return 1;
    }


    if (s1[n-1]==s2[m-1])
    {
        r1=disct(s1,s2,n-1,m-1,result_map);
    }

    r2=disct(s1,s2,n-1,m,result_map);

    int result;
    if (r1!=-1 && r2!=-1)
        result=r1+r2;
    else if (r1==-1)
        result=r2;
    else if (r2==-1)
        result=r1;
    else
        result=-1;

    debug_print("n:"<<n<<", m:"<<m<<", r1:"<<r1<<", r2:"<<r2<<", result:"<<result<<endl);

    result_map[pair<size_t,size_t>(n,m)]=result;

    return result;
}

class Solution {
public:
    int numDistinct(string S, string T) {
    map<pair<size_t,size_t>,int > result_map;     
    int result= disct(S,T,S.size(),T.size(),result_map);
    if (result==-1)
      return 0;
    else
      return result;
    }
};

int main()
{
    Solution s;
    assert(s.numDistinct("abc","abc")==1);
    assert(s.numDistinct("abcc","abc")==2);
    assert(s.numDistinct("rabbb","rabb")==3);
    assert(s.numDistinct("rabbbit","rabbit")==3);
    assert(s.numDistinct("abcde","ace")==1);
    assert(s.numDistinct("abcde","ce")==1);
    assert(s.numDistinct("aabccde","ce")==2);
}
