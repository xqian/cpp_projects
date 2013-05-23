/*
 * regularExpression.cc
 *
 *  Created on: Feb 16, 2013
 *      Author: Xin
 *      http://www.careercup.com/question?id=15029918
 */

#include "common.h"
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;
int debug_level = 0;

// c++ map seems not accepting pair as hash member
//typedef pair<size_t, size_t> key_type;
//http://stackoverflow.com/questions/4870437/pairint-int-pair-as-key-of-unordered-map-issue
typedef unsigned int key_type;

key_type key(size_t l1, size_t l2)
{
  debug_print("key of, l1:"
              <<hex<<l1<<", l2:"
              <<l2<<", k:"
              <<((l1<<16)|l2)<<endl
              );
  return (l1<<16)|l2;
}


bool quit_result(string& p, string& t, size_t l1, size_t l2)
{
   if (l1==0 && l2==0)
    return true;
   //else if (l1==0 && l2!=0) //no need for this line
   //  return false;
  else if (l2==0 && l1==1 && (p[0]=='*'))
    return true;
  return false;
}

//str1 is pattern, str2 is the target string
//assume l1 will be less than 1024
bool ismatch(string& str1, string& str2, size_t l1, size_t l2, unordered_map<key_type,bool>& results)
{

  debug_print("p:"<<str1<<", t:"<<str1<<", l1:"<<l1<<", l2:"<<l2<<endl);
  if (l1==0 || l2==0)
    return quit_result(str1,str2,l1,l2);

  if (results.find(key(l1,l2))!=results.end())
    return results.find(key(l1,l2))->second;

  bool result=false;
 
  if (str1[l1-1]=='?')
    {
      result=ismatch(str1,str2,l1-1,l2-1,results);
    }
  else if (str1[l1-1]=='*')
    {
      result=ismatch(str1,str2,l1-1,l2-1,results);
      if (result==false)
        result=ismatch(str1,str2,l1-1,l2,results);
      if (result==false)
        result=ismatch(str1,str2,l1,l2-1,results);
    }
  else if (str1[l1-1]==str2[l2-1])
    {
    result=ismatch(str1,str2,l1-1,l2-1,results); 
    }

  results[key(l1,l2)]=result;
  debug_print("   result:"<<result<<", l1:"<<l1<<", l2:"<<l2<<endl);
  return result;
}

bool ismatch(string patten, string target)
{
    unordered_map<key_type,bool> results;
    assert(patten.size()<(1<<16) && target.size()<(1<<16));
    bool r=ismatch(patten,target,patten.size(),target.size(),results);
    debug_print("p:"<<patten<<", t:"<<target<<", r:"<<r<<endl);
    return r;
}

int main()
{
  assert(key(1,1)==(1<<16)+1);
  assert(key(16,3)==(16<<16)+3);
  assert(ismatch("abc*d","abctyzd")!=false);
  assert(ismatch("abc?d","abctyzd")==false);
  assert(ismatch("*abc?d","xyzxxxabctyzd")==false);
  assert(ismatch("*abc?d","xyzxxxabcxd")!=false);
}
