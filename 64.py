"""
The square root of 23 can be expressed as a continued fraction:

√23 = 4 +___1_______________
        1 +__1______________
            3 +__1__________
                1 +__1______
                    8 + ...
We notate this continued series as:
sqrt(23) == [4;(1,3,1,8)]
which has a period of 4 repeating numbers (1,3,1,8)

How many continued fractions under 10000 have an odd-numbered period?
"""
def getCFracPeriod(n):               
    start = int(n**.5)
    last = [start, 1, 0]
    period = 0
    
    while 2 * start != last[0]:  #period ends when last val == 2 * start
        minus = last[1] * last[0] - last[2]
        denom = (n - minus**2) // last[1]
        val = int((start + minus) // denom)
        last= [val, denom, minus]
        period += 1
        
    return period

nonsquares = [i for i in range(10000) if i**.5 != int(i**.5)]

def getOddPeriodsUpTo(n):
    count = 0
    for i in nonsquares:
        if getCFracPeriod(i) & 1:
            count += 1
    return count


# print(getOddPeriodsUpTo(10000))
