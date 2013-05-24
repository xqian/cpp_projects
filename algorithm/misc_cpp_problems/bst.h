/*
 * bst.h
 *
 *  Created on: Mar 17, 2013
 *      Author: xqian
 */

#ifndef BST_H_
#define BST_H_

namespace std
{
template<typename T>
class Node
{
public:
  T v;
  Node *right;
  Node *left;
  int maxDepth;
  int maxDistance;
  //the whole tree's parent relationship can be stored into a hash table.
  Node(T in_v, Node<T>* in_left, Node<T>* in_right)
  {
    v=in_v;
    right=in_right;
    left=in_left;
  }


  Node(T v)
  {
    this->v = v;
    right = NULL;
    left = NULL;
  }
  ;

  ~Node()
  {
    //if (right) delete right;
    //if (left) delete left;
    this->v=0xff;
  }

  Node()
  {
    right = NULL;
    left = NULL;
  }

  void freeTree(Node<T>* c)
  {
    if (c->right) freeTree(c->right);
    if (c->left) freeTree(c->left);
    delete c;
  }

  Node<T>* find_parent(T in_v)
  {
    Node<T>* current=this;
    Node<T>* p=this;
    if (current->v==in_v)
      return NULL;

    while(current!=NULL && current->v!=in_v)
      {
      debug_print("find p for:"<<in_v<<", c"<<current->v<<endl);
      p=current;
      if (current->v>in_v)
        current=current->left;
      else if (current->v<in_v)
        current=current->right;
      }
    debug_print("find:"<<in_v<<", found:"<<current->v<<", p:"<<p->v<<endl);
    if (current==NULL)
      return NULL;
    else
      return p;
  }

  Node<T>* find_v(T in_v)
  {
    Node<T>* current = this;

    while (current != NULL && current->v != in_v)
      {
      debug_print("find:"<<in_v<<", c"<<current->v<<endl);
      if (current->v > in_v)
        current = current->left;
      else if (current->v < in_v)
        current = current->right;
      }

    return current;
  }

  Node<T>* find_next(T in_v)
  {
    Node<T>* current = this->find_v(in_v);
    if (current->right!=NULL)
      {
      Node<T>* the_left_most=current->right;
      current=current->right;
      while(the_left_most!=NULL)
        {
        debug_print("find next, left most:"<<the_left_most->v<<", c"<<current->v<<endl);
        current=the_left_most;
        the_left_most=the_left_most->left;
        }
      }
    else //find first right parent
      {
      Node<T>* the_parent=find_parent(current->v);

      while(the_parent!=NULL && the_parent->left!=current)
        {
        current=the_parent;
        the_parent=find_parent(current->v);
        }
      current=the_parent;
      }
    return current;
  }

  Node<T>* find_prev(T in_v)
  {
      Node<T>* current = this->find_v(in_v);
      if (current->left!=NULL)
        {
        Node<T>* the_right_most=current->left;
        current=current->left;
        while(the_right_most!=NULL)
          {
          current=the_right_most;
          the_right_most=the_right_most->right;
          }
        }
      else //find first right parent
        {
        Node<T>* the_parent=find_parent(current->v);

        while(the_parent!=NULL && the_parent->right!=current)
          {
          current=the_parent;
          the_parent=find_parent(current->v);
          }
        current=the_parent;
        }
      return current;
  }

  bool insert(const T& in_v)
  {
    Node<T>* current = this;
    if (current->v==in_v)
      return false;
    Node<T>* p=this;

    while (current != NULL && current->v != in_v)
      {
      p=current;
      debug_print("find:"<<in_v<<", c"<<current->v<<endl);
      if (current->v > in_v)
        current = current->left;
      else if (current->v < in_v)
        current = current->right;
      }
    debug_print("done, p:"<<p->v<<endl);
    if ( current!=NULL && current->v == in_v)
      {
      return false;
      }

    current= new Node<T>(in_v,NULL,NULL);
    if (current==NULL) return false;

    if (current->v < p->v)
      p->left=current;
    else if (current->v > p->v)
      p->right=current;
    else

      return false;
    return true;
  }

  void remove(Node<T>* p, Node<T>* n, Node<T>* c)
  {
    if (p==NULL)
      {
      this->v=c->v;
      this->right=c->right;
      this->left=c->left;
      delete c;
      }
    else
      {
      if (c->v < p->v)
        p->left=c;
      else
        p->right=c;
      }

  }

  bool remove(const T& in_v)
  {
    Node<T>* current = this->find_v(in_v);
    if (current==NULL) return false;
    if (current->right==NULL)
      {
      debug_print("remove:"<<current->v<<endl);
      remove(this->find_parent(current->v),current,current->left);
      if (current!=this)
        delete current;
      }
    else if (current->left==NULL)
      {
      remove(this->find_parent(current->v),current,current->right);
      if (current!=this)
        delete current;
      }
    else
      {
      Node<T> *to_remove=find_next(in_v);
      assert(to_remove!=NULL && this->find_parent(to_remove->v)!=NULL);
      T v=to_remove->v;
      remove(this->find_parent(to_remove->v),to_remove,to_remove->right);
      current->v=v;
      }
    return true;
  }

  bool rotate_right(Node<T>* p, Node<T>* c)
  {
    if (p->left!=c)
      {
      assert(0);
      return false;
      }
    Node<T> *beta=c->right;
    c->right=p;
    p->left=beta;
    return true;
  }

  bool rotate_left(Node<T>* p, Node<T>* c)
  {
    if (p->right!=c)
      {
      assert(0);
      return false;
      }
    Node<T> *alpha=c->left;
    c->left=p;
    p->right=alpha;
    return true;
  }

  bool rotate_up(const T& in_v)
  {
    Node<T>* c = this->find_v(in_v);
    Node<T>* p = this->find_parent(in_v);
    Node<T>* gp= find_parent(p);
    if (c==NULL || p==NULL) return false;
    if (p->left==c)
      rotate_right(p,c);
    else if (p->right==c)
      rotate_left(p,c);
    else
      {
      assert(0);
      return false;
      }

    if (gp!=NULL)
      {
      debug_print("change gp:"<<gp->v<<endl);
      if (gp->v>c->v)
        gp->left=c;
      else if (gp->v<c->v)
        gp->right=c;
      }
    else
      {
      assert(0);
      }
  }

  bool rotate_down(const T& in_v)
  {
    Node<T>* c = this->find_v(in_v);
    if (c==NULL)
      return false;
    Node<T>* l = c->left;
    Node<T>* r = c->right;
    Node<T>* child=NULL;
    Node<T>* p = find_parent(c->v);
    if (l!=NULL)
      {
      child=l;
      rotate_right(c,l);
      }
    else if (r!=NULL)
      {
      child=r;
      rotate_left(c,r);
      }
    else
      return false;

    if (p!=NULL)
      {
      debug_print("change p:"<<p->v<<endl);
      if (p->v>child->v)
        p->left=child;
      else if (p->v<child->v)
        p->right=child;
      }
    else
      {
      assert(0);
      }

    return true;
  }

  void pre_order()
  {
    pre_order(this);
  }

  void in_order()
  {
    in_order(this);
  }

  bool in_order_check_bst()
  {
    return false;
  }

  void in_order(Node<T>* n)
  {
    in_order(n, NULL);
  }

  void in_order(Node<T>* n, std::vector<T>* visiting_vector)
  {
    if (n!=NULL)
      {
      cout<<"(";
      in_order(n->left,visiting_vector);
      if (visiting_vector) visiting_vector->push_back(n->v);
      cout<<n->v;
      in_order(n->right,visiting_vector);
      cout<<")";
      }
  }

  void pre_order(Node<T>* n)
  {
    if (n!=NULL)
      {
      cout<<"(";
      cout<<n->v;
      pre_order(n->left);
      if(n->left||n->right)
        cout<<",";
      pre_order(n->right);
      cout<<")";
      }
  }

  //not practical, no space or time have been save, but much more complex
  void in_order_non_recursive(Node<T>* n)
  {
    vector<Node<T>*> stack;
    Node<T>* c=n;
    do
      {
      while(c!=NULL)
        {
        stack.push_back(c);
        c=c->left;
        }
      c=stack.back();
      stack.pop_back();
      cout<<c->v<<" ";
      c=c->right;
      }
    while(stack.size()>0 || c!=NULL);
  }

  void pre_order_non_recursive(Node<T>* n)
  {
    vector<Node<T>*> stack;
    stack.push_back(n);
    while(stack.size()>0)
      {
      Node<T>* current=stack.back();
      cout<<current->v<<" ";
      stack.pop_back();
      if (current->right)
        stack.push_back(current->right);
      if (current->left)
        stack.push_back(current->left);
      }
  }

  Node<T>* find_common_parent(T v1, T v2)
  {
    Node<T>* current = this;
    if (v1>v2) myswap(v1,v2);
    while (current != NULL && !(current->v <= v2 && current->v >= v1))
      {
      if (v2 < current->v)
        current = current->left;
      else if (v1 > current->v)
        current = current->right;
      }
    return current;
  }


  int find_maxDistance(Node<T>* n)
    {
    assert(0);
    return 0;
    }
};

}


#endif /* BST_H_ */
