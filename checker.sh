#!/bin/bash

# Define the number of times to run the command
iterations=20
nbr_of_values=100


# Define the minimum and maximum integer values
min_int=-2147483648  # Minimum 32-bit integer value
max_int=2147483647   # Maximum 32-bit integer value

# Initialize variables to store min, max, and total for calculating average
min_result=0
max_result=0
total_result=0

# Loop for the specified number of iterations
for ((i=1; i<=$iterations; i++))
do
    # Generate 100 random integer values within the specified range
    random_values=""
    for ((j=1; j<=$nbr_of_values; j++))
    do
        random_values="$random_values $((RANDOM % ($max_int - $min_int + 1) + $min_int))"
    done

    # Run the command with the random values and count the lines
    result=$(echo "$random_values" | ./push_swap $random_values | wc -l)

    # Display the result for this iteration
    echo "Iteration $i: $result"

    # Update min, max, and total
    if [[ $i -eq 1 || $result -lt $min_result ]]; then
        min_result=$result
    fi
    if [[ $result -gt $max_result ]]; then
        max_result=$result
    fi
    total_result=$((total_result + result))
done

# Calculate average
average_result=$(echo "scale=2; $total_result / $iterations" | bc)

# Display min, max, and average
echo "Minimum: $min_result"
echo "Maximum: $max_result"
echo "Average: $average_result"
