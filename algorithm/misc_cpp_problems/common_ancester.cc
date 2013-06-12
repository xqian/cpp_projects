/*
 * common_ancester.cc
 * http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-i.html
 * http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-ii.html
 *
 *  Created on: Jun 1, 2013
 *      Author: xqian
 */

#include "common.h"
using namespace std;

template<typename T>
  class BT : public MyClass
  {
  public:
    BT* left;
    BT* right;
    T v;
    BT()
    {
      left = 0;
      right = 0;
    }
    BT(T inv)
        {
          this->v = inv;
          left = 0;
          right = 0;
        }
    BT(T inv, BT<T>* l, BT<T>* r)
    {
      this->v = inv;
      left = l;
      right = r;
    }
    virtual ~BT()
    {
      delete left;
      delete right;
    }
    virtual void output(std::ostream& o) const
    {
      o << "(";
      o << v << ", ";
      if (left)
        o << *left;
      o << ",";
      if (right)
        o << *right;
      o << ")";
    }
    const BT* both_ancester(const BT *n, const T& n1,const T& n2)
    {
      bool found=false;
      pair<T,T> np(n1,n2);
      return both_ancester(n, np, found);
    }

    const BT* both_ancester(const BT *n, pair<T,T>& node_pair, bool& found)
    {
      if (n==NULL) return 0;

      debug_print("v n:"<<n->v<<endl);
      const BT * result=NULL;
      pair<T,T> left_node_pair=node_pair;
      pair<T,T> right_node_pair=node_pair;

      if (!found)
        {
        result=both_ancester(n->left,left_node_pair,found);
        }
      if (!found)
        {
        result=both_ancester(n->right,right_node_pair,found);
        }

      if (node_pair.first==n->v)
        node_pair.first=0;
      if (node_pair.second==n->v)
        node_pair.second=0;

      if ( (    ( left_node_pair.first==0 || right_node_pair.first==0 || node_pair.first==0 )
             && ( left_node_pair.second ==0 || right_node_pair.second==0 || node_pair.second==0  )
            )
          && !found)
        {
        found = true;
        cout<<"ca:"<<n->v<<endl;
        return n;
        }

      if (left_node_pair.first==0 || right_node_pair.first==0)
        node_pair.first=0;
      if (left_node_pair.second==0 || right_node_pair.second==0)
        node_pair.second=0;

      return result;
    }
#if 0
    bool both_ancester_cc(const BT *root, const BT *n1,const BT *n2, int &flag)
    {
      debug_print("v n:"<<(root?root->v:'@')<<",f1:"<<flag<<endl);
      if(!root || !n1 || !n2)
        {
          debug_print("return false"<<endl);
          return false;
        }
      if(root == n1)
        {
          flag++;
        }
      else if(root == n2)
        {
          flag++;
        }

      int left_flag = 0;
      int right_flag = 0;
      if(!both_ancester_cc(root->left,n1,n2,left_flag) && !both_ancester_cc(root->right,n1,n2,right_flag))
        {
          cout << "found common ancester: " << root->v << endl;
          debug_print("return false"<<endl);
          return true;
        }
      else if(!flag1 || !flag2)
        {
          debug_print("return false"<<endl);
          return false;
        }

      debug_print("r:"<< (both_ancester_cc(root->left,n1,n2,flag1,flag2) || both_ancester_cc(root->right,n1,n2,flag1,flag2))<<endl);
      return both_ancester_cc(root->left,n1,n2,flag1,flag2) || both_ancester_cc(root->right,n1,n2,flag1,flag2);
    }
#endif
  };

void testcase()
{

  BT<char>* h=new BT<char>('h');
  BT<char>* i=new BT<char>('i');
  BT<char>* d=new BT<char>('d');
  BT<char>* f=new BT<char>('f');
  BT<char>* g=new BT<char>('g');

  BT<char>* e=new BT<char>('e',h,i);
  BT<char>* b=new BT<char>('b',d,e);
  BT<char>* c=new BT<char>('c',f,g);

  BT<char>* a=new BT<char>('a',b,c);


  cout<<"tree:"<<a<<endl;
  assert(a->both_ancester(a,'d','f')==a);
  assert(a->both_ancester(a,'d','h')==b);
  assert(a->both_ancester(a,'h','e')==e);
  assert(a->both_ancester(a,'h','z')==NULL);

}

#if 0
void testcase_cc()
{

  BT<char>* h=new BT<char>('h');
  BT<char>* i=new BT<char>('i');
  BT<char>* d=new BT<char>('d');
  BT<char>* f=new BT<char>('f');
  BT<char>* g=new BT<char>('g');

  BT<char>* e=new BT<char>('e',h,i);
  BT<char>* b=new BT<char>('b',d,e);
  BT<char>* c=new BT<char>('c',f,g);

  BT<char>* a=new BT<char>('a',b,c);


  cout<<"tree:"<<a<<endl;
  int flag1=0;
  int flag2=0;
  //cout<<"bool:"<<(a->both_ancester_cc(a,d,f,flag1,flag2 )?"true":"false")<<endl;

}
#endif

int debug_level=1;
int main()
{
  testcase();
}
