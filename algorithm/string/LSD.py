import os, sys

class LSDSort():
	def __init__(self, a=[]):
		self.a = a
		self.R = 256  #ascii
		self.aux = [0]*(len(a))

	def sort(self):
		N = len(self.a)
		
		print 'self.a: {}'.format(self.a)
		length = len(self.a[0])
		print 'length=',length

		for d in range(length-1,-1,-1):
			bucket = [0] * (self.R + 1)
			print bucket

			#compute the times each character appear
			for i in range(0,N):
				lsd = self.a[i][d]
				bucket[ord(lsd)]+=1

			print 'first bucket:{}'.format(bucket)
			#cumulative to compute the actual position
			for i in range(0,self.R):
				bucket[i+1] += bucket[i]

			print 'after cumlative:{}'.format(bucket)

			
			# aux variable
			for i in range(0,N):
				lsd = self.a[i][d]
				print 'lxb:',bucket[ord(lsd)], 'N=',N,'i=',i
				self.aux[bucket[ord(lsd)]] = self.a[i]
				bucket[ord(lsd)] += 1
			print 'aux= {}'.format(self.aux)
			import pdb;pdb.set_trace()

			#copy back
			self.a = self.aux


	def printList(self):
		print self.a

def UnitTest():
	data=[]
	with open ("airport.csv", "r") as myfile:
		for line in myfile.readlines():
			data.append(line.replace('\n', '')) 
	print data

	RS = LSDSort(data)
	RS.sort()
	RS.printList()

UnitTest()




