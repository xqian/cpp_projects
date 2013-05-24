/*
 * bst.cc
 *
 *  Created on: Mar 17, 2013
 *      Author: xqian
 */


#include "common.h"
#include "bst.h"

using namespace std;
int debug_level = 1;


template<typename T>
class TestNode: public Node<T>
{
public:
  static Node<char>* constructTree1()
  {
    Node<char>* C=new Node<char>('C');
    Node<char>* D=new Node<char>('D');
    Node<char>* B=new Node<char>('B', C, D);
    Node<char>* F=new Node<char>('F');
    Node<char>* G=new Node<char>('G');
    Node<char>* E=new Node<char>('E', F, G);

    static Node<char> _A('A', B, E);
    return &_A;
  }

  /*======================================
   testing code
   */
  static Node<int>* constructTree3()
  {
    Node<int>* I5=new Node<int>(5);
    Node<int>* I10=new Node<int>(10, I5, NULL);

    Node<int>* I35=new Node<int>(35);
    Node<int>* I30=new Node<int>(30, NULL, I35);

    Node<int>* I20=new Node<int>(20, I10, I30);

    Node<int>* I55=new Node<int>(55);
    Node<int>* I50=new Node<int>(50, NULL, I55);

    Node<int>* I90=new Node<int>(90);
    Node<int>* I70=new Node<int>(70, NULL, I90);

    Node<int>* I60=new Node<int>(60, I50, I70);

    Node<int>* _I40=new Node<int>(40, I20, I60);

    return _I40;
  }

  static Node<int>* constructTree4()
    {
      Node<int>* I5=new Node<int>(5);
      Node<int>* I10=new Node<int>(10, I5, NULL);

      Node<int>* I35=new Node<int>(35);
      Node<int>* I30=new Node<int>(30, NULL, I35);

      Node<int>* I20=new Node<int>(20, I10, I30);

      Node<int>* I55=new Node<int>(55);
      Node<int>* I50=new Node<int>(50, NULL, I55);


      Node<int>* I70=new Node<int>(70, NULL, NULL);

      Node<int>* I60=new Node<int>(60, I50, I70);

      Node<int>* I40=new Node<int>(40, I20, I60);

      Node<int>* I90=new Node<int>(90, I40, NULL);
      return I90;
    }

  static Node<char>* testCase1()
  {
    Node<char>* p_a = constructTree1();
    std::cout << "pre_order recursive:";
    p_a->pre_order(p_a);
    std::cout << std::endl << "pre_order non-recursive:";
    p_a->pre_order_non_recursive(p_a);

    std::cout << std::endl;

    return p_a;
  }
  static Node<char>* testCase2()
  {
    Node<char>* p_a = constructTree1();
    std::cout << "in_order as-recursive:";
    p_a->in_order();
    std::cout << std::endl << "in_order no-recursive:";
    p_a->in_order_non_recursive(p_a);

    std::cout << std::endl;
    std::cout<<"distance:"<<p_a->find_maxDistance(p_a)<<endl;
    return p_a;
  }

  static Node<int>* testCase3()
  {
    Node<int>* p_40 = constructTree3();
    std::cout << "pre_order recursive:";
    p_40->pre_order();

    std::cout << std::endl << "in_order as-recursive:";
    p_40->in_order();
    std::cout << std::endl << "in_order no-recursive:";
    p_40->in_order_non_recursive(p_40);

    std::cout << std::endl;

    if (p_40->in_order_check_bst())
      std::cout << std::endl << "it is bst" << std::endl;
    std::cout<<"distance 40:"<<p_40->find_maxDistance(p_40)<<endl;
    std::cout<<"distance 20:"<<p_40->find_maxDistance(p_40->left)<<endl;
    //std::cout<<"distance 70:"<<p_40->find_maxDistance(p_40->right->right)<<endl;
    return p_40;
  }

  static void testCase4()
  {
    Node<int>* p_40 = constructTree3();
    Node<int>* n = p_40->find_common_parent(50, 70);
    cout << "c 50,70:" << (n ? n->v : -1) << endl;
    n = p_40->find_common_parent(95, 100);
    cout << "c 95,100:" << (n ? n->v : -1) << endl;
  }

  static void testCase5()
  {
    srand ( 100 );

    Node<int>* p_40 = new Node<int>(40);
    Node<int>* p;
    p_40->insert(rand() % 100);
    p_40->insert(rand() % 100);
    cout<<"three member:"<<endl;
    p_40->pre_order();
    cout<<endl;

    for(int i=0;i<8;i++)
      p_40->insert(rand() % 100);
    p_40->insert(3);
    cout<<"seven member:"<<endl;
    p_40->pre_order();
    cout<<endl;
    bool is_bst=p_40->in_order_check_bst();
    cout<<endl<<"   is bst:"<<is_bst<<endl;

    cout<<"find parent 11:"<<p_40->find_parent(11)->v<<endl;
    cout<<"find parent 5:"<<p_40->find_parent(5)->v<<endl;
    cout<<"find parent 82:"<<p_40->find_parent(82)->v<<endl;
    cout<<"find parent 40:"<<((p=p_40->find_parent(40))!=NULL? p->v:-1)<<endl;
    cout<<"find next 82:"<<p_40->find_next(82)->v<<endl;
    cout<<"find next 58:"<<p_40->find_next(58)->v<<endl;

    Node<int>* p_40_2 = new Node<int>(40);
    p_40_2->insert(30);
    p_40_2->insert(31);
    p_40_2->insert(33);
    p_40_2->insert(34);
    p_40_2->insert(50);
    p_40_2->insert(49);
    p_40_2->insert(44);
    cout<<"p40_2 items:"<<endl;
    p_40_2->pre_order();
    cout<<endl;
    cout<<"find parent 34:"<<((p=p_40_2->find_parent(34))!=NULL? p->v:-1)<<endl;
    cout<<"find next 34:"<<((p=p_40_2->find_next(34))!=NULL? p->v:-1)<<endl;
    cout<<"find previous 44:"<<((p=p_40_2->find_prev(44))!=NULL? p->v:-1)<<endl;
    cout<<"find previous 49:"<<((p=p_40_2->find_prev(49))!=NULL? p->v:-1)<<endl;

    cout<<"removed 44:";
    p_40_2->remove(44);
    p_40_2->pre_order();
    cout<<endl;

    cout<<"removed 40:";
    p_40_2->remove(40);
    p_40_2->pre_order();
    cout<<endl;

    cout<<"removed 82:";
    p_40->remove(82);
    p_40->pre_order();
    cout<<endl;

    cout<<"removed 5:";
    p_40->remove(5);
    p_40->pre_order();
    cout<<endl;
  }

  static void testCase6()
  {
    cout<<"case 6"<<endl;
    Node<int>* p_40 = constructTree3();
    p_40->in_order();
    cout<<endl;
    assert(p_40->find_v(30)->v==30);
    assert(p_40->find_parent(30)->v==20);
    assert(p_40->find_parent(40)==NULL);
    assert(p_40->find_next(35)->v==40);
    assert(p_40->find_next(40)->v==50);
    assert(p_40->find_next(90)==NULL);
    assert(p_40->find_prev(5)==NULL);
    assert(p_40->find_prev(40)->v==35);
    assert(p_40->find_prev(50)->v==40);
    assert(p_40->find_prev(55)->v==50);
    assert(p_40->insert(4)==true);
    assert(p_40->insert(38)==true);
    vector<int> v;
    p_40->in_order(p_40,&v);
    cout<<endl;
    cout<<v<<endl;

    assert(p_40->find_common_parent(30,50)->v==40);
    assert(p_40->find_common_parent(4,5)->v==5);
    assert(p_40->find_common_parent(4,30)->v==20);
    cout<<"find parent done"<<endl;

    assert(p_40->remove(10)==true);
    v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
    assert(p_40->remove(20)==true);
    v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
    assert(p_40->remove(25)==false);
    v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
    assert(p_40->remove(40)==true);
    v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
    p_40->freeTree(p_40);
  }
  static void testCase7()
   {
     cout<<"case 7"<<endl;
     Node<int>* p_40 = constructTree3();
     vector<int> v;
     v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
     assert(p_40->rotate_down(20));
     v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
     assert(p_40->rotate_down(60));
     v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
     p_40->freeTree(p_40);
   }

  static void testCase8()
     {
       cout<<"case 8"<<endl;
       Node<int>* p_40 = constructTree3();
       vector<int> v;
       v.clear();p_40->in_order(p_40,&v);cout<<endl<<v<<endl;
       p_40->pre_order();
       cout<<endl;
       p_40->pre_order_non_recursive(p_40);
       cout<<endl;
       p_40->in_order_non_recursive(p_40);
       cout<<endl;
     }
};

void old_test_cases()
{
  Node<char> A('A');
  Node<char>* p_A=TestNode<char>::testCase1();

  cout<<"visiting p_A:";
  p_A->pre_order();
  cout<<endl;

  TestNode<char>::testCase2();
  cout<<endl;

  TestNode<char>::testCase3();
  cout<<endl;

  TestNode<char>::testCase4();
  cout<<endl;

  TestNode<char>::testCase5();
  cout<<endl;
}

template<typename T>
void printPerimiter_leftBundary(Node<T>* n, bool begin_print)
{
  if (n!=NULL)
  {
    if (begin_print)
    {
      if (n->left!=NULL || n->right!=NULL)
      cout<<n->v<<", ";
    }
    if (n->left!=NULL)
      printPerimiter_leftBundary(n->left,true);
    else //left is empty
      printPerimiter_leftBundary(n->right, begin_print);
  }
}

template<typename T>
void printPerimiter_leaves(Node<T>* n)
{
  if (n==NULL) return;
  if (n->left==NULL && n->right==NULL)
    cout<<n->v<<", ";
  printPerimiter_leaves(n->left);
  printPerimiter_leaves(n->right);
}

template<typename T>
void printPerimiter_rightBundary(Node<T>* n, bool begin_print)
{
  if (n!=NULL)
    {
      if (n->right!=NULL)
        printPerimiter_rightBundary(n->right, true);
      else
        printPerimiter_rightBundary(n->left, begin_print);
      if (begin_print)
      {
        if (n->left!=NULL || n->right!=NULL)
              cout<<n->v<<", ";
      }
    }
}


template<typename T>
void printPerimiter(Node<T>* n)
{
  if (n==NULL) return;
  cout<<n->v<<", ";
  printPerimiter_leftBundary(n,false);
  printPerimiter_leaves(n);
  printPerimiter_rightBundary(n,false);
  cout<<endl;
}

/*
 * http://www.careercup.com/question?id=18065671
 * print the perimeter of a Binary tree
 * */

void testCase9()
{
  Node<int>* p_40 = TestNode<int>::constructTree4();
  std::cout << "pre_order recursive:";
  p_40->pre_order();
  cout<<endl;
  printPerimiter(p_40);

  p_40 = TestNode<int>::constructTree3();
  std::cout << "pre_order recursive:";
  p_40->pre_order();
  cout<<endl;
  printPerimiter(p_40);
}

int main(int argc, char *argv[])
{
  TestNode<char>::testCase6();
  TestNode<char>::testCase7();
  TestNode<char>::testCase8();
  testCase9();
}
