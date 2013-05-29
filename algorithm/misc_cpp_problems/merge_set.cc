#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "assert.h"
#include "algorithm"
#include "map"
using namespace std;

/*
 * utility
 * */
int debug_level = 1;
//#define debug_print(...) do {if (debug_level) std::cerr<<__VA_ARGS__;} while(0)
//#define debug_do(...) do {__VA_ARGS__;} while(0)
#define debug_do(...)
#define debug_print(...)

template<typename T>
void print_vector( ostream& o, const vector<T>& v )
{
  //ostream_iterator<T> out(o, ";");
  //copy(v.begin(), v.end(), out);

  typename vector<T>::const_iterator it = v.begin();
  for (it = v.begin(); it != v.end(); it++)
  {
    o << *it << " ";
  }

  o << flush;
}

template<typename T>
inline std::ostream& operator<<( std::ostream& out, const vector<T>& v )
{
  print_vector( out , v );
  return out;
}

void swap( string& str, size_t i, size_t j )
{
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

//======================================================
class MySet
{
  public:
    int range_b;
    int range_e;
    MySet()
    {
      range_b=-1;
      range_e=-1;
    }
    MySet(int b, int e)
    {
      assert(b<e);
      range_b=b;
      range_e=e;
    }

    MySet(const MySet& s)
    {
      this->range_b=s.range_b;
      this->range_e=s.range_e;
    }
    void assign(const MySet& s)
    {
      this->range_b=s.range_b;
      this->range_e=s.range_e;
    }
    void to_void()
    {
      range_b=-1;
      range_e=-1;
    }
    bool is_void()
    {
      if (range_b==-1)
        assert(range_e==-1);
      return (range_b==-1);
    }
};

inline std::ostream& operator<<(std::ostream& out, const MySet& obj)
{
    out<<"["<<obj.range_b<<","<<obj.range_e<<"]";
    return out;
}


MySet merge(const MySet& s1, const MySet& s2)
{
  MySet result;

  if (s1.range_b>s2.range_b)
  {
    debug_print("   switch, s1:"<<s1<<",s2:"<<s2<<",r:"<<result<<endl);
    return merge(s2,s1);
  }
  else
  {

    //[1,2] [3,5] -> merged into 1,5
    //need more consideration
    if (s1.range_e+1>=s2.range_b)
    {
      result.range_b=s1.range_b;
      result.range_e=s2.range_e>s1.range_e? s2.range_e:s1.range_e;
    }
    debug_print("   s1:"<<s1<<",s2:"<<s2<<",r:"<<result<<endl);
    return result;
  }
}


class RangeSet
{
  public:
    list<MySet> set_list;
    void add(const MySet& s)
    {
      MySet newset=s;

      debug_do(
          cout<<"before scan new set:"<<newset<<"; l:";
          print_current_list(cout);
      );


      if (set_list.size()==0)
      {
        set_list.push_back(s);
        return;
      }


      //use binary search to find first need to compare, and the last need to compare
      for(list<MySet>::iterator it=set_list.begin();it!=set_list.end();it++)
      {
        debug_print("it:"<<*it<<", n:"<<newset<<endl);
        if (!(merge(newset,*it).is_void()))
        {
          debug_print("2- it:"<<*it<<", n:"<<newset<<endl);
          newset=merge(newset,*it);
          it->to_void();
        }
      }

      debug_do(
          cout<<"after scan new set:"<<newset<<"; l:";
          print_current_list(cout);
      );

      //remove all void, after remove, it will jump to next
      for(list<MySet>::iterator it=set_list.begin();it!=set_list.end();)
      {
        debug_print(" erasing-1 it:"<<*it<<endl);
        if (it->is_void())
        {
          debug_print(" erased-2 it:"<<*it<<" ");
          it=set_list.erase(it);
        }
        else
        {
          it++;
        }
        debug_print(" erasing-1.1 it:"<<*it<<endl);
      }

      //insert to right place, insert it inserting to the front of it
      bool inserted=false;
      for(list<MySet>::iterator it=set_list.begin();it!=set_list.end();it++)
      {
        debug_print("insert it:"<<*it<<endl);
        if (it->range_b>newset.range_b)
        {
          set_list.insert(it,newset);
          inserted=true;
        }
      }
      if (!inserted) set_list.push_back(newset);
      debug_do(
                cout<<"current list:";
                print_current_list(cout);
            );
    }

    void print_current_list(ostream& out)
    {
      for(list<MySet>::iterator it=set_list.begin();it!=set_list.end();it++)
      {
        out<<*it<<", ";
      }
      out<<endl;
    }

};


//merge in middle
void test1()
{
    RangeSet rangeSet;
    rangeSet.add(MySet(1,2));
    rangeSet.add(MySet(4,6));
    rangeSet.add(MySet(8,9));
    rangeSet.print_current_list(cout);
    cout<<"==============, merging(3,5)"<<endl;
    rangeSet.add(MySet(3,5));
    rangeSet.print_current_list(cout);
    assert(rangeSet.set_list.size()==2);
    cout<<"============== done"<<endl;
}


//merge in front
void test2()
{
    RangeSet rangeSet;
    rangeSet.add(MySet(2,3));
    rangeSet.add(MySet(4,6));
    rangeSet.add(MySet(8,9));
    rangeSet.print_current_list(cout);
    cout<<"==============, merging(1,5)"<<endl;
    rangeSet.add(MySet(1,5));
    rangeSet.print_current_list(cout);
    assert(rangeSet.set_list.size()==2);
    cout<<"============== done"<<endl;
}

//merge all range
void test3()
{
    RangeSet rangeSet;
    rangeSet.add(MySet(1,2));
    rangeSet.add(MySet(4,6));
    rangeSet.add(MySet(8,9));
    rangeSet.print_current_list(cout);
    cout<<"==============, merging(3,15)"<<endl;
    rangeSet.add(MySet(3,15));
    rangeSet.print_current_list(cout);
    assert(rangeSet.set_list.size()==1);
    cout<<"============== done"<<endl;
}

//random adding
void test4()
{
    RangeSet rangeSet;
    rangeSet.add(MySet(4,6));
    rangeSet.add(MySet(1,2));
    rangeSet.add(MySet(8,9));
    rangeSet.print_current_list(cout);
    cout<<"==============, merging(3,15)"<<endl;
    rangeSet.add(MySet(3,15));
    rangeSet.print_current_list(cout);
    assert(rangeSet.set_list.size()==1);
    cout<<"============== done"<<endl;
}


int main()
{
    test1();
    test2();
    test3();
    test4();
}


