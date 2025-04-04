"""
***Notes***
If we want the max string result, we need to assign the 5 largest numbers to the outer
values of the 5-gon (indices 0,3,6,9,12 in our array) and arrange them in the order
(6, 10, 9, 8, 7)
Then we recursively backtrack, checking that every 0 has been assigned a number, 
when we assign, we also assign to the other chain of three that number will be a part of 
using our refs dict, and if our recursive call is false, then we add our last assignment
back to numbers, and we change our last assigned indices in res back to 0
"""
start = [6, 0, 0, 10, 0, 0, 9, 0, 0, 8, 0, 0, 7, 0, 0]

numbers = [1, 2, 3, 4, 5]

ref = {1:14, 2:4, 5:7, 8:10, 11:13}

def max5gon(res, nums):
    if all(res) and sum(res[:3]) == sum(res[3:6]) == sum(res[6:9]) == sum(res[9:12]) == sum(res[12:]):
        return True
    for i in range(len(nums)):
        n = nums[i]
        for j in ref.keys():
            if res[j] == 0:
                res[j], res[ref[j]] = n, n
                nums.pop(i)
                check = max5gon(res, nums)
                if check:
                    return res
                else:
                    res[j], res[ref[j]] = 0, 0
                    nums.insert(i, n)
    return False

print(max5gon(start, numbers))

