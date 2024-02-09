//******************************************************---****************************************************************

//  1. Problem Description: Find the Next Prime Number

//You are tasked with creating a C program to find the next prime number after a given number.
// The program should efficiently identify and return the next prime number that comes after the provided input.

//Input:
//    num: A positive integer greater than 1.

//Output:
//    Returns the next prime number greater than the input.

// Example 1
//int result1 = findNextPrime(10);
// Output: 11 (The next prime number after 10 is 11)

// Example 2
//int result2 = findNextPrime(20);
// Output: 23 (The next prime number after 20 is 23)

// Example 3
//int result3 = findNextPrime(31);
// Output: 37 (The next prime number after 31 is 37)

//Notes:
//    The solution should efficiently find the next prime number after the given input.
//    The function should consider positive integers greater than 1 as input.
//    The program should run without errors for valid input values.

#include <stdio.h>
#include <stdbool.h>
#include <math.h> // for sqrt function

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not a prime number
        }
    }

    return true; // No divisors found, it's a prime number
}

// Function to find the next prime number
int findNextPrime(int num) {
    if (num < 1) {
        printf("Input should be a positive integer greater than 1.\n");
        return -1;
    }

    while (true) {
        num++;

        if (isPrime(num)) {
            return num; // Found the next prime number
        }
    }
}

// Main function for testing
int main() {
    // Test Cases
    int input1 = 10;
    int result1 = findNextPrime(input1);
    printf("Test Case 1: Next Prime Number = %d\n", result1);

    int input2 = 20;
    int result2 = findNextPrime(input2);
    printf("Test Case 2: Next Prime Number = %d\n", result2);

    int input3 = 31;
    int result3 = findNextPrime(input3);
    printf("Test Case 3: Next Prime Number = %d\n", result3);

    int input4 = 1;
    int result4 = findNextPrime(input4);
    printf("Test Case 4: Next Prime Number = %d\n", result4);

    return 0;
}


//Sample Output:
// Test Case 1: Next Prime Number = 11
//Test Case 2: Next Prime Number = 23
//Test Case 3: Next Prime Number = 37
//Test Case 4: Next Prime Number = 2


//******************************************************---****************************************************************

//  2. Problem Description: Find the Sum of Two Largest Elements in an Array

//You are tasked with creating a C program to find the sum of the two largest elements in an array.
// The program should efficiently calculate and return the sum of the two largest distinct elements in the array.

//Input:
//    nums: An array of integers.

//Output:
//    Returns the sum of the two largest distinct elements in the array.

// Example 1
//int[] arr1 = {3, 7, 2, 8, 5};
//int result1 = sumOfTwoLargest(arr1);
// Output: 15 (The two largest elements are 8 and 7, and their sum is 15)

// Example 2
//int[] arr2 = {5, 5, 5, 5};
//int result2 = sumOfTwoLargest(arr2);
// Output: 10 (The two largest distinct elements are both 5, and their sum is 10)

//Notes:
//    The solution should efficiently find and calculate the sum of the two largest distinct elements in the array.
//    The function should consider arrays of varying sizes and handle cases where there are not enough distinct elements.
//    The program should run without errors for valid input arrays.

#include <stdio.h>
#include <limits.h> // for INT_MIN

// Function to find the sum of the two largest elements in an array
int sumOfTwoLargest(int nums[], int length) {
    if (nums == NULL || length < 2) {
        printf("Array should contain at least two elements.\n");
        return -1;
    }

    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < length; i++) {
        if (nums[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = nums[i];
        } else if (nums[i] > secondLargest && nums[i] < firstLargest) {
            secondLargest = nums[i];
        }
    }

    if (secondLargest == INT_MIN) {
        printf("Array should contain at least two distinct elements.\n");
        return -1;
    }

    return firstLargest + secondLargest;
}

// Main function for testing
int main() {
    // Test Cases
    int arr1[] = {3, 7, 2, 8, 5};
    int result1 = sumOfTwoLargest(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("Test Case 1: Sum of Two Largest = %d\n", result1);

    int arr2[] = {5, 8, 4, 3};
    int result2 = sumOfTwoLargest(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("Test Case 2: Sum of Two Largest = %d\n", result2);

    int arr3[] = {1, 2, 3, 4, 5};
    int result3 = sumOfTwoLargest(arr3, sizeof(arr3) / sizeof(arr3[0]));
    printf("Test Case 3: Sum of Two Largest = %d\n", result3);

    int arr4[] = {10, 10, 20, 20, 30};
    int result4 = sumOfTwoLargest(arr4, sizeof(arr4) / sizeof(arr4[0]));
    printf("Test Case 4: Sum of Two Largest = %d\n", result4);

    int arr5[] = {5, 3};
    int result5 = sumOfTwoLargest(arr5, sizeof(arr5) / sizeof(arr5[0]));
    printf("Test Case 5: Sum of Two Largest = %d\n", result5);

    return 0;
}

//Sample Output:
// Test Case 1: Sum of Two Largest = 15
//Test Case 2: Sum of Two Largest = 13
//Test Case 3: Sum of Two Largest = 9
//Test Case 4: Sum of Two Largest = 50
//Test Case 5: Sum of Two Largest = 8


//******************************************************---****************************************************************

//  3. Problem Description: Square of the Sum of Digits

//You are tasked with creating a C program to find the square of the sum of digits of a given number.
// The program should efficiently calculate and return the square of the sum of the individual digits of the input number.

//Input:
//    num: A non-negative integer.

//Output:
//    Returns the square of the sum of the individual digits of the input number.

// Example 1
//int result1 = squareOfSumOfDigits(123);
// Output: 36 (The sum of digits is 1 + 2 + 3 = 6, and the square of 6 is 36)

// Example 2
//int result2 = squareOfSumOfDigits(456);
// Output: 81 (The sum of digits is 4 + 5 + 6 = 15, and the square of 15 is 225)

//Notes:
//    The solution should efficiently calculate the square of the sum of digits for a given non-negative integer.
//    The function should handle valid non-negative integer inputs.
//    The program should run without errors for valid input numbers.

#include <stdio.h>
#include <stdlib.h> // for abs function

// Function to calculate the square of the sum of digits of a non-negative integer
int squareOfSumOfDigits(int num) {
    if (num < 0) {
        printf("Input should be a non-negative integer.\n");
        return -1;
    }

    int sumOfDigits = 0;

    while (num > 0) {
        int digit = num % 10;
        sumOfDigits += digit;
        num /= 10;
    }

    int squareOfSum = sumOfDigits * sumOfDigits;
    return squareOfSum;
}

// Main function for testing
int main() {
    // Test Cases
    int input1 = 123;
    int result1 = squareOfSumOfDigits(input1);
    printf("Test Case 1: Square of Sum of Digits = %d\n", result1);

    int input2 = 456;
    int result2 = squareOfSumOfDigits(input2);
    printf("Test Case 2: Square of Sum of Digits = %d\n", result2);

    int input3 = 7890;
    int result3 = squareOfSumOfDigits(input3);
    printf("Test Case 3: Square of Sum of Digits = %d\n", result3);

    int input4 = 0;
    int result4 = squareOfSumOfDigits(input4);
    printf("Test Case 4: Square of Sum of Digits = %d\n", result4);

    int input5 = 987654321;
    int result5 = squareOfSumOfDigits(input5);
    printf("Test Case 5: Square of Sum of Digits = %d\n", result5);

    return 0;
}


//Sample Output:
// Test Case 1: Square of Sum of Digits = 36
//Test Case 2: Square of Sum of Digits = 225
//Test Case 3: Square of Sum of Digits = 576
//Test Case 4: Square of Sum of Digits = 0
//Test Case 5: Square of Sum of Digits = 2025

//******************************************************---****************************************************************

//  4. Problem Description: Check if a Number is a Perfect Square

//You are tasked with creating a C program to determine whether a given number is a perfect square.
// The program should efficiently check and return true if the number is a perfect square, and false otherwise.

//Input:
//    num: A non-negative integer.

//Output:
//    Returns true if the number is a perfect square, and false otherwise.

// Example 1
//boolean result1 = isPerfectSquare(16);
// Output: true (16 is a perfect square, as 4 * 4 = 16)

// Example 2
//boolean result2 = isPerfectSquare(25);
// Output: true (25 is a perfect square, as 5 * 5 = 25)

// Example 3
//boolean result3 = isPerfectSquare(14);
// Output: false (14 is not a perfect square)

//Notes:
//    The solution should efficiently check whether the given number is a perfect square.
//    The function should handle non-negative integers as input.
//    The program should run without errors for valid input numbers.

#include <stdio.h>
#include <stdbool.h> // for bool data type
#include <math.h>     // for sqrt function

// Function to check if a number is a perfect square
bool isPerfectSquare(int num) {
    if (num < 0) {
        printf("Input should be a non-negative integer.\n");
        return false;
    }

    int sqrtRoot = 0;

    while (sqrtRoot * sqrtRoot <= num) {
        if (sqrtRoot * sqrtRoot == num) {
            return true; // Found a perfect square
        }
        sqrtRoot++;
    }

    return false; // No perfect square found
}

// Main function for testing
int main() {
    // Test Cases
    int input1 = 16;
    bool result1 = isPerfectSquare(input1);
    printf("Test Case 1: Is Perfect Square? %s\n", result1 ? "true" : "false");

    int input2 = 25;
    bool result2 = isPerfectSquare(input2);
    printf("Test Case 2: Is Perfect Square? %s\n", result2 ? "true" : "false");

    int input3 = 14;
    bool result3 = isPerfectSquare(input3);
    printf("Test Case 3: Is Perfect Square? %s\n", result3 ? "true" : "false");

    int input4 = 0;
    bool result4 = isPerfectSquare(input4);
    printf("Test Case 4: Is Perfect Square? %s\n", result4 ? "true" : "false");

    int input5 = 100;
    bool result5 = isPerfectSquare(input5);
    printf("Test Case 5: Is Perfect Square? %s\n", result5 ? "true" : "false");

    return 0;
}

//Sample Output:
// Test Case 1: Is Perfect Square? true
//Test Case 2: Is Perfect Square? true
//Test Case 3: Is Perfect Square? false
//Test Case 4: Is Perfect Square? true
//Test Case 5: Is Perfect Square? true


//******************************************************---****************************************************************

//  5. Problem Description: Check if a String Starts with a Specific Prefix
//
//You are tasked with creating a C program to check if a given string starts with a specific prefix.
// The program should efficiently determine and return true if the string begins with the specified prefix, and false otherwise.//

//Input:
//    str: A string.
//    prefix: The prefix to check.

//Output:
//    Returns true if the string starts with the specified prefix, and false otherwise.

// Example 1
//boolean result1 = startsWithPrefix("Hello, World!", "Hello");
// Output: true ("Hello, World!" starts with the prefix "Hello")

// Example 2
//boolean result2 = startsWithPrefix("Java Programming", "Python");
// Output: false ("Java Programming" does not start with the prefix "Python")

// Example 3
//boolean result3 = startsWithPrefix("12345", "12");
// Output: true ("12345" starts with the prefix "12")

//Notes:
//    The solution should efficiently check whether the given string starts with the specified prefix.
//    The function should handle cases where the string or prefix may be empty.
//    The program should run without errors for valid input strings and prefixes.

#include <stdio.h>
#include <stdbool.h> // for bool data type

// Function to check if a string starts with a prefix
bool startsWithPrefix(const char *str, const char *prefix) {
    if (str == NULL || prefix == NULL) {
        printf("Input strings cannot be null.\n");
        return false;
    }

    int i = 0;

    while (prefix[i] != '\0') {
        if (str[i] != prefix[i]) {
            return false; // Mismatch at current position
        }
        i++;
    }

    return true; // Prefix matches the start of the string
}

// Main function for testing
int main() {
    // Test Cases
    bool result1 = startsWithPrefix("Hello, World!", "Hello");
    printf("Test Case 1: Starts with Prefix? %s\n", result1 ? "true" : "false");

    bool result2 = startsWithPrefix("Java Programming", "Python");
    printf("Test Case 2: Starts with Prefix? %s\n", result2 ? "true" : "false");

    bool result3 = startsWithPrefix("12345", "12");
    printf("Test Case 3: Starts with Prefix? %s\n", result3 ? "true" : "false");

    bool result4 = startsWithPrefix("Java", "Java");
    printf("Test Case 4: Starts with Prefix? %s\n", result4 ? "true" : "false");

    bool result5 = startsWithPrefix("", "Prefix");
    printf("Test Case 5: Starts with Prefix? %s\n", result5 ? "true" : "false");

    return 0;
}

//Sample Output:
// Test Case 1: Starts with Prefix? true
//Test Case 2: Starts with Prefix? false
//Test Case 3: Starts with Prefix? true
//Test Case 4: Starts with Prefix? true
//Test Case 5: Starts with Prefix? false

//******************************************************---****************************************************************

//  6. Problem Description: Sum of Prime Numbers up to a Given Limit
//
//You are tasked with creating a C program to find the sum of prime numbers up to a given limit.
// The program should efficiently determine and return the sum of all prime numbers within the specified range.

//public static int sumOfPrimes(int limit)
//
//Input:
//    limit: An integer representing the upper limit of the range.

//Output:
//    Returns the sum of prime numbers up to the given limit.

// Example
//int result = sumOfPrimes(10);
// Output: 17 (2 + 3 + 5 + 7 are prime numbers up to the limit 10)

//Notes:
//    The solution should efficiently find and return the sum of prime numbers up to the specified limit.
//    The function should handle non-negative integer inputs.
//    The program should run without errors for valid input limits.

#include <stdio.h>
#include <stdbool.h> // for bool data type
#include <math.h>    // for sqrt function

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false; // Not a prime number
        }
    }

    return true; // Prime number
}

// Function to calculate the sum of prime numbers up to a given limit
int sumOfPrimes(int limit) {
    if (limit < 0) {
        printf("Limit should be a non-negative integer.\n");
        return 0;
    }

    int sum = 0;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    return sum;
}

// Main function for testing
int main() {
    // Test Cases
    int result1 = sumOfPrimes(10);
    printf("Test Case 1: Sum of Primes = %d\n", result1);

    int result2 = sumOfPrimes(20);
    printf("Test Case 2: Sum of Primes = %d\n", result2);

    int result3 = sumOfPrimes(5);
    printf("Test Case 3: Sum of Primes = %d\n", result3);

    int result4 = sumOfPrimes(0);
    printf("Test Case 4: Sum of Primes = %d\n", result4);

    int result5 = sumOfPrimes(30);
    printf("Test Case 5: Sum of Primes = %d\n", result5);

    return 0;
}



//Sample Output:
// Test Case 1: Sum of Primes = 17
//Test Case 2: Sum of Primes = 77
//Test Case 3: Sum of Primes = 10
//Test Case 4: Sum of Primes = 0
//Test Case 5: Sum of Primes = 129


//******************************************************---****************************************************************

//  7. Problem Description: Find the Kth Largest Element in an Array ***(skip this for C language)***

//You are tasked with creating a C program to find the Kth largest element in an array.
// The program should efficiently determine and return the Kth largest element from the given array.

//Input:
//    nums: An array of integers.
//    k: An integer representing the position of the Kth largest element (1 <= k <= length of the array).

//Output:
//    Returns the Kth largest element from the array.

// Example
//int[] arr = {3, 1, 5, 7, 2, 4, 6};
//int k = 3;
//int result = findKthLargest(arr, k);
// Output: 5 (The 3rd largest element in the array is 5)

//Notes:
//    The solution should efficiently find and return the Kth largest element from the array.
//    The function should handle valid positions for K within the range of the array length.
//    The program should run without errors for valid input arrays and positions.



//Sample Output:
// Test Case 1: Kth Largest Element = 5
//Test Case 2: Kth Largest Element = 50
//Test Case 3: Kth Largest Element = 7
//Test Case 4: Kth Largest Element = 5
//Test Case 5: Kth Largest Element = 1


//******************************************************---****************************************************************

//  8. Problem Description: Single Number

//You are tasked with creating a C program to find the single number in an array where every element appears twice except for one.
// Your solution must have linear runtime complexity and use only constant extra space.

//Input:
//    nums: A non-empty array of integers where every element appears twice except for one.

//Output:
//    Returns the single number that appears only once in the array.

// Example
//int[] arr = {4, 2, 7, 2, 4};
//int result = findSingleNumber(arr);
// Output: 7 (7 is the only element that appears once in the array)

//Notes:
//    The solution should have linear runtime complexity O(n) and use only constant extra space O(1).
//    The array will always contain an odd number of elements.
//    The program should run without errors for valid input arrays.

#include <stdio.h>

int findSingleNumber(int nums[], int size) {
    if (nums == NULL || size % 2 == 0) {
        printf("Invalid input array.\n");
        return -1; // Return a flag value to indicate error
    }

    int result = 0;

    for (int i = 0; i < size; i++) {
        result ^= nums[i]; // Using XOR operation to find the single number
    }

    return result;
}

int main() {
    // Test Case 1
    int arr1[] = {4, 2, 7, 2, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = findSingleNumber(arr1, size1);
    printf("Test Case 1: Single Number = %d\n", result1);

    // Test Case 2
    int arr2[] = {1, 2, 3, 1, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = findSingleNumber(arr2, size2);
    printf("Test Case 2: Single Number = %d\n", result2);

    // Test Case 3
    int arr3[] = {5, 6, 6};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int result3 = findSingleNumber(arr3, size3);
    printf("Test Case 3: Single Number = %d\n", result3);

    return 0;
}


//Sample Output:
// Test Case 1: Single Number = 7
//Test Case 2: Single Number = 2
//Test Case 3: Single Number = 5

//******************************************************---****************************************************************

//  9. Problem Description: Missing Number

//You are tasked with creating a C program to find the missing number in an array.
// Given an array nums containing n distinct numbers in the range [0, n],
// the program should efficiently determine and return the only number in the range that is missing from the array.

//Input:
//    nums: An array of distinct integers in the range [0, n], where n is the length of the array.

//Output:
//    Returns the missing number from the array.

// Example
//int[] arr = {3, 0, 1};
//int result = findMissingNumber(arr);
// Output: 2 (The missing number in the array is 2)

//Notes:
//    The solution should efficiently find and return the missing number in the array.
//    The array will always contain n distinct numbers in the range [0, n], where n is the length of the array.
//    The program should run without errors for valid input arrays.

#include <stdio.h>

int findMissingNumber(int nums[], int size) {
    if (nums == NULL || size == 0) {
        printf("Invalid input array.\n");
        return -1; // Return a flag value to indicate error
    }

    int n = size;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}

int main() {
    // Test Case 1
    int arr1[] = {3, 0, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = findMissingNumber(arr1, size1);
    printf("Test Case 1: Missing Number = %d\n", result1);

    // Test Case 2
    int arr2[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = findMissingNumber(arr2, size2);
    printf("Test Case 2: Missing Number = %d\n", result2);

    // Test Case 3
    int arr3[] = {1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int result3 = findMissingNumber(arr3, size3);
    printf("Test Case 3: Missing Number = %d\n", result3);

    return 0;
}

//Sample Output:
// Test Case 1: Missing Number = 2
//Test Case 2: Missing Number = 8
//Test Case 3: Missing Number = 0


//******************************************************---****************************************************************

//  10.


//******************************************************---****************************************************************

//  11.


//******************************************************---****************************************************************

//  12.


//******************************************************---****************************************************************

//  13.

