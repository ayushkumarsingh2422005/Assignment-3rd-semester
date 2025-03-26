def noOfDegits(n):
    count = 0
    while n != 0:
        n = n // 10
        count += 1
    return count

number = int(input("Enter a number : "))

print(f"Total number of digits : {noOfDegits(number)}")
