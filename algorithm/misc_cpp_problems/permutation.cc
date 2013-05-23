#include "iostream"
#include "string"
#include "vector"
#include "assert.h"
#include "algorithm"
#include "map"
using namespace std;

/*
 * utility
 * */
int debug_level = 1;
#define debug_print(...) do {if (debug_level) std::cerr<<__VA_ARGS__;} while(0)
//#define debug_print(...)

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

unsigned int factorial( unsigned int x )
{
  unsigned int y = 1;
  for (unsigned int i = 2; i <= x; i++)
  {
    y = y * i;
  }
  return y;
}

/*recursive with count list to handle duplication
 * */
template<typename E>
void integrate_element_list( vector<E>& in_list, vector<E>& integrated_list,
    vector<size_t>& count_list )
{
  E previous = -1;
  sort( in_list.begin() , in_list.end() );
  integrated_list.clear();
  count_list.clear();
  for (size_t i = 0, j = 0; i < in_list.size(); i++)
  {
    if (in_list[i] != previous || j == 0)
    {
      integrated_list.push_back( in_list[i] );
      count_list.push_back( 1 );
      previous = in_list[i];
      j++;
    }
    else
    {
      count_list.back() = count_list.back() + 1;
    }
  }
}

template<typename E>
void integrate_element_list_with_map( vector<E>& in_list,
    vector<E>& integrated_list, vector<size_t>& count_list )
{
  map<E,size_t> the_map;
  for (size_t i = 0; i < in_list.size(); i++)
  {
    if (the_map.find(in_list[i])==the_map.end())
    {
      the_map[in_list[i]]=1;
    }
    else
    {
      the_map[in_list[i]]++;
    }
  }

  for(typename  map<E,size_t>::iterator it=the_map.begin();it!=the_map.end();it++)
  {
    integrated_list.push_back(it->first);
    count_list.push_back(it->second);
  }
}


template<typename E>
void all_permitutation( vector<E>& perm_iter, size_t perm_len,
    const vector<E>& integrated_list, vector<size_t>& count_list )
{
  debug_print("p:"<<perm_iter<<", l:"<<integrated_list<<", c:"<<count_list<<endl);
  if (perm_iter.size() == perm_len)
  {
    cout << perm_iter << endl;
  }
  else
  {
  for (size_t i = 0; i < integrated_list.size(); i++)
  {
    if (count_list[i] > 0)
    {
      perm_iter.push_back( integrated_list[i] );
      count_list[i]--;
      all_permitutation( perm_iter , perm_len , integrated_list , count_list );
      count_list[i]++;
      perm_iter.pop_back();
    }
  }
  }
}

void output_all_perm_recursive( const string& str )
{
  string s1 = str;
  vector<char> s( s1.begin() , s1.end() );
  vector<char> ch_arr;
  vector<size_t> n_arr;
  integrate_element_list_with_map( s , ch_arr , n_arr );
  size_t count = s.size();
  s.clear();
  all_permitutation( s , count , ch_arr , n_arr );
}

/* recursive, cannot handle duplicates
 * */
void all_permitutation( string& str, size_t begin )
{
  debug_print("  d:"<<str<<", b:"<<begin<<endl);

  if (begin >= str.size() - 1)
  {
    cout << str << endl;
    return;
  }

  for (size_t i = begin; i < str.size(); i++)
  {
    swap( str , begin , i );
    all_permitutation( str , begin + 1 );
    swap( str , begin , i );
  }
}

// 1 2 5 4 3
//   j     i
// 1 3 2 4 5
//
bool next_permutation( string& str )
{
  //find j
  size_t len = str.size();
  size_t i, j;

  if (len == 1)
    return false;

  for (j = len - 2; j > 0; j--)
  {
    if (str[j] < str[j + 1])
      break;
  }
  if (j == 0 && str[j] >= str[j + 1])
    return false;

  for (i = len - 1; i >= j; i--)
  {
    if (str[i] > str[j])
      break;
  }
  if (i == j)
    assert( 0 );
  swap( str , i , j );
  debug_print("  i:"<<i<<",j:"<<j<<endl);
  for (j = j + 1, i = len - 1; j < i; j++, i--)
  {
    swap( str , i , j );
  }
  return true;
}

int output_all_perm( const string& str )
{
  string s1 = str;
  int c = 0;
  cout << "[" << c << "]" << s1 << endl;
  while (next_permutation( s1 ))
  {
    c++;
    cout << "[" << c << "]" << s1 << endl;
  }
  return ++c;
}

int main()
{
  //swap(string("abcd"),0, 1);
  string s1 = "abc";
  all_permitutation( s1 , 0 );
  cout << "4!:" << factorial( 4 ) << endl;
  cout << "2!:" << factorial( 2 ) << endl;
  assert( output_all_perm("1223")==(factorial(4)/factorial(2)) );
  cout << "==========" << endl;
  assert(
      output_all_perm("1222344")==(factorial(7)/factorial(3)/factorial(2)) );

  //==============================
  output_all_perm_recursive( "122" );
  output_all_perm_recursive( "1222344" );
}
