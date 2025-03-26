def myAtoi(s):
    first = s[0]
    if first=="+":
        first = 1
        s=s[1:-1]
    if first=="-":
        first = -1
        s=s[1:-1]
    return int(s)*first

print("-042")
    