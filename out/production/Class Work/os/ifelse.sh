echo "Welcome to the Arithmetic Operations Program!"

# Input: Get two numbers from the user
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2

# Menu: Display options for operations
echo "Choose an operation:"
echo "1. Addition (+)"
echo "2. Subtraction (-)"
echo "3. Multiplication (*)"
echo "4. Division (/)"
echo "5. Modulus (%)"
read -p "Enter your choice (1-5): " choice

# Perform the selected operation
case $choice in
    1) 
        result=$((num1 + num2))
        echo "Result of $num1 + $num2 = $result"
        ;;
    2) 
        result=$((num1 - num2))
        echo "Result of $num1 - $num2 = $result"
        ;;
    3) 
        result=$((num1 * num2))
        echo "Result of $num1 * $num2 = $result"
        ;;
    4) 
        if [ $num2 -ne 0 ]; then
            result=$((num1 / num2))
            echo "Result of $num1 / $num2 = $result"
        else
            echo "Error: Division by zero is not allowed."
        fi
        ;;
    5) 
        result=$((num1 % num2))
        echo "Result of $num1 % $num2 = $result"
        ;;
    *) 
        echo "Invalid choice! Please select a valid option (1-5)."
        ;;
esac

