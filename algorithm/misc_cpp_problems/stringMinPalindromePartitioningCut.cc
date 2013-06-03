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


class Solution {
public:
    virtual ~Solution() { }
    virtual int minCut(string s) =0;
};


class Solution1: public Solution {
public:
    size_t len_of_s;
    vector< vector<int> > is_palindrome_matrix;

    inline bool isPalindrome(const string& s, size_t range_begin, size_t range_end)
    {
      if (is_palindrome_matrix[range_begin][range_end] != -1)
      {
        return is_palindrome_matrix[range_begin][range_end];
      }

      bool result = true;
      for (; range_begin <= range_end; range_begin++, range_end--)
      {
        debug_print("rb:"<<range_begin<<", re:"<<range_end<<endl);
        if (s[range_begin] != s[range_end])
        {
          result = false;
          break;
        }
        if (range_begin == 65536 || range_end == 0)
          break;
      }
      is_palindrome_matrix[range_begin][range_end] = result;
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
    if (isPalindrome(s, range_begin, range_end))
    {
      min_cut=0;
      debug_print("==rb:"<<range_begin<<", re:"<<range_end<<", returning 0"<<endl);
    }
    else
    {
    for(size_t seperation=range_begin;seperation+1<=range_end;seperation++)
      {
      int current_result = minCut_rec(s,range_begin,seperation,results)
                          +minCut_rec(s,seperation+1,range_end,results)+1;
      if (min_cut>current_result)
        min_cut=current_result;
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


      is_palindrome_matrix.clear();
      is_palindrome_matrix.resize(len);
      for (size_t i=0;i<len;i++)
      {
        is_palindrome_matrix[i].resize(len);
        for (size_t j=0;j<len;j++)
          is_palindrome_matrix[i][j]=-1;
      }

      int r=minCut_rec(s,0,len-1,results);
      delete[] results;
      return r;
    }
};

class Solution2  : public Solution{
public:
    size_t len_of_s;
    //vector of vector seems good, no need to take care of leak
    vector< vector<int> > is_palindrome_matrix;
    int* results;

    inline void prepare_is_palindrome_matrix
                (const string& s)
    {
      size_t len = s.size();
      is_palindrome_matrix.clear();
      is_palindrome_matrix.resize(len);
      for (size_t i=0;i<len;i++)
      {
        is_palindrome_matrix[i].resize(len);
        for (size_t j=0;j<len;j++)
          is_palindrome_matrix[i][j]=0;
      }

      for(size_t palindrome_len=1;palindrome_len<=len;palindrome_len++)
      {
        for(size_t start=0;start+palindrome_len<=len;start++)
        {
          debug_print("==rb:"<<start<<", re:"<<start+palindrome_len-1<<endl);
          if (s[start]==s[start+palindrome_len-1])
          {
            if (palindrome_len==1||palindrome_len==2)
            {
              debug_print("rb:"<<start<<", re:"<<start<<endl);
              is_palindrome_matrix[start][start+palindrome_len-1]=1;
            }
            else if (is_palindrome_matrix[start+1][start+palindrome_len-2])
            {
              debug_print("rb:"<<start<<", re:"<<start+palindrome_len-1<<endl);
              is_palindrome_matrix[start][start+palindrome_len-1]=1;
            }
          }
        }
      }
    }

    inline bool isPalindrome(size_t range_begin, size_t range_end)
    {
      return is_palindrome_matrix[range_begin][range_end];
    }

    inline int* get_result(int *results, size_t b, size_t e)
    {
      return results+(len_of_s*b)+e;
    }

    //to get [rng_bgn,]
    inline int minCut_rec(const string& s,size_t range_begin,size_t range_end)
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
      int current_result = minCut_rec(s,range_begin,seperation)
                          +minCut_rec(s,seperation+1,range_end)+1;
      if (min_cut>current_result)
        min_cut=current_result;
      }

    if (min_cut>0)
      {
      if (isPalindrome(range_begin, range_end))
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
      results=new int[len*len];
      for(size_t i=0;i<len*len;i++) *(results+i)=-1;
      prepare_is_palindrome_matrix(s);
      int r=minCut_rec(s,0,len-1);
      delete[] results;
      return r;
    }
};

class Solution3 : public Solution{
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( s.length() <=1) return 0;
        vector<vector<int> > palLens(s.length(), vector<int>(1,1)); //palLens[i] is the lengths of palindrome start with i;
        checkPal(s, palLens);
        vector<int> numSeg(s.length(), 0); //number of palindrom segmentations
        calSeg(s.length(), numSeg, 0, palLens);
        return numSeg[0]-1;
    }

    //palLens[start_point][length of p]
    //numSeg[start_point], numSeg of [start_point,end_of_string]
    //cur from 0 until increase to cur + palLens[cur][i]
    //smarter on using the known palindrome to step forward
    void calSeg(int totalLen, vector<int> & numSeg, int cur, const vector<vector<int> > & palLens) {
        if ( numSeg[cur] != 0) return;
        int t = INT_MAX;
        for(int i=0; i < palLens[cur].size(); ++i) {
            debug_print("cur:"<<cur<<endl);
            if ( cur + palLens[cur][i] < totalLen ) {
                calSeg(totalLen, numSeg, cur + palLens[cur][i], palLens);
                t = min(t, 1+numSeg[cur+palLens[cur][i]]);
            }
            else {
                t = 1;
                break;
            }
        }
        numSeg[cur] = t;
    }

    void checkPal(const string & s, vector<vector<int> > & palLens) {
        for(int pivot = 1; pivot < s.length()-1; ++pivot) {
            int halfLen = getEqlSubLen(s, pivot-1, pivot+1);
            if ( halfLen > 0) {
                for(int i=1; i <=halfLen;++i) {
                    palLens[pivot-i].push_back(i*2 + 1);
                }
            }
        }
        for(int pivot = 0; pivot < s.length()-1; ++pivot) {
            int halfLen = getEqlSubLen(s, pivot, pivot+1);
            if( halfLen > 0) {
                for(int i=1; i <= halfLen; ++i) {
                    palLens[pivot-i+1].push_back(i*2);
                }
            }
        }
    }

    int getEqlSubLen(const string & s, int left, int right) {
        int len = 0;
        while( left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            len++;
        }
        return len;
    }
};


//sloution 2 plus cut brunches
class Solution4 : public Solution{
public:
    int global_min;
    size_t len_of_s;
    //vector of vector seems good, no need to take care of leak
    int* is_palindrome_matrix;
    int* results;

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

    inline int* get_result(int *results, size_t b, size_t e)
    {
      return results+(len_of_s*b)+e;
    }

    //to get [rng_bgn,]
    inline int minCut_rec(const string& s,size_t range_begin,size_t range_end)
    {
      debug_print("rb:"<<range_begin<<", re:"<<range_end<<endl);
      if (*get_result( results , range_begin , range_end ) != -1)
      {
        return *get_result( results , range_begin , range_end );
      }

      int min_cut = len_of_s;
      if ((range_begin == range_end ) || isPalindrome( range_begin , range_end ))
      {
        min_cut = 0;
        debug_print(" returing as 0, isp:"<< isPalindrome( range_begin , range_end )<<endl);
      }
      else
      {
        debug_print("working on rb:"<<range_begin<<", re:"<<range_end<<endl);

        for (size_t seperation = range_begin; seperation + 1 <= range_end;
            seperation++)
        {
          int current_result1 = minCut_rec( s , range_begin    , seperation ) +1;
          if (current_result1>min_cut||current_result1>global_min)  continue;

          int current_result2 = minCut_rec( s , seperation + 1 , range_end  ) ;
          if (current_result2>min_cut||current_result2>global_min) continue;

          int current_result = current_result1 + current_result2 ;

          if (min_cut > current_result)
          {
            min_cut = current_result;
            if (global_min>min_cut && (range_end-range_begin)==len_of_s-1)   global_min=min_cut;
          }
        }
      }

      *get_result( results , range_begin , range_end ) = min_cut;
      debug_print("==rb:"<<range_begin<<", re:"<<range_end<<", r:"<<min_cut<<endl);
      return min_cut;
    }

    int minCut(string s) {
      size_t len=s.size();
      if (len==0 || len==1) return 0;

      len_of_s=len;
      global_min=len;
      results=new int[len*len];
      is_palindrome_matrix=new int [len*len];
      memset(is_palindrome_matrix,0,len*len*sizeof(int));
      memset(results,0xff,len*len*sizeof(int));
      prepare_is_palindrome_matrix(s);
      int r=minCut_rec(s,0,len-1);
      delete[] results;
      delete[] is_palindrome_matrix;
      return r;
    }
};

//sloution 2 plus cut brunches, isPalindrome is also DP
class Solution5 : public Solution{
public:
    size_t len_of_s;
    int global_min;
    //vector of vector seems good, no need to take care of leak
    int* is_palindrome_matrix;
    int* results;

    inline bool isPalindrome(const string& s, size_t range_begin, size_t range_end)
    {
      debug_print("is p rb:"<<range_begin<<", re:"<<range_end<<endl);
      if  (*get_is_palindrome(range_begin,range_end)!=-1)
      {
        debug_print("is p rb:"<<range_begin<<", re:"<<range_end
                   <<", r:"<<*get_is_palindrome(range_begin,range_end)<<endl);
        return *get_is_palindrome(range_begin,range_end);
      }
      else
      {
        bool result=0;
        if (s[range_begin] == s[range_end])
        {
          if (range_begin==range_end || range_begin+1==range_end)
          {
            debug_print("is p rb:"<<range_begin<<", re:"<<range_end
                               <<", r:"<<1<<endl);
            result=1;
          }
          else if (range_begin+1<=INT_MAX && range_end-1>=0)
          {
            return isPalindrome(s,range_begin+1,range_end-1);
          }
          else
          {
            debug_print("is p rb:"<<range_begin<<", re:"<<range_end
                                           <<"l:"<<len_of_s<<endl);
            assert(0);
          }
        }
        else
        {
          result=0;
        }
        debug_print("is p rb:"<<range_begin<<", re:"<<range_end
                   <<", r:"<<result<<endl);
        *get_is_palindrome(range_begin,range_end)=result;
        return result;
      }
    }

    inline int* get_is_palindrome(size_t b, size_t e)
    {
      return is_palindrome_matrix+(len_of_s*b)+e;
    }

    inline int* get_result(int *results, size_t b, size_t e)
    {
      return results+(len_of_s*b)+e;
    }

    //to get [rng_bgn,]
    inline int minCut_rec(const string& s,size_t range_begin,size_t range_end)
    {
      debug_print("rb:"<<range_begin<<", re:"<<range_end<<endl);
      if (*get_result( results , range_begin , range_end ) != -1)
      {
        return *get_result( results , range_begin , range_end );
      }

      int min_cut = len_of_s;
      if ((range_begin == range_end ) || isPalindrome(s, range_begin , range_end ))
      {
        min_cut = 0;
        debug_print(" returing as 0, isp:"<< isPalindrome(s, range_begin , range_end )<<endl);
      }
      else
      {
        debug_print("working on rb:"<<range_begin<<", re:"<<range_end<<endl);

        for (size_t seperation = range_begin; seperation + 1 <= range_end;
            seperation++)
        {
          int current_result1 = minCut_rec( s , range_begin , seperation ) + 1;
          if (current_result1 > min_cut || current_result1 > global_min)
            continue;

          int current_result2 = minCut_rec( s , seperation + 1 , range_end );
          if (current_result2 > min_cut || current_result2 > global_min)
            continue;

          int current_result = current_result1 + current_result2;

          if (min_cut > current_result)
          {
            min_cut = current_result;
            if (global_min > min_cut
                && ( range_end - range_begin ) == len_of_s - 1)
              global_min = min_cut;
          }
        }
      }

      *get_result( results , range_begin , range_end ) = min_cut;
      debug_print("==rb:"<<range_begin<<", re:"<<range_end<<", r:"<<min_cut<<endl);
      return min_cut;
    }

    int minCut(string s) {
      size_t len=s.size();
      if (len==0 || len==1) return 0;
      global_min=len;
      len_of_s=len;
      results=new int[len*len];
      is_palindrome_matrix=new int [len*len];
      memset(is_palindrome_matrix,0xff,len*len*sizeof(int));
      memset(results,0xff,len*len*sizeof(int));

      int r=minCut_rec(s,0,len-1);
      delete[] results;
      delete[] is_palindrome_matrix;
      return r;
    }
};

/*
//x[i]=x[k]+1    if s[k~i] is para
//     x[k]+i-k  if s[k~i] is not para
//

//global best is also the local best
 * http://www.cppblog.com/wicbnu/archive/2013/03/18/198565.html
 *
 *and the isPalindrome becomes something that no need to touch the thing that have no need to touch
 */
class Solution6 : public Solution{
public:
    size_t len_of_s;
    int global_min;
    //vector of vector seems good, no need to take care of leak
    int* is_palindrome_matrix;
    int* results;

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

    inline int* get_result(int *results, size_t e)
    {
      return results+e;
    }

    //to get [rng_bgn,]
    inline int minCut_rec(const string& s,size_t range_end)
    {
      debug_print("re:"<<range_end<<endl);

      if (*get_result( results ,  range_end ) != -1)
      {
        return *get_result( results ,  range_end );
      }

      int min_cut = len_of_s;

      if (isPalindrome( 0, range_end))
      {
        min_cut=0;
      }
      else
      {
        for(size_t i=1;i<=range_end;i++)
        {
          debug_print("i:"<<i<<endl);
          int result=len_of_s;
          if (isPalindrome( i, range_end))
          {
            result=minCut_rec( s ,  i-1 )+1;
            debug_print("result:"<<result<<", i:"<<i<<endl);
          }
          else
          {
            if (range_end-i+1<min_cut)
              {
                result=minCut_rec( s ,  i-1 )+range_end-i+1;
              }
            debug_print("result:"<<result<<", i:"<<i<<endl);
          }
          debug_print("result:"<<result<<", i:"<<i<<endl);
          if (min_cut>result)
            min_cut=result;
          debug_print("min_cut:"<<min_cut<<endl);
        }
      }
      *get_result( results , range_end ) = min_cut;
      debug_print("==re:"<<range_end<<", r:"<<min_cut<<endl);
      return min_cut;
    }

    int minCut(string s) {
      size_t len=s.size();
      if (len==0 || len==1) return 0;
      global_min=len;
      len_of_s=len;
      results=new int[len];
      is_palindrome_matrix=new int [len*len];
      memset(is_palindrome_matrix,0,len*len*sizeof(int));
      memset(results,0xff,len*sizeof(int));

      prepare_is_palindrome_matrix(s);
      *get_result( results , 0 )=0;
      int r=minCut_rec(s,len-1);
      delete[] results;
      delete[] is_palindrome_matrix;
      return r;
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
    assert(s1.minCut("aab")==1);
    debug_print("===ababab"<<endl);
    assert(s1.minCut("ababab")==1);
    debug_print("===leet"<<endl);
    assert(s1.minCut("leet")==2);
    string s="apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
    string s2="adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece";
    string s3="apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
    string s4="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
#if 1
    assert(s1.minCut(s)==452);
    assert(s1.minCut(s2)==273);
    assert(s1.minCut(s3)==452);
    assert(s1.minCut(s4)==1);
#endif
  }
  cout<<(clock()-t)<<", cli per second, s1:"<<CLOCKS_PER_SEC<<endl;
  //time(&now);
  //cout<<"t:"<<difftime(now,t1)<<""<<endl;
}

int main()
{
  Solution1 s1;
  Solution2 s2;
  Solution3 s3;
  Solution4 s4;
  Solution5 s5;
  Solution6 s6;

  //test_s1(s1);
  //test_s1(s2);
  test_s1(s3);
  //test_s1(s4);
  //test_s1(s5);
  test_s1(s6);
}
