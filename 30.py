"""
upper bound of sum is (9^5)*d where d is number of digits

"""

def sumOfDigitsToTheFifth():
    result = 0
    i = 1000
    while i <= (9**5)*5:
        n = i
        sumDigits = 0
        while n > 0:
            sumDigits += ((n % 10)**5)
            n = n // 10
        if sumDigits == i:
            result += i
        i += 1
    return result

print(sumOfDigitsToTheFifth())
