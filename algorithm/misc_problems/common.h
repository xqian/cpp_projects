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
#include <algorithm>
#include <cassert>
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
#define debug_print(...) do {if (debug_level) std::cerr<<__VA_ARGS__;} while(0)
//#define debug_print(...)

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
inline std::ostream& operator<<(std::ostream& out, const vector<T>& v)
{
  print_vector(out, v);
  return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const set<T>& s)
{
  ostream_iterator<T> oi(out, " ");
  copy(s.begin(), s.end(), oi);
  out << endl;
  return out;
}

}
#endif /* COMMON_H_ */
