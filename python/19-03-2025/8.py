nums = [1,3,-1,-3,5,3,6,7]
k = 3

while len(nums) >= k:
    print(max(nums[:k]), end=" ")
    nums.pop(0)