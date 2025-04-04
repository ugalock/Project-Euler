"""
The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
"""
from sympy import primerange, isprime
from math import log10
def concat5nums(a, b, c, d, e):
    result = []
    digits = int(log10(a)) + 1
    for n in [b, c, d, e]:
        if not isprime(n*int(10**digits)+a):
            return False
    digits = int(log10(b)) + 1
    for n in [a, c, d, e]:
        if not isprime(n*int(10**digits)+b):
            return False
    digits = int(log10(c)) + 1
    for n in [a, b, d, e]:
        if not isprime(n*int(10**digits)+c):
            return False
    digits = int(log10(d)) + 1
    for n in [a, b, c, e]:
        if not isprime(n*int(10**digits)+d):
            return False
    digits = int(log10(e)) + 1
    for n in [a, b, c, d]:
        if not isprime(n*int(10**digits)+e):
            return False
    return True

primes = list(primerange(3, 30000))
length = len(primes)

pairs = dict()
def concatAndHash(a, b):
    digitsA = int(log10(a)) + 1
    digitsB = int(log10(b)) + 1
    if isprime(a*int(10**digitsB)+b) and isprime(b*int(10**digitsA)+a):
        pairs[a*b] = True
    else:
        pairs[a*b] = False

def getPairs():
    for i in range(length):
        for j in range(i+1, length):
            if primes[i]*primes[j] not in pairs:
                concatAndHash(primes[i], primes[j])

def find5primes():
    for a in primes:
        for b in primes: 
            if b > a and pairs[a*b]:
                for c in primes: 
                    if c > b and pairs[b*c] and pairs[a*c]:
                        for d in primes: 
                            if d > c and pairs[d*c] and pairs[d*b] and pairs[a*d]:
                                for e in primes: 
                                    if e > d and pairs[a*e] and pairs[b*e] and pairs[c*e] and pairs[d*e]:
                                        print(a,b,c,d,e, a+b+c+d+e)

                        
getPairs()
print(find5primes())
