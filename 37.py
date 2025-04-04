"""
trunctable primes from R to L and L to R
3797 -> 797 -> 97 -> 7 are all prime
3797 -> 379 -> 37 -> 3 are all prime
find sum of the 11 numbers that satisfy both
"""
from sympy.ntheory import isprime, sieve
import math

def removeFirstDigit(n):
    return n - (n // 10**int(math.log10(n)))*10**int(math.log10(n))

def getFirstDigit(n):
    return n // 10**int(math.log10(n))

def checkLtoR(n):
    while n > 0:
        if isprime(n):
            n = removeFirstDigit(n)
        else:
            return False
    return True 

def checkRtoL(n):
    while n > 0:
        if isprime(n):
            n = n // 10
        else:
            return False
    return True

def findTrunctablePrimes():
    total = 0
    count = 0
    while count < 11:
        for i in sieve.primerange(9,1000000):
            if checkRtoL(i) and checkLtoR(i):
                total += i
                count += 1
    return total

print(findTrunctablePrimes())




