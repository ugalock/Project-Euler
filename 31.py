def findCoinCombos(target, coins):
    combos = [0]*(target+1)
    combos[0] = 1
    for i in range(len(coins)):
        j = coins[i]
        while j <= target:
            combos[j] += combos[j - coins[i]]
            j += 1
    return combos[-1]

print(findCoinCombos(200, [1, 2, 5, 10, 20, 50, 100, 200]))