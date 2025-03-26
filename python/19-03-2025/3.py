# Q3 Given an array, rotate it to the right by k steps, where k is a non-negative integer. You must do this in-place
# without using extra space for another array.
# Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
# Output: [5, 6, 7, 1, 2, 3, 4] 

nums = [1, 2, 3, 4, 5, 6, 7]
k = 3

def reverse(array, start, end):
    for i in range(0, (end-start+1)//2):
        temp = array[start+i]
        array[start+i] = array[end-i]
        array[end-i] = temp

reverse(nums, 0, len(nums)-1)
# print(nums)
reverse(nums, 0, k-1)
# print(nums)
reverse(nums, k, len(nums)-1)
print(nums)