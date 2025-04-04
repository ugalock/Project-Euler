"""
The sequence of the first ten convergents for √2 are:

1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...
What is most surprising is that the important mathematical constant,
e = [2; 1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...].

The first ten terms in the sequence of convergents for e are:

2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.

Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

***Note***
denom behaves in same way
**********
"""

def getNumeratorOfNthConvergenceOfE(N):
    last = 3
    b4last = 2
    tcount = 1
    for i in range(1,N-1):
        if (i - 1) % 3 == 0:
            t = 2 * tcount
            tcount += 1
        else:
            t = 1
        n = t * last + b4last
        b4last = last
        last = n
    return n

import time
s = time.clock()
print(sum([int(c) for c in str(getNumeratorOfNthConvergenceOfE(100))]))
e = time.clock()
print(e-s)


