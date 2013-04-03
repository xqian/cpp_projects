#http://www.bryceboe.com/2006/10/23/line-segment-intersection-algorithm/

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

'''
The solution involves determining if three points are listed in a counterclockwise order.
So say you have three points A, B and C. If the slope of the line AB is less than the slope
of the line AC then the three points are listed in a counterclockwise order.
'''
def ccw(A, B, C):
    '''
    Kab = (B.y - A.y ) / (B.x - A.x)
    Kac = (C.y - A.y ) / (C.x - A.x)
    Kab > Kac ?
    '''
    return (B.y - A.y) * (C.x -A.x) > (C.y - A.y) * (B.x - A.x)
    
'''
AB, CD

'''
def intersect(A,B,C,D):
    return ccw(A,B,C) != ccw(A,B,D) and ccw(C,D,A) != ccw(C,D,B)
    
a = Point(0,0)
b = Point(0,1)

c = Point(1,1)
d = Point(1,0)

print intersect(a,b,c,d)
print intersect(a,c,b,d)
print intersect(a,d,b,c)

    