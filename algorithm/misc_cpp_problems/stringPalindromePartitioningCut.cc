/*
 * stringMinPalindromePartitioningCut.cc
 *
 *  Created on: May 30, 2013
 *      Author: xqian
 *
 * using matrix is much faster then using map
 */




#include <iostream>
#include <string.h>
#include <assert.h>
#include <string>
#include <vector>
#include <time.h>
#include <limits.h>
using namespace std;

//#define debug_print(...) do {std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_print(...)

inline std::ostream& operator<<(std::ostream& out, const vector< vector<string> > obj)
{
  for (size_t child_i=0; child_i<obj.size();child_i++)
        {
          out<<"[";
          for(size_t child_ii=0; child_ii<obj[child_i].size(); child_ii++)
          {
            out<<obj[child_i][child_ii]<<", ";
          }
          out<<"];"<<endl;
        }

    return out;
}

/*
//x[i]=x[k]+1    if s[k~i] is para
//     x[k]+i-k  if s[k~i] is not para
//

//global best is also the local best
 * http://www.cppblog.com/wicbnu/archive/2013/03/18/198565.html
 *
 *and the isPalindrome becomes something that no need to touch the thing that have no need to touch
 */
class Solution{
public:
    size_t len_of_s;
    //vector of vector seems good, no need to take care of leak
    int* is_palindrome_matrix;
    vector< vector<string> >*  results;

    Solution()
    {
      len_of_s=0;
      results=NULL;
      is_palindrome_matrix=NULL;
    }

    inline void prepare_is_palindrome_matrix
                  (const string& s)
      {
        for(size_t b=0;b<=len_of_s-1;b++)
          for(size_t e=b;(e==b || e==b+1)&&e<=len_of_s-1;e++)
          {
            bool is_palindrome_so_far=true;
            for(size_t movement=0;
                (b-movement>=0 && e+movement<=len_of_s-1 && is_palindrome_so_far);
                movement++)
            {
              if (s[b-movement]==s[e+movement])
              {
                debug_print("rb:"<<b-movement<<", re:"<<e+movement<<endl);
                *get_is_palindrome(b-movement,e+movement)=true;
              }
              else
                is_palindrome_so_far=false;
            }

          }
      }


      inline bool isPalindrome(size_t range_begin, size_t range_end)
      {
        return *get_is_palindrome(range_begin,range_end);
      }

    inline int* get_is_palindrome(size_t b, size_t e)
    {
      return is_palindrome_matrix+(len_of_s*b)+e;
    }

    inline vector< vector<string> >& get_result(size_t e)
    {
      return *(results+e);
    }

    //to get [rng_bgn,]
    inline vector< vector<string> >& minCut_rec(const string& s,size_t range_end)
    {
      debug_print("re:"<<range_end<<endl);

      if (get_result( range_end ).size()!=0)
      {
        return get_result( range_end );
      }

      string current(s, 0, range_end+1);

      if (isPalindrome( 0, range_end))
      {
        get_result( range_end ).push_back(vector<string>());
        get_result(range_end).back().push_back(current);
      }

      for(size_t i=1;i<=range_end;i++)
      {
        debug_print("i:"<<i<<endl);
        if (isPalindrome( i, range_end))
        {
          minCut_rec( s ,  i-1 );
          current=string(s,i,range_end-i+1);
          debug_print("push:"<<current<<", to"<<get_result( i-1 )<<endl);
          for (size_t child_i=0; child_i<results[i-1].size();child_i++)
          {
            get_result( range_end ).push_back(vector<string>());
            for(size_t child_ii=0; child_ii<get_result(i-1)[child_i].size(); child_ii++)
            {
              get_result(range_end).back().push_back(get_result(i-1)[child_i][child_ii]);
            }
            get_result(range_end).back().push_back(current);
          }
        }
      }

      debug_print("range_end:"<<range_end<<", "<<get_result( range_end )<<endl);
      return get_result( range_end );
    }

    vector< vector<string> > partition(string s) {
      size_t len=s.size();
      len_of_s=len;
      if (results!=NULL) delete[] results;
      if (is_palindrome_matrix!=NULL) delete[] is_palindrome_matrix;

      results=new vector< vector<string> >[len];
      is_palindrome_matrix=new int [len*len];

      memset(is_palindrome_matrix,0,len*len*sizeof(int));
      prepare_is_palindrome_matrix(s);


      get_result( 0 ).push_back(vector<string>());
      if (len>=1)
        get_result(0)[0].push_back( string(s,0,1) );
      else
        get_result(0)[0].push_back("");

      vector< vector<string> > *r;
      if (len==0 || len==1)
      {
        r=&(results[0]);
      }
      else
      {
        r=&(minCut_rec(s,len-1));
      }
      return *r;
    }
};


void test_s1( Solution& s1)
{
  clock_t t;
  t=clock();
  time_t t1;
  time(&t1);
  time_t now;
  for(int i=0;i<5;i++)
  {

    debug_print("===aab"<<endl);
    cout<<s1.minCut("aab").size()<<endl;
    debug_print("===ababab"<<endl);
    s1.minCut("ababab");
    debug_print("===leet"<<endl);
    s1.minCut("leet");
#if 0
    string s="apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
    string s2="adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece";
    string s3="apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
    string s4="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    assert(s1.minCut(s)==452);
    assert(s1.minCut(s2)==273);
    assert(s1.minCut(s3)==452);
    assert(s1.minCut(s4)==1);
#endif
  }
  cout<<(clock()-t)<<", cli per second, s1:"<<CLOCKS_PER_SEC<<endl;
  time(&now);
  cout<<"t:"<<difftime(now,t1)<<""<<endl;
}

int main()
{

  Solution s;
  test_s1(s);
}
