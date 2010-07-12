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
#include <limits>

using namespace std;

extern int debug_level;
#define debug_print(statement) if (debug_level) std::cerr<<statement;
//#define debug_print(statement)

class MyObject
{
public:
    virtual void output(ostream& o)
    {
        return;
    }
};

class RegionResultPair: public MyObject
{
public:
    int maxWithHead;
    int maxWithoutHead;
    RegionResultPair()
    {
        maxWithHead = numeric_limits<int>::min();
        maxWithoutHead = numeric_limits<int>::min();
    }
    void output(ostream& o)
    {
        o<<"withH:"<<maxWithHead<<", withoutH:"<<maxWithoutHead;
    }
};

class RegionResult: public MyObject
{
public:
    int maxWithoutTailAndHead;
    int maxWithTail;
    int maxWithHead;
    int maxWithTailAndHead;

    RegionResult()
    {
        maxWithoutTailAndHead = numeric_limits<int>::min();
        maxWithTail = numeric_limits<int>::min();
        maxWithHead = numeric_limits<int>::min();
        maxWithTailAndHead = numeric_limits<int>::min();
    }

    RegionResult(int in_maxWithoutTailAndHead, int in_maxWithTail,
            int in_maxWithHead, int in_maxWithTailAndHead)
    {

    }

};

class TestCase: public MyObject
{
public:

    int N;
    vector<int> nums;

    TestCase()
    {
        N = 0;
    }
    //return 0 is success, other value is fail;
    int input(istream& in)
    {
        in >> N;

        int temp;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            nums.push_back(temp);
        }

        debug_print("readed N:"<<N<<endl);
        vector<int>::iterator it;
        for(it=nums.begin(); it!=nums.end();it++)
        {
            debug_print(" "<<*it);
        }
        debug_print(" "<<endl);
        return 0;
    }

    void output(ostream& o)
    {
        o << N << ": " << ends;
        for (int i; i < N; i++)
        {
            o << nums[i] << ",";
        }
        o << endl;
    }

    virtual int caculate()
    {
        int i = 0;
        int j = nums.size() - 1;
        caculateMax(i, j);
        return 0;
    }

    RegionResult virtual caculateMax(int start, int end);

};

class TestCase_FromHead: public TestCase
{
public:
    virtual int caculate()
    {
        RegionResultPair result;
        result=caculateMax(0);
        if (result.maxWithHead>result.maxWithoutHead)
        {
            return result.maxWithHead;
        }
        else
        {
            return result.maxWithoutHead;
        }
    }

    RegionResultPair virtual caculateMax(size_t start);
};

class TestCase_DPWithoutRecur: public TestCase_FromHead
{
public:

    RegionResultPair virtual caculateMax(size_t start);
};


inline ostream& operator<<(ostream& out, MyObject& obj)
{
    obj.output(out);
    return out;
}

#endif /* XINQIAN_H_ */
