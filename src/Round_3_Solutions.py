# 1. Problem Description: Find the Next Prime Number

# You are tasked with creating a Python program to find the next prime number after a given number.
# The program should efficiently identify and return the next prime number that comes after the provided input.

# Input:
#     num: A positive integer greater than 1.

# Output:
#     Returns the next prime number greater than the input.

# Example 1
# result1 = findNextPrime(10)
# Output: 11 (The next prime number after 10 is 11)

# Example 2
# result2 = findNextPrime(20)
# Output: 23 (The next prime number after 20 is 23)

# Example 3
# result3 = findNextPrime(31)
# Output: 37 (The next prime number after 31 is 37)

# Notes:
#     The solution should efficiently find the next prime number after the given input.
#     The function should consider positive integers greater than 1 as input.
#     The program should run without errors for valid input values.

import math

def findNextPrime(num):
    if num < 1:
        raise ValueError("Input should be a positive integer greater than 1.")

    while True:
        num += 1

        if isPrime(num):
            return num  # Found the next prime number

def isPrime(num):
    if num <= 1:
        return False

    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False  # Found a divisor, not a prime number

    return True  # No divisors found, it's a prime number

# Test Case 1
input1 = 10
result1 = findNextPrime(input1)
print(f"Test Case 1: Next Prime Number = {result1}")

# Test Case 2
input2 = 20
result2 = findNextPrime(input2)
print(f"Test Case 2: Next Prime Number = {result2}")

# Test Case 3
input3 = 31
result3 = findNextPrime(input3)
print(f"Test Case 3: Next Prime Number = {result3}")

# Test Case 4
input4 = 1
try:
    result4 = findNextPrime(input4)
    print(f"Test Case 4: Next Prime Number = {result4}")
except ValueError as e:
    print(f"Test Case 4: {e}")


'''
Output:
Test Case 1: Next Prime Number = 11
Test Case 2: Next Prime Number = 23
Test Case 3: Next Prime Number = 37
Test Case 4: Next Prime Number = 2
'''

#2.  Problem Description: Find the Sum of Two Largest Elements in an Array

# You are tasked with creating a Python program to find the sum of the two largest elements in an array.
# The program should efficiently calculate and return the sum of the two largest distinct elements in the array.

# Input:
#     nums: An array of integers.

# Output:
#     Returns the sum of the two largest distinct elements in the array.

# Example 1
# arr1 = [3, 7, 2, 8, 5]
# result1 = sum_of_two_largest(arr1)
# Output: 15 (The two largest elements are 8 and 7, and their sum is 15)

# Example 2
# arr2 = [5, 5, 5, 5]
# result2 = sum_of_two_largest(arr2)
# Output: 10 (The two largest distinct elements are both 5, and their sum is 10)

# Notes:
#     The solution should efficiently find and calculate the sum of the two largest distinct elements in the array.
#     The function should consider arrays of varying sizes and handle cases where there are not enough distinct elements.
#     The program should run without errors for valid input arrays.

def sum_of_two_largest(nums):
    if nums is None or len(nums) < 2:
        raise ValueError("Array should contain at least two elements.")

    first_largest = float('-inf')
    second_largest = float('-inf')

    for num in nums:
        if num > first_largest:
            second_largest = first_largest
            first_largest = num
        elif num > second_largest and num < first_largest:
            second_largest = num

    if second_largest == float('-inf'):
        raise ValueError("Array should contain at least two distinct elements.")

    return first_largest + second_largest

# Test Cases
# Test Case 1
arr1 = [3, 7, 2, 8, 5]
result1 = sum_of_two_largest(arr1)
print("Test Case 1: Sum of Two Largest =", result1)

# Test Case 2
arr2 = [5, 8, 4, 3]
result2 = sum_of_two_largest(arr2)
print("Test Case 2: Sum of Two Largest =", result2)

# Test Case 3
arr3 = [1, 2, 3, 4, 5]
result3 = sum_of_two_largest(arr3)
print("Test Case 3: Sum of Two Largest =", result3)

# Test Case 4
arr4 = [10, 10, 20, 20, 30]
result4 = sum_of_two_largest(arr4)
print("Test Case 4: Sum of Two Largest =", result4)

# Test Case 5
arr5 = [5, 3]
result5 = sum_of_two_largest(arr5)
print("Test Case 5: Sum of Two Largest =", result5)

'''
Output:
Test Case 1: Sum of Two Largest = 15
Test Case 2: Sum of Two Largest = 13
Test Case 3: Sum of Two Largest = 9
Test Case 4: Sum of Two Largest = 50
Test Case 5: Sum of Two Largest = 8
'''

# 3. Problem Description: Square of the Sum of Digits

# You are tasked with creating a Python program to find the square of the sum of digits of a given number.
# The program should efficiently calculate and return the square of the sum of the individual digits of the input number.

# Input:
#     num: A non-negative integer.

# Output:
#     Returns the square of the sum of the individual digits of the input number.

# Example 1
# result1 = square_of_sum_of_digits(123)
# Output: 36 (The sum of digits is 1 + 2 + 3 = 6, and the square of 6 is 36)

# Example 2
# result2 = square_of_sum_of_digits(456)
# Output: 81 (The sum of digits is 4 + 5 + 6 = 15, and the square of 15 is 225)

# Notes:
#     The solution should efficiently calculate the square of the sum of digits for a given non-negative integer.
#     The function should handle valid non-negative integer inputs.
#     The program should run without errors for valid input numbers.

def square_of_sum_of_digits(num):
    if num < 0:
        raise ValueError("Input should be a non-negative integer.")

    sum_of_digits = 0

    while num > 0:
        digit = num % 10
        sum_of_digits += digit
        num //= 10

    square_of_sum = sum_of_digits ** 2
    return square_of_sum

# Test Cases
# Test Case 1
input1 = 123
result1 = square_of_sum_of_digits(input1)
print("Test Case 1: Square of Sum of Digits =", result1)

# Test Case 2
input2 = 456
result2 = square_of_sum_of_digits(input2)
print("Test Case 2: Square of Sum of Digits =", result2)

# Test Case 3
input3 = 7890
result3 = square_of_sum_of_digits(input3)
print("Test Case 3: Square of Sum of Digits =", result3)

# Test Case 4
input4 = 0
result4 = square_of_sum_of_digits(input4)
print("Test Case 4: Square of Sum of Digits =", result4)

# Test Case 5
input5 = 987654321
result5 = square_of_sum_of_digits(input5)
print("Test Case 5: Square of Sum of Digits =", result5)

'''
Output:
Test Case 1: Square of Sum of Digits = 36
Test Case 2: Square of Sum of Digits = 81
Test Case 3: Square of Sum of Digits = 576
Test Case 4: Square of Sum of Digits = 0
Test Case 5: Square of Sum of Digits = 2025
'''

# 4. Problem Description: Check if a Number is a Perfect Square

# You are tasked with creating a Python program to determine whether a given number is a perfect square.
# The program should efficiently check and return True if the number is a perfect square, and False otherwise.

# Input:
#     num: A non-negative integer.

# Output:
#     Returns True if the number is a perfect square, and False otherwise.

# Example 1
# result1 = isPerfectSquare(16)
# Output: True (16 is a perfect square, as 4 * 4 = 16)

# Example 2
# result2 = isPerfectSquare(25)
# Output: True (25 is a perfect square, as 5 * 5 = 25)

# Example 3
# result3 = isPerfectSquare(14)
# Output: False (14 is not a perfect square)

# Notes:
#     The solution should efficiently check whether the given number is a perfect square.
#     The function should handle non-negative integers as input.
#     The program should run without errors for valid input numbers.

def isPerfectSquare(num):
    if num < 0:
        raise ValueError("Input should be a non-negative integer.")

    sqrt_root = 0

    while sqrt_root * sqrt_root <= num:
        if sqrt_root * sqrt_root == num:
            return True  # Found a perfect square
        sqrt_root += 1

    return False  # No perfect square found

# Test Cases
input1 = 16
result1 = isPerfectSquare(input1)
print("Test Case 1: Is Perfect Square?", result1)

input2 = 25
result2 = isPerfectSquare(input2)
print("Test Case 2: Is Perfect Square?", result2)

input3 = 14
result3 = isPerfectSquare(input3)
print("Test Case 3: Is Perfect Square?", result3)

input4 = 0
result4 = isPerfectSquare(input4)
print("Test Case 4: Is Perfect Square?", result4)

input5 = 100
result5 = isPerfectSquare(input5)
print("Test Case 5: Is Perfect Square?", result5)

# Sample Output:
# Test Case 1: Is Perfect Square? True
# Test Case 2: Is Perfect Square? True
# Test Case 3: Is Perfect Square? False
# Test Case 4: Is Perfect Square? True
# Test Case 5: Is Perfect Square? True


#  5. Problem Description: Check if a String Starts with a Specific Prefix
#
# You are tasked with creating a Python program to check if a given string starts with a specific prefix.
# The program should efficiently determine and return True if the string begins with the specified prefix, and False otherwise.

# Input:
#    str: A string.
#    prefix: The prefix to check.

# Output:
#    Returns True if the string starts with the specified prefix, and False otherwise.

# Example 1
# result1 = starts_with_prefix("Hello, World!", "Hello")
# Output: True ("Hello, World!" starts with the prefix "Hello")

# Example 2
# result2 = starts_with_prefix("Java Programming", "Python")
# Output: False ("Java Programming" does not start with the prefix "Python")

# Example 3
# result3 = starts_with_prefix("12345", "12")
# Output: True ("12345" starts with the prefix "12")

# Notes:
#    The solution should efficiently check whether the given string starts with the specified prefix.
#    The function should handle cases where the string or prefix may be empty.
#    The program should run without errors for valid input strings and prefixes.

def starts_with_prefix(string, prefix):
    if string is None or prefix is None:
        raise ValueError("Input strings cannot be None.")

    prefix_length = len(prefix)

    if prefix_length > len(string):
        return False  # Prefix is longer than the string, cannot be a match

    for i in range(prefix_length):
        if string[i] != prefix[i]:
            return False  # Mismatch at current position

    return True  # Prefix matches the start of the string


# Test Case 1
result1 = starts_with_prefix("Hello, World!", "Hello")
print("Test Case 1: Starts with Prefix?", result1)

# Test Case 2
result2 = starts_with_prefix("Java Programming", "Python")
print("Test Case 2: Starts with Prefix?", result2)

# Test Case 3
result3 = starts_with_prefix("12345", "12")
print("Test Case 3: Starts with Prefix?", result3)

# Test Case 4
result4 = starts_with_prefix("Java", "Java")
print("Test Case 4: Starts with Prefix?", result4)

# Test Case 5
result5 = starts_with_prefix("", "Prefix")
print("Test Case 5: Starts with Prefix?", result5)


'''
Output:
Test Case 1: Starts with Prefix? True
Test Case 2: Starts with Prefix? False
Test Case 3: Starts with Prefix? True
Test Case 4: Starts with Prefix? True
Test Case 5: Starts with Prefix? False
'''

# 6. Problem Description: Sum of Prime Numbers up to a Given Limit
#
# You are tasked with creating a Python program to find the sum of prime numbers up to a given limit.
# The program should efficiently determine and return the sum of all prime numbers within the specified range.
#
# Function Signature: def sum_of_primes(limit: int) -> int
#
# Input:
#     limit: An integer representing the upper limit of the range.
#
# Output:
#     Returns the sum of prime numbers up to the given limit.
#
# Example
# result = sum_of_primes(10)
# Output: 17 (2 + 3 + 5 + 7 are prime numbers up to the limit 10)
#
# Notes:
#     The solution should efficiently find and return the sum of prime numbers up to the specified limit.
#     The function should handle non-negative integer inputs.
#     The program should run without errors for valid input limits.


import math

class SumOfPrimes:
   
    def sum_of_primes(limit):
        if limit < 0:
            raise ValueError("Limit should be a non-negative integer.")

        prime_sum = 0

        for i in range(2, limit + 1):
            if SumOfPrimes.is_prime(i):
                prime_sum += i

        return prime_sum
    
    def is_prime(num):
        if num < 2:
            return False

        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                return False  # Not a prime number

        return True  # Prime number


# Test Case 1
result1 = SumOfPrimes.sum_of_primes(10)
print("Test Case 1: Sum of Primes =", result1)

# Test Case 2
result2 = SumOfPrimes.sum_of_primes(20)
print("Test Case 2: Sum of Primes =", result2)

# Test Case 3
result3 = SumOfPrimes.sum_of_primes(5)
print("Test Case 3: Sum of Primes =", result3)

# Test Case 4
result4 = SumOfPrimes.sum_of_primes(0)
print("Test Case 4: Sum of Primes =", result4)

# Test Case 5
result5 = SumOfPrimes.sum_of_primes(30)
print("Test Case 5: Sum of Primes =", result5)


# Sample Output:
# Test Case 1: Sum of Primes = 17
# Test Case 2: Sum of Primes = 77
# Test Case 3: Sum of Primes = 10
# Test Case 4: Sum of Primes = 0
# Test Case 5: Sum of Primes = 129


#  7. Problem Description: Find the Kth Largest Element in an Array

#You are tasked with creating a Python program to find the Kth largest element in an array.
# The program should efficiently determine and return the Kth largest element from the given array.

#Input:
#    nums: A list of integers.
#    k: An integer representing the position of the Kth largest element (1 <= k <= length of the array).

#Output:
#    Returns the Kth largest element from the array.

# Example
#arr = [3, 1, 5, 7, 2, 4, 6]
#k = 3
#result = findKthLargest(arr, k)
# Output: 5 (The 3rd largest element in the array is 5)

#Notes:
#    The solution should efficiently find and return the Kth largest element from the array.
#    The function should handle valid positions for K within the range of the array length.
#    The program should run without errors for valid input arrays and positions.

class KthLargestElement:

    @staticmethod
    def findKthLargest(nums, k):
        if nums is None or k <= 0 or k > len(nums):
            raise ValueError("Invalid input parameters.")

        nums.sort()
        return nums[-k]

    @staticmethod
    def main():
        # Test Case 1
        arr1 = [3, 1, 5, 7, 2, 4, 6]
        k1 = 3
        result1 = KthLargestElement.findKthLargest(arr1, k1)
        print("Test Case 1: Kth Largest Element =", result1)

        # Test Case 2
        arr2 = [10, 20, 30, 40, 50]
        k2 = 1
        result2 = KthLargestElement.findKthLargest(arr2, k2)
        print("Test Case 2: Kth Largest Element =", result2)

        # Test Case 3
        arr3 = [7]
        k3 = 1
        result3 = KthLargestElement.findKthLargest(arr3, k3)
        print("Test Case 3: Kth Largest Element =", result3)

        # Test Case 4
        arr4 = [5, 5, 5, 5, 5]
        k4 = 2
        result4 = KthLargestElement.findKthLargest(arr4, k4)
        print("Test Case 4: Kth Largest Element =", result4)

        # Test Case 5
        arr5 = [1, 2, 3, 4, 5]
        k5 = 5
        result5 = KthLargestElement.findKthLargest(arr5, k5)
        print("Test Case 5: Kth Largest Element =", result5)

KthLargestElement.main()


#Sample Output:
# Test Case 1: Kth Largest Element = 5
#Test Case 2: Kth Largest Element = 50
#Test Case 3: Kth Largest Element = 7
#Test Case 4: Kth Largest Element = 5
#Test Case 5: Kth Largest Element = 1


# 8. Problem Description: Single Number
# You are tasked with creating a Python program to find the single number in an array where every element appears twice except for one.
# Your solution must have linear runtime complexity and use only constant extra space.

# Input:
#     nums: A non-empty array of integers where every element appears twice except for one.

# Output:
#     Returns the single number that appears only once in the array.

# Example
# arr = [4, 2, 7, 2, 4]
# result = findSingleNumber(arr)
# Output: 7 (7 is the only element that appears once in the array)

# Notes:
#     The solution should have linear runtime complexity O(n) and use only constant extra space O(1).
#     The array will always contain an odd number of elements.
#     The program should run without errors for valid input arrays.

def findSingleNumber(nums):
    if nums is None or len(nums) % 2 == 0:
        raise ValueError("Invalid input array.")

    result = 0

    for num in nums:
        result ^= num  # Using XOR operation to find the single number

    return result

# Test Case 1
arr1 = [4, 2, 7, 2, 4]
result1 = findSingleNumber(arr1)
print("Test Case 1: Single Number =", result1)

# Test Case 2
arr2 = [1, 2, 3, 1, 3]
result2 = findSingleNumber(arr2)
print("Test Case 2: Single Number =", result2)

# Test Case 3
arr3 = [5, 6, 6]
result3 = findSingleNumber(arr3)
print("Test Case 3: Single Number =", result3)

'''
Output:
Test Case 1: Single Number = 7
Test Case 2: Single Number = 2
Test Case 3: Single Number = 5
'''


#  9. Problem Description: Missing Number

# You are tasked with creating a Python program to find the missing number in an array.
# Given an array nums containing n distinct numbers in the range [0, n],
# the program should efficiently determine and return the only number in the range that is missing from the array.

# Input:
#     nums: An array of distinct integers in the range [0, n], where n is the length of the array.

# Output:
#     Returns the missing number from the array.

# Example
# arr = [3, 0, 1]
# result = find_missing_number(arr)
# Output: 2 (The missing number in the array is 2)

# Notes:
#     The solution should efficiently find and return the missing number in the array.
#     The array will always contain n distinct numbers in the range [0, n], where n is the length of the array.
#     The program should run without errors for valid input arrays.


def find_missing_number(nums):
    if nums is None or len(nums) == 0:
        raise ValueError("Invalid input array.")

    n = len(nums)
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(nums)

    return expected_sum - actual_sum


# Test cases
# Test Case 1
arr1 = [3, 0, 1]
result1 = find_missing_number(arr1)
print("Test Case 1: Missing Number =", result1)

# Test Case 2
arr2 = [9, 6, 4, 2, 3, 5, 7, 0, 1]
result2 = find_missing_number(arr2)
print("Test Case 2: Missing Number =", result2)

# Test Case 3
arr3 = [1]
result3 = find_missing_number(arr3)
print("Test Case 3: Missing Number =", result3)

# Sample Output:
# Test Case 1: Missing Number = 2
# Test Case 2: Missing Number = 8
# Test Case 3: Missing Number = 0


