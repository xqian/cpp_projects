/*
 * xinqian.cc
 *
 *  Created on: May 8, 2010
 *      Author: xqian
 */

#include "xinqian.h"
RegionResultPair TestCase_DPWithoutRecur::caculateMax(size_t start)
{

        int currentMax =0; nums[0];
        int headMax =0; nums[0];

    if (N>=1)
    {
        currentMax = nums[0];
        headMax = nums[0];
        debug_print("endP:"<<0<<", n[i]:"<<nums[0]<<", c_max:"<<currentMax<<", h_max:"<<headMax<<endl);
    }

    for (int i = 1; i < N; i++)
    {
        if (nums[i] >= 0)
        {
            if (headMax>0)
            {
                headMax = nums[i] + headMax;
            }
            else
            {
                headMax=nums[i];
            }

            if (headMax > currentMax)
                currentMax = headMax;
        }
        else
        {
            if (headMax>=0)
            {
                headMax = nums[i] + headMax;
            }
            else
            {
                if ( headMax<nums[i])
                {
                    headMax=nums[i];
                }
            }
            if (headMax>currentMax)
                currentMax=headMax;
        }

        debug_print("endP:"<<i<<", n[i]:"<<nums[i]<<", c_max:"<<currentMax<<", h_max:"<<headMax<<endl);
    }

    RegionResultPair result;
    result.maxWithHead=currentMax;
    result.maxWithoutHead=currentMax;
    return result;
}


RegionResultPair TestCase_FromHead:: caculateMax(size_t start)
{
    RegionResultPair result;
    RegionResultPair temp_result;
    if (start==nums.size()-1)
    {
        result.maxWithHead=nums[start];
        result.maxWithoutHead=numeric_limits<int>::min();
    }
    else
    {
        temp_result=caculateMax(start+1);
        if (nums[start]>=0)
        {
            if (temp_result.maxWithHead>0)
                result.maxWithHead=nums[start]+temp_result.maxWithHead;
            else
                result.maxWithHead=nums[start];

            if (temp_result.maxWithHead>temp_result.maxWithoutHead)
                result.maxWithoutHead=temp_result.maxWithHead;
            else
                result.maxWithoutHead=temp_result.maxWithoutHead;
        }
        else
        {
            if (nums[start]<temp_result.maxWithHead)
            {
                result.maxWithHead=nums[start]+temp_result.maxWithHead;
            }
            else
            {
                result.maxWithHead=nums[start];
            }

            if (temp_result.maxWithHead>temp_result.maxWithoutHead)
            {
                result.maxWithoutHead=temp_result.maxWithHead;
            }
            else
            {
                result.maxWithoutHead=temp_result.maxWithoutHead;
            }
        }
    }

    debug_print("start"<<start<<", result, "<<result<<endl);

    return result;
}

RegionResult TestCase::caculateMax(int start, int end)
{
    RegionResult result;
    RegionResult result_temp;

    if (start == end)
    {
        result.maxWithHead = numeric_limits<int>::min();
        result.maxWithTail = numeric_limits<int>::min();
        result.maxWithTailAndHead = nums[start];
        result.maxWithoutTailAndHead = numeric_limits<int>::min();
        return result;
    }
    else if (start==end-1)
    {
        if (nums[start]>0 && nums[end]>0)
        {
            result.maxWithTailAndHead=nums[start]+nums[end];
            result.maxWithHead=0;
            result.maxWithTail=0;
            result.maxWithTailAndHead=nums[start];
            result.maxWithoutTailAndHead=0;
        }
        if (nums[start]>nums[end])
        {
            result.maxWithHead=start;
            result.maxWithTail=0;

        }
        result.maxWithoutTailAndHead=0;

    }
    else
    {


        if (start+1<=end-1)
            result_temp=caculateMax(start+1,end-1);

        if (result_temp.maxWithoutTailAndHead+nums[start])

        return result;
    }
    return result;
}

