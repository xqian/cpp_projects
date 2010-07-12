/*
 * xinqian.cc
 *
 *  Created on: May 8, 2010
 *      Author: xqian
 */

#include "xinqian.h"

int TestCase::lcs()
{
    size_t i,j;
    for (i = 0; i < str1.size(); i++)
        for (j = 0; j < str2.size(); j++)
        {
            if (str1[i]==str2[j])
            {
                *lcsij(i,j)=*lcsij(i-1,j-1)+1;
            }
            else
            {
                if (*lcsij(i,j-1)>*lcsij(i-1,j))
                    *lcsij(i,j)=*lcsij(i,j-1);
                else
                    *lcsij(i,j)=*lcsij(i-1,j);
            }
            debug_print("i:"<<i<<", j:"<<j<<", lcsij:"<<*lcsij(i,j)<<endl);
        }
    return *lcsij(str1.size()-1,str2.size()-1) ;
}

