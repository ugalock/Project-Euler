"""
if {p = x+y+h} in +Z where x,y,h are sides of a right triangle for
what value of p <= 1000 does p = x+y+h have the most solutions?
"""

def makeTriples():
    triples = set()
    for i in range(1, 100):
        for j in range(1, 500):
            m, n = max(i, j), min(i, j)
            a = m**2-n**2
            b = 2*m*n
            c = m**2+n**2
            if a+b+c<=1000 and a != 0:
                for k in range(1, 84):
                    if k*(a+b+c) <= 1000:
                        triples.add((min(k*a,k*b), max(k*a,k*b), k*c))
                
    return triples

def findMostCommonP():
    l = [sum(list(tup)) for tup in makeTriples()]
    return max(set(l), key=l.count)

print(findMostCommonP())



