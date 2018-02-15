from itertools import product

def distinctValues(maxRange):
    return len(set([a**b for (a, b) in [x for x in product(range(2,maxRange), repeat=2)]]))

print(distinctValues(16))
