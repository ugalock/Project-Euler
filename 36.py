"""
sum of all nums < a million that are palindromes in base10 and base2 
"""

def isPalNum(n):
    num = n
    reverse = 0
    while num > 0:
        d = num % 10
        reverse = reverse * 10 + d
        num = num // 10
    return reverse == n

def sumPals2and10LessThan(max):
    total = 0
    for i in range(1, max):
        if i % 10 != 0:
            if isPalNum(i):
                if isPalNum(int(bin(i)[2:])):
                    total += i
    return total

print(sumPals2and10LessThan(1000000))