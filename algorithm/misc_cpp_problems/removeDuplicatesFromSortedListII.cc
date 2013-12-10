/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void RemoveDupInList2(ListNode *&head);
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        RemoveDupInList2(head);
    }
};

void Solution::RemoveDupInList2(ListNode *&head)
{
  bool flag = 0;
  ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
  if(!head)
  {
    return;
  }
  if(!head->next)
  {
    return;
  }
  temp->next = head;
  head = temp;
  
  while(head->next && head->next->next)
  {
    
    if(head->next->val == head->next->next->val)
    {
      head->next = head->next->next;
      flag = 1;
    }
    else
    {
      if(flag == 1)
      {
        head->next = head->next->next;
        flag = 0;
      }
      else
      {
        head = head->next;
      }
    }
  }

  if(head->next)
  {
    if(flag == 1)
    {
      head->next = NULL;
    }
    head = temp->next;
    free(temp);
  } 
}