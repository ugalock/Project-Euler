"""
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Find every Lychrel number (can't produce a palindrome < 50 iterations)
under 10,000
"""
import time
def isPalNum(n):
    num = n
    reverse = 0
    while num > 0:
        d = num % 10
        reverse = reverse * 10 + d
        num = num // 10
    return reverse == n

def getReverse(n):
    reverse = 0
    while n > 0:
        d = n % 10
        reverse = reverse * 10 + d
        n = n // 10
    return reverse

def checkLychrel(n):
    for i in range(25):
        rev = getReverse(n)
        n += rev
        if isPalNum(n):
            return False
    return True

def getLychrelsLessThan(bound):
    count = 0
    for i in range(1, bound):
        if checkLychrel(i):
            count += 1
    return count

start = time.clock()
getLychrelsLessThan(10000)
end = time.clock()
print(end-start)





