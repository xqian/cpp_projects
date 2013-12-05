//
//  Node.h
//  HashTable
//
//  Created by Qian, Anson on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef HashTable_Node_h
#define HashTable_Node_h

#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>

#define MAXLEN 256

class Node {
public:
    Node(char* s, Node* p) { 
        assert(s != NULL);
        strncpy(word, s, MAXLEN); 
        count = 1;
        next = p; 
    };
    void set(Node* p) { 
        assert(p != NULL);
        strncpy(word, p->getWord(), MAXLEN); 
        count = p->getCount();
        next = p->getNext(); 
    };
    void addCount () {
        count++;
    };
    void decCount () {
        count--;
    };
    int getCount() {
        return count;
    };
    Node* getNext() {
        return next;
    };
    char* getWord() {
        return word;
    }
private:
    char word[MAXLEN];
    Node* next;
    int count;
};

#endif
