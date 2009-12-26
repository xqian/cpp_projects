/*
 * myHealp.h
 *
 *  Created on: Dec 12, 2009
 *      Author: Qian Xin
 */

#ifndef MYHEALP_H_
#define MYHEALP_H_

#include "xinqian.h"

template<class T, class CompareT> class MyHeap
{
public:
    virtual bool setup_heap()=0;
    virtual bool add(T& e) =0;
    virtual int size() const =0;
    virtual bool isEmpty() const =0;
    virtual void output(std::ostream &o) const =0;
};

template<class T, class CompareT>
inline std::ostream & operator <<(std::ostream &o, MyHeap<T, CompareT> &heap)
{
    heap.output(o);
    return o;
}
;

template<class T> class DefaultCompare
{
public:
    bool operator()(T& a, T& b)
    {
        return (a > b);
    }
    bool swap(T& a, T& b)
    {
        T tmp;
        return swap(a,b,tmp);
    }
    bool swap(T& a, T& b, T&tmp)
    {
        tmp = a;
        a = b;
        b = tmp;

        return true;
    }
};

template<class T, class CompareT, int iSize> class MyArrHeap: public MyHeap<T,
        CompareT>
{
private:
    T arr[iSize+1];
    CompareT compare;
public:

    int iPosition;
    MyArrHeap()
    {
        iPosition = 0;
    }
    MyArrHeap(const MyArrHeap<T, CompareT, iSize>& iArrHeap)
    {
        int i;
        iPosition = iArrHeap.currentPosition();
        if (iPosition >= iSize)
            iPosition = iSize;
        for (i = 1; i < iPosition; i++)
        {
            if (!iArrHeap.getI(i, arr[i]))
                break;
        }
        if (i < iPosition)
            iPosition = i;
    }
    virtual bool setup_heap(int start, int end);
    virtual bool setup_heap_recursive(int start, int end);
    virtual bool setup_heap();
    virtual bool sort();
    virtual bool add(T& e)
    {
        if (iPosition < iSize)
        {
            arr[iPosition++] = e;
            return true;
        }
        else
            return false;
    }
    virtual int size() const
    {
        return iSize;
    }
    virtual bool isEmpty() const
    {
        return iPosition;
    }
    virtual int currentPosition() const
    {
        return iPosition;
    }

    virtual bool getI(int i, T &outT) const
    {
        if (i < iPosition)
        {
            outT = arr[i];
            return true;
        }
        else
        {
            return false;
        }
    }
    virtual bool setI(int i, const T &inT)
    {
        if (i < iPosition)
        {
            arr[i] = inT;
            return true;
        }
        else
        {
            return false;
        }
    }
    virtual void output(std::ostream &o) const
    {
        for (int i=0; i < iPosition; i++)
            o << arr[i] << " ";
    }
};

template<class T, class CompareT, int iSize>
bool MyArrHeap<T, CompareT, iSize>::setup_heap()
{
    setup_heap(0, iPosition);
    return true;
}

template<class T, class CompareT, int iSize>
bool MyArrHeap<T, CompareT, iSize>::setup_heap(int start, int end)
{
    int maxChild, leftChild;
    bool done=false;

    if (start==end) done=true;

    //depends on start from 0 or 1, this is the thing should change
    // start<[]; leftChild==[]
    while ((start <= (end-1)/2)&&(!done))
    {
        leftChild = start + start + 1;
        debug_print(  "l:"<<leftChild<<",e/2-1:"<<end/2-1<<",s:"<<start
                    <<",arr[start]"<<arr[start]
                    <<",arr[leftChild]"<<arr[leftChild]
                    <<std::endl);

        if (leftChild == end)
            maxChild = leftChild; // no child or only one child
        else if (compare(arr[leftChild], arr[leftChild + 1]))
            maxChild = leftChild;
        else
            maxChild = leftChild + 1;

        if (!compare(arr[start], arr[maxChild]))
        {
            compare.swap(arr[start], arr[maxChild], arr[iPosition]);
            start = maxChild;
        }
        else
            done = true;
    }

    return true;
}

template<class T, class CompareT, int iSize>
bool MyArrHeap<T, CompareT, iSize>::setup_heap_recursive(int start, int end)
{
    int maxChild, leftChild;

    leftChild=start+start+1;
    debug_print("start:"<<start<<", l:"<<leftChild<<", e:"<<end<<std::endl);

    if (leftChild < end)
    {
        debug_print("h:"<<leftChild<<",e:"<<end<<std::endl);
        setup_heap_recursive(leftChild, end);
        debug_print("h:"<<leftChild<<",e:"<<end<<std::endl);
        setup_heap_recursive(leftChild + 1, end);
    }
    else if (leftChild > end)
    {
        return true;
    }

    if (leftChild == end)
        maxChild = leftChild; // no child or only one child
    else if (compare(arr[leftChild], arr[leftChild + 1]))
        maxChild = leftChild;
    else
        maxChild = leftChild + 1;

    debug_print("maxChild:"<<maxChild<<"e:"<<end<<std::endl);
    if (!compare(arr[start], arr[maxChild]))
    {
        compare.swap(arr[start], arr[maxChild], arr[iPosition]);
        start = maxChild;
    }

    return true;
}


template<class T, class CompareT, int iSize>
bool MyArrHeap<T, CompareT, iSize>::sort()
{
    int i;

    for (i = ( (iPosition-1) / 2); i >= 0; i--)
    {
        debug_print("i:"<<i<<", current arr:"<<*this<<std::endl);
        setup_heap_recursive(i, iPosition-1);
        //setup_heap(i, iPosition-1);
    }
    debug_print("heaped arr:"<<*this<<std::endl);

    for (i = iPosition-1; i >= 0; i--)
    {
        compare.swap(arr[0], arr[i]);
        debug_print("after swap, i-1:"<<i-1<<", current arr:"<<*this<<std::endl);
        setup_heap_recursive(0, i-1);
        //setup_heap(i, iPosition-1);
        debug_print("i-1:"<<i-1<<", current arr:"<<*this<<std::endl);
    }

    debug_print("sorted arr:"<<*this<<std::endl);
    return true;
}

#endif /* MYHEALP_H_ */
