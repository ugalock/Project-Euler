"""
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

    3
   7 4
  2 4 6
 8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
"""

rows = [line.split('\n') for line in open('67_triangle.txt')]
for i, row in enumerate(rows):
    row.pop(-1)
    rows[i] = row[0].split(' ')
    for j, c in enumerate(rows[i]):
        rows[i][j] = int(c)

for i in range(len(rows)-1, 0, -1):
    for j in range(len(rows[i-1])):
        rows[i-1][j] = rows[i-1][j] + max(rows[i][j], rows[i][j+1])
print(rows[0][0])