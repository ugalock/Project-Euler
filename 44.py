"""
Pentagonal numbers given by P(n) = n(3n-1)/2
Find the pair of pentagonal numbers P(i)+P(j) E P(n)
s.t. |P(i) - P(j)| is minimized
"""
import math

def getNPentagonals(N):
    return set(int((3*n**2-n)/2) for n in range(1, N+1))


def isPentagonal(n):
    return (((24*n+1)**(.5)+1)/6).is_integer()    

s = getNPentagonals(2500)

def findPentagonalPairIn(lst):
    minimum = float('inf')
    for i in lst:
        for j in lst:
            if isPentagonal(i+j) and isPentagonal(abs(i - j)) and (abs(i - j) < minimum):
               return abs(i - j)
    

print(findPentagonalPairIn(s))