
#include <string>
#include <iostream>
#include <vector>

int debug_level =0 ;
#define debug_print(...) do {if (debug_level) std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)

using namespace std;



class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result="";
        
        if (strs.size()==0) return result;
        
        result=strs[0];
        //debug_print("r:"<<result<<endl);

        for(size_t i=0; i<strs.size(); i++)
        {
            size_t result_size=result.size();
            for(size_t k=0; k<result_size; k++)
            {
                if (   k==strs[i].size() 
                    || result[k]==0 
                    || strs[i][k]==0
                    || result[k]!=strs[i][k]
                   )
                {
                    result[k]=0;
                    result_size=k;
                }
            }
        }

        string s="";
        for(size_t i=0; i<result.size(); i++)
        {
            if (result[i]!=0)
                s.push_back(result[i]);
            else
                break;
        }
        return s;
    }
    
};

void test2()
{
    string r1="a";
    string r2="b";
    
    cout<<r1.size()<<r1.length()<<endl;
    vector<string> strs(1,r1);
    strs.push_back(r2);
    
    Solution s1;
    cout<<"a,b:"<<s1.longestCommonPrefix(strs).size()<<endl;
}

void test3()
{
    string r1="abab";
    string r2="aba";
    string r3="";
    
    
    cout<<r1.size()<<r1.length()<<endl;
    vector<string> strs(1,r1);
    strs.push_back(r2);
    strs.push_back(r3);
    Solution s1;
    cout<<"a,b:"<<s1.longestCommonPrefix(strs).size()<<endl;
}


int main()
{
    string r1="abcd";
    string r2="abce";
    
    cout<<r1.size()<<r1.length()<<endl;
    vector<string> strs(1,r1);
    strs.push_back(r2);
    
    Solution s1;
    cout<<""<<s1.longestCommonPrefix(strs)<<endl;

    test2();
    
    test3();
    
}
