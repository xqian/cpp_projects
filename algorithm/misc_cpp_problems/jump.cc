#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
#define debug_print(...) do {std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)

class Solution{
  public:

    bool canJump(int A[], int n)
    {
        vector<int> v(A,A+n);
        vector<int> result(n,-1);
        result[0]=1;
        canJumpRecursive(v,result,n-1);
        return result[n-1];
    }

    //return whehter point x can be reached, the result will be in result
    void canJumpRecursive(const vector<int>& A, vector<int>& result, int  x)
    {
        if (x==0) return;
        debug_print("x:"<<x<<endl);
        bool search_done=false;
        for(int i=x-1; i>=0 && !search_done; i--)
        {
            if (result[i]==-1)
                canJumpRecursive(A,result,i);
            if (result[i]==1 && (A[i]+i)>=x)
            {
                debug_print("judge x:"<<x<<", i:"<<i<<", A[i]:"<<A[i]<<endl);
                result[x]=1; //the judgement on x is made
                search_done = true;
            }
        }
        if (result[x]==-1)
            result[x]=0;
        return;
    }
    
    int jump(int A[], int n)
    {
        if (n == 0) return 0;
        int *jumpSteps = new int[n];
        jumpSteps[0] = 0;
        int lastend = 0;
        int end, currentJump;
        for (int i = 0; i < n - 1; i++)
        {
            end = i + A[i];
            currentJump = jumpSteps[i] + 1;
            if (end >= n - 1)
            {
                end = n - 1;
                return currentJump;
            }
            for (int j = end; j > lastend; j--)
            {
                debug_print("j:" << j << ", jj:" << jumpSteps[j] << ", le:" << lastend << ", e:" << end << endl);
                jumpSteps[j] = currentJump;
            }
            if (lastend < end) lastend = end;
        }
        return jumpSteps[n - 1];
    }
};

int main()
{
    Solution s;
    int B[4] = {1,2,3,4};
    int A[4] = {1,1,1,1};
    int C[]={1,2,1,1,1};
    int D[]={3,1,1,1,1,0,0};
    int E[]={2,0,0};
    //0,1,2,3
    //1,2,3,4
    //jump 0->1->3
    assert(s.jump(B,4)==2);
    //0,1,2,3
    //1,2,3
    //jump 0->1->2
    assert(s.jump(B,3)==2);

    assert(s.jump(A,4)==3);
    assert(s.jump(C,5)==3);
    assert(s.jump(D,5)==2);

    assert(s.canJump(B,4));
    assert(!s.canJump(D,7));
    assert(s.canJump(E,3));
    
    return 0;
}
