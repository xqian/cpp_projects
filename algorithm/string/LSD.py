import os, sys

class LSDSort():
	def __init__(self, a=[]):
		self.a = a
		self.R = 256  #ascii
		self.aux = [0]*len(a)

	def sort(self):
		N = len(self.a)
		
		print 'self.a: {}'.format(self.a)

		for d in range(len(self.a[0])-1,-1,-1):
			count = [0] * (self.R + 1)

			#compute the times each character appear
			for i in range(0,N):
				lsd = self.a[i][d]
				count[ord(lsd)+1]+=1

			print 'first count:{}'.format(count)
			#cumulative to compute the actual position
			for i in range(0,self.R):
				count[i+1] += count[i]

			print 'after cumlative:{}'.format(count)

			import pdb;pdb.set_trace()

			# aux variable
			for i in range(0,N):
				lsd = self.a[i][d]
				print 'lxb:',count[ord(lsd)], 'N=',N,'i=',i
				self.aux[count[ord(lsd)]] = self.a[i]
				count[ord(lsd)] += 1
			print 'aux= {}'.format(self.aux)

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




