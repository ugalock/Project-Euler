"""
Euler's Totient function, φ(n)is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.

n   Relatively Prime    φ(n)    n/φ(n)
2   1                   1       2
3   1,2                 2       1.5
4   1,3                 2       2
5   1,2,3,4             4       1.25
6   1,5                 2       3
7   1,2,3,4,5,6         6       1.1666...
8   1,3,5,7             4       2
9   1,2,4,5,7,8         6       1.5
10  1,3,7,9             4       2.5
It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
"""
from primes import lessThan1e6
from functools import reduce

primes = lessThan1e6

def prime_factors(n):
    i = 2
    factors = set()
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.add(i)
    if n > 1:
        factors.add(n)
    return factors

def totientRatio(n):
    factors = prime_factors(n)
    res = reduce(lambda x,y: x*y, [(1 - 1/f) for f in factors], n) 
    return n / res

def getHighestRatio():
    best = 5.213541666666665
    res = 180180
    for i in range(500004,1000000,6):
        if i not in primes:
            curr = totientRatio(i)
            if curr > best:
                best = curr
                res = i
                print(best, i)
    return best, res

print(getHighestRatio())
