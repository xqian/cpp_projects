#!/usr/bin/python
import random
import os
import sys

class BinarySearch():
	N = []
	
	def __init__(self, n, N1=[]):
	    if (len(N1) != 0):
	        self.N = N1;
	        return
	        
	    random.seed(10000)
	    for i in range(0,n):
	        self.N.append(random.randint(1, n*n*n))
	    
	    self.N.sort()
	    self.printN()
	
	def search(self,m,low=0):
	    high = len(self.N)
	    
	    while low <= high:
	        mid = low + (high - low)/2
	        #print "mid={},high={},low={}".format(mid,high,low)
	        if (self.N[mid] == m):
	            return mid
	        elif (self.N[mid] > m):
	            high = mid - 1
	        else:
	            low = mid + 1
	            
	    return -1
	    
	def printN(self):
	    print self.N
	    

def BinarySearch_UNITTEST():
	bs = BinarySearch(100)
	bs.printN()
	
	for i in range(31978,31999):
	    ret = bs.search(i)
	    if (ret == -1):
	        print "{}: ret=N[{}], NOT FOUND".format(i,ret)
	    else:
	        print "{}: ret=N[{}], {}".format(i,ret,bs.N[ret])
	        
#BinarySearch_UNITTEST()