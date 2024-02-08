# 1. Problem Description: Check if Two Strings are Anagrams
# You are tasked with creating a Python program to determine whether two strings are anagrams of each other.
# Two strings are considered anagrams if they have the same characters with the same frequencies, ignoring spaces and case.
# The program should efficiently check if the given strings are anagrams and return the result.

# Input:
#    str1: The first string.
#    str2: The second string.

# Output:
#    Returns True if the strings are anagrams, and False otherwise.

# Example:

# Example 1
#    s1 = "listen"
#    s2 = "silent"
#    result1 = are_anagrams(s1, s2)
# Output: True

# Example 2
#    s3 = "Java"
#    s4 = "jAvA"
#    result2 = are_anagrams(s3, s4)
# Output: True

# Example 3
#    s5 = "Hello"
#    s6 = "World"
#    result3 = are_anagrams(s5, s6)
# Output: False

# Notes:
#    Solution Should be of O(n) time complexity
#    The function should consider spaces and be case-insensitive.

def are_anagrams(str1, str2):
    if str1 is None or str2 is None or len(str1) != len(str2):
        return False

    char_count = [0] * 26  # Assuming only lowercase alphabets, adjust if considering uppercase as well

    # Count the frequency of characters in str1
    for c in str1.lower():
        if c.isalpha():
            char_count[ord(c) - ord('a')] += 1

    # Decrement the frequency of characters in str2
    for c in str2.lower():
        if c.isalpha():
            char_count[ord(c) - ord('a')] -= 1

    # Check if all character frequencies are zero
    for count in char_count:
        if count != 0:
            return False

    return True

# Test Cases
# Test Case 1
s1 = "listen"
s2 = "silent"
print("Test Case 1: Are Anagrams?", are_anagrams(s1, s2))

# Test Case 2
s3 = "Java"
s4 = "jAvA"
print("Test Case 2: Are Anagrams?", are_anagrams(s3, s4))

# Test Case 3
s5 = "Hello"
s6 = "World"
print("Test Case 3: Are Anagrams?", are_anagrams(s5, s6))

# Test Case 4
s7 = "Astronomer"
s8 = "Moon starer"
print("Test Case 4: Are Anagrams?", are_anagrams(s7, s8))

# Test Case 5
s9 = "AABB"
s10 = "ABAB"
print("Test Case 5: Are Anagrams?", are_anagrams(s9, s10))

# Test Case 6
s11 = "A gentleman"
s12 = "Elegant man"
print("Test Case 6: Are Anagrams?", are_anagrams(s11, s12))

# Test Case 7
s13 = "Debit card"
s14 = "Bad credit"
print("Test Case 7: Are Anagrams?", are_anagrams(s13, s14))

# Test Case 8
s15 = "School master"
s16 = "The classroom"
print("Test Case 8: Are Anagrams?", are_anagrams(s15, s16))

# Test Case 9
s17 = "Dormitory"
s18 = "Dirty room"
print("Test Case 9: Are Anagrams?", are_anagrams(s17, s18))


'''
Output
Test Case 1: Are Anagrams? True
Test Case 2: Are Anagrams? True
Test Case 3: Are Anagrams? False
Test Case 4: Are Anagrams? False
Test Case 5: Are Anagrams? True
Test Case 6: Are Anagrams? True
Test Case 7: Are Anagrams? True
Test Case 8: Are Anagrams? True
Test Case 9: Are Anagrams? False'''


# 2. Problem Description: Binary Search

# You are tasked with creating a Python program to implement the binary search algorithm.
# Binary search is an efficient search algorithm that finds the position of a target value within a sorted array.
# The program should efficiently perform binary search and return the index of the target element if found, or -1 if the element is not present in the array.

# Input:
#    sorted_array: A sorted list of integers in ascending order.
#    target: The value to be searched in the array.

# Output:
#    Returns the index of the target element if found; otherwise, returns -1.

# Example:

# Example 1
# arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# target1 = 6
# result1 = binary_search(arr1, target1)
# Output: 5

# Example 2
# arr2 = [2, 4, 6, 8, 10, 12, 14]
# target2 = 5
# result2 = binary_search(arr2, target2)
# Output: -1

# Example 3
# arr3 = [1, 3, 5, 7, 9, 11, 13]
# target3 = 1
# result3 = binary_search(arr3, target3)
# Output: 0

# Notes:
#        The function should return the correct index or -1 based on the binary search.


def binary_search(sorted_array, target):
    left = 0
    right = len(sorted_array) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if sorted_array[mid] == target:
            return mid  # Target found, return the index
        elif sorted_array[mid] < target:
            left = mid + 1  # Adjust search range to the right half
        else:
            right = mid - 1  # Adjust search range to the left half

    return -1  # Target not found


# Test cases

# Test Case 1
arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
target1 = 6
print("Test Case 1: Index of", target1, "=", binary_search(arr1, target1))

# Test Case 2
arr2 = [2, 4, 6, 8, 10, 12, 14]
target2 = 5
print("Test Case 2: Index of", target2, "=", binary_search(arr2, target2))

# Test Case 3
arr3 = [1, 3, 5, 7, 9, 11, 13]
target3 = 1
print("Test Case 3: Index of", target3, "=", binary_search(arr3, target3))

# Test Case 4
arr4 = [3, 6, 9, 12, 15, 18]
target4 = 15
print("Test Case 4: Index of", target4, "=", binary_search(arr4, target4))

# Test Case 5
arr5 = [5, 10, 15, 20, 25]
target5 = 8
print("Test Case 5: Index of", target5, "=", binary_search(arr5, target5))

'''
Output
Test Case 1: Index of 6 = 5
Test Case 2: Index of 5 = -1
Test Case 3: Index of 1 = 0
Test Case 4: Index of 15 = 4
Test Case 5: Index of 8 = -1
'''


# 3. Problem Description: Find the nth Fibonacci Number without Recursion

# You are tasked with creating a Python program to find the nth Fibonacci number without using recursion.
# The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1.
# The program should efficiently calculate and return the nth Fibonacci number.

# Input:
#     n: An integer representing the position in the Fibonacci sequence (n >= 0).
#
# Output:
#     Returns the nth Fibonacci number.

# Example:
# Example 1
# result1 = find_nth_fibonacci(5)
# Output: 5 (Fibonacci sequence: 0, 1, 1, 2, 3, 5)

# Example 2
# result2 = find_nth_fibonacci(8)
# Output: 21 (Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21)

# Example 3
# result3 = find_nth_fibonacci(10)
# Output: 55 (Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55)

# Notes:
#     The function should use an iterative approach without recursion.

def find_nth_fibonacci(n):
    if n < 0:
        raise ValueError("Input should be a non-negative integer.")

    if n == 0:
        return 0
    elif n == 1:
        return 1

    prev = 0
    current = 1

    for i in range(2, n + 1):
        next_val = prev + current
        prev = current
        current = next_val

    return current



# Test Case 1

result1 = find_nth_fibonacci(5)
print("Test Case 1: Nth Fibonacci Number =", result1)

# Test Case 2
result2 = find_nth_fibonacci(8)
print("Test Case 2: Nth Fibonacci Number =", result2)

# Test Case 3
result3 = find_nth_fibonacci(10)
print("Test Case 3: Nth Fibonacci Number =", result3)

# Test Case 4
result4 = find_nth_fibonacci(0)
print("Test Case 4: Nth Fibonacci Number =", result4)

# Test Case 5
result5 = find_nth_fibonacci(2)
print("Test Case 5: Nth Fibonacci Number =", result5)

'''
Output
Test Case 1: Nth Fibonacci Number = 5
Test Case 2: Nth Fibonacci Number = 21
Test Case 3: Nth Fibonacci Number = 55
Test Case 4: Nth Fibonacci Number = 0
Test Case 5: Nth Fibonacci Number = 1
'''


# 4. Problem Description: Find Factorial using Recursion

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


#5. Problem Description: Find Majority Element in an Array

# You are tasked with creating a Python program to find the majority element in an array.
# The majority element is defined as the element that appears more than n/2 times in the array, where n is the size of the array.
# The program should efficiently identify and return the majority element if it exists; otherwise, it should return -1.

# Input:
#     nums: An array of integers.

# Output:
#     Returns the majority element if it exists; otherwise, returns -1.

# Example:
# Example 1
# arr1 = [2, 2, 1, 1, 1, 2, 2]
# result1 = find_majority_element(arr1)
# Output: 2 (Majority element in the array is 2)

# Example 2
# arr2 = [3, 3, 4, 2, 4, 4, 2, 4, 4]
# result2 = find_majority_element(arr2)
# Output: 4 (Majority element in the array is 4)

# Example 3
# arr3 = [1, 2, 3, 4, 5]
# result3 = find_majority_element(arr3)
# Output: -1 (No majority element in the array)

def find_majority_element(nums):
    n = len(nums)

    if n == 0:
        return -1  # No majority element in an empty array

    element_count = [0] * 1001  # Assuming elements in the range [0, 1000]

    for num in nums:
        element_count[num] += 1

    for i in range(len(element_count)):
        if element_count[i] > n / 2:
            return i  # Found majority element

    return -1  # No majority element found


# Test Case 1
arr1 = [2, 2, 1, 1, 1, 2, 2]
result1 = find_majority_element(arr1)
print("Test Case 1: Majority Element =", result1)

# Test Case 2
arr2 = [3, 3, 4, 2, 4, 4, 2, 4, 4]
result2 = find_majority_element(arr2)
print("Test Case 2: Majority Element =", result2)

# Test Case 3
arr3 = [1, 2, 3, 4, 5]
result3 = find_majority_element(arr3)
print("Test Case 3: Majority Element =", result3)

# Test Case 4
arr4 = [1, 1, 1, 2, 2]
result4 = find_majority_element(arr4)
print("Test Case 4: Majority Element =", result4)

# Test Case 5
arr5 = [5]
result5 = find_majority_element(arr5)
print("Test Case 5: Majority Element =", result5)

'''
Test Case 1: Majority Element = 2
Test Case 2: Majority Element = 4
Test Case 3: Majority Element = -1
Test Case 4: Majority Element = 1
Test Case 5: Majority Element = 5
'''


# 6. Problem Description: Calculate Character Frequency in a String

# You are tasked with creating a Python program to calculate the frequency of each character in a given string.
# The program should use a dictionary to store the frequency of each lowercase alphabet character (a to z) in the string.
# The output should display the frequency of each character.

# Input:
# input: A string containing lowercase alphabet characters.

# Output:
# Prints the frequency of each character in the format: "Character: Frequency".

# Example:
# String input = "abracadabra"
# calculate_char_frequency(input)
# Output:
# a: 5
# b: 2
# c: 1
# d: 1
# r: 2

# Notes:
# The solution should efficiently calculate the frequency of characters in the given string.
# The function should print the frequency for each lowercase alphabet character in the specified format.

def calculate_char_frequency(input_str):
    if not input_str:
        print("Input string is empty.")
        return

    char_frequency = {}

    for char in input_str:
        if char.islower():
            char_frequency[char] = char_frequency.get(char, 0) + 1

    for char, frequency in char_frequency.items():
        print(f"{char}: {frequency}")


# Test Case 1
input1 = "abracadabra"
print("Test Case 1:")
calculate_char_frequency(input1)

# Test Case 2
input2 = "hello"
print("\nTest Case 2:")
calculate_char_frequency(input2)

# Test Case 3
input3 = "programming"
print("\nTest Case 3:")
calculate_char_frequency(input3)

# Test Case 4
input4 = "java"
print("\nTest Case 4:")
calculate_char_frequency(input4)

# Test Case 5
input5 = ""
print("\nTest Case 5:")
calculate_char_frequency(input5)

'''
Output:
Test Case 1:
a: 5
b: 2
c: 1
d: 1
r: 2

Test Case 2:
e: 1
h: 1
l: 2
o: 1

Test Case 3:
a: 1
g: 2
i: 1
m: 2
n: 1
o: 1
p: 1
r: 2

Test Case 4:
a: 2
j: 1
v: 1

Test Case 5:
Input string is empty.
'''


# 7. Problem Description: Find the Average of Elements in an Array
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


# 8. Problem Description: Count Even and Odd Numbers in an Array
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

# 9. Problem Description: Find the Maximum of Three Numbers

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


#10. Problem Description: Difference Between Sum of Even and Odd-Indexed Elements

# You are tasked with creating a Python program to find the difference between the sum of even-indexed elements and odd-indexed elements in an array.
# The program efficiently calculates and returns the absolute difference between the sums of elements at even and odd indices in the array.

# Input:
#     nums: An array of integers.

# Output:
#     Returns the absolute difference between the sum of even-indexed elements and odd-indexed elements in the array.

# Example 1
# arr1 = [1, 2, 3, 4, 5]
# result1 = difference_between_sums(arr1)
# Output: 3 (Sum of even-indexed elements: 1 + 3 + 5 = 9, Sum of odd-indexed elements: 2 + 4 = 6, Difference = |9 - 6| = 3)

# Example 2
# arr2 = [10, 20, 30, 40, 50, 60]
# result2 = difference_between_sums(arr2)
# Output: 30 (Sum of even-indexed elements: 10 + 30 + 50 = 90, Sum of odd-indexed elements: 20 + 40 + 60 = 120, Difference = |90 - 120| = 30)

# Notes:
#     The solution should efficiently find and calculate the difference between the sum of even-indexed elements and odd-indexed elements in the array.
#     The function should consider arrays of varying sizes and handle cases where the array may not have both even and odd indices.
#     The program should run without errors for valid input arrays.


def difference_between_sums(nums):
    if nums is None or len(nums) < 2:
        raise ValueError("Array should contain at least two elements.")

    sum_even = 0
    sum_odd = 0

    for i in range(len(nums)):
        if i % 2 == 0:
            sum_even += nums[i]
        else:
            sum_odd += nums[i]

    return abs(sum_even - sum_odd)


# Example Usage
arr1 = [1, 2, 3, 4, 5]
result1 = difference_between_sums(arr1)
print("Example 1: Difference Between Sums =", result1)

arr2 = [10, 20, 30, 40, 50, 60]
result2 = difference_between_sums(arr2)
print("Example 2: Difference Between Sums =", result2)

'''
Output:
Example 1: Difference Between Sums = 3
Example 2: Difference Between Sums = 30
'''


# 11. Armstrong Number
#
# You are tasked with creating a python program to determine whether a given integer 'n' is an Armstrong number.
# An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits in the number.

# Input:
#    n: An integer representing the number to be checked for being an Armstrong number.

# Output:
#    Returns true if the input number n is an Armstrong number, and false otherwise.

# Example 1
#Input: 153
#Output: true
#Explanation: 1^3 + 5^3 + 3^3 = 153

# Example 2
#Input: 370
#Output: true
#Explanation: 3^3 + 7^3 + 0^3 = 370

# Example 3
#Input: 9474
#Output: true
#Explanation: 9^4 + 4^4 + 7^4 + 4^4 = 9474

# Example 4
#Input: 123
#Output: false
#Explanation: 1^3 + 2^3 + 3^3 ≠ 123

# Notes:
#        The solution should efficiently determine whether the input number is an Armstrong number.
#        Armstrong numbers are positive integers with at least two digits.
#        The program should run without errors for valid input values.

class ArmstrongNumber:

    @staticmethod
    def is_armstrong(n):
        # Count the number of digits in the number
        num_digits = len(str(n))
        temp = n
        # Calculate the sum of digits raised to the power of num_digits
        sum_of_powers = sum(int(digit) ** num_digits for digit in str(temp))
        # Check if the sum is equal to the original number
        return sum_of_powers == n

    @staticmethod
    def main():
        # Test Cases
        print("Test Case 1:")
        n1 = 153
        print("Input:", n1)
        print("Output:", ArmstrongNumber.is_armstrong(n1))

        print("\nTest Case 2:")
        n2 = 370
        print("Input:", n2)
        print("Output:", ArmstrongNumber.is_armstrong(n2))

        print("\nTest Case 3:")
        n3 = 9474
        print("Input:", n3)
        print("Output:", ArmstrongNumber.is_armstrong(n3))

        print("\nTest Case 4:")
        n4 = 123
        print("Input:", n4)
        print("Output:", ArmstrongNumber.is_armstrong(n4))


# Execute the main method
if __name__ == "__main__":
    ArmstrongNumber.main()

'''
Output:
Test Case 1:
Input: 153
Output: True

Test Case 2:
Input: 370
Output: True

Test Case 3:
Input: 9474
Output: True

Test Case 4:
Input: 123
Output: False
'''

# 12.  Count Unique Characters in a String
#
# You are tasked with writing a Python program to count the number of unique characters in a given string.
# The uniqueness of characters should be case insensitive, meaning uppercase and lowercase characters should be treated as the same.
# Input:
#    str: A string containing characters.
#
# Output:
#    Returns an integer representing the count of unique characters in the input string str.
#
# Example 1
#Input: "Hello"
#Output: 3  // 'H', 'e', 'o'
#
#Example 2
#Input: "Mississippi"
#Output: 1  // 'M'
#
#Example 3
#Input: "JavaProgramming"
#Output: 6  // 'J', 'v', 'P', 'o', 'g', 'i'
#
# Notes:
#    The input string may contain alphanumeric characters and special symbols.
#    The program should consider characters case-insensitively. For example, 'a' and 'A' should be considered the same character.
#    The program should efficiently determine the count of unique characters in the string.

class UniqueCharacterCounter:

    @staticmethod
    def count_unique_characters(string):
        # Dictionary to store frequency of characters, considering case insensitivity
        frequency = {}
        string = string.lower()  # Convert the string to lowercase

        # Iterate through the string and update frequency dictionary
        for ch in string:
            if ch.isalpha():
                frequency[ch] = frequency.get(ch, 0) + 1

        # Count unique characters
        unique_count = sum(1 for freq in frequency.values() if freq == 1)

        return unique_count

    @staticmethod
    def main():
        # Test Cases
        test_cases = ["Hello", "Mississippi", "JavaProgramming"]
        for idx, test_case in enumerate(test_cases, start=1):
            print(f"Test Case {idx}:")
            print("Input:", test_case)
            print("Output:", UniqueCharacterCounter.count_unique_characters(test_case))

# Execute the main method
if __name__ == "__main__":
    UniqueCharacterCounter.main()

'''
Output:
Test Case 1:
Input: Hello
Output: 3
Test Case 2:
Input: Mississippi
Output: 1
Test Case 3:
Input: JavaProgramming
Output: 6
'''


# 13. Peak Element in Array
#
# You are given an array of integers.
# A peak element in the array is an element that is strictly greater than its neighbors.
# It is the largest element in the array, satisfying the given condition. Additionally, it's important to note that there are no duplicates in the array.
#
# Input:
#    nums: An array of integers.
#
# Output:
#    Returns the peak element in the array.
#
# Example 1
#Input: nums = [5, 10, 20, 15]
#Output: 20
#Explanation: The element 20 is strictly greater than its neighbors 10 and 15.
#
# Example 2
#Input: nums = [1, 3, 6, 7, 4, 2]
#Output: 7
#Explanation: The element 7 is strictly greater than its neighbors 6 and 4.
#
# Example 3
#Input: nums = [10, 20, 30, 40]
#Output: 40
#Explanation: The element 40 is strictly greater than its neighbor 30.
#
# Example 4
#Input: nums = [5, 10, 15, 20, 25]
#Output: 25
#Explanation: The element 25 is strictly greater than its neighbor 20.
#
# Notes:
#    The array will contain at least one element.
#    There will be exactly one peak element in the array.
#    The peak element is guaranteed to be greater than its adjacent elements.
#    Use linear search approach to find the peak element efficiently.

class PeakElement:

    @staticmethod
    def find_peak_element(nums):
        n = len(nums)

        # Edge cases
        if n == 1:
            return nums[0]

        # Check first element
        if nums[0] > nums[1]:
            return nums[0]

        # Check last element
        if nums[n - 1] > nums[n - 2]:
            return nums[n - 1]

        # Check middle elements
        for i in range(1, n - 1):
            if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]:
                return nums[i]

        return -1  # Peak element not found

    @staticmethod
    def main():
        # Test Cases
        nums1 = [5, 10, 20, 15]
        print("Test Case 1:", PeakElement.find_peak_element(nums1))  # Output: 20

        nums2 = [1, 3, 6, 7, 4, 2]
        print("Test Case 2:", PeakElement.find_peak_element(nums2))  # Output: 7

        nums3 = [10, 20, 30, 40]
        print("Test Case 3:", PeakElement.find_peak_element(nums3))  # Output: 40

        nums4 = [5, 10, 15, 20, 25]
        print("Test Case 4:", PeakElement.find_peak_element(nums4))  # Output: 25

        nums5 = [1]
        print("Test Case 5:", PeakElement.find_peak_element(nums5))  # Output: 1

        nums6 = [10, 9, 8, 7]
        print("Test Case 6:", PeakElement.find_peak_element(nums6))  # Output: 10

        nums7 = [10, 11, 13, 16, 20, 8, 5, 4]
        print("Test Case 7:", PeakElement.find_peak_element(nums7))  # Output: 20

        nums8 = [20, 40, 50, 70, 90, 60, 30, 10]
        print("Test Case 8:", PeakElement.find_peak_element(nums8))  # Output: 90

# Execute the main method
if __name__ == "__main__":
    PeakElement.main()

'''
Output:
Test Case 1: 20
Test Case 2: 7
Test Case 3: 40
Test Case 4: 25
Test Case 5: 1
Test Case 6: 10
Test Case 7: 20
Test Case 8: 90
'''


# 15. Sum of Digits
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

# 16. Pairs with Sum

# You are tasked with creating a Python program to find all pairs of elements in an array whose sum is equal to a given target number.

# Input:
#    nums: An array of integers representing the input array.
#    target: An integer representing the target sum.

# Output:
#    Prints all pairs of elements in the array nums whose sum equals the target.

# Example 1
#Input: nums = {1, 2, 3, 4, 5}, target = 5
#Output: (1, 4), (2, 3)
#Explanation: In the input array, the pairs (1, 4) and (2, 3) have a sum equal to the target 5.

# Example 2
#Input: nums = {3, 8, 5, 2, 9}, target = 10
#Output: (3, 7), (8, 2)
#Explanation: In the input array, the pairs (3, 7) and (8, 2) have a sum equal to the target 10.

# Notes:
#    Each pair should be printed only once, and the order of elements within the pair does not matter.
#    If there are no such pairs in the array whose sum equals the target, print "No pairs found."

class PairSum:

    @staticmethod
    def find_pairs(nums, target):
        found_pair = False
        # Brute-force approach: Check all pairs of elements in the array
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    print("({}, {})".format(nums[i], nums[j]))
                    found_pair = True
        if not found_pair:
            print("No pairs found.")

    @staticmethod
    def main():
        # Test Cases
        nums1 = [1, 2, 3, 4, 5]
        target1 = 5
        print("Pairs with sum {} in nums1:".format(target1))
        PairSum.find_pairs(nums1, target1)

        nums2 = [3, 8, 5, 2, 9]
        target2 = 10
        print("\nPairs with sum {} in nums2:".format(target2))
        PairSum.find_pairs(nums2, target2)

        nums3 = [1, 2, 3, 4, 5]
        target3 = 20
        print("\nPairs with sum {} in nums3:".format(target3))
        PairSum.find_pairs(nums3, target3)

        nums4 = [5, 4, 6, 5]
        target4 = 10
        print("\nPairs with sum {} in nums4:".format(target4))
        PairSum.find_pairs(nums4, target4)

        nums5 = [1, 2, 3, 4, 5]
        target5 = 8
        print("\nPairs with sum {} in nums5:".format(target5))
        PairSum.find_pairs(nums5, target5)

# Execute the main method
if __name__ == "__main__":
    PairSum.main()

'''
Output:
Pairs with sum 5 in nums1:
(1, 4)
(2, 3)

Pairs with sum 10 in nums2:
(8, 2)

Pairs with sum 20 in nums3:
No pairs found.

Pairs with sum 10 in nums4:
(5, 5)
(4, 6)

Pairs with sum 8 in nums5:
(3, 5)
'''

# 18. Finding Factors
#
# You are tasked with creating a Python program to find all the factors (numbers that evenly divide) of a given input number.
#
# Input:
#     n: A positive integer representing the input number.
#
# Output:
#     Prints all the factors of the input number n.
#
# Example 1
# Input: n = 12
# Output: Factors of 12: 1, 2, 3, 4, 6, 12
# Explanation: The factors of 12 are 1, 2, 3, 4, 6, and 12.
#
# Example 2
# Input: n = 15
# Output: Factors of 15: 1, 3, 5, 15
# Explanation: The factors of 15 are 1, 3, 5, and 15.
#
# Notes:
#     Factors are the numbers that divide the given input number evenly without leaving a remainder.
#     The factors should be printed in ascending order.
#     Include the input number itself and 1 as factors.

class Factors:

    @staticmethod
    def find_factors(n):
        print("Factors of", n, end=": ")
        # Iterate from 1 to n and check if i divides n evenly
        factors = []
        for i in range(1, n + 1):
            if n % i == 0:
                factors.append(i)
        print(", ".join(map(str, factors)))

    @staticmethod
    def main():
        # Test Cases
        num1 = 12
        print("Test Case 1:")
        Factors.find_factors(num1)

        num2 = 15
        print("\nTest Case 2:")
        Factors.find_factors(num2)

        num3 = 28
        print("\nTest Case 3:")
        Factors.find_factors(num3)

# Execute the main method
if __name__ == "__main__":
    Factors.main()

'''
Output;
Test Case 1:
Factors of 12: 1, 2, 3, 4, 6, 12

Test Case 2:
Factors of 15: 1, 3, 5, 15

Test Case 3:
Factors of 28: 1, 2, 4, 7, 14, 28
'''

