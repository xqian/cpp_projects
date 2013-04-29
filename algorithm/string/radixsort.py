import os, sys

class RadixSort():
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
			count[self.a[i]+1]+=1

		print 'first count:{}'.format(count)
		#cumulative to compute the actual position
		for i in range(0,self.R):
			count[i+1] += count[i]

		print 'after cumlative:{}'.format(count)

		# aux variable
		for i in range(0,N):
			count[self.a[i]] += 1
			self.aux[count[self.a[i]]] = self.a[i]   #??
		print 'aux= {}'.format(self.aux)

		#copy back
		self.a = self.aux


	def printList(self):
		print self.a

def UnitTest():
	words = [5,1,4,2,2,8,6]
	RS = RadixSort(words)
	RS.sort()
	RS.printList()

UnitTest()




