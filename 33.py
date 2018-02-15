def checkDigits(a, b):
    if a % 11 == 0 or b % 11 == 0:
        return False
    digits = 0
    while a % 10 > 0:
        temp = a % 10
        digits |= (1<<temp)
        a = a // 10
    while b % 10 > 0:
        temp = b % 10
        if digits & (1<<temp) > 0:
            return temp
        digits |= (1<<temp)
        b = b // 10
    return False

def removeShared(a, b, shared):
    if a % 10 == shared:
        a = a // 10
    else:
        a -= (a // 10) * 10
    if b % 10 == shared:
        b = b // 10
    else:
        b -= (b // 10) * 10
    return a / b

def getFractions():
    result = 1
    for i in range(12,99):
        for j in range(i+1,99):
            shared = checkDigits(i, j)
            if shared:
                if removeShared(i, j, shared) == (i / j):
                    result *= j/i
    return result
print(getFractions())




