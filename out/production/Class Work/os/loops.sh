# FOR LOOP: Print numbers from 1 to 5
echo -e "\nFOR LOOP: Counting from 1 to 5"
for i in {1..5}; do
    echo "Number: $i"
done

# WHILE LOOP: Count down from 5 to 1
echo -e "\nWHILE LOOP: Counting down from 5 to 1"
counter=5
while [ $counter -gt 0 ]; do
    echo "Counter: $counter"
    ((counter--))
done

# UNTIL LOOP: Print numbers until it reaches 5
echo -e "\nUNTIL LOOP: Counting up until 5"
counter=1
until [ $counter -gt 5 ]; do
    echo "Counter: $counter"
    ((counter++))
done

# FOR LOOP WITH ARRAY: Iterating through an array
echo -e "\nFOR LOOP WITH ARRAY: Print fruits"
fruits=("Apple" "Banana" "Cherry" "Date")
for fruit in "${fruits[@]}"; do
    echo "Fruit: $fruit"
done

# BREAK AND CONTINUE: Demonstrating control statements
echo -e "\nBREAK AND CONTINUE DEMONSTRATION"
for i in {1..10}; do
    if [ $i -eq 5 ]; then
        echo "Skipping number 5 (using continue)"
        continue
    fi
    if [ $i -eq 8 ]; then
        echo "Breaking the loop at 8"
        break
    fi
    echo "Number: $i"
done

