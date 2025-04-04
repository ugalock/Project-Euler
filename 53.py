"""
It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
"""

from math import factorial

def nCr(n, r):
    return int(factorial(n)/(factorial(r)*factorial(n-r)))

def getCombosOverBound(bound):
    count = 0
    for i in range(1, 101):
        tempCount = 0
        for j in range(2, int(i/2)+1):
            if nCr(i, j) > bound:
                tempCount += 1
            print(i, j, tempCount)
        if i % 2 == 1:
            count += (tempCount*2)
        elif tempCount:
            count += ((tempCount*2) - 1)
    return count

print(getCombosOverBound(1000000))