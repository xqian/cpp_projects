//
//  main.cpp
//  HashTable
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "HashTable.h"
#include <sstream>

void hashTest () {
        cout << "hashTest" << endl;
        Table tb;
        istringstream ss;
        ss.str("abc cba dbe ade cba abc abc");
        string buf = "";
        while (ss >> buf)
                tb.put((char *)buf.c_str());
        tb.print();        
        cout << tb.get((char*)"abc") << endl;
        cout << tb.get((char*)"ads") << endl;
        cout << tb.get((char*)"ade") << endl;
        tb.print();
};


int main(int argc, const char * argv[])
{
    hashTest();
    return 0;
}
