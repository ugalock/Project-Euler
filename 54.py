"""
how many of the 1000 hands in poker.txt does player 1 win?
"""

from collections import Counter
import time
hands = (line.split() for line in open('54_poker.txt'))

values = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14}
straights = [(14, 13, 12, 11, 10), (13, 12, 11, 10, 9), (12, 11, 10, 9, 8), (11, 10, 9, 8, 7), (10, 9, 8, 7, 6), (9, 8, 7, 6, 5), (8, 7, 6, 5, 4), (7, 6, 5, 4, 3), (6, 5, 4, 3, 2), (14, 5, 4, 3, 2)]
ranks = [(1,1,1,1,1),(2,1,1,1),(2,2,1),(3,1,1),(),(),(3,2),(4,1)]
def rankHands(hand):
    score = [s for s in zip(*sorted(((v, values[k]) for k,v in Counter(x[0] for x in hand).items()), reverse=True))]
    score[0] = ranks.index(score[0])
    if len(set(card[1] for card in hand)) == 1: score[0] = 5 
    if score[1] in straights: score[0] = 8 if score[0] == 5 else 4 
    return score
start = time.clock()
print(sum(rankHands(hand[:5]) > rankHands(hand[5:]) for hand in hands))
end = time.clock()
print(end-start)