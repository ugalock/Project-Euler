factorials = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

UB = 

def findDigitFactorials():
    total = 0
    for i in range(25, UB):
        curr_sum = 0
        number = i
        while number > 0:
            temp = number % 10
            curr_sum += factorials[temp]
            number = number // 10
        if curr_sum == i:
            total += i
    return total

print(findDigitFactorials())

