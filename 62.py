"""
The cube, 41063625 (3453), can be permuted to produce two other cubes: 56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.
"""
from collections import Counter

def findCubeFamily():
    cubes = [int(i**3) for i in range(346, 10000)]
    digits = []
    for c in cubes:
        found = 1
        d = Counter(str(c))
        nums = []
        for perm, d1 in digits:
            if found == 5:
                nums.sort()
                return nums[0]
            if d == perm:
                found += 1
                nums.append(d1)
        digits.append((d, c))
    return False
print(findCubeFamily())








