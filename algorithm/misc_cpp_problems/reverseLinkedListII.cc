<<<<<<< HEAD
//Reverse Linked List II
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/


#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <memory>

using namespace std;


#define debug_print(...) do { std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_do(...) do {__VA_ARGS__;} while(0)
//#define debug_print(...)
//#define debug_do(...)

struct ListNode {
      int val;
      #ifdef SHARE_PTR
        shared_ptr<ListNode>  next;
      #else
        ListNode*  next;
      #endif
      ListNode(int x) : val(x), next(NULL) {
        debug_print("   c:"<<val<<endl);
      }
      ~ListNode() {
        debug_print("   d-c:"<<val<<endl);
      }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head) return NULL;

        vector<ListNode*> queue;
        ListNode *node=head;
        ListNode *t=head;
        int index=0;
        do {
            index++;
            debug_print("working on :"<<node->val<<endl);
            if (index>=m && index<=n)
            {
                debug_print("push:"<<node->val<<endl);
                queue.push_back(node);
            } 
            
            if (index==n)
            {                
                t=node->next;
                debug_print("tail:"<<node->val<<", t:"<<(t?t->val:-7777)<<endl);
            }
            
            node=node->next;
                        
        }while(node);

        ListNode *fakeHead=new ListNode(-7777);
        fakeHead->next=head;
        node=fakeHead;
        index=0;
        do {
            index++;
            debug_print("index:"<<index<<", working on :"<<node->val<<endl);
            if (index>=m && index<=n)
            {
                node->next=queue.back();
                debug_print("node:"<<node->val<<",n->n:"<<((node->next)?node->next->val:-7777)<<endl);
                node=queue.back();
                queue.pop_back();
            } 
            else if (index==n+1)
            {
                node->next=t;
                node=t;
            } 
            else
            {
                node=node->next;
            }
        }while(node);

        return fakeHead->next;
    }
};

/*
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/
void test()
{
#ifdef SHARE_PTR
    shared_ptr<ListNode> l5(new ListNode(5));
    shared_ptr<ListNode> last; 
    last=l5;
    for(int i =4;i>=1;i--)
    {
        shared_ptr<ListNode> l(new ListNode(i));
        debug_print("last:"<<last->val<<endl);
        l->next=last;
        last=l;
        debug_print("last:"<<last->val<<", l->next:"<<l->next->val<<endl);
    }
    debug_do(
        shared_ptr<ListNode> l=last;
        do
        {
            cerr<<" "<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );
#endif
}

void test1()
{
    ListNode* l5(new ListNode(5));
    ListNode* last; 
    last=l5;
    for(int i =4;i>=1;i--)
    {
        ListNode*  l=new ListNode(i);
        debug_print("last:"<<last->val<<endl);
        l->next=last;
        last=l;
        debug_print("last:"<<last->val<<", l->next:"<<l->next->val<<endl);
    }
    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<" "<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );

    Solution s;
    s.reverseBetween(last, 2, 4);

    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<"(2):"<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );
    ListNode*  l=last;
    do
    {   
        l=last;
        last=l->next;
        delete(l);
    }while(last);
}

void test2(vector<int> arr, size_t m, size_t n)
{
    ListNode* l5(new ListNode(arr[0]));
    ListNode* last; 
    last=l5;
    for(size_t i =1;i<arr.size();i++)
    {
        ListNode*  l=new ListNode(arr[i]);
        debug_print("last:"<<last->val<<endl);
        l->next=last;
        last=l;
        debug_print("last:"<<last->val<<", l->next:"<<l->next->val<<endl);
    }
    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<" "<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );

    Solution s;
    last=s.reverseBetween(last, m, n);

    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<"(2):"<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );
    ListNode*  l=last;
    do
    {   
        l=last;
        last=l->next;
        delete(l);
    }while(last);
}
int main()
{
    test1();
    int arr[]={-1,-3};
    vector<int> v(arr,arr+2);
    test2(v,1,2);
    return 0;
=======
//Reverse Linked List II
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/


#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <memory>

using namespace std;


#define debug_print(...) do { std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_do(...) do {__VA_ARGS__;} while(0)
//#define debug_print(...)
//#define debug_do(...)

struct ListNode {
      int val;
      #ifdef SHARE_PTR
        shared_ptr<ListNode>  next;
      #else
        ListNode*  next;
      #endif
      ListNode(int x) : val(x), next(NULL) {
        debug_print("   c:"<<val<<endl);
      }
      ~ListNode() {
        debug_print("   d-c:"<<val<<endl);
      }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head) return NULL;

        ListNode *node=head;

        int index=0;

        ListNode *fakeHead=new ListNode(-7777);
        fakeHead->next=head;
        node=fakeHead;
        index=0;
        ListNode *middleListHead=new ListNode(-7777);
        ListNode *middleListTail=middleListHead;
        ListNode *front=NULL;
        do {
            index++;
            debug_print("index:"<<index<<", working on :"<<node->val<<endl);
            if (index>=m && index<=n)
            {
                //put it to the end of middle list
               middleListTail->next=node->next;
               middleListTail=node->next;

            } 
            else if (index==n+1)
            {
                node->next=t;
                node=t;
            } 
            else
            {
                node=node->next;
            }
        }while(node);

        return fakeHead->next;
    }
};

/*
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/
void test()
{
#ifdef SHARE_PTR
    shared_ptr<ListNode> l5(new ListNode(5));
    shared_ptr<ListNode> last; 
    last=l5;
    for(int i =4;i>=1;i--)
    {
        shared_ptr<ListNode> l(new ListNode(i));
        debug_print("last:"<<last->val<<endl);
        l->next=last;
        last=l;
        debug_print("last:"<<last->val<<", l->next:"<<l->next->val<<endl);
    }
    debug_do(
        shared_ptr<ListNode> l=last;
        do
        {
            cerr<<" "<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );
#endif
}

void test1()
{
    ListNode* l5(new ListNode(5));
    ListNode* last; 
    last=l5;
    for(int i =4;i>=1;i--)
    {
        ListNode*  l=new ListNode(i);
        debug_print("last:"<<last->val<<endl);
        l->next=last;
        last=l;
        debug_print("last:"<<last->val<<", l->next:"<<l->next->val<<endl);
    }
    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<" "<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );

    Solution s;
    s.reverseBetween(last, 2, 4);

    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<"(2):"<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );
    ListNode*  l=last;
    do
    {   
        l=last;
        last=l->next;
        delete(l);
    }while(last);
}

void test2(vector<int> arr, size_t m, size_t n)
{
    ListNode* l5(new ListNode(arr[0]));
    ListNode* last; 
    last=l5;
    for(size_t i =1;i<arr.size();i++)
    {
        ListNode*  l=new ListNode(arr[i]);
        debug_print("last:"<<last->val<<endl);
        l->next=last;
        last=l;
        debug_print("last:"<<last->val<<", l->next:"<<l->next->val<<endl);
    }
    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<" "<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );

    Solution s;
    last=s.reverseBetween(last, m, n);

    debug_do(
        ListNode*  l=last;
        do
        {
            cerr<<"(2):"<<l->val<<" ,"<<endl;
            l=l->next;
        }while(l);
        );
    ListNode*  l=last;
    do
    {   
        l=last;
        last=l->next;
        delete(l);
    }while(last);
}
int main()
{
    test1();
    int arr[]={-1,-3};
    vector<int> v(arr,arr+2);
    test2(v,1,2);
    return 0;
>>>>>>> no message
}