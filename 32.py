from math import sqrt, floor, log10
def isPandigital(num):
    s = set()
    while num > 0:
        s.add(num % 10)
        num = num // 10
    return (len(s) == max(s) if 0 not in s else False) and len(s) == 9

def isPandigitalOpt(n):
    digits = 0
    while n > 0:
        temp = n % 10
        if temp == 0: 
            return False
        if (digits & (1 << temp)) > 0:
            return False
        digits |= (1 << temp)
        n = n // 10
    return True

def concat(a, b):
    temp = b
    while temp > 0:
        a *= 10
        temp = temp // 10
    return a + b

def concatAll(a, b, c):
    return concat(concat(a, b), c)

def findPanProducts():
    max_value = 10000
    seen = []
    seenProducts = set()
    for i in range(1, floor(sqrt(max_value))):
        for j in range(i, (max_value//i)):
            temp = concatAll(i, j, i*j)
            if int(log10(temp)+1) == 9:
                if isPandigitalOpt(temp):
                    if (i, j) in seen:
                        pass
                    else:
                        seenProducts.add(i * j)
                        seen.append((i, j))
    return sum(seenProducts)
print(findPanProducts())
               