# Radis sort requires integer as key. So assiociated key index need just handle the key part.

import os, sys

class KeyIndexedRadixSort():
	def __init__(self, a=[]):
		self.a = a
		self.R = 10  #ascii
		self.aux = [0]*len(a)

	def sort(self):
		N = len(self.a)
		count = [0] * (self.R + 1)
		
		print 'self.a: {}'.format(self.a)
		#compute the times each character appear
		for i in range(0,N):
			count[self.a[i][0]+1]+=1

		print 'first count:{}'.format(count)
		#cumulative to compute the actual position
		for i in range(0,self.R):
			count[i+1] += count[i]

		print 'after cumlative:{}'.format(count)

		# aux variable
		for i in range(0,N):
			self.aux[count[self.a[i][0]]] = self.a[i]
			count[self.a[i][0]] += 1
		print 'aux= {}'.format(self.aux)

		#copy back
		self.a = self.aux


	def printList(self):
		print self.a

def UnitTest():
	words = [[5,'abc'], [1,'this'],[4,'dsf'],[2,'dffds'],[2,'pdfs'],[8,'lfjsd'],[6,'fdsfs']]
	RS = KeyIndexedRadixSort(words)
	RS.sort()
	RS.printList()

UnitTest()




