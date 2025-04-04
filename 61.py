"""

Bounds
********
T(n) = n(n+1)/2
T(n): 44 < n < 141

S(n) = n^2
S(n): 31 < n < 100

p(n) = n(3n−1)/2
P(n): 25 < n < 82

Hex(n) = n(2n−1)
Hex(n): 22 < n < 71

Hep(n) = n(5n−3)/2
Hep(n): 20 < n < 64

O(n) = n(3n−2)
O(n): 18 < n < 59
"""

figurates = []

def getTriangles(lower=44, upper=141):
    for x in range(lower+1, upper):
        n = int(x*(x+1)/2)
        figurates.append((n, 0))

def getSquares(lower=31, upper=100):
    for x in range(lower+1, upper):
        n = int(x**2)
        figurates.append((n, 1))

def getPents(lower=25, upper=82):
    for x in range(lower+1, upper):
        n = int(x*(3*x-1)/2)
        figurates.append((n, 2))

def getHex(lower=22, upper=71):
    for x in range(lower+1, upper):
        n = x*(2*x-1)
        figurates.append((n, 3))

def getHepts(lower=20, upper=64):
    for x in range(lower+1, upper):
        n = int(x*(5*x-3)/2)
        figurates.append((n, 4))

def getOcts(lower=18, upper=59):
    for x in range(lower+1, upper):
        n = x*(3*x-2)
        figurates.append((n, 5))

def getFigurates():
    getTriangles()
    getSquares()
    getPents()
    getHex()
    getHepts()
    getOcts()

getFigurates()

# a = [n[0] for n in figurates]
# print(a)

def getFirstTwoDigits(n):
    n -= n % 100
    n = n // 100
    return int(n)

def getLastTwoDigits(n):
    return n % 100


def getFamily(found, ftypes, numFound):
    if numFound == 5:
        for n, t in figurates:
            l2 = getLastTwoDigits(n)
            f2 = getFirstTwoDigits(n)
            if n not in found and t not in ftypes and l2 == getFirstTwoDigits(found[0]) and f2 == getLastTwoDigits(found[-1]) and len(found + [n]) == 6:
                print(sum(found + [n]))

    for n, t in figurates:
        currfirst2 = getFirstTwoDigits(n)
        if not found:
            check = getFamily([n], [t], 1)

        elif n not in found and t not in ftypes and currfirst2 == getLastTwoDigits(found[-1]):
            f = found + [n]
            ft = ftypes + [t]
            newNum = numFound + 1
            nl2 = getLastTwoDigits(n)
            c = getFamily(f, ft, newNum)
            if c:
                return c
    return False



print(getFamily([], [], 0))


