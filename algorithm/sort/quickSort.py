#!/usr/bin/python
import sys
import random
class QuickSort():
    N = []
        
    def __init__(self,arr):
        import random
        random.shuffle(arr)
        self.N = arr
        self._size=len(self.N)
        
    def exchange(self, x, y):
        tmp = self.N[x]
        self.N[x] = self.N[y]
        self.N[y] = tmp
        
        
    def isSorted(self):
        return self.checkSorted(0,len(self.N)-1)
        
    def checkSorted(self,low,high):
        if low>= high:
            return True

        for k in range(low,high):
            if self.N[k] > self.N[k+1]:
                print "array not sorted!"
                for kk in range(low,high+1):
                    print self.N[kk]
                return False

        return True
    
    def partition(self, low, high):
        #print "low={},high={}".format(low,high)
        i = low + 1
        j = high
        
        while i <= j:
            while self.N[i] < self.N[low] and i < high:
                i = i + 1
                
            while self.N[j] > self.N[low] and j > low:
                j = j - 1
                
            if ( i >= j):
                break;
            
            self.exchange(i,j)
        
        #find it
        self.exchange(j,low)
        return j
        
    def Sort(self,low,high):
        if (low >= high or low < 0):
            return
            
        pivot = self.partition(low,high) 
        
        self.Sort(low,pivot-1)
        self.Sort(pivot+1, high)
        
    def quickCheckWithPartition(self,k):
        low = 0
        high = len(self.N) - 1
        
        while (low < high):
            pivot = self.partition(low,high)
            if pivot == k:
                return pivot
            elif pivot > k: 
                high = pivot - 1;
            else:
                low = pivot + 1
        
        return k
        
    def quickCheck(self,k):
        kth = self.quickCheckWithPartition(k)
        print "kth=",kth
        for i in range(0,kth):
            print self.N[i]
        
    def quickSort(self):
        self.Sort(0,self._size - 1)
            
    def printN(self):
        print self.N

class QuickSortOpt1(QuickSort):
    def __init__(self,arr):
        QuickSort.__init__(self,arr)
    
    def Sort(self, low, high):
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
            
        return QuickSort.Sort(self, low, high) 

class ThreePartitionQuickSort(QuickSort):
    def __init__(self,arr):
        QuickSort.__init__(self,arr)
    
    def compare(self,a, b):
        if a == b:
            return 0
        elif a < b:
            return -1
        else:
            return 1
    def QuickSort(self):
        self.Sort(0,len(self.N)-1)
        
    def Sort(self, low, high):
        if ( low >= high ):
            return
            
        v = self.N[low]
        lt = low
        i = low
        gt = high
        
        #partition
        while i <= gt:
            r = self.compare(self.N[i], v)
            if r == 0:
                i = i + 1
            elif r < 0:
                self.exchange(i,lt)
                i = i + 1
                lt = lt + 1 
            else:
                self.exchange(i, gt)
                gt = gt - 1
        
        self.Sort(low,lt)
        self.Sort(i,high)
                
def QuickSortUnitTest():
    arrayN = []
    random.seed(10000000)
    
    for i in range(0,10):
        arrayN.append(random.randint(1, 100000))
    print arrayN
    m = QuickSortOpt1(arrayN)
    m.quickSort()
    m.printN()
    assert(m.isSorted())

#Find kth smallest value
def QuickCheckUnitTest():
    arrayN = []
    random.seed(1000000)

    for i in range(0,10000):
        arrayN.append(random.randint(1, 100000))
    print arrayN
    m = QuickSortOpt1(arrayN)
    m.quickCheck(100)
    
    m = QuickSortOpt1(arrayN)
    m.quickSort()
    m.printN()
    assert(m.isSorted())

#Find kth smallest value
def ThreewayPartitionQuicksortUnitTest():
    arrayN = []
    random.seed(1000000)

    for i in range(0,1000000):
        x = random.randint(1, 100000)
        arrayN.append(x)
        arrayN.append(x)
        arrayN.append(x)
        
    print arrayN
    m = ThreePartitionQuickSort(arrayN)
    m.QuickSort()
    m.printN()
    assert(m.isSorted())

#QuickSortUnitTest()
#TODO : WHEN SIZE IS LARGE, IT'S VERY SLOW!!!!

#QuickCheckUnitTest()

ThreewayPartitionQuicksortUnitTest()

