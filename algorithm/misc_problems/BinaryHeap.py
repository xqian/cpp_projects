import sys
import os
import random

class BinaryHeap(object):
    N = 0
    PQ = [0]
    
    def __init__(self):
        pass
        
    def isEmpty(self):
        return N == 0
    
    def exch(self,i,j):
        #print 'i={},j={}'.format(i,j)
        tmp = self.PQ[i]
        self.PQ[i] = self.PQ[j]
        self.PQ[j] = tmp
        
    def swim(self,k):
        while k > 1:
            if self.PQ[k] > self.PQ[k/2]:
                self.exch(k,k/2)
                k = k/2
            else:
                break

    def insert(self,value):
        self.PQ.append(value)
        self.N = self.N + 1
        #self.swim(self.N)
    
    def sink(self,k):
        while k < self.N:
            j = 2 * k
            
            if j > self.N:
                break
            
            if j < self.N and self.PQ[j] < self.PQ[j+1]:
                j = j + 1
            
            if self.PQ[j] > self.PQ[k]:
                self.exch(j,k)
                k = j
            else:
                break
                
    def delMax(self):
        if self.N == 0:
            return

        maxValue=self.PQ[1]
        
        tmp=self.PQ.pop()
        self.N = self.N - 1
        
        if self.N > 0:
            self.PQ[1]=tmp
            
        self.sink(1)    
        
        return maxValue
        
    def buildHeap(self):
        l = self.N / 2
        while (l > 1):
            self.sink(l)
            l = l - 1
        
    def HeapSort(self):
        self.buildHeap()
        while self.N > 1:
            self.exch(1,self.N)
            self.N = self.N - 1
            self.sink(1)
        
        
class BinaryHeap1():
    PQ = []
    N = 0
    def __init__(self,arr):
        self.PQ = arr
        self.N = len(arr)
        
    def isEmpty(self):
        return self.N == 0

    def exch(self,i,j):
        #print 'i={},j={}'.format(i,j)
        tmp = self.PQ[i]
        self.PQ[i] = self.PQ[j]
        self.PQ[j] = tmp
                
    def sink(self,k):
        while 2 * k + 1 < self.N:
            j = 2 * k + 1

            if j < self.N - 1 and self.PQ[j] < self.PQ[j+1]:
                j = j + 1

            if self.PQ[j] > self.PQ[k]:
                self.exch(j,k)
                k = j
            else:
                break

    def buildHeap(self):
        l = (self.N - 2) / 2
        while (l >= 0):
            self.sink(l)
            l = l - 1

    def HeapSort(self):
        self.buildHeap()
        
        print self.PQ
        
        while self.N > 0:
            self.exch(0,self.N-1)
            self.N = self.N - 1
            self.sink(0)
        
def UnitTest():
    bh=BinaryHeap()
    
    for i in range(1,100000):
        bh.insert(random.randint(1, 100000))
    
    print bh.PQ
    
    for i in range(1,100000):
        print bh.delMax(),','

def HeapSortTest():
    bh=BinaryHeap()

    for i in range(0,5):
        bh.insert(random.randint(0, 10))

    print bh.PQ

    bh.HeapSort()
    print bh.PQ
    
def HeapSortTest2():
    arr = []
    for i in range(0,100):
        arr.append(random.randint(0, 1000))
    
    print arr
    bh=BinaryHeap1(arr)
    print bh.PQ
    bh.HeapSort()
    print arr

HeapSortTest2()
#UnitTest()