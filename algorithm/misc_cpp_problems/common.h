/*
 * common.h
 *
 *  Created on: Sep 11, 2011
 *      Author: Qian Xin
 */

#ifndef COMMON_H_
#define COMMON_H_

#include "stdio.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <map>
#include <deque>
#include <algorithm>
#include <cassert>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <utility>
#include <list>
#include <assert.h>
#include <limits>
#include <tr1/unordered_set>

//using namespace std::tr1;
//gg  -std=c++0x  word_breaks.cc for unordered_set and unordered_map
namespace num
{
  typedef long num_int_t;
  typedef unsigned long num_size_t;
}

#define COMMOA ,
extern int debug_level;
#define debug_print(...) do {if (debug_level) std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
//#define debug_print(...)
#define debug_do(...) do {__VA_ARGS__;} while(0)

namespace std
{

class MyClass
{
public:
  virtual void output(std::ostream& o) const =0;
  virtual ~MyClass() {};
};

inline std::ostream& operator<<(std::ostream& out, const MyClass& obj)
{
    obj.output(out);
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const MyClass* obj)
{
    if (obj!=NULL)
      {
      out<<"[p]";
      obj->output(out);
      }
    else
      {
      out<<"[null]";
      }
    return out;
}

template<typename T>
void print_vector(ostream& o, const vector<T>& v)
{
  //ostream_iterator<T> out(o, ";");
  //copy(v.begin(), v.end(), out);

  typename vector<T>::const_iterator it=v.begin();
  for(it=v.begin();it!=v.end();it++)
    {
    o<<*it<<" ";
    }

  o << flush;
}

template<typename T>
void print_seqcontainer(ostream& o, const deque<T>& v)
{
  //ostream_iterator<T> out(o, ";");
  //copy(v.begin(), v.end(), out);

  typename deque<T>::const_iterator it=v.begin();
  for(it=v.begin();it!=v.end();it++)
    {
    o<<*it<<", ";
    }

  o << flush;
}

template<typename T>
void print_seqcontainer(ostream& o, const list<T>& v)
{
  //ostream_iterator<T> out(o, ";");
  //copy(v.begin(), v.end(), out);

  typename list<T>::const_iterator it=v.begin();
  for(it=v.begin();it!=v.end();it++)
    {
    o<<*it<<", ";
    }

  o << flush;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const vector<T>& v)
{
  print_vector(out, v);
  return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const deque<T>& d)
{
  print_seqcontainer(out, d);
  return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const list<T>& d)
{
  print_seqcontainer(out, d);
  return out;
}

template<typename T1,typename T2>
inline std::ostream& operator<<(std::ostream& out, const pair<T1, T2>& p)
{
  out<<"{"<<p.first<<","<<p.second<<"}";
  return out;
}


template<typename T>
inline std::ostream& operator<<(std::ostream& out, const set<T>& s)
{
  ostream_iterator<T> oi(out, " ");
  copy(s.begin(), s.end(), oi);
  return out;
}

template<typename T1,typename T2>
inline std::ostream& operator<<(std::ostream& out, const map<T1, T2>& m)
{
  typename map<T1, T2>::const_iterator it;
  for(it=m.begin();it!=m.end();it++)
    {
    out<<"["<<it->first <<"]"<<":"<<it->second<<" ";
    }
  return out;
}

template<typename T1,typename T2, typename T3>
inline std::ostream& operator<<(std::ostream& out, const map<T1, T2, T3>& m)
{
  typename map<T1, T2>::const_iterator it;
  for(it=m.begin();it!=m.end();it++)
    {
    out<<"["<<it->first <<"]"<<":"<<it->second<<" ";
    }
  return out;
}
template<typename T>
inline void myswap(T& x, T& y)
{
  T temp=x;
  x=y;
  y=temp;
  return;
}

template<typename T>
T inline mymax(const T& v1, const T& v2)
{
    if (v1>v2)
      return v1;
    else
      return v2;
}

}
#endif /* COMMON_H_ */
