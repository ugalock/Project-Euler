"""
Find the last ten digits of the series 1^1 + 2^2 +...+1000^1000
"""
from functools import reduce

def findLastNDigitsOfSeriesUpToX(N, X):
    resultBound = N
    total = 0
    for x in range(1, X+1):
        total += ((x**x) % resultBound)
        total = total % resultBound
    return total

# print(findLastNDigitsOfSeriesUpToX(10**10, 1000))

print(reduce(lambda x,y: x+y, [i ** i for i in range(1, 1000)]) % 10**10)