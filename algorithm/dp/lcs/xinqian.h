/*
 * xinqian.h
 *
 *  Created on: Dec 13, 2009
 *      Author: Qian Xin
 */

#ifndef XINQIAN_H_
#define XINQIAN_H_

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

extern int debug_level;
#define debug_print(statement) if (debug_level) std::cerr<<statement;
//#define debug_print(statement)

class MyClass
{
public:
    virtual void output(ostream& o)
    {
        return;
    }
};

class TestCase: public MyClass
{
public:

    string str1;
    string str2;
    int* matrix;
    int zero_const;
    TestCase()
    {

    }
    //return 0 is success, other value is fail;
    int input(istream& in)
    {
        in >> str1;
        in >> str2;
        debug_print("get str 1:"<<str1<<", 2:"<<str2<<endl);
        matrix=new int[str1.size()*str2.size()];
        for (size_t i=0;i<str1.size()*str2.size();i++)
        {
            matrix[i]=0;
        }
        zero_const=0;
        return 0;
    }

    void output(ostream& o)
    {
        o<<str1<<endl;
        o<<str2<<endl;
    }

    int lcs();

    int* lcsij(int i, int j)
    {
        //debug_print("visit i:"<<i<<", j:"<<j);
        if ( i<0 || j<0 )
        {
            //debug_print(""<<endl);
            return &zero_const;
        }
        else if ( i>=int(str1.size()) || j>=int(str2.size()) )
        {
            assert(1);
            return &zero_const;
        }
        //debug_print(", p:"<<i*str2.size()+j<<endl);
        return matrix+(i*str2.size()+j);
    }
};

inline ostream& operator<<(ostream& out, MyClass& obj)
{
    obj.output(out);
    return out;
}

#endif /* XINQIAN_H_ */
