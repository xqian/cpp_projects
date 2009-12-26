/*
 * main.cc
 *
 *  Created on: Dec 12, 2009
 *      Author: Qian Xin
 */

#include "iostream"
#include "vector"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "myHeap.h"
#include "xinqian.h"

int debug_level = 1;

int main()
{
    const int CArraySize = 8;
    int arr_int[CArraySize];

    vector<int> vec_int;
    vector<int>::iterator vec_int_i;
    MyArrHeap<int,DefaultCompare<int>,CArraySize> heap;
    int i;

    srand(10);

    for (i = 0; i < CArraySize; i++)
    {
        arr_int[i]=rand() % 100;
        vec_int.push_back(arr_int[i]);
        heap.add(arr_int[i]);
        debug_print("i:"<<i<<",v:"<<arr_int[i]<<endl);
    }

    cout<<"heap content:"<<heap<<endl;

    debug_print("vec_int size:"<<vec_int.size()<<endl);
    debug_print("heap size:"<<heap.size()<<", ipos:"<<heap.currentPosition()<<endl);
    debug_print("heap content:"<<heap<<endl);

    heap.sort();
    cout<<"sorted heap content:"<<heap<<endl;
}
