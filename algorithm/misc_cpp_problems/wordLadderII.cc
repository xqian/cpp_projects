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
    //0 - not visited
    //1 - visited this layer
    //2 - visited previouse layer
    vector<size_t> visited;
    vector< vector<size_t> > back_trace;

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
      debug_print("adding:"<<adding_s<<", s:"<<node_count<<endl);
      for(size_t i=0;i<node_count-1;i++)
      {
        debug_print(" deal with:"<<strs[i]<<endl);
        if (is_diff_one(strs[i],strs.back()))
        {
          debug_print(" link:"<<strs[i]<<", "<<strs.back()<<endl);
          links[i].push_back(node_count-1);
          links[node_count-1].push_back(i);
        }
      }
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      vector<vector<string> > result;
      unordered_set<string> my_dict=dict;
      my_dict.erase(start);
      my_dict.erase(end);

      len_s=start.size();

      strs.clear();
      links.clear();
      visited.clear();
      back_trace.clear();

      size_t dict_size=my_dict.size()+2;
      links.resize(dict_size);
      visited.resize(dict_size);
      back_trace.resize(dict_size);


      add_string(start);
      for(unordered_set<string>::iterator it=my_dict.begin(); it!=my_dict.end(); it++)
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
      for(size_t i=0; i<dict_size; i++) visited[i]=0;
      visited[0]=1;

      size_t current_layer_size=1;

      bool not_found=true;
      while(current_layer_size&&not_found)
      {
        debug_do(cout<<"current_layer:");
        debug_do(copy(current_layer.begin(),current_layer.end(),ostream_iterator<int>(cout,", ")));
        debug_do(cout<<endl);
        for(size_t i=0;i<current_layer_size;i++)
        {
          for(size_t j=0;j<links[current_layer[i]].size();j++)
          {
            if (visited[links[current_layer[i]][j]]==0)
            {
              current_layer.push_back(links[current_layer[i]][j]);
              back_trace[links[current_layer[i]][j]].push_back(current_layer[i]);
              debug_print("from "<<current_layer[i]<<"["<<strs[current_layer[i]]<<"] , to:"<<links[current_layer[i]][j]<<"["<<strs[links[current_layer[i]][j]]<<"]"<<endl);
              if (links[current_layer[i]][j]==dict_size-1)
                not_found=false;
              else
                visited[links[current_layer[i]][j]]=1;
            }
            else if (visited[links[current_layer[i]][j]]==1)
            {
              //current layer, backtrace can still happen
              debug_print("from-2 "<<current_layer[i]<<"["<<strs[current_layer[i]]<<"] , to:"<<links[current_layer[i]][j]<<"["<<strs[links[current_layer[i]][j]]<<"]"<<endl);
              back_trace[links[current_layer[i]][j]].push_back(current_layer[i]);
            }
          }
        }
        for(size_t i=0;i<current_layer_size;i++)
        {
          current_layer.pop_front();
        }
        for(size_t i=0;i<dict_size;i++)
        {
          if (visited[i]==1) visited[i]=2;
        }
        current_layer_size=current_layer.size();
      }

      list<vector<int> > result_index;
      result_index.push_back(vector<int>());
      result_index.back().push_back(dict_size-1);
      bool reach_start=false;
      bool no_path=false;
      do
      {
        for(list<vector<int> >::iterator l_it=result_index.begin();
            l_it!=result_index.end();l_it++)
        {
        debug_print("working on result_index:");
        debug_do(copy(l_it->begin(),l_it->end(),ostream_iterator<int>(cout,", ")));
        debug_do(cout<<endl);

        for(size_t i=1; i<back_trace[l_it->back()].size();i++)
          {
          list<vector<int> >::iterator added_vector=result_index.insert(l_it,vector<int>(l_it->begin(),l_it->end()));
          added_vector->push_back(back_trace[l_it->back()][i]);
          }
        debug_print("back_trace_size:"<<back_trace[l_it->back()].size()<<endl);
        if ( (back_trace[l_it->back()].size())>=1)
        {
          l_it->push_back(back_trace[l_it->back()][0]);
        }
        else
        {
          no_path=true;
        }
        if (l_it->back()==0) reach_start=true;
        }
      }
      while(!reach_start&&!no_path);
      //result[0].push_back(strs[0]);

      debug_do(copy(result_index.front().begin(),result_index.front().end(),ostream_iterator<int>(cout,", ")));
      debug_do(cout<<endl);
      debug_do(copy(result_index.back().begin(),result_index.back().end(),ostream_iterator<int>(cout,", ")));
      debug_do(cout<<endl);

      if (no_path) return result;

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


      debug_do(
           for(size_t i=0;i<result.size();i++)
           {
             cout<<"[";
             debug_do(copy(result[i].begin(),result[i].end(),ostream_iterator<string>(cout,", ")));
             cout<<"]";
             debug_do(cout<<endl);
           }
               );
      debug_do(cout<<"rs:"<<result.size()<<endl);

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

  set1.clear();
  s1.findLadders("hot","dog",set1);

  set1.clear();
  set1.insert("ted");
  set1.insert("tex");
  set1.insert("red");
  set1.insert("tax");

  set1.insert("tad");
  set1.insert("den");
  set1.insert("rex");
  set1.insert("pee");
  s1.findLadders("red","tax",set1);

  cout<<(clock()-t)<<", cli per second, s1:"<<CLOCKS_PER_SEC<<endl;
}

int main()
{

  Solution s;
  test_s1(s);
}

