import sys
import os
import random
# Maintain max n value
class UnorderedPQ():
    def __init__(self,capacity=10):
        self.maxSize = capacity
        self.PQ=[]
        
    def insert(self,n):
        if len(self.PQ) < self.maxSize:
            self.PQ.append(n)
        else:
            #remove max value and then insert
            minV=min(self.PQ)
            if n > minV:
                self.PQ.remove(minV)
                self.PQ.append(n)
    
    def delMax(self):
        n=max(self.PQ)
        self.PQ.remove(n)
        return n

class OrderedPQ(UnorderedPQ):
    def exch(self):
        maxV=max(self.PQ)
        maxIndex=self.PQ.index(maxV)
        if self.PQ[0] != maxV:
                tmp = self.PQ[0]
                self.PQ[0] = self.PQ[maxIndex]
                self.PQ[maxIndex] = tmp
                
    def insert(self,n):
        UnorderedPQ.insert(self, n)
        self.exch()

    def delMax(self):
        n=self.PQ[0]
        self.PQ.remove(n)
        return n

def TestUnorderedPQ():
    pq=OrderedPQ(3)
    random.seed(10000)
    
    for i in range(0,10):
        k=random.randint(1, 100000)
        pq.insert(k)
        print '[',k,']',pq.PQ
    
TestUnorderedPQ()