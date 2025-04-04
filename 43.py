"""
find all 0 to 9 pandigital numbers s.t. :
d2d3d4 is divisble by 2
d3d4d5 is divisible by 3
d4d5d6 is divisible by 5
etc...
"""
import math
import itertools

def isPandigitalZeroTo9(n):
    digits = 0
    num = n
    while num > 0:
        temp = num % 10
        if temp == 0:
            temp = 10
        if (digits & (1 << temp)) > 0:
            return False
        digits |= (1 << temp)
        num = num // 10
    if digits != (2**(int(math.log10(n)) + 2) - 2):
        return False
    return True

def checkDivisibility(n):
    s = str(n)
    if int(s[7:]) % 17 != 0:
        return False
    elif int(s[6:9]) % 13 != 0:
        return False
    elif int(s[5:8]) % 11 != 0:
        return False
    elif int(s[4:7]) % 7 != 0:
        return False
    elif int(s[3:6]) % 5 != 0:
        return False
    elif int(s[2:5]) % 3 != 0:
        return False
    elif int(s[1:4]) % 2 != 0:
        return False
    return True


perms = []
for j in itertools.permutations('1234567890',10):
    if j[0] != '0':
        perms.append(int(''.join(j)))

def getPansWithDivisibility():
    total = 0
    for i in perms:
        if checkDivisibility(i):
            print(i)
            total += i
    return total

print(getPansWithDivisibility())