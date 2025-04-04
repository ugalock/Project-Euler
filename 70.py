"""
Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find n, 1 < n < 10^7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.
"""
from functools import reduce
from math import log10
from collections import Counter
from primes import lessThan1e6

def checkDigits(a, b):
    if int(log10(a)) != int(log10(b)):
        return False
    return Counter(str(a)) == Counter(str(b))


def prime_factors(n):
    i = 2
    factors = set()
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.add(i)
        if len(factors) > 2:
            return [2]
    if n > 1:
        factors.add(n)
    return factors

def totient(n):
    return reduce(lambda x,y: x*y, [(1 - 1/f) for f in prime_factors(n)], n)


primes = [p for p in lessThan1e6 if p > 2000 and p < 5000]

def getRatio():
    minRatio = 100
    n = 0
    for i in range(len(primes)):
        for j in range(i+1, len(primes)):
            curr = primes[i]*primes[j]
            if curr < 10000000:
                t = int(totient(curr)) 
                if checkDigits(curr, t) and curr / t < minRatio:
                    minRatio, n = curr / t, curr
                    print(minRatio, curr)

    return minRatio, n

print(getRatio())

