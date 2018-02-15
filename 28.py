"""
Sum of the diagonals of each new layer of the spiral (always odd for n)
given by 4n^2-6n+6

Sum of odd squares 1^2 + 3^2 + ... + (2n-1)^2 = n(2n+1)(2n-1)/3
sum of odds 1 + 3 +... + (2n-1) = n^2
"""

def addLayers(x):
    n = (x + 1) / 2
    return (4 * (n * (2 * n - 1) * (2 * n + 1)) / 3) - (6 * n**2) + (6 * n) - 3

print(addLayers(1001))


