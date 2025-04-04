"""
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
"""
from sympy.ntheory import isprime

def checkDigits(a, b):
    digitsA, digitsB = 0, 0
    while a > 0:
        temp = a % 10
        # if (digitsA & (1 << temp)) > 0:
        #     return False
        digitsA |= (1<<temp)
        a = a // 10
    while b  > 0:
        temp = b % 10
        # if (digitsB & (1 << temp)) > 0:
        #     return False
        digitsB |= (1<<temp)
        b = b // 10
    return digitsA == digitsB

def getFourDigitPrimesSequence():
    results= []
    for i in range(1488, 10000):
        if isprime(i):
            for j in range(1, int((10000-i)/2)):
                if isprime(i+j) and checkDigits(i, i+j):
                    if isprime((i+2*j)) and checkDigits(i, (i+2*j)):
                        return(str(i)+str(i+j)+str(i+2*j))

print(getFourDigitPrimesSequence())




