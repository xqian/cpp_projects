#!/usr/bin/python
import sys
import random
class MergeSort():
    N = []
    auxN = []
    
    def isSorted(self,low,high):
        if low>= high:
            return True
        
        for k in range(low,high):
            if self.N[k] > self.N[k+1]:
                print "array not sorted!"
                for kk in range(low,high+1):
                    print self.N[kk]
                return False
        
        return True
        
        
    def __init__(self,arr):
        import random
        self.N = arr
        random.shuffle(self.N)
        
        for i in range(0,len(arr)):
            self.auxN.append(arr[i])
        
    def merge(self, low, mid, high):
        if (low >= high):
            return
        
        assert(self.isSorted(low,mid))
        assert(self.isSorted(mid+1,high))
        
        i = low
        j = mid+1
        
        #copy to auxN
        for k in range(low,high+1):
            self.auxN[k] = self.N[k]
            
        #merge
        for k in range(low,high+1):
            if i > mid:
                self.N[k] = self.auxN[j]
                j = j + 1
            elif j > high:
                self.N[k] = self.auxN[i]
                i = i + 1
            elif self.auxN[i] > self.auxN[j]:
                self.N[k] = self.auxN[j]
                j = j + 1
            else:
                self.N[k] = self.auxN[i]
                i = i + 1

    def Sort(self,low,high):
        if (low >= high):
            return
            
        mid = low + (high - low)/2;
        
        self.Sort(low,mid)
        self.Sort(mid+1,high)
        
        self.merge(low,mid,high)
        
    def mergeSort(self):
        self.Sort(0,len(self.N)-1)
            
    def printN(self):
        print self.N

class MergeSortOpt1(MergeSort):
    def __init__(self,arr):
        MergeSort.__init__(self,arr)
    
    def merge(self, low, mid, high):
        #if array size is less than 5, just sort it with insert sort
        if (high - low <= 5):
            #Insert Sort
            for i in range(low,high+1):
                for j in range(i+1,high+1):
                    if self.N[i] > self.N[j]:
                        tmp = self.N[i]
                        self.N[i] = self.N[j]
                        self.N[j] = tmp
            return
            
        return MergeSort.merge(self,low,mid,high) 
        
        
def UnitTest():
    arrayN = []
    random.seed(10000000)
    
    for i in range(0,10000000):
        arrayN.append(random.randint(1, 10000000))
    print arrayN
    m = MergeSort(arrayN)
    m.mergeSort()
    m.printN()

UnitTest()