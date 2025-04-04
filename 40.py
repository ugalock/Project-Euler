"""
consider 0.12345678910(1)11213... formed by concatenating every positive
integer together to form an irrational fraction
note that (1) is the 12th digit (d12)
find d1 x d10 x d100 x d1000 x d100000 x d1000000
"""
import math

def numDigits(n):
    return int(math.log10(n))+1

def isPowerOf10(n):
    return int(math.log10(n)) == math.log10(n)

def champernowne():
    total = 1
    count = 1
    power10 = 10
    i = 2
    while power10 <= 1000000:
        if numDigits(i) + count >= power10:
            print(i, count)
            digitPlace = power10 - count - 1
            total *= int(str(i)[digitPlace])
            power10 = power10 * 10
        count += numDigits(i)
        i += 1
    return total
print(champernowne())
