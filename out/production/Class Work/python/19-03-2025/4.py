# Q4 Given a string, find the length of the longest substring without repeating characters in O(n) time complexity
# Input: "abcabcbb"
# Output: 3


string = "abcabcbb"
dictonary = {}
max_len = 0
for i in range(len(string)):
    char = string[i]
    if char not in dictonary.keys():
        dictonary[char] = i
    else:
        current = i-dictonary[char]
        if current > max_len:
            max_len = current
        i = dictonary[char]+1
        dictonary = {}

print(max_len)