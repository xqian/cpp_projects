/*
 * stringMinPalindromePartitioningCut.cc
 *
 *  Created on: May 30, 2013
 *      Author: xqian
 *
 * using matrix is much faster then using map
 */




#include <iostream>
#include <assert.h>
#include <string>
#include <map>
using namespace std;

//#define debug_print(...) do {std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_print(...)

class Solution {
public:
    size_t len_of_s;
    inline bool isPalindrome(const string& s, size_t range_begin, size_t range_end)
    {
    bool result=true;
    for(;range_begin<=range_end;range_begin++,range_end--)
      {
      debug_print("rb:"<<range_begin<<", re:"<<range_end<<endl);
      if (s[range_begin]!=s[range_end])
        return false;
      if (range_begin==65536||range_end==0) return result;
      }
    return result;
    }

    inline int* get_result(int *results, size_t b, size_t e)
    {
      return results+(len_of_s*b)+e;
    }

    //to get [rng_bgn,]
    inline int minCut_rec(const string& s,size_t range_begin,size_t range_end,
                   int* results)
    {
    debug_print("rb:"<<range_begin<<", re:"<<range_end<<endl);
    if (*get_result(results,range_begin,range_end)!=-1)
      {
      return *get_result(results,range_begin,range_end);
      }

    debug_print("working on rb:"<<range_begin<<", re:"<<range_end<<endl);

    if (range_begin==range_end)
      {
      *get_result(results,range_begin,range_end)=0;
      debug_print("==rb:"<<range_begin<<", re:"<<range_end<<", returning 0"<<endl);
      return 0;
      }

    int min_cut=s.size();
    for(size_t seperation=range_begin;seperation+1<=range_end;seperation++)
      {
      int current_result = minCut_rec(s,range_begin,seperation,results)
                          +minCut_rec(s,seperation+1,range_end,results)+1;
      if (min_cut>current_result)
        min_cut=current_result;
      }

    if (min_cut>0)
      {
      if (isPalindrome(s, range_begin, range_end))
        {
        min_cut=0;
        debug_print(" returing as 0"<<endl);
        }
      }
    *get_result(results,range_begin,range_end)=min_cut;
    debug_print("==rb:"<<range_begin<<", re:"<<range_end<<", r:"<<min_cut<<endl);
    return min_cut;
    }

    int minCut(string s) {
      size_t len=s.size();
      if (len==0 || len==1) return 0;

      len_of_s=len;
      int *results=new int[len*len];
      for(size_t i=0;i<len*len;i++) *(results+i)=-1;
      int r=minCut_rec(s,0,len-1,results);
      delete[] results;
      return r;
    }
};


int main()
{
  Solution s1;
  assert(s1.isPalindrome("a",0,0)!=false);
  assert(s1.isPalindrome("aa",0,1)!=false);
  assert(s1.isPalindrome("aba",0,2)!=false);
  assert(s1.isPalindrome("aba",0,1)==false);
  assert(s1.minCut("aab")==1);
  assert(s1.minCut("ababab")==1);
  assert(s1.minCut("leet")==2);
  string s="apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
  string s2="adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece";
  cout<<s1.minCut(s)<<endl;
  cout<<s1.minCut(s2)<<endl;
}
