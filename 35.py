"""
Note that for a number to be prime in all it's digital permutations, it cannot
contain the digits {0, 2, 4, 5, 6, 8}
Also, it cannot have all of the remaing digits {1, 3, 7, 9} because 
1379 / 7 == 197
"""
import math
from sympy import sieve

def checkDigits(a):
    not_allowed = [0, 2, 4, 5, 6, 8]
    while a > 0:
        temp = a % 10
        if temp in not_allowed:
            return False
        a = a // 10
    return True

def isPrime(num):
    bound = math.sqrt(num)
    if num % 2 == 0:
        return False
    elif num % 3 == 0:
        return False
    i, j = 5, 2
    while i <= bound:
        if num % i == 0:
            return False
        else:
            i += j
            j = 6 - j
    return True

def getPrimesLessThan(num):
    primes = []
    for i in range(1001, num, 2):
        if isPrime(i):
            primes.append(i)
    return primes

def cycleInt(num):
    numDigitsIsh = math.floor(math.log10(num))
    perms = []
    perms.append(num)
    i = numDigitsIsh
    while i > 0:
        temp = num % 10
        num = num // 10
        num += temp * math.pow(10, numDigitsIsh)
        perms.append(int(num))
        i -= 1
    return perms

def circ(x):
    c = []
    for i in range(len(str(x))):
        c.append(str(x)[i:]+str(x)[0:i])
    return c

def isCirc(x):
    cir = circ(x)
    for i in cir:
        if not isPrime(int(i)):
            return False
    return len(cir)

def getCircularPrimes():
    total = 25
    primes = getPrimesLessThan(1000000)
    for i in primes:
        temp = isCirc(i)
        if temp:
            for x in circ(i):
                primes.remove(x)
        total += temp
        # if all(x in primes for x in cycle):
        #     total += len(cycle)
        #     print(cycle)
        #     for c in cycle:
        #         primes.remove(c)
    return total

print(getCircularPrimes())





    