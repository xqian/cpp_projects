
/*
* main.cc
*
*  Created on: Dec 12, 2009
*      Author: Qian Xin
*      DataStructure Java book 11.2.2
*/

#include "xinqian.h"

int debug_level = 1;

int main()
{
    TestCase *the_case;
    
    int case_count;
    int failed=0;
    
    fstream in_file;
    in_file.open ("in", fstream::in);
    
    istream& in=cin;
    
    //istream& in=in_file;
    in>>case_count;
    if (case_count<=0)
    {
        cerr<<"invalid case_count"<<case_count;
        failed=1;
    }
    debug_print("case_count:"<<case_count<<endl);
    
    if (!failed)
    {
        for(int i=0;i<case_count;i++)
        {
            debug_print("case:"<<i<<"======================="<<endl);
            //the_case=new TestCase_FromHead();
            the_case=new TestCase_DPWithoutRecur();
            the_case->input(in);
            int v=the_case->caculate();
            cout<<"Case #"<<i+1<<": "<<v<<endl;
            delete the_case;
        }
    }
    return 0;
}

