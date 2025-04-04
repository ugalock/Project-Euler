"""
Find the smallest odd composite integer that cannot be written
as the sum of a prime and twice a square
"""
from sympy import primerange, isprime


def isSqr(n):
    return n**.5 == int(n**.5)

def disproveGoldbach():
    for odd in range(33,6000,2):
        if not isprime(odd):
            check = False
            for prime in primerange(1, odd):
                if isSqr((odd - prime)/2):
                    check = True
            if not check:
                return odd
print(disproveGoldbach())   


# n = 3
# while True:
#     n+=2
#     if isprime(n):
#         continue
#     else:
#         if any(isprime(n-2*i*i) for i in range(1, n)):
#             continue
#         else:
#             print(n)
#             break        

