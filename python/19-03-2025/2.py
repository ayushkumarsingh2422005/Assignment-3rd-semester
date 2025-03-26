# Q2 Given an array of integers, find the length of the longest increasing subsequence. A subsequence is a sequence
# driver from the array without changing the relative order of elements Time complexity O(nlog(n))
# Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
# Output: 4


nums = [10, 9, 2, 5, 37, 101, 18]
longest = 0
temp = 1
for i in range(0, len(nums)-1):
    if nums[i] < nums[i+1]:
        temp+=1
    else:
        if temp > longest:
            longest = temp
        temp = 1

print(longest)