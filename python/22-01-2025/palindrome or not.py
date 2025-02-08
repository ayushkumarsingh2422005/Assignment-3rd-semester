def isPalindrome(s):
    return s == s[::-1]

string = input("Enter the string : ")

if isPalindrome(string):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")
