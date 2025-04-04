"""
Consider quadratic Diophantine equations of the form:

x^2 – Dy^2 = 1

For example, when D=13, the minimal solution in x is 6492 – 13×1802 = 1.

It can be assumed that there are no solutions in positive integers when D is square.

By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

3^2 – 2×2^2 = 1
2^2 – 3×1^2 = 1
9^2 – 5×4^2 = 1
5^2 – 6×2^2 = 1
8^2 – 7×3^2 = 1

Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

***Notes***
denom(i) = term*denom(i-1)+denom(i-2)
same for num
continued fraction solutions for sqrt(d) will find solutions to Pell equation 
"""

def getFirstCFrac(n):
    start = int(n**.5)
    last = [start, 1, 0]
    denoms = [0,1]
    nums = [1,start]
    while True:
        t = last[1] * last[0] - last[2]
        d = (n - t**2) // last[1]
        val = int((start + t) // d)
        newnum = val*nums[-1]+nums[-2]
        newdenom = val*denoms[-1]+denoms[-2]
        if newnum**2 - n*newdenom**2 == 1:
            return newnum
        nums.append(newnum)
        denoms.append(newdenom)
        last = [val, d, t]    

nonsquares = [i for i in range(1,1001) if i**.5 != int(i**.5)]

print(max(nonsquares, key=getFirstCFrac))