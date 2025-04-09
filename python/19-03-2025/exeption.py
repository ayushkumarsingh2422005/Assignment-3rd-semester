#1. Write a Python program that executes a list operation and handles an AttributeError exception if the attribute does not exist.

# my_list = [1, 2, 3, 4, 5]
# try:
#     result = my_list.nonexistent_method()
#     print(result)
# except AttributeError as e:
#     print(f"Error: {e}")
#     print("The attempted method does not exist for list objects")


#2. Write a Python program that prompts the user to input two numbers and raises a TypeError exception if the inputs are not numerical.
try:
    a = int(input("enter 1st number : "))
    b = int(input("enter 2nd number : "))
except ValueError:
    print("Error: Please enter valid numerical values")
    print("The inputs must be numbers")
else:
    print(f"Successfully received numbers: {a} and {b}")
    
#3. Write a Python program that executes an operation on a list and handles an IndexError exception if the index is out of range.
# lst = [1,2,3,4]
# idx = int(input("Enter a number on which you want to se the value : "))
# try:
#     print(lst[idx])
# except IndexError:
#     print(f"Error: Index {idx} is out of range")
    
#4. Write a Python program that executes division and handles an ArithmeticError exception if there is an arithmetic error.
try:
    num1 = float(input("Enter the numerator: "))
    num2 = float(input("Enter the denominator: "))
    result = num1 / num2
    print(f"Result of division: {result}")
except ArithmeticError as e:
    print(f"Arithmetic Error occurred: {e}")
