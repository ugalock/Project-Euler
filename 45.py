"""
Triangle num: T(n) = n(n-1)/2
Pentagonal num: p(n) = n(3n-1)/2
Hexagonal num: H(n) = n(2n-1)
Find the number x after 40755 that is in T, P, and H
"""

def isHexagonal(n):
    return (((8*n+1)**(.5)+1)/4).is_integer()

def isPentagonal(n):
    return (((24*n+1)**(.5)+1)/6).is_integer() 

def isTriangular(n):
    return (((8*n+1)**(.5)-1)/2).is_integer()

def genNHexagonals(N):
    for i in range(400,N):
        yield i*(2*i-1)

g = genNHexagonals(500000)

def findTriPentHex():
    for i in g:
        if isPentagonal(i): 
            return i

print(findTriPentHex())