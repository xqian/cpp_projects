#!/usr/bin/python
import random
import os
import sys
import binarySearch

class ThreeNumberSum():
    N=[]
    def __init__(self, n):
        random.seed(10000)
        for i in range(0,n):
            self.N.append(random.randint(1, n*n*n))
        
    def bruteMethod(self,s):
        print "bruteMethod:"
        l = len (self.N)
        
        for i in range(1,l):
            for j in range (i,l):
                for k in range(j,l):
                    if (self.N[i] + self.N[j] + self.N[k] == s):
                        print "{}+{}+{}={}".format(self.N[i],self.N[j],self.N[k],s)
    
    def smartMethod(self,s):
        print "smartSearch:"
        self.N.sort()
        
        bs = binarySearch.BinarySearch(len(self.N),self.N)
        bs.printN()
        l = len(self.N)
        print 'l={}'.format(l)
        for i in range(0,l):
            for j in range(i+1,l):
                #print 'i={}, j={}, l={}'.format(i,j,l)
                num = s - (self.N[i] + self.N[j])
                if (bs.search(num,j) != -1):
                    print "{}+{}+{}={}".format(self.N[i],self.N[j],num,s)

def ThreeNumberSum_UNITTEST():
    threeSum=ThreeNumberSum(100)
    threeSum.bruteMethod(166348);
    threeSum.smartMethod(166348);

ThreeNumberSum_UNITTEST()                    