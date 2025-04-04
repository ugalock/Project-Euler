"""
find the largest n-digit pandigital prime
only searching 7 digit numbers because 5,6,8,9 digit
nums are all div by 3
"""
import math
from sympy import sieve

def isPandigital(n):
    digits = 0
    num = n
    while num > 0:
        temp = num % 10
        if temp == 0: 
            return False
        if (digits & (1 << temp)) > 0:
            return False
        digits |= (1 << temp)
        num = num // 10
    if digits != (2**(int(math.log10(n)) + 2) - 2):
        return False
    return True

def findLargestPanPrime():
    highest = 0
    for i in sieve.primerange(1000000, 10000000):
        if isPandigital(i) and i > highest:
            highest = i
    return highest
print(findLargestPanPrime())

