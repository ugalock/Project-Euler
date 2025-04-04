"""
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
Which prime, below one-million, can be written as the sum of the most consecutive primes?
"""


from sympy import primerange

# primes = [i for i in primerange(1,1000000)]
# check, length = 0, 0
# for i in range(len(primes)):
#     check += primes[i]
#     if check > 1000000:
#         break
#     length = i
# length equals 545

def findLongestConsecPrimeSumInRange(LowerBound,UpperBound):
    primes = [i for i in primerange(LowerBound,UpperBound)]
    highestChain, largest = 0, 0
    for i, prime in enumerate(primes):
        if prime > 995000:
            for j in range(i):
                total, k = 0, j
                while True:
                    if total == prime:
                        if (k-j) > highestChain:
                            print(prime)
                            highestChain, largest = k-j, prime
                    elif total > prime or (k-j) > 545:
                        break
                    total += primes[k]
                    k += 1        
    return highestChain, largest

print(findLongestConsecPrimeSumInRange(1,1000000))






