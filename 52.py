"""
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
"""
import time

def checkDigits(a):
    prevDigits = 0
    b, c, d, e, f = 2*a, 3*a, 4*a, 5*a, 6*a
    for i, n in enumerate([a, b, c, d, e, f]):
        currDigits = 0
        while n > 0:
            temp = n % 10
            if (currDigits & (1<<temp)) > 0:
                return False
            currDigits |= (1<<temp)
            n = n // 10
        if i == 0:
            prevDigits = currDigits
        if prevDigits != currDigits:
            return False
        prevDigits = currDigits
    return True

start = time.clock()
def findPermutatedMultiples():
    for i in range(1, 1000000):
        if checkDigits(i):
            return i
print(findPermutatedMultiples())
end = time.clock()
print('Finished in {} seconds'.format(end-start))