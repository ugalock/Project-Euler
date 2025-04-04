import math
"""
find largest pandigital formed by n X (1, 2, ..., i) such that
n X 1 is concatenated n x 2 etc.
Ex: 9 x (1, 2, 3, 4, 5) = 918273645
"""
def isPandigital(n):
    digits = 0
    while n > 0:
        temp = n % 10
        if temp == 0: 
            return False
        if (digits & (1 << temp)) > 0:
            return False
        digits |= (1 << temp)
        n = n // 10
    if digits != 1022:
        return False
    return True

def findLargestPanMultiple():
    highest = [0, 0]
    for n in range(2, 7):
        for i in range(1, 10000):
            string = ''
            for j in range(1, n):
                string += str(i*j)
            num = int(string)
            if isPandigital(num) and num > highest[0]:
                highest[0], highest[1] = num, i
    return highest

print(findLargestPanMultiple())




