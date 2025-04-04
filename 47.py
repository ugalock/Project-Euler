"""
Find the first four consecutive numbers with four distinct prime factors each
Return the first of these numbers
"""
def findDistinctPrimeFactors(n):
    i = 2
    factors = dict()
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            if i in factors.keys():
                factors[i] += 1
            else: 
                factors[i] = 1
    if n > 1:
        if n in factors.keys():
            factors[n] += 1
        else:
            factors[n] = 1
    return {int(x**(factors[x])) for x in factors.keys()}

def findFourConsecNums(i):
    if len(findDistinctPrimeFactors(i)) == 4:
        if len(findDistinctPrimeFactors(i+1)) == 4:
            if len(findDistinctPrimeFactors(i+2)) == 4:
                if len(findDistinctPrimeFactors(i+3)) == 4:
                    if (len(findDistinctPrimeFactors(i) | findDistinctPrimeFactors(i+1) | findDistinctPrimeFactors(i+2) | findDistinctPrimeFactors(i+3))) == 16:
                        return True
            
def findDistinctFourPrimeFactors():
    for i in range(647, 10000000):
        if findFourConsecNums(i):
            return i
    return False
# print(findDistinctFourPrimeFactors())


# Five consecutive = 129963314

