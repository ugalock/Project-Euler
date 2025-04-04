"""
The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.

How many n-digit positive integers exist which are also an nth power?

Bounds
******* (for x,y in +Z)
floor(log10(x^y)) == y-1

(y-1)/y <= log10(x) < 1  <--- x <= 9

==> y <= y*log10(x) + 1

y <= 1/(1-log10(x))
"""
from math import log10, floor

def getNdigitNpowers():
    count = 0
    for i in range(1, 10):
        count += floor(1/(1-log10(i)))
    return count

from tests import time1f

time1f(1000, getNdigitNpowers)
