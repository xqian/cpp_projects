//
//  HashTable.h
//  HashTable
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef HashTable_HashTable_h
#define HashTable_HashTable_h

#include "Node.h"
#include <iostream>

using namespace std;

#define NHASH 29989
#define MULT 31

class Table {
public:
    Table() {
        for (int i = 0; i < NHASH; i++) 
            bin[i] = NULL;
    };
    void put(char *s) {
        int h = hash(s);
        if (NULL != bin[h]) {
            for (Node* p = bin[h]; p!= NULL; p = p->getNext())
                if (strncmp(p->getWord(), s, MAXLEN) == 0) {
                    p->addCount();
                    return;
                }
        }
        Node* p = new Node(s, bin[h]);
        bin[h] = p;        
    };
    bool get(char *s) {
        bool res = false;
        int h = hash(s);
        Node* p;
        if (bin[h] != NULL) {
            for (p = bin[h]; p!= NULL; p = p->getNext())
                if (strncmp(p->getWord(), s, MAXLEN) == 0) {
                    res = true;
                    break;
                }
        }
        if (res) {
            if (p->getCount() == 1) {
                Node* pnext = p->getNext();
                if (pnext!= NULL) {
                    p->set(pnext);        
                    delete pnext;
                    pnext = NULL;
                } else {
                    delete p;
                    if (p == bin[h])
                        bin[h] = NULL;
                    p = NULL;
                }
            }
            else
                p->decCount();
        }
        return res;
    };
    void print() {
        for (int i = 0; i< NHASH; i++)
            for (Node* p = bin[i]; p != NULL; p = p->getNext())
                cout << p->getWord() << ":" << p->getCount() << endl;
    };
private:
    int hash(char *p) {
        unsigned long long h = 0;
        for (; *p; p++) {
            assert(h < INT_MAX);
            h = MULT * h + *p;
        }
        h %= NHASH;
        return static_cast<int> (h);
    };
    Node* bin[NHASH];
};


#endif
