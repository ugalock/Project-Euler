"""
By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
"""
# int(math.log10(n))

import math
from sympy import primerange, isprime

def replaceNthDigit(n, r, num):
    temp = num
    digit = (temp // 10**(n-1)) % 10
    return num - digit * 10**(n-1) + r * 10**(n-1)



def isCandidate(n):
    digits = 0
    num = n
    while num > 0:
        temp = num % 10
        if temp == 0:
            temp = 10
        digits |= (1 << temp)
        num = num // 10
    digits -= 1024
    if digits <= 0:
        return False
    if math.log2(digits) > 4:
        return False
    return (math.log2(digits)).is_integer()

def getDifference(n):
    digits = 0
    num = n
    while num > 0:
        temp = num % 10
        if temp == 0:
            temp = 10
        digits |= (1 << temp)
        num = num // 10
    digits -= 1024
    return int(n / (math.log2(digits)))

def check(a,b):
    count = 0
    while a > 0 and b > 0:
        tempA = a % 10
        tempB = b % 10
        if tempA != tempB and count == 0:
            count += 1
            diffA = tempA
            diffB = tempB
            if diffA not in [0, 1] or diffB not in [2, 3]:
                return False
        if tempA != tempB and count > 0 and (tempA != diffA or tempB != diffB):
            return False
        a = a // 10
        b = b // 10
    return True

def findPrimeFamilyWithNMembers(N):
    primes = list(primerange(100000, 1000000))
    for i in range(len(primes)):
        for j in range(i+1, len(primes)):
            if primes[j]-primes[i] > 125000:
                break
            if isCandidate(primes[j]-primes[i]) and check(primes[i], primes[j]):
                diff = getDifference(primes[j]-primes[i])
                count = 1
                num = primes[i]
                for n in range(9):
                    num += diff
                    if int(math.log10(num)) != int(math.log10(primes[i])):
                        break
                    if num in primes:
                        count += 1
                    if count == N:
                        return primes[i], primes[j]
    return False
print(findPrimeFamilyWithNMembers(8))
# import time
# import collections

# start_time = time.clock()

# def find_number():
#     for i in range(1,1000000):
#         if isprime(i):
#             str_i = str(i)
#             count_dict = collections.Counter(str_i)
#             for key in count_dict:
#                 if key in ['0','1'] and count_dict[key] >= 3:
#                     count = 0
#                     for k in range(10):
#                         new = str_i.replace(key,str(k))
#                         if len(str(int(new))) == len(str_i) and isprime(int(new)):
#                             count += 1
#                         if count == 8:
#                             return i

# print(find_number())  
# end_time = time.clock()
# print ('Use time: ', end_time-start_time, ' seconds.')

            




