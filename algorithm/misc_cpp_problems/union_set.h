/*
 * union_set.h
 *
 *  Created on: Jun 13, 2013
 *      Author: xqian
 */

#ifndef UNION_SET_H_
#define UNION_SET_H_

#include "common.h"
#include <tr1/unordered_map>

using namespace std::tr1;
using namespace std;

template
<typename T>
class UnionSet
{
private:
  unordered_map<T,T> in_map;
public:
  void union_together(const T& value,const T& parent)
  {
    typename unordered_map<T,T>::const_iterator it=in_map.find(parent);
    if (it==in_map.end())
      {
      debug_print("added head "<<value<<endl);
      in_map[value]=parent;
      }
    else if (it->second!=parent)
      {
      //parent is not pointing to itself, doing compress on value after added
      in_map[value]=parent;
      compress(value);
      }
    else
      {
      in_map[value]=parent;
      }

  }

  inline void compress(const T& value)
  {
    vector<T> path;
    typename unordered_map<T,T>::const_iterator it=in_map.find(value);
    assert(it!=in_map.end());
    while(it->first!=it->second)
      {
      path.push_back(it->first);
      debug_print("push "<<it->first<<endl);
      it=in_map.find(it->second);
      assert(it!=in_map.end());
      };
    for(auto i : path)
    {
      typename unordered_map<T,T>::iterator it2=in_map.find(i);
      debug_print("compressing:"<<i<<":"<<it2->second<<", to:"<<it->first<<endl);
      if (it2->second!=it->first)
      {
        it2->second=it->first;
      }
    }
  }

  bool is_in(const T& v)
  {

    return (in_map.find(v)!=in_map.end());
  }

  bool is_same(const T& v1, const T& v2)
  {
    typename unordered_map<T,T>::const_iterator it1=in_map.find(v1);
    typename unordered_map<T,T>::const_iterator it2=in_map.find(v2);
    if (in_map[it1->second]!=it1->second) compress(v1);
    if (in_map[it2->second]!=it2->second) compress(v2);
    debug_print("is_same:"<<it1->first<<","<<it1->second<<", with :"<<it2->first<<","<<it2->second<<endl);
    return (it1->second==it2->second);
  }

};


#endif /* UNION_SET_H_ */
