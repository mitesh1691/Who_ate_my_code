# 1. Two Sum:
# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.

# Example 1:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]

# Example 2:
# Input: nums = [3,2,4], target = 6
# Output: [1,2]

# Example 3:
# Input: nums = [3,3], target = 6
# Output: [0,1]

def two_sum(nums, target):
    result = [0, 0]

    for i in range(len(nums) - 1):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                result[0] = i
                result[1] = j
                return result

    # If no solution is found
    raise ValueError("No two elements sum up to the target")

# Test Cases
# Test Case 1
nums1 = [2, 7, 11, 15]
target1 = 9
print(f"Test Case 1: {two_sum(nums1, target1)}")

# Test Case 2
nums2 = [3, 2, 4]
target2 = 6
print(f"Test Case 2: {two_sum(nums2, target2)}")

# Test Case 3
nums3 = [3, 3]
target3 = 6
print(f"Test Case 3: {two_sum(nums3, target3)}")

# Additional Test Case 1
nums4 = [1, 2, 3, 4, 5]
target4 = 9
print(f"Additional Test Case 1: {two_sum(nums4, target4)}")

# Additional Test Case 2
nums5 = [-1, -2, -3, -4, -5]
target5 = -8
print(f"Additional Test Case 2: {two_sum(nums5, target5)}")

'''
Output :
Test Case 1: [0, 1]
Test Case 2: [1, 2]
Test Case 3: [0, 1]
Additional Test Case 1: [3, 4]
Additional Test Case 2: [2, 4]'''


#**************************************************************************************************************************************

#  2. Problem Description: Count Vowels and Consonants in a String

# You are tasked with creating a Python program to count the number of vowels and consonants in a given string.
# Vowels are defined as the letters 'a', 'e', 'i', 'o', and 'u', while consonants are all other alphabetic characters.
# The program should be case-insensitive, meaning it should treat uppercase and lowercase letters as equivalent.

# Input:
# str: A string containing alphabetic characters (both uppercase and lowercase).

# Output:
# Prints the number of vowels and consonants in the input string.


# Example
#    str = "Hello World"
#    print("Test Case:")
#    count_vowels_and_consonants(str)
# Output:
# Number of vowels = 3
# Number of consonants = 7

def count_vowels_and_consonants(string):
    vowel_count = 0
    consonant_count = 0
    string = string.lower()  # Convert the string to lowercase for case-insensitivity

    for char in string:
        # Check if the character is a vowel
        if char in 'aeiou':
            vowel_count += 1
        # Check if the character is a consonant
        elif char.isalpha():
            consonant_count += 1

    print("Number of vowels =", vowel_count)
    print("Number of consonants =", consonant_count)



# Test Case 1
str1 = "Hello World"
print("Test Case 1:")
count_vowels_and_consonants(str1)
print()

# Test Case 2
str2 = "Programming is Fun"
print("Test Case 2:")
count_vowels_and_consonants(str2)
print()

# Test Case 3
str3 = "Java"
print("Test Case 3:")
count_vowels_and_consonants(str3)
print()

# Test Case 4
str4 = "Python"
print("Test Case 4:")
count_vowels_and_consonants(str4)
print()

# Test Case 5
str5 = "The quick brown fox jumps over the lazy dog"
print("Test Case 5:")
count_vowels_and_consonants(str5)
print()

# Test Case 6 (Empty String)
str6 = ""
print("Test Case 6:")
count_vowels_and_consonants(str6)
print()

'''
Output :

Test Case 1:
Number of vowels = 3
Number of consonants = 7

Test Case 2:
Number of vowels = 5
Number of consonants = 11

Test Case 3:
Number of vowels = 2
Number of consonants = 2

Test Case 4:
Number of vowels = 1
Number of consonants = 5

Test Case 5:
Number of vowels = 11
Number of consonants = 24

Test Case 6:
Number of vowels = 0
Number of consonants = 0'''


#**************************************************************************************************************************************

#  3. Problem Description: Check Prime Number

# Checks whether a given number is prime or not.
    
# Args: - number: An integer to be checked for primality.
    
# Returns:- True if the input number is prime, False otherwise.
#          The function should return false for numbers less than or equal to 1.

#Example 1

#int num1 = 7
#boolean result1 = isPrime(num1)
#Output: true

#Example 2

#int num1 = 15
#boolean result1 = isPrime(num1)
#Output: false

#Example 3

#int num1 = 50
#boolean result1 = isPrime(num1);
#Output: false


import math

def is_prime(number):
    if number <= 1:
        return False
    
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    
    return True

# Test Cases

# Test Case 1
num1 = 7
print("Test Case 1: Is", num1, "prime?", is_prime(num1))

# Test Case 2
num2 = 15
print("Test Case 2: Is", num2, "prime?", is_prime(num2))

# Test Case 3
num3 = 23
print("Test Case 3: Is", num3, "prime?", is_prime(num3))

# Test Case 4
num4 = 1
print("Test Case 4: Is", num4, "prime?", is_prime(num4))

# Test Case 5
num5 = 0
print("Test Case 5: Is", num5, "prime?", is_prime(num5))


# Test Case 6
num6 = 97
print("Test Case 6: Is", num6, "prime?", is_prime(num6))

'''
Output:

Test Case 1: Is 7 prime? True
Test Case 2: Is 15 prime? False
Test Case 3: Is 23 prime? True
Test Case 4: Is 1 prime? False
Test Case 5: Is 0 prime? False
Test Case 6: Is 97 prime? True
'''


#**************************************************************************************************************************************

# 4. Problem Description: Check Palindrome

# You are tasked with creating a Python program to determine whether a given string is a palindrome or not.
# A palindrome is a word, phrase, number, or other sequences of characters that reads the same forward and backward
# (ignoring spaces, punctuation, and capitalization).
# The program should efficiently check whether a given input string is a palindrome and return a boolean result.

# Returns True if the input string is a palindrome, and False otherwise.

# Example:

# Example 1
# str1 = "radar"
# result1 = is_palindrome(str1)
# Output: True

# Example 2
# str2 = "Palindrome"
# result2 = is_palindrome(str2)
# Output: False

# Example 3
# str3 = "A man, a plan, a canal, Panama"
# result3 = is_palindrome(str3)
# Output: True

# Notes:
# The solution should efficiently handle various input strings.
# The function should consider the alphanumeric characters only and ignore spaces, punctuation, and capitalization.
# The program should run without errors for valid input strings.


def is_palindrome(s):
    # Remove non-alphanumeric characters and convert to lowercase
    clean_str = ''.join(char.lower() for char in s if char.isalnum())

    # Check if the cleaned string is a palindrome
    left = 0
    right = len(clean_str) - 1

    while left < right:
        if clean_str[left] != clean_str[right]:
            return False
        left += 1
        right -= 1

    return True



# Test Cases
# Test Case 1
str1 = "radar"
print(f"Test Case 1: Is \"{str1}\" a palindrome? {is_palindrome(str1)}")

# Test Case 2
str2 = "Palindrome"
print(f"Test Case 2: Is \"{str2}\" a palindrome? {is_palindrome(str2)}")

# Test Case 3
str3 = "A man, a plan, a canal, Panama"
print(f"Test Case 3: Is \"{str3}\" a palindrome? {is_palindrome(str3)}")

# Test Case 4
str4 = "No lemon, no melon"
print(f"Test Case 4: Is \"{str4}\" a palindrome? {is_palindrome(str4)}")

# Test Case 5
str5 = "Java"
print(f"Test Case 5: Is \"{str5}\" a palindrome? {is_palindrome(str5)}")


'''
Output:
Test Case 1: Is "radar" a palindrome? True
Test Case 2: Is "Palindrome" a palindrome? False
Test Case 3: Is "A man, a plan, a canal, Panama" a palindrome? True
Test Case 4: Is "No lemon, no melon" a palindrome? True
Test Case 5: Is "Java" a palindrome? False
'''


#**************************************************************************************************************************************

# 5. Problem Description: Find Factorial of a Number

# You are required to create a Python program to calculate the factorial of a given number.
# The factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n.
# The program should efficiently calculate the factorial of the input number and return the result.

# Returns the factorial of the input number as a long data type.

# Example 1
# num1 = 5
# result1 = calculate_factorial(num1)
# Output: 120

# Example 2
# num2 = 0
# result2 = calculate_factorial(num2)
# Output: 1

# Example 3
# num3 = 10
# result3 = calculate_factorial(num3)
# Output: 3628800

# Notes:
#   The solution should efficiently handle various input numbers.
#   The function should return 1 for n equal to 0, as 0! is defined as 1.
#   The program should run without errors for valid input numbers.

def calculate_factorial(n):
    if n < 0:
        raise ValueError("Input must be a non-negative integer.")

    # Base case: 0! is defined as 1
    if n == 0:
        return 1

    # Initialize result to 1
    result = 1

    # Calculate factorial using a loop
    for i in range(1, n + 1):
        result *= i

    return result


# Test Case 1
num1 = 5
print(f"Test Case 1: Factorial of {num1} = {calculate_factorial(num1)}")

# Test Case 2
num2 = 0
print(f"Test Case 2: Factorial of {num2} = {calculate_factorial(num2)}")

# Test Case 3
num3 = 10
print(f"Test Case 3: Factorial of {num3} = {calculate_factorial(num3)}")

# Test Case 4
num4 = 15
print(f"Test Case 4: Factorial of {num4} = {calculate_factorial(num4)}")

# Test Case 5
num5 = 3
print(f"Test Case 5: Factorial of {num5} = {calculate_factorial(num5)}")


# Sample output:
'''
Test Case 1: Factorial of 5 = 120
Test Case 2: Factorial of 0 = 1
Test Case 3: Factorial of 10 = 3628800
Test Case 4: Factorial of 15 = 1307674368000
Test Case 5: Factorial of 3 = 6
'''


#**************************************************************************************************************************************

# 6.Problem Description: Find Second Smallest Element in an Array

# You are required to create a Python program to find the second smallest element in an array of integers.
# The program should efficiently determine the second smallest element and return the result.

# Example:
#  Example 1
# arr1 = [5, 2, 8, 1, 3]
# result1 = find_second_smallest(arr1)
# Output: 2

# Example 2
# arr2 = [10, 7, 15, 4, 6]
# result2 = find_second_smallest(arr2)
# Output: 6
#
# Example 3
# arr3 = [3, 3, 1, 4, 5]
# result3 = find_second_smallest(arr3)
# Output: 3


def find_second_smallest(arr):
    if arr is None or len(arr) < 2:
        raise ValueError("Array must have at least two elements.")

    smallest = float('inf')
    second_smallest = float('inf')

    for num in arr:
        if num < smallest:
            second_smallest = smallest
            smallest = num
        elif num < second_smallest and num != smallest:
            second_smallest = num

    return second_smallest


# Test Cases

# Test Case 1
arr1 = [5, 2, 8, 3, 7]
print("Test Case 1: Second Smallest Element =", find_second_smallest(arr1))

# Test Case 2
arr2 = [10, 5, 7, 3, 2]
print("Test Case 2: Second Smallest Element =", find_second_smallest(arr2))

# Test Case 3
arr10 = [5, 2, 8, 3, 7, 1]
print("Test Case 3: Second Smallest Element =", find_second_smallest(arr10))

# Test Case 4
arr4 = [9, 9, 5, 2, 8, 3, 7]
print("Test Case 4: Second Smallest Element =", find_second_smallest(arr4))

# Test Case 5
arr5 = [5, 5, 5, 2, 8, 3, 7]
print("Test Case 5: Second Smallest Element =", find_second_smallest(arr5))

# Test Case 6
arr6 = [5, 2, 2, 8, 3, 7]
print("Test Case 6: Second Smallest Element =", find_second_smallest(arr6))

# Test Case 7
arr7 = [10, 10, 5, 7, 3, 2]
print("Test Case 7: Second Smallest Element =", find_second_smallest(arr7))

# Test Case 8
arr8 = [1, 2, 3, 4, 5]
print("Test Case 8: Second Smallest Element =", find_second_smallest(arr8))


'''
Output:

Test Case 1: Second Smallest Element = 3
Test Case 2: Second Smallest Element = 3
Test Case 3: Second Smallest Element = 2
Test Case 4: Second Smallest Element = 3
Test Case 5: Second Smallest Element = 3
Test Case 6: Second Smallest Element = 3
Test Case 7: Second Smallest Element = 3
Test Case 8: Second Smallest Element = 2
'''


#**************************************************************************************************************************************

#7. Problem Description: Reverse a String without Using the Reverse Function

# You are tasked with creating a Python program to reverse a given string,
# without using any built-in reverse function or any other library functions that directly provide string reversal.
# The program should efficiently reverse the input string and return the result.

# Return a new string representing the reversed version of the input string.

# Example:

# Example 1
# input1 = "Hello World"
# result1 = reverse_string(input1)
# Output: "dlroW olleH"

# Example 2
# input2 = "Java Programming"
# result2 = reverse_string(input2)
# Output: "gnimmargorP avaJ"

# Example 3
# input3 = "12345"
# result3 = reverse_string(input3)
# Output: "54321"


def reverse_string(string):
    char_array = list(string)
    left = 0
    right = len(char_array) - 1

    while left < right:
        # Swap characters at left and right indices
        char_array[left], char_array[right] = char_array[right], char_array[left]

        # Move indices towards the center
        left += 1
        right -= 1

    return ''.join(char_array)

# Test Cases
# Test Case 1
input1 = "Hello World"
print("Test Case 1: Reversed String =", reverse_string(input1))

# Test Case 2
input2 = "Java Programming"
print("Test Case 2: Reversed String =", reverse_string(input2))

# Test Case 3
input3 = "12345"
print("Test Case 3: Reversed String =", reverse_string(input3))

# Test Case 4
input4 = "a"
print("Test Case 4: Reversed String =", reverse_string(input4))

# Test Case 5
input5 = ""
print("Test Case 5: Reversed String =", reverse_string(input5))

# sample output:
'''
Test Case 1: Reversed String = dlroW olleH
Test Case 2: Reversed String = gnimmargorP avaJ
Test Case 3: Reversed String = 54321
Test Case 4: Reversed String = a
Test Case 5: Reversed String =
'''



#**************************************************************************************************************************************

# 8. Problem Description: Calculate Power of a Number using Recursion

# You are required to create a Python program to calculate the power of a given number using recursion.
# The power of a number a raised to the power of b (denoted as a^b) is the product of multiplying a by itself b times.
# The program should efficiently calculate the power using recursion and return the result.

# Input:
#     base: An integer representing the base.
#     exponent: An integer representing the exponent.

# Output:
#     Returns the result of raising the base to the power of the exponent.

# Example:

# Example 1
# base1 = 2
# exponent1 = 3
# result1 = calculate_power(base1, exponent1)
# Output: 8

# Example 2
# base2 = 5
# exponent2 = 0
# result2 = calculate_power(base2, exponent2)
# Output: 1

# Example 3
# base3 = 3
# exponent3 = 4
# result3 = calculate_power(base3, exponent3)
# Output: 81

# Notes:
#     The function should use recursion to calculate the power.

def calculate_power(base, exponent):
    # Base case: any number raised to the power of 0 is 1
    if exponent == 0:
        return 1

    # Recursive case: calculate power using recursion
    return base * calculate_power(base, exponent - 1)

# Test Case 1
base1 = 2
exponent1 = 3
print(f"Test Case 1: {base1}^{exponent1} = {calculate_power(base1, exponent1)}")

# Test Case 2
base2 = 5
exponent2 = 0
print(f"Test Case 2: {base2}^{exponent2} = {calculate_power(base2, exponent2)}")

# Test Case 3
base3 = 3
exponent3 = 4
print(f"Test Case 3: {base3}^{exponent3} = {calculate_power(base3, exponent3)}")

# Test Case 4
base4 = 7
exponent4 = 2
print(f"Test Case 4: {base4}^{exponent4} = {calculate_power(base4, exponent4)}")

# Test Case 5
base5 = 1
exponent5 = 5
print(f"Test Case 5: {base5}^{exponent5} = {calculate_power(base5, exponent5)}")


# sample output:
'''
Test Case 1: 2^3 = 8
Test Case 2: 5^0 = 1
Test Case 3: 3^4 = 81
Test Case 4: 7^2 = 49
Test Case 5: 1^5 = 1
'''


#**************************************************************************************************************************************

# 9. Reverse N-Number Triangle

# Aryan and his friends have a fascination for patterns.
# They want to create a reverse N-number triangle for a given positive integer 'N'.
# The reverse N-number triangle consists of rows where each row contains decreasing numbers starting from 'N' down to 1.

#  Input:
#        N: A positive integer representing the number of rows in the reverse number triangle.

#    Output:
#        Prints the reverse N-number triangle pattern as described.

class ReverseNumberTriangle:
    def reverseNumberTriangle(N):
        # Iterate through each row
        for i in range(N, 0, -1):
            # Print numbers in decreasing order from 'N' to 'N - i + 1' for each row
            for j in range(N, N - i, -1):
                print(j, end="")
            print()  # Move to the next line after printing each row

    def main():
        # Test Cases
        print("Test Case 1:")
        ReverseNumberTriangle.reverseNumberTriangle(5)

        print("\nTest Case 2:")
        ReverseNumberTriangle.reverseNumberTriangle(3)

        print("\nTest Case 3:")
        ReverseNumberTriangle.reverseNumberTriangle(7)

# Execute the main method
if __name__ == "__main__":
    ReverseNumberTriangle.main()

'''
Outout:
Test Case 1:
54321
5432
543
54
5

Test Case 2:
321
32
3

Test Case 3:
7654321
765432
76543
7654
765
76
7
'''


#**************************************************************************************************************************************

# 10. : Right Angled Number Triangle

# You are tasked with creating a python program to generate a right-angled number triangle with a specified number of rows.
# Each row of the triangle contains consecutive odd numbers starting from 1.
# The first row contains 1, the second row contains 3 and 5, the third row contains 7, 9, and 11, and so on.

# Input:
#        rows: An integer representing the number of rows in the triangle.

# Output:
#        Prints the right-angled number triangle pattern as described.

# Example
#Input: Enter number of rows: 5
#Output:
#1
#3 5
#7 9 11
#13 15 17 19
#21 23 25 27 29

#Notes:
#        The solution should efficiently generate and print the right-angled number triangle pattern.
#        The input rows will always be a positive integer.
#        The program should run without errors for valid input values.

class RightAngledNumberTriangle:

    # Method to print right-angled number triangle
    @staticmethod
    def printRightAngledNumberTriangle(rows):
        number = 1

        # Iterate through each row
        for i in range(1, rows + 1):
            # Print numbers in each row
            for j in range(1, i + 1):
                print(number, end=" ")
                number += 2  # Increment number by 2 for next odd number
            print()  # Move to the next line after printing each row

    # Main method for testing
    @staticmethod
    def main():
        # Test Cases
        print("Test Case 1:")
        RightAngledNumberTriangle.printRightAngledNumberTriangle(5)

        print("\nTest Case 2:")
        RightAngledNumberTriangle.printRightAngledNumberTriangle(4)

        print("\nTest Case 3:")
        RightAngledNumberTriangle.printRightAngledNumberTriangle(6)

# Execute the main method
if __name__ == "__main__":
    RightAngledNumberTriangle.main()

'''
Output:
Test Case 1:
1 
3 5 
7 9 11 
13 15 17 19 
21 23 25 27 29 

Test Case 2:
1 
3 5 
7 9 11 
13 15 17 19 

Test Case 3:
1 
3 5 
7 9 11 
13 15 17 19 
21 23 25 27 29 
31 33 35 37 39 41 
'''


#**************************************************************************************************************************************

# 11. Right Angled Pattern 2

# You are tasked with creating a python program to generate a right-angled pattern with consecutive even numbers starting from 2.
# Each row of the pattern contains consecutive even numbers incremented by 2.
# The first row contains 2, the second row contains 4 and 6, the third row contains 8, 10, and 12, and so on.

# Input:
#    rows: An integer representing the number of rows in the pattern.

# Output:
#    Prints the right-angled pattern 2 as described.

# Example
#Input: Enter the number of rows: 5
#Output:
#2
#4 6
#8 10 12
#14 16 18 20
#22 24 26 28 30

#Notes:
#    The solution should efficiently generate and print the right-angled pattern 2.
#    The input rows will always be a positive integer.
#    The program should run without errors for valid input values.

class RightAngledPattern2:

    # Method to print right-angled pattern 2
    @staticmethod
    def printRightAngledPattern2(rows):
        number = 2

        # Iterate through each row
        for i in range(1, rows + 1):
            # Print numbers in each row
            for j in range(1, i + 1):
                print(number, end=" ")
                number += 2  # Increment number by 2 for next even number
            print()  # Move to the next line after printing each row

    # Main method for testing
    @staticmethod
    def main():
        # Test Cases
        print("Test Case 1:")
        RightAngledPattern2.printRightAngledPattern2(5)

        print("\nTest Case 2:")
        RightAngledPattern2.printRightAngledPattern2(4)

        print("\nTest Case 3:")
        RightAngledPattern2.printRightAngledPattern2(6)

# Execute the main method
if __name__ == "__main__":
    RightAngledPattern2.main()

'''
Output:
Test Case 1:
2 
4 6 
8 10 12 
14 16 18 20 
22 24 26 28 30 

Test Case 2:
2 
4 6 
8 10 12 
14 16 18 20 

Test Case 3:
2 
4 6 
8 10 12 
14 16 18 20 
22 24 26 28 30 
32 34 36 38 40 42 '''


#**************************************************************************************************************************************

# 12. Problem Description: Print Fibonacci Series

# You are tasked with creating a python program to generate and print the Fibonacci series up to a specified number of terms.
# The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, starting from 0 and 1.
# The sequence thus starts as 0, 1, 1, 2, 3, 5, 8, 13, 21, and so on.


# Input:
#    terms: An integer representing the number of terms in the Fibonacci series to generate and print.

# Output:
#    Prints the Fibonacci series up to the specified number of terms.


# Example
#Input: Enter the number of terms: 8
#Output:
#Fibonacci Series: 0 1 1 2 3 5 8 13 21

#Notes:
#    The solution should efficiently generate and print the Fibonacci series.
#    The input terms will always be a positive integer.
#    The program should run without errors for valid input values.

class FibonacciSeries:

    # Method to print Fibonacci series
    @staticmethod
    def printFibonacciSeries(terms):
        firstTerm = 0
        secondTerm = 1

        # Print the first two terms of Fibonacci series
        print("Fibonacci Series:", firstTerm, secondTerm, end="")

        # Generate and print remaining terms
        for i in range(2, terms):
            nextTerm = firstTerm + secondTerm
            print("", nextTerm, end="")
            firstTerm = secondTerm
            secondTerm = nextTerm

    # Main method for testing
    @staticmethod
    def main():
        # Test Cases
        print("Test Case 1:")
        FibonacciSeries.printFibonacciSeries(8)

        print("\nTest Case 2:")
        FibonacciSeries.printFibonacciSeries(10)

        print("\nTest Case 3:")
        FibonacciSeries.printFibonacciSeries(12)

# Execute the main method
if __name__ == "__main__":
    FibonacciSeries.main()

'''
Output:
Test Case 1:
Fibonacci Series: 0 1 1 2 3 5 8 13
Test Case 2:
Fibonacci Series: 0 1 1 2 3 5 8 13 21 34
Test Case 3:
Fibonacci Series: 0 1 1 2 3 5 8 13 21 34 55 89
'''


#**************************************************************************************************************************************

# 13. Calculate Sum Excluding Multiples of 3

# You are tasked with creating a Java program to calculate the sum of all numbers up to a given input, excluding the numbers that are divisible by 3.

# Input:
#     n: An integer representing the upper limit up to which the sum should be calculated (inclusive).

# Output:
#     Returns an integer representing the sum of numbers up to n, excluding those divisible by 3.

# Example
# Input: 8
# Output: 27
# Explanation: The sum of numbers up to 8 excluding multiples of 3: 1 + 2 + 4 + 5 + 7 + 8 = 27

# Notes:
#     The solution should efficiently calculate the sum excluding multiples of 3.
#     The input n will always be a non-negative integer.
#     The program should run without errors for valid input values.

def sum_excluding_multiples_of_three(n):
    sum = 0
    # Iterate through numbers up to n
    for i in range(1, n + 1):
        # Add the number to sum if it's not divisible by 3
        if i % 3 != 0:
            sum += i
    return sum

# Main method for testing
def main():
    # Test Cases
    print("Test Case 1:")
    result1 = sum_excluding_multiples_of_three(8)
    print("Output:", result1)

    print("\nTest Case 2:")
    result2 = sum_excluding_multiples_of_three(10)
    print("Output:", result2)

    print("\nTest Case 3:")
    result3 = sum_excluding_multiples_of_three(12)
    print("Output:", result3)

# Execute the main method
if __name__ == "__main__":
    main()

'''
Output:
Test Case 1:
Output: 27

Test Case 2:
Output: 37

Test Case 3:
Output: 48
'''






#**************************************************************************************************************************************

# 14. Reverse a Number

# You are tasked with creating a python program to reverse a given number.
# Given an input integer, the program should reverse the digits of the number and return the result.

# Input:
#    number: An integer representing the number to be reversed.

# Output:
#    Returns an integer representing the reversed number.

#Example
#Input: 3221
#Output: 1223

#Notes:
#    The solution should efficiently reverse the digits of the given number.
#    Ignore negative numbers, as reversing them would change the sign.
#    The program should run without errors for valid input values.

class ReverseNumber:

    # Method to reverse a number
    @staticmethod
    def reverseNumber(number):
        # Ensure number is positive
        number = abs(number)

        reversedNumber = 0

        # Reverse the digits of the number
        while number > 0:
            digit = number % 10
            reversedNumber = reversedNumber * 10 + digit
            number //= 10

        return reversedNumber

    # Main method for testing
    @staticmethod
    def main():
        # Test Cases
        print("Test Case 1:")
        result1 = ReverseNumber.reverseNumber(3221)
        print("Output:", result1)

        print("\nTest Case 2:")
        result2 = ReverseNumber.reverseNumber(12345)
        print("Output:", result2)

        print("\nTest Case 3:")
        result3 = ReverseNumber.reverseNumber(987654321)
        print("Output:", result3)

# Execute the main method
if __name__ == "__main__":
    ReverseNumber.main()

'''
Output:
Test Case 1:
Output: 1223

Test Case 2:
Output: 54321

Test Case 3:
Output: 123456789
'''


#**************************************************************************************************************************************

# 15.  Check Palindrome Number

# You are tasked with creating a Python program to determine whether a given number is a palindrome or not.
# A palindrome number is a number that remains the same when its digits are reversed.

#Input:
#    number: An integer representing the number to be checked for palindrome property.

#Output:
#    Returns a boolean value true if the given number is a palindrome, false otherwise.

# Example
#Input: 1221
#Output: true
#Explanation: 1221 is a palindrome number.

#Input: 12345
#Output: false
#Explanation: 12345 is not a palindrome number.

#Notes:
#    The solution should efficiently determine whether the given number is a palindrome.
#    Ignore negative numbers, as reversing them would change the sign.
#    The program should run without errors for valid input values

class PalindromeNumber:

    # Method to check if a number is palindrome
    @staticmethod
    def isPalindrome(number):
        # Ensure number is positive
        number = abs(number)

        # Reverse the number
        reversedNumber = 0
        originalNumber = number

        while number > 0:
            digit = number % 10
            reversedNumber = reversedNumber * 10 + digit
            number //= 10

        # Check if original number is equal to reversed number
        return originalNumber == reversedNumber

    # Main method for testing
    @staticmethod
    def main():
        # Test Cases
        print("Test Case 1:")
        number1 = 1221
        print("Input:", number1)
        print("Output:", PalindromeNumber.isPalindrome(number1))

        print("\nTest Case 2:")
        number2 = 12345
        print("Input:", number2)
        print("Output:", PalindromeNumber.isPalindrome(number2))

        print("\nTest Case 3:")
        number3 = 12321
        print("Input:", number3)
        print("Output:", PalindromeNumber.isPalindrome(number3))

# Execute the main method
if __name__ == "__main__":
    PalindromeNumber.main()

'''
Output:
Test Case 1:
Input: 1221
Output: True

Test Case 2:
Input: 12345
Output: False

Test Case 3:
Input: 12321
Output: True
'''


#**************************************************************************************************************************************

# 16. Count Alphabetic Characters in a String

# You are tasked with creating a Python program to count the number of alphabetic characters (letters) in a given string.
# Alphabetic characters include all uppercase and lowercase letters of the alphabet (A-Z, a-z).

# Input:
#    str: A string representing the input string in which alphabetic characters need to be counted.

# Output:
#    Returns an integer representing the count of alphabetic characters in the input string.

# Example
#Input: "Ja$#@ck"
#Output: 4
#Explanation: The string contains the alphabetic characters 'J', 'a', 'c', and 'k'.

#Input: "Hello World!"
#Output: 10
#Explanation: The string contains alphabetic characters from 'a' to 'z' and 'A' to 'Z'.

#Notes:
#    The solution should efficiently count the number of alphabetic characters in the given string.
#    Consider both uppercase and lowercase alphabetic characters.
#    Ignore non-alphabetic characters (e.g., digits, symbols, spaces).
#    The program should run without errors for valid input values.

class CountAlphabeticCharacters:

    # Method to count alphabetic characters in a string
    @staticmethod
    def countAlphabeticCharacters(s):
        count = 0

        # Iterate through each character in the string
        for ch in s:
            # Check if the character is alphabetic
            if ch.isalpha():
                count += 1

        return count

    # Main method for testing
    @staticmethod
    def main():
        # Test Cases
        print("Test Case 1:")
        str1 = "Ja$#@ck"
        print("Input:", str1)
        print("Output:", CountAlphabeticCharacters.countAlphabeticCharacters(str1))

        print("\nTest Case 2:")
        str2 = "Hello World!"
        print("Input:", str2)
        print("Output:", CountAlphabeticCharacters.countAlphabeticCharacters(str2))

        print("\nTest Case 3:")
        str3 = "123ABCabcXYZxyz"
        print("Input:", str3)
        print("Output:", CountAlphabeticCharacters.countAlphabeticCharacters(str3))

# Execute the main method
if __name__ == "__main__":
    CountAlphabeticCharacters.main()

'''
Output:
Test Case 1:
Input: Ja$#@ck
Output: 4

Test Case 2:
Input: Hello World!
Output: 10

Test Case 3:
Input: 123ABCabcXYZxyz
Output: 12
'''


#**************************************************************************************************************************************

# 17. Find Maximum and Minimum Elements in an Array

# You are required to implement a Python program that finds the maximum and minimum elements in a given array of integers.

# Input
#    nums: An array of integers.

# Output:
#    Returns an array of two integers, where the first element represents the maximum element in the input array nums,
#    and the second element represents the minimum element in the array.

# Example 1
#Input: [5, 2, 9, 3, 7]
#Output: [9, 2]

# Example 2
#Input: [10, 20, 30, 40, 50]
#Output: [50, 10]

# Example 3
#Input: [-5, -2, -9, -3, -7]
#Output: [-2, -9]

# Notes:
#    The input array may contain both positive and negative integers.
#    The array will not be empty, and it will contain at least one element.
#    The program should efficiently determine the maximum and minimum elements in the array.

class MaxMinInArray:

    # Method to find maximum and minimum elements in an array
    @staticmethod
    def findMaxAndMin(nums):
        if not nums:
            return []
        
        max_num = nums[0]
        min_num = nums[0]

        for num in nums:
            if num > max_num:
                max_num = num
            if num < min_num:
                min_num = num

        return [max_num, min_num]

    # Main method for testing
    @staticmethod
    def main():
        # Test Cases
        nums1 = [5, 2, 9, 3, 7]
        result1 = MaxMinInArray.findMaxAndMin(nums1)
        print("Test Case 1:")
        print("Input:", nums1)
        print("Output: Max =", result1[0], ", Min =", result1[1])

        nums2 = [10, 20, 30, 40, 50]
        result2 = MaxMinInArray.findMaxAndMin(nums2)
        print("\nTest Case 2:")
        print("Input:", nums2)
        print("Output: Max =", result2[0], ", Min =", result2[1])

        nums3 = [-5, -2, -9, -3, -7]
        result3 = MaxMinInArray.findMaxAndMin(nums3)
        print("\nTest Case 3:")
        print("Input:", nums3)
        print("Output: Max =", result3[0], ", Min =", result3[1])

# Execute the main method
if __name__ == "__main__":
    MaxMinInArray.main()

'''
Output:
Test Case 1:
Input: [5, 2, 9, 3, 7]
Output: Max = 9 , Min = 2

Test Case 2:
Input: [10, 20, 30, 40, 50]
Output: Max = 50 , Min = 10

Test Case 3:
Input: [-5, -2, -9, -3, -7]
Output: Max = -2 , Min = -9
'''



#**************************************************************************************************************************************

# 18. Product of Array Elements

# You are required to create a Java program to find the product of all elements in a given integer array.

# Input:
#     nums: An integer array containing the elements whose product needs to be calculated.

# Output:
#     Returns a long integer representing the product of all elements in the input array.

# Example 1
# Input: nums = {1, 2, 3, 4, 5}
# Output: 120
# Explanation: The product of all elements in the array {1, 2, 3, 4, 5} is 1 * 2 * 3 * 4 * 5 = 120.

# Example 2
# Input: nums = {3, 7, 2, 8}
# Output: 336
# Explanation: The product of all elements in the array {3, 7, 2, 8} is 3 * 7 * 2 * 8 = 336.

# Example 3
# Input: nums = {5}
# Output: 5
# Explanation: The product of all elements in the array {5} is 5.

# Notes:
#     The input array may contain both positive and negative integers.
#     The input array may have zero or multiple elements.
#     The product of array elements should be calculated and returned as a long integer.

def product_of_array_elements(nums):
    product = 1
    for num in nums:
        product *= num
    return product

# Test Cases
test_cases = [
    [1, 2, 3, 4, 5],
    [3, 7, 2, 8],
    [5],
    [-1, -2, -3, -4, -5],
    [0],
    [10, 20, 30, 40]
]

# Output product for each test case
for nums in test_cases:
    print("Product of array elements:", product_of_array_elements(nums))

'''
Output:
Product of array elements: 120
Product of array elements: 336
Product of array elements: 5
Product of array elements: -120
Product of array elements: 0
Product of array elements: 240000
'''

#**************************************************************************************************************************************

# 19. Summation of Natural Numbers

# You are required to create a python program to calculate the summation of the first 'n' natural numbers.

# Input:
#    n: An integer representing the number of natural numbers for which the summation needs to be calculated.

# Output:
#    Returns an integer representing the summation of the first 'n' natural numbers.

# Example 1
#Input: n = 5
#Output: 15
#Explanation: The summation of the first 5 natural numbers (1 + 2 + 3 + 4 + 5) is 15.

# Example 2
#Input: n = 10
#Output: 55
#Explanation: The summation of the first 10 natural numbers (1 + 2 + 3 + ... + 10) is 55.

# Example 3
#Input: n = 1
#Output: 1
#Explanation: The summation of the first 1 natural number (1) is 1.

# Notes:
#    The input 'n' represents the count of natural numbers for which the summation needs to be calculated.
#    The calculated summation should be returned as an integer.

class SumOfNaturalNumbers:

    @staticmethod
    def sum_of_natural_numbers(n):
        # Calculate the summation using the formula (n * (n + 1)) / 2
        return (n * (n + 1)) // 2

    @staticmethod
    def main():
        # Test Cases
        numbers = [5, 10, 1, 100, 20, 30, 15]
        for n in numbers:
            print("Summation of first", n, "natural numbers:", SumOfNaturalNumbers.sum_of_natural_numbers(n))

# Execute the main method
if __name__ == "__main__":
    SumOfNaturalNumbers.main()

'''
Output:
Summation of first 5 natural numbers: 15
Summation of first 10 natural numbers: 55
Summation of first 1 natural numbers: 1
Summation of first 100 natural numbers: 5050
Summation of first 20 natural numbers: 210
Summation of first 30 natural numbers: 465
Summation of first 15 natural numbers: 120
'''

#**************************************************************************************************************************************

# 20. Problem Description: Find Factorial using Recursion

# You are tasked with creating a Python program to find the factorial of a given number using 'recursion'.
# The factorial of a non-negative integer n is the product of all positive integers less than or equal to n.
# The program should efficiently calculate and return the factorial of the input number.

# Input:
#   n: A non-negative integer for which the factorial needs to be calculated (n >= 0).

# Output:
#   Returns the factorial of the input number.

# Example:
# Example 1
# result1 = calculate_factorial(5)
# Output: 120 (Factorial of 5: 5 * 4 * 3 * 2 * 1 = 120)

# Example 2
# result2 = calculate_factorial(8)
# Output: 40320 (Factorial of 8: 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 = 40320)

# Example 3
# result3 = calculate_factorial(0)
# Output: 1 (Factorial of 0 is defined as 1)

# The function should use recursion to calculate the factorial.

def calculate_factorial(n):
    if n < 0:
        raise ValueError("Input should be a non-negative integer.")
    if n == 0 or n == 1:
        return 1  # Factorial of 0 and 1 is 1
    return n * calculate_factorial(n - 1)


# Test Case 1
input1 = 5
result1 = calculate_factorial(input1)
print(f"Test Case 1: Factorial of {input1} = {result1}")

# Test Case 2
input2 = 8
result2 = calculate_factorial(input2)
print(f"Test Case 2: Factorial of {input2} = {result2}")

# Test Case 3
input3 = 0
result3 = calculate_factorial(input3)
print(f"Test Case 3: Factorial of {input3} = {result3}")

# Test Case 4
input4 = 3
result4 = calculate_factorial(input4)
print(f"Test Case 4: Factorial of {input4} = {result4}")

# Test Case 5
input5 = 7
result5 = calculate_factorial(input5)
print(f"Test Case 5: Factorial of {input5} = {result5}")

'''
Sample Output:

 Test Case 1: Factorial of 5 = 120
 Test Case 2: Factorial of 8 = 40320
 Test Case 3: Factorial of 0 = 1
 Test Case 4: Factorial of 3 = 6
 Test Case 5: Factorial of 7 = 5040
 '''


#**************************************************************************************************************************************

# 21. Problem Description: Find the Average of Elements in an Array
# You are tasked with creating a Python program to find the average of elements in an array.
# The program should efficiently calculate and return the average of all elements present in the array.

# Input:
#    nums: An array of integers.

# Output:
#    Returns the average of all elements in the array.


# Example 1
# arr1 = [1, 2, 3, 4, 5]
# result1 = find_average(arr1)
# Output: 3.0 (The average of elements 1, 2, 3, 4, 5 is (1 + 2 + 3 + 4 + 5) / 5 = 3.0)

# Example 2
# arr2 = [10, 20, 30, 40, 50]
# result2 = find_average(arr2)
# Output: 30.0 (The average of elements 10, 20, 30, 40, 50 is (10 + 20 + 30 + 40 + 50) / 5 = 30.0)

def find_average(nums):
    if nums is None or len(nums) == 0:
        raise ValueError("Array should contain at least one element.")

    _sum = sum(nums)
    return _sum / len(nums)


# Test Case 1
arr1 = [1, 2, 3, 4, 5]
result1 = find_average(arr1)
print("Test Case 1: Average of Elements =", result1)

# Test Case 2
arr2 = [10, 20, 30, 40, 50]
result2 = find_average(arr2)
print("Test Case 2: Average of Elements =", result2)

# Test Case 3
arr3 = [5]
result3 = find_average(arr3)
print("Test Case 3: Average of Elements =", result3)

# Test Case 4
arr4 = [-1, 0, 1]
result4 = find_average(arr4)
print("Test Case 4: Average of Elements =", result4)

# Test Case 5
arr5 = [2, 4, 6, 8, 10]
result5 = find_average(arr5)
print("Test Case 5: Average of Elements =", result5)

'''
Output:
Test Case 1: Average of Elements = 3.0
Test Case 2: Average of Elements = 30.0
Test Case 3: Average of Elements = 5.0
Test Case 4: Average of Elements = 0.0
Test Case 5: Average of Elements = 6.0
'''



#**************************************************************************************************************************************

# 22. Problem Description: Count Even and Odd Numbers in an Array
# You are tasked with creating a Python program to count the number of even and odd numbers in an array.
# The program should efficiently determine and return the count of even and odd numbers present in the array.

# Input:
#     nums: An array of integers.

# Output:
#     Returns a list where the first element is the count of even numbers, and the second element is the count of odd numbers.

# Example
#     arr = [2, 5, 8, 3, 6, 7]
#     result = count_even_odd_numbers(arr)
# Output: [3, 3] (There are 3 even numbers {2, 8, 6} and 3 odd numbers {5, 3, 7})

def count_even_odd_numbers(nums):
    if nums is None or len(nums) == 0:
        raise ValueError("Array should contain at least one element.")
    
    even_count = 0
    odd_count = 0
    
    for num in nums:
        if num % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
            
    return [even_count, odd_count]


# Test Case 1
arr1 = [2, 5, 8, 3, 6, 7]
result1 = count_even_odd_numbers(arr1)
print(f"Test Case 1: Even Count = {result1[0]}, Odd Count = {result1[1]}")

# Test Case 2
arr2 = [10, 20, 30, 40, 50]
result2 = count_even_odd_numbers(arr2)
print(f"Test Case 2: Even Count = {result2[0]}, Odd Count = {result2[1]}")

# Test Case 3
arr3 = [7]
result3 = count_even_odd_numbers(arr3)
print(f"Test Case 3: Even Count = {result3[0]}, Odd Count = {result3[1]}")

# Test Case 4
arr4 = [-1, 0, 1]
result4 = count_even_odd_numbers(arr4)
print(f"Test Case 4: Even Count = {result4[0]}, Odd Count = {result4[1]}")

# Test Case 5
arr5 = [2, 4, 6, 8, 10]
result5 = count_even_odd_numbers(arr5)
print(f"Test Case 5: Even Count = {result5[0]}, Odd Count = {result5[1]}")

'''
Output:
Test Case 1: Even Count = 3, Odd Count = 3
Test Case 2: Even Count = 5, Odd Count = 0
Test Case 3: Even Count = 0, Odd Count = 1
Test Case 4: Even Count = 1, Odd Count = 2
Test Case 5: Even Count = 5, Odd Count = 0
'''




#**************************************************************************************************************************************

# 23. Problem Description: Find the Maximum of Three Numbers

# You are tasked with creating a Python program to find the maximum of three numbers.
# The program should efficiently determine and return the largest value among the three input numbers.

# Input:
#     num1, num2, and num3: Three integers.

# Output:
#     Returns the maximum value among the three input numbers.

# Example:
# result = find_maximum(5, 12, 8)
# Output: 12 (Among the numbers 5, 12, and 8, 12 is the largest)

# Notes:
#     The solution should efficiently find and return the maximum value among the three input numbers.
#     The function should handle integer inputs.
#     The program should run without errors for valid input numbers.


def find_maximum(num1, num2, num3):
    max_num = num1

    if num2 > max_num:
        max_num = num2

    if num3 > max_num:
        max_num = num3

    return max_num


# Test Case 1
result1 = find_maximum(5, 12, 8)
print("Test Case 1: Maximum =", result1)

# Test Case 2
result2 = find_maximum(20, 15, 25)
print("Test Case 2: Maximum =", result2)

# Test Case 3
result3 = find_maximum(10, 10, 10)
print("Test Case 3: Maximum =", result3)

# Test Case 4
result4 = find_maximum(-5, -2, -8)
print("Test Case 4: Maximum =", result4)

# Test Case 5
result5 = find_maximum(0, 0, 0)
print("Test Case 5: Maximum =", result5)

# Sample Output:
# Test Case 1: Maximum = 12
# Test Case 2: Maximum = 25
# Test Case 3: Maximum = 10
# Test Case 4: Maximum = -2
# Test Case 5: Maximum = 0



#**************************************************************************************************************************************

# 24. Sum of Digits
#
# You are tasked with creating a python program to calculate the sum of digits of a given integer number.
#
# Input:
#    number: An integer representing the number whose digits' sum needs to be calculated.
#
# Output:
#    Returns an integer representing the sum of digits of the input number.
#
# Example 1
#Input: number = 123
#Output: 6
#Explanation: The sum of digits of the number 123 is 1 + 2 + 3 = 6.
#
# Example 2
#Input: number = 9876
#Output: 30
#Explanation: The sum of digits of the number 9876 is 9 + 8 + 7 + 6 = 30.
#
# Example 3
#Input: number = 5
#Output: 5
#Explanation: The sum of digits of the number 5 is 5.
#
# Notes:
#    The input number may be positive or negative.
#    The sum of digits should be calculated for the absolute value of the number.
#    The calculated sum should be returned as an integer.

class SumOfDigits:

    @staticmethod
    def sum_of_digits(number):
        # Take absolute value to handle negative numbers
        number = abs(number)
        sum_digits = 0
        while number > 0:
            sum_digits += number % 10  # Add the last digit to the sum
            number //= 10  # Remove the last digit
        return sum_digits

    @staticmethod
    def main():
        # Test Cases
        numbers = [123, 9876, 5, -456, 0]
        for number in numbers:
            print("Sum of digits for", number, ":", SumOfDigits.sum_of_digits(number))

# Execute the main method
if __name__ == "__main__":
    SumOfDigits.main()

'''
Ouput:
Sum of digits for 123 : 6
Sum of digits for 9876 : 30
Sum of digits for 5 : 5
Sum of digits for -456 : 15
Sum of digits for 0 : 0
'''
#**************************************************************************************************************************************
