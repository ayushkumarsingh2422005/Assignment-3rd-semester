# Q1 Given a string, find the first non-repeating character and return it. If all characters repeat, return None.
# Input: "aabbcddce"
# Output: "e"
inp = input("Enter the string : ")
lst = []
for i in inp:
    if i not in lst:
        lst.append(i)
    else:
        inp = inp.replace(i, "")
if inp!="":
    print(inp[0])
else:
    print(None)