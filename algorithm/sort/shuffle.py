import sys
import random

class KnuthRandomShuffle():
    def __init__(self,arr):
        self.N = arr
    
    def exchange(self, i, j):
        tmp = self.N[i]
        self.N[i] = self.N[j]
        self.N[j] = tmp
        
    def RandomShuffle(self):
        for i in range(1,len(self.N)):
            #generate a random number
            r = random.randint(0,i-1)
            self.exchange(i,r)
            
        print self.N

def KnuthRandomShuffleUnitTest():
    arrayN = []
    random.seed(10000000)

    for i in range(0,100):
        arrayN.append(i)

    print arrayN
    m = KnuthRandomShuffle(arrayN)
    for i in range(1,4):
        m.RandomShuffle()
    

if __name__ == '__main__':
    KnuthRandomShuffleUnitTest()
