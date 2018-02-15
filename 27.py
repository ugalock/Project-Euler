import math

def isPrime(num):
    if num == 3 or num == 2:
        return True
    if (num % 2 == 0) or (num % 3) == 0 or (num == 1):
        return False
    i = 5
    w = 2
    while i < math.sqrt(num):
        if num % i == 0:
            return False
        else:
            i += w
            w = 6 - w
    return True

def getPrimes(bound):
    return [i for i in range(bound) if isPrime(i)]


def getQuadratic(primeBound, aMin, aMax, bMax):
    primes = getPrimes(primeBound)
    maxLength = 0
    pairAB = []
    for a in range(aMin,aMax,2):
        bRange = [x for x in primes if x < bMax]
        for b in bRange :
            n = 0
            count = 0
            while (n**2 + a*n + b) in primes:
                n += 1
                count += 1
            if count > maxLength:
                maxLength = count
                pairAB = [a, b]
    return (maxLength, pairAB)

print(getQuadratic(1800,-999,999,999))






