"""
A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
"""

def sumDigits(n):
    total = 0
    while n > 0:
        total += (n % 10)
        n = n // 10
    return total
import time
s = time.clock()
print(max(sumDigits(int(a**b)) for a in range(90, 100) for b in range(90, 100)))
e = time.clock()
print(e-s)
