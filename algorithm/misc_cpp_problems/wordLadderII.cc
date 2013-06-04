/*
 * wordLadderII.cc
 *
 *  Created on: Jun 3, 2013
 *      Author: xinqian
 */

#include <iostream>
#include <string.h>
#include <assert.h>
#include <string>
#include <vector>
#include <list>
#include <time.h>
#include <limits.h>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <deque>
using namespace std;

#define debug_print(...) do {std::cout<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_do(...) do { __VA_ARGS__;} while(0)
//#define debug_print(...)
//#define debug_do(...)


class Solution {
public:

    size_t len_s;
    vector<string> strs;
    vector< vector<size_t> > links;
    unordered_set<size_t> visited;
    unordered_multimap<size_t, size_t> back_trace;

    inline bool is_diff_one(const string& str1, const string& str2)
    {
      debug_do(assert(str1.size()==str2.size()));
      size_t diff_count=0;

      for(size_t i=0; i<len_s;i++)
      {
        if (str1[i]!=str2[i])
        {
          diff_count++;
          if (diff_count>1) return false;
        }
      }
      if (diff_count==1)
        return true;
      debug_do(assert(0)); //greater than 1 will return in above loop
      return false;
    }

    void add_string(const string& adding_s)
    {
      strs.push_back(adding_s);
      size_t node_count=strs.size();
      for(size_t i=0;i<node_count-1;i++)
      {
        if (is_diff_one(strs[i],strs.back()))
        {
          links[i].push_back(node_count-1);
          links[node_count-1].push_back(i);
        }
      }
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

      len_s=start.size();
      strs.clear();
      links.clear();
      size_t dict_size=dict.size()+2;
      links.resize(dict_size);

      visited.clear();
      back_trace.clear();

      add_string(start);
      for(unordered_set<string>::iterator it=dict.begin(); it!=dict.end(); it++)
      {
        add_string(*it);
      }
      add_string(end);

      debug_do(copy(strs.begin(),strs.end(),ostream_iterator<string>(cout,", ")));
      debug_do(cout<<endl);
      debug_do(
          for(size_t i=0;i<strs.size();i++)
          {
            cout<<"[";
            copy(links[i].begin(),links[i].end(),ostream_iterator<int>(cout,", "));
            cout<<"]";
          }
          );
      debug_do(cout<<endl);

      deque<int> current_layer;
      current_layer.push_back(0);
      visited.insert(0);

      size_t current_layer_size=1;

      bool not_found=true;
      while(current_layer_size&&not_found)
      {
        for(size_t i=0;i<current_layer_size;i++)
        {
          for(size_t j=0;j<links[current_layer[i]].size();j++)
          {
            if (visited.find(links[current_layer[i]][j])==visited.end())
            {
              current_layer.push_back(links[current_layer[i]][j]);
              back_trace.insert(pair<size_t,size_t>(links[current_layer[i]][j],current_layer[i]));
              debug_print("from "<<current_layer[i]<<", to:"<<links[current_layer[i]][j]<<endl);
              if (links[current_layer[i]][j]==dict_size-1)
                not_found=false;
              else
                visited.insert(links[current_layer[i]][j]);
            }
          }
        }
        for(size_t i=0;i<current_layer_size;i++)
        {
          current_layer.pop_front();
        }
        current_layer_size=current_layer.size();
      }

      vector<vector<string> > result;

      list<vector<int> > result_index;
      result_index.push_back(vector<int>());
      result_index.back().push_back(dict_size-1);
      bool reach_start=false;
      do
      {
        for(list<vector<int> >::iterator l_it=result_index.begin();
            l_it!=result_index.end();l_it++)
        {
        debug_print("working on result_index:");
        debug_do(copy(l_it->begin(),l_it->end(),ostream_iterator<int>(cout,", ")));
        debug_do(cout<<endl);
        pair< unordered_multimap<size_t, size_t>::iterator, unordered_multimap<size_t, size_t>::iterator> all_next
                                                                = back_trace.equal_range(l_it->back());
        unordered_multimap<size_t, size_t>::iterator next_it=all_next.first;
        l_it->push_back(next_it->second);
        if (next_it->second==0) reach_start=true;
        next_it++;
        for(; next_it!=all_next.second;next_it++)
          {
          list<vector<int> >::iterator added_vector=result_index.insert(l_it,vector<int>(l_it->begin(),l_it->end()-1));
          added_vector->push_back(next_it->second);
          }
        }
      }
      while(!reach_start);
      //result[0].push_back(strs[0]);

      debug_do(copy(result_index.front().begin(),result_index.front().end(),ostream_iterator<int>(cout,", ")));
      debug_do(cout<<endl);
      debug_do(copy(result_index.back().begin(),result_index.back().end(),ostream_iterator<int>(cout,", ")));
      debug_do(cout<<endl);

      for(list<vector<int> >::iterator l_it=result_index.begin();
                  l_it!=result_index.end();l_it++)
      {
        result.push_back(vector<string>());
        size_t path_length=l_it->size();
        for(size_t i=0;i<path_length;i++)
        {
          result.back().push_back(strs[(*l_it)[path_length-1-i]]);
        }
      }

      debug_do(copy(result.front().begin(),result.front().end(),ostream_iterator<string>(cout,", ")));
      debug_do(cout<<endl);
      debug_do(copy(result.back().begin(),result.back().end(),ostream_iterator<string>(cout,", ")));
      debug_do(cout<<endl);


      return result;
    }
};




void test_s1( Solution& s1)
{
  clock_t t;
  t=clock();
  debug_print("hello"<<endl);
  unordered_set<string> set1;
  //"hot","dot","dog","lot","log"
  set1.insert("hot");
  set1.insert("dot");
  set1.insert("dog");
  set1.insert("lot");
  set1.insert("log");
  s1.findLadders("hit","cog",set1);
  cout<<(clock()-t)<<", cli per second, s1:"<<CLOCKS_PER_SEC<<endl;
}

int main()
{

  Solution s;
  test_s1(s);
}

