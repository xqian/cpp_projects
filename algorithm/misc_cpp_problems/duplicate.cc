#include "stdio.h"
#include "iostream"
using namespace std;
/*
 * using the sign place to hold whether the number have appeared before
 * */
bool   hasDuplicate(int   a[],   int   n){
int i; 
    for(i=0;i<n;i++){
      size_t index=0;
      if (a[i]>=0)
        index=a[i];
      else
        index=(-1)*(a[i]+1);

      if (a[index]<0)
        return 1;
      else
        a[index]=(-1)*(a[index]+1);
    }   
    return 0;
  }
  
/*
if (a[i] == i) a[i] = -1;
  === if yourself appear in the array, does not matter
for the case, a[i] is not i:
  === indicate a[a[i]] as -1, at the same time, take a[a[i]]'s value to a[i],
      and do the same thing for the value that was in a[i]
*/
int hasDuplicate2(int a[], int n)
{
  for (int i = 0; i < n; ++i)
    {
    while (a[i] != i && a[i] != -1)
      {
      if (a[a[i]] == -1)
        return 1;
      a[i] = a[a[i]];
      a[a[i]] = -1;
      }
    if (a[i] == i)
      {
      a[i] = -1;
      }
    }
  return 0;
}


int main()
{
printf("a:\n");
int a[]={0,1,2};
cout<<hasDuplicate(a,3)<<endl;
int a2[]={0,1,2};
cout<<hasDuplicate2(a2,3)<<endl;

printf("b:\n");
int b[]={0,0,1,2,1};
cout<<hasDuplicate(b,5)<<endl;
int b2[]={0,0,1,2,1};
cout<<hasDuplicate2(b2,5)<<endl;
}
