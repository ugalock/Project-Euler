"""
Use the names in the text file to get a number value for each word 
(A = 1, etc) and determine whether the word's total value is a triangle number
***Longest word is 14 for we don't need any Triangles higher than 14*26 = 364
"""

file = open("42_words.txt", "r") 
l = file.read().split('","')
l[0], l[-1] = 'A', 'YOUTH'

def getTrianglesUpTo(bound):
    res = []
    val = 1
    i = 2
    while val < bound:
        res.append(val)
        val += i
        i += 1
    return res

triangles = [1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351]

def determineTriangleWords(lst):
    words = 0
    for word in lst:
        total = 0
        for char in word:
            total += ord(char)-64
        if total in triangles:
            words += 1
    return words

print(determineTriangleWords(l))
