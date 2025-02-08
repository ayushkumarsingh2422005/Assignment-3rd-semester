def sumOfNthNaturalNumber(n):
    return n * (n + 1) // 2

integer = int(input('Enter a number : '))
result = sumOfNthNaturalNumber(integer)
print('The sum of the first', integer, 'natural numbers is', result)