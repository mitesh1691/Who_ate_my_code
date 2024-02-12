//******************************************************---****************************************************************

//  1. Problem Description: Check if Two Strings are Anagrams

//You are tasked with creating a C program to determine whether two strings are anagrams of each other.
// Two strings are considered anagrams if they have the same characters with the same frequencies, ignoring spaces and case.
// The program should efficiently check if the given strings are anagrams and return the result.

// Input:
//    str1: The first string.
//    str2: The second string.

//Output:
//    Returns true if the strings are anagrams, and false otherwise.

//Example:
// Example 1
//String s1 = "listen";
//        String s2 = "silent";
//        boolean result1 = areAnagrams(s1, s2);
// Output: true

// Example 2
//        String s3 = "Java";
//        String s4 = "jAvA";
//        boolean result2 = areAnagrams(s3, s4);
// Output: true

// Example 3
//        String s5 = "Hello";
//        String s6 = "World";
//        boolean result3 = areAnagrams(s5, s6);
// Output: false

//Notes:
//        Solution Should be of O(n) time complexity
//        The function should consider spaces and be case-insensitive.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function to check if two strings are anagrams
bool areAnagrams(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL || strlen(str1) != strlen(str2)) {
        return false;
    }

    int charCount[26] = {0}; // Assuming only lowercase alphabets

    // Count the frequency of characters in str1
    for (int i = 0; str1[i] != '\0'; i++) {
        char c = tolower(str1[i]);
        if (isalpha(c)) {
            charCount[c - 'a']++;
        }
    }

    // Decrement the frequency of characters in str2
    for (int i = 0; str2[i] != '\0'; i++) {
        char c = tolower(str2[i]);
        if (isalpha(c)) {
            charCount[c - 'a']--;
        }
    }

    // Check if all character frequencies are zero
    for (int i = 0; i < 26; i++) {
        if (charCount[i] != 0) {
            return false;
        }
    }

    return true;
}

// Main function for testing
int main() {
    // Test Cases
    const char *s1 = "listen";
    const char *s2 = "silent";
    printf("Test Case 1: Are Anagrams? %s\n", areAnagrams(s1, s2) ? "true" : "false");

    const char *s3 = "Java";
    const char *s4 = "jAvA";
    printf("Test Case 2: Are Anagrams? %s\n", areAnagrams(s3, s4) ? "true" : "false");

    const char *s5 = "Hello";
    const char *s6 = "World";
    printf("Test Case 3: Are Anagrams? %s\n", areAnagrams(s5, s6) ? "true" : "false");

    const char *s7 = "Astronomer";
    const char *s8 = "Moon starer";
    printf("Test Case 4: Are Anagrams? %s\n", areAnagrams(s7, s8) ? "true" : "false");

    const char *s9 = "AABB";
    const char *s10 = "ABAB";
    printf("Test Case 5: Are Anagrams? %s\n", areAnagrams(s9, s10) ? "true" : "false");

    const char *s11 = "A gentleman";
    const char *s12 = "Elegant man";
    printf("Test Case 6: Are Anagrams? %s\n", areAnagrams(s11, s12) ? "true" : "false");

    const char *s13 = "Debit card";
    const char *s14 = "Bad credit";
    printf("Test Case 7: Are Anagrams? %s\n", areAnagrams(s13, s14) ? "true" : "false");

    const char *s15 = "School master";
    const char *s16 = "The classroom";
    printf("Test Case 8: Are Anagrams? %s\n", areAnagrams(s15, s16) ? "true" : "false");

    const char *s17 = "Dormitory";
    const char *s18 = "Dirty room";
    printf("Test Case 9: Are Anagrams? %s\n", areAnagrams(s17, s18) ? "true" : "false");

    return 0;
}

// sample output
// Test Case 1: Are Anagrams? true
//Test Case 2: Are Anagrams? true
//Test Case 3: Are Anagrams? false
//Test Case 4: Are Anagrams? false
//Test Case 5: Are Anagrams? true
//Test Case 6: Are Anagrams? true
//Test Case 7: Are Anagrams? true
//Test Case 8: Are Anagrams? true
//Test Case 9: Are Anagrams? false



//******************************************************---****************************************************************

//  2. Problem Description: Binary Search
//
//You are tasked with creating a C program to implement the binary search algorithm.
// Binary search is an efficient search algorithm that finds the position of a target value within a sorted array.
// The program should efficiently perform binary search and return the index of the target element if found, or -1 if the element is not present in the array.


// Input:
//    sortedArray: A sorted array of integers in ascending order.
//    target: The value to be searched in the array.

//Output:
//    Returns the index of the target element if found; otherwise, returns -1.

// Example:
// Example 1
//int[] arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//int target1 = 6;
//int result1 = binarySearch(arr1, target1);
// Output: 5

// Example 2
//int[] arr2 = {2, 4, 6, 8, 10, 12, 14};
//int target2 = 5;
//int result2 = binarySearch(arr2, target2);
// Output: -1

// Example 3
//int[] arr3 = {1, 3, 5, 7, 9, 11, 13};
//int target3 = 1;
//int result3 = binarySearch(arr3, target3);
// Output: 0

//Notes:
//        The function should return the correct index or -1 based on the binary search.


#include <stdio.h>

// Function to perform binary search
int binarySearch(int sortedArray[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArray[mid] == target) {
            return mid; // Target found, return the index
        } else if (sortedArray[mid] < target) {
            left = mid + 1; // Adjust search range to the right half
        } else {
            right = mid - 1; // Adjust search range to the left half
        }
    }

    return -1; // Target not found
}

int main() {
    // Test Cases
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target1 = 6;
    printf("Test Case 1: Index of %d = %d\n", target1, binarySearch(arr1, sizeof(arr1) / sizeof(arr1[0]), target1));

    int arr2[] = {2, 4, 6, 8, 10, 12, 14};
    int target2 = 5;
    printf("Test Case 2: Index of %d = %d\n", target2, binarySearch(arr2, sizeof(arr2) / sizeof(arr2[0]), target2));

    int arr3[] = {1, 3, 5, 7, 9, 11, 13};
    int target3 = 1;
    printf("Test Case 3: Index of %d = %d\n", target3, binarySearch(arr3, sizeof(arr3) / sizeof(arr3[0]), target3));

    int arr4[] = {3, 6, 9, 12, 15, 18};
    int target4 = 15;
    printf("Test Case 4: Index of %d = %d\n", target4, binarySearch(arr4, sizeof(arr4) / sizeof(arr4[0]), target4));

    int arr5[] = {5, 10, 15, 20, 25};
    int target5 = 8;
    printf("Test Case 5: Index of %d = %d\n", target5, binarySearch(arr5, sizeof(arr5) / sizeof(arr5[0]), target5));

    return 0;
}


// sample output:
// Test Case 1: Index of 6 = 5
//Test Case 2: Index of 5 = -1
//Test Case 3: Index of 1 = 0
//Test Case 4: Index of 15 = 4
//Test Case 5: Index of 8 = -1



//******************************************************---****************************************************************

//  3. Problem Description: Find the nth Fibonacci Number without Recursion

//You are tasked with creating a C program to find the nth Fibonacci number without using recursion.
// The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1.
// The program should efficiently calculate and return the nth Fibonacci number.

//    Input:
//        n: An integer representing the position in the Fibonacci sequence (n >= 0).
//
//     Output:
//        Returns the nth Fibonacci number.

// Example:
// Example 1
//int result1 = findNthFibonacci(5);
// Output: 5 (Fibonacci sequence: 0, 1, 1, 2, 3, 5)

// Example 2
//        int result2 = findNthFibonacci(8);
// Output: 21 (Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21)

// Example 3
//        int result3 = findNthFibonacci(10);
// Output: 34 (Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34)

// Notes:
//    The function should use an iterative approach without recursion.

#include <stdio.h>

// Function to find the nth Fibonacci number
int findNthFibonacci(int n) {
    if (n < 0) {
        printf("Input should be a non-negative integer.\n");
        return -1; // Return -1 to indicate error
    }

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    int prev = 0;
    int current = 1;

    for (int i = 2; i <= n; i++) {
        int next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

int main() {
    // Test Cases
    // Test Case 1
    int result1 = findNthFibonacci(5);
    printf("Test Case 1: Nth Fibonacci Number = %d\n", result1);

    // Test Case 2
    int result2 = findNthFibonacci(8);
    printf("Test Case 2: Nth Fibonacci Number = %d\n", result2);

    // Test Case 3
    int result3 = findNthFibonacci(10);
    printf("Test Case 3: Nth Fibonacci Number = %d\n", result3);

    // Test Case 4
    int result4 = findNthFibonacci(0);
    printf("Test Case 4: Nth Fibonacci Number = %d\n", result4);

    // Test Case 5
    int result5 = findNthFibonacci(2);
    printf("Test Case 5: Nth Fibonacci Number = %d\n", result5);

    return 0;
}


// sample output:
// Test Case 1: Nth Fibonacci Number = 5
//Test Case 2: Nth Fibonacci Number = 21
//Test Case 3: Nth Fibonacci Number = 55
//Test Case 4: Nth Fibonacci Number = 0
//Test Case 5: Nth Fibonacci Number = 1

//******************************************************---****************************************************************

//  4. Problem Description: Find the Next Prime Number

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

    for (int i = 2; i*i <= num; i++) {
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

//  5. Problem Description: Find Majority Element in an Array

//You are tasked with creating a C program to find the majority element in an array.
// The majority element is defined as the element that appears more than n/2 times in the array, where n is the size of the array.
// The program should efficiently identify and return the majority element if it exists; otherwise, it should return -1.

//Input:
//    nums: An array of integers.

//Output:
//    Returns the majority element if it exists; otherwise, returns -1.

//Example:
// Example 1
//int[] arr1 = {2, 2, 1, 1, 1, 2, 2};
//int result1 = findMajorityElement(arr1);
// Output: 2 (Majority element in the array is 2)

// Example 2
//int[] arr2 = {3, 3, 4, 2, 4, 4, 2, 4, 4};
//int result2 = findMajorityElement(arr2);
// Output: 4 (Majority element in the array is 4)

// Example 3
//int[] arr3 = {1, 2, 3, 4, 5};
//int result3 = findMajorityElement(arr3);
// Output: -1 (No majority element in the array)

#include <stdio.h>

// Function to find the majority element
int findMajorityElement(int nums[], int n) {
    if (n == 0) {
        return -1; // No majority element in an empty array
    }

    int elementCount[1001] = {0}; // Assuming elements in the range [0, 1000]

    for (int i = 0; i < n; i++) {
        elementCount[nums[i]]++;
    }

    for (int i = 0; i < 1001; i++) {
        if (elementCount[i] > n / 2) {
            return i; // Found majority element
        }
    }

    return -1; // No majority element found
}

int main() {
    // Test Cases
    // Test Case 1
    int arr1[] = {2, 2, 1, 1, 1, 2, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = findMajorityElement(arr1, n1);
    printf("Test Case 1: Majority Element = %d\n", result1);

    // Test Case 2
    int arr2[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = findMajorityElement(arr2, n2);
    printf("Test Case 2: Majority Element = %d\n", result2);

    // Test Case 3
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int result3 = findMajorityElement(arr3, n3);
    printf("Test Case 3: Majority Element = %d\n", result3);

    // Test Case 4
    int arr4[] = {1, 1, 1, 2, 2};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int result4 = findMajorityElement(arr4, n4);
    printf("Test Case 4: Majority Element = %d\n", result4);

    // Test Case 5
    int arr5[] = {5};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int result5 = findMajorityElement(arr5, n5);
    printf("Test Case 5: Majority Element = %d\n", result5);

    return 0;
}


// sample output:
//Test Case 1: Majority Element = 2
//        Test Case 2: Majority Element = 4
//        Test Case 3: Majority Element = -1
//        Test Case 4: Majority Element = 1
//        Test Case 5: Majority Element = 5


//******************************************************---****************************************************************

//  6. Problem Description: Calculate Character Frequency in a String

//You are tasked with creating a C program to calculate the frequency of each character in a given string.
// The program should use an array of size 26 to store the frequency of each lowercase alphabet character (a to z) in the string.
// The output should display the frequency of each character.

//        Input:
//        input: A string containing lowercase alphabet characters.
//
//        Output:
//        Prints the frequency of each character in the format: "Character: Frequency".

// Example
//        String input = "abracadabra";
//        calculateCharFrequency(input);
// Output:
// a: 5
// b: 2
// c: 1
// d: 1
// r: 2

//        Notes:
//        The solution should efficiently calculate the frequency of characters in the given string.
//        The function should print the frequency for each lowercase alphabet character in the specified format.

#include <stdio.h>
#include <string.h>

void calculateCharFrequency(const char *input) {
    if (input == NULL || input[0] == '\0') {
        printf("Input string is empty.\n");
        return;
    }

    int charFrequency[26] = {0};

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            charFrequency[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (charFrequency[i] > 0) {
            char currentChar = 'a' + i;
            printf("%c: %d\n", currentChar, charFrequency[i]);
        }
    }
}

int main() {
    // Test Cases
    // Test Case 1
    const char *input1 = "abracadabra";
    printf("Test Case 1:\n");
    calculateCharFrequency(input1);

    // Test Case 2
    const char *input2 = "hello";
    printf("\nTest Case 2:\n");
    calculateCharFrequency(input2);

    // Test Case 3
    const char *input3 = "programming";
    printf("\nTest Case 3:\n");
    calculateCharFrequency(input3);

    // Test Case 4
    const char *input4 = "java";
    printf("\nTest Case 4:\n");
    calculateCharFrequency(input4);

    // Test Case 5
    const char *input5 = "";
    printf("\nTest Case 5:\n");
    calculateCharFrequency(input5);

    return 0;
}

// sample output:
//Test Case 1:
//        a: 5
//        b: 2
//        c: 1
//        d: 1
//        r: 2
//
//        Test Case 2:
//        e: 1
//        h: 1
//        l: 2
//        o: 1
//
//        Test Case 3:
//        a: 1
//        g: 2
//        i: 1
//        m: 2
//        n: 1
//        o: 1
//        p: 1
//        r: 2
//
//        Test Case 4:
//        a: 2
//        j: 1
//        v: 1
//
//        Test Case 5:
//        Input string is empty.
//
//        Process finished with exit code 0


//******************************************************---****************************************************************

//  7. Problem Description: Find the Sum of Two Largest Elements in an Array

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

//  8. Problem Description: Square of the Sum of Digits

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

//  9. Problem Description: Check if a Number is a Perfect Square

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

//  10. Problem Description: Difference Between Sum of Even and Odd-Indexed Elements
//
//You are tasked with creating a C program to find the difference between the sum of even-indexed elements and odd-indexed elements in an array.
// The program should efficiently calculate and return the absolute difference between the sums of elements at even and odd indices in the array.
//Input:
//    nums: An array of integers.

//Output:
//    Returns the absolute difference between the sum of even-indexed elements and odd-indexed elements in the array.

// Example 1
//int[] arr1 = {1, 2, 3, 4, 5};
//int result1 = differenceBetweenSums(arr1);
// Output: 3 (Sum of even-indexed elements: 1 + 3 + 5 = 9, Sum of odd-indexed elements: 2 + 4 = 6, Difference = |9 - 6| = 3)

// Example 2
//int[] arr2 = {10, 20, 30, 40, 50, 60};
//int result2 = differenceBetweenSums(arr2);
// Output: 60 (Sum of even-indexed elements: 10 + 30 + 50 = 90, Sum of odd-indexed elements: 20 + 40 + 60 = 120, Difference = |90 - 120| = 30)

//Notes:
//    The solution should efficiently find and calculate the difference between the sum of even-indexed elements and odd-indexed elements in the array.
//    The function should consider arrays of varying sizes and handle cases where the array may not have both even and odd indices.
//    The program should run without errors for valid input arrays.

#include <stdio.h>
#include <stdlib.h> // for abs function

int differenceBetweenSums(int nums[], int length) {
    if (nums == NULL || length < 2) {
        printf("Array should contain at least two elements.\n");
        return -1;
    }

    int sumEven = 0;
    int sumOdd = 0;

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            sumEven += nums[i];
        } else {
            sumOdd += nums[i];
        }
    }

    return abs(sumEven - sumOdd); // Return the absolute difference
}

int main() {
    // Test Cases
    // Test Case 1
    int arr1[] = {1, 2, 3, 4, 5};
    int result1 = differenceBetweenSums(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("Test Case 1: Difference Between Sums = %d\n", result1);

    // Test Case 2
    int arr2[] = {10, 20, 30, 40, 50, 60};
    int result2 = differenceBetweenSums(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("Test Case 2: Difference Between Sums = %d\n", result2);

    // Test Case 3
    int arr3[] = {5};
    printf("Test Case 3: ");
    differenceBetweenSums(arr3, sizeof(arr3) / sizeof(arr3[0])); // This will continue without exiting
    printf("\n");

    // Test Case 4
    int arr4[] = {2, 4};
    int result4 = differenceBetweenSums(arr4, sizeof(arr4) / sizeof(arr4[0]));
    printf("Test Case 4: Difference Between Sums = %d\n", result4);

    // Test Case 5
    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result5 = differenceBetweenSums(arr5, sizeof(arr5) / sizeof(arr5[0]));
    printf("Test Case 5: Difference Between Sums = %d\n", result5);

    return 0;
}


// sample output:
// Test Case 1: Difference Between Sums = 3
//Test Case 2: Difference Between Sums = 30
//Test Case 3: Array should contain at least two elements.
//Test Case 4: Difference Between Sums = 2
//Test Case 5: Difference Between Sums = 5

//******************************************************---****************************************************************
// 11. Skipped for C


//******************************************************---****************************************************************
// 12.  Count Unique Characters in a String

//You are tasked with writing a C program to count the number of unique characters in a given string.
// The uniqueness of characters should be case insensitive, meaning uppercase and lowercase characters should be treated as the same.
//Input:
//    str: A string containing characters.

//Output:
//    Returns an integer representing the count of unique characters in the input string str.

// Example 1
//Input: "Hello"
//Output: 3  // 'H', 'e', 'o'

//Example 2
//Input: "Mississippi"
//Output: 1  // 'M'

//Example 3
//Input: "JavaProgramming"
//Output: 6  // 'J', 'v', 'P', 'o', 'g', 'i'

//Notes:
//    The input string may contain alphanumeric characters and special symbols.
//    The program should consider characters case-insensitively. For example, 'a' and 'A' should be considered the same character.
//    The program should efficiently determine the count of unique characters in the string.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of unique characters in a string
int countUniqueCharacters(char str[]) {
    // Array to store frequency of characters, considering case insensitivity
    int frequency[26] = {0}; // Considering only alphabets (case-insensitive)
    int len = strlen(str);

    // Convert the string to lowercase
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // Iterate through the string and update frequency array
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (isalpha(ch)) {
            frequency[ch - 'a']++;
        }
    }

    // Count unique characters
    int uniqueCount = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] == 1) {
            uniqueCount++;
        }
    }

    return uniqueCount;
}

// Main function for testing
int main() {
    // Test Cases
    char str1[] = "Hello";
    printf("Test Case 1:\n");
    printf("Input: %s\n", str1);
    printf("Output: %d\n", countUniqueCharacters(str1));

    char str2[] = "Mississippi";
    printf("\nTest Case 2:\n");
    printf("Input: %s\n", str2);
    printf("Output: %d\n", countUniqueCharacters(str2));

    char str3[] = "JavaProgramming";
    printf("\nTest Case 3:\n");
    printf("Input: %s\n", str3);
    printf("Output: %d\n", countUniqueCharacters(str3));

    return 0;
}


// sample output:
// Test Case 1:
//Input: Hello
//Output: 3

//Test Case 2:
//Input: Mississippi
//Output: 1

//Test Case 3:
//Input: JavaProgramming
//Output: 6



//******************************************************---****************************************************************
// 13. Peak Element in Array

//You are given an array of integers.
// A peak element in the array is an element that is strictly greater than its neighbors.
// It is the largest element in the array, satisfying the given condition. Additionally, it's important to note that there are no duplicates in the array.

//Input:
//    nums: An array of integers.

//Output:
//    Returns the peak element in the array.

//// Example 1
//Input: nums = [5, 10, 20, 15]
//Output: 20
//Explanation: The element 20 is strictly greater than its neighbors 10 and 15.

//// Example 2
//Input: nums = [1, 3, 6, 7, 4, 2]
//Output: 7
//Explanation: The element 7 is strictly greater than its neighbors 6 and 4.

//// Example 3
//Input: nums = [10, 20, 30, 40]
//Output: 40
//Explanation: The element 40 is strictly greater than its neighbor 30.

//// Example 4
//Input: nums = [5, 10, 15, 20, 25]
//Output: 25
//Explanation: The element 25 is strictly greater than its neighbor 20.

//Notes:
//    The array will contain at least one element.
//    There will be exactly one peak element in the array.
//    The peak element is guaranteed to be greater than its adjacent elements.
//    Use linear search approach to find the peak element efficiently.

#include <stdio.h>

// Function to find the peak element in an array
int findPeakElement(int nums[], int n) {
    // Edge cases
    if (n == 1) {
        return nums[0];
    }

    // Check first element
    if (nums[0] > nums[1]) {
        return nums[0];
    }

    // Check last element
    if (nums[n - 1] > nums[n - 2]) {
        return nums[n - 1];
    }

    // Check middle elements
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            return nums[i];
        }
    }

    return -1; // Peak element not found
}

// Main function for testing
int main() {
    // Test Cases
    int nums1[] = {5, 10, 20, 15};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1: %d\n", findPeakElement(nums1, n1)); // Output: 20

    int nums2[] = {1, 3, 6, 7, 4, 2};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test Case 2: %d\n", findPeakElement(nums2, n2)); // Output: 7

    int nums3[] = {10, 20, 30, 40};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test Case 3: %d\n", findPeakElement(nums3, n3)); // Output: 40

    int nums4[] = {5, 10, 15, 20, 25};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test Case 4: %d\n", findPeakElement(nums4, n4)); // Output: 25

    int nums5[] = {1};
    int n5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test Case 5: %d\n", findPeakElement(nums5, n5)); // Output: 1

    int nums6[] = {10, 9, 8, 7};
    int n6 = sizeof(nums6) / sizeof(nums6[0]);
    printf("Test Case 6: %d\n", findPeakElement(nums6, n6)); // Output: 10

    int nums7[] = {10, 11, 13, 16, 20, 8, 5, 4};
    int n7 = sizeof(nums7) / sizeof(nums7[0]);
    printf("Test Case 7: %d\n", findPeakElement(nums7, n7)); // Output: 20

    int nums8[] = {20, 40, 50, 70, 90, 60, 30, 10};
    int n8 = sizeof(nums8) / sizeof(nums8[0]);
    printf("Test Case 8: %d\n", findPeakElement(nums8, n8)); // Output: 90

    return 0;
}


// sample output:
// Test Case 1: 20
// Test Case 2: 7
//Test Case 3: 40
//Test Case 4: 25
//Test Case 5: 1
//Test Case 6: 10
//Test Case 7: 20
//Test Case 8: 90

//******************************************************---****************************************************************
// 14. Leap Year Checker
//
//You are tasked with creating a C program to determine whether a given year is a leap year or not.
// A leap year is a year that is evenly divisible by 4, except for years that are evenly divisible by 100.
// However, years that are evenly divisible by 400 are leap years.

//Input:
//    year: An integer representing the year to be checked.

//Output:
//    Returns true if the input year is a leap year, and false otherwise.

// Example 1
//Input: year = 2020
//Output: true
//Explanation: 2020 is divisible by 4 and not divisible by 100, so it's a leap year.

// Example 2
//Input: year = 1900
//Output: false
//Explanation: Although 1900 is divisible by 4, it is also divisible by 100.
//Since it's not divisible by 400, it's not a leap year.

// Example 3
//Input: year = 2000
//Output: true
//Explanation: 2000 is divisible by 4, divisible by 100, and divisible by 400,
//making it a leap year.

// Example 4
//Input: year = 2021
//Output: false
//Explanation: 2021 is not divisible by 4, so it's not a leap year.

//Notes:
//    The input year is a positive integer.
//    Implement the logic to check whether the given year is a leap year or not.
//    The program should return true if the year is a leap year, and false otherwise.

#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year condition satisfied
    } else {
        return 0; // Not a leap year
    }
}

// Main function for testing
int main() {
    // Test Cases
    int years[] = {2020, 1900, 2000, 2021, 2022, 3036, 3033, 1986, 1956, 1600};
    int num_years = sizeof(years) / sizeof(years[0]);
    for (int i = 0; i < num_years; i++) {
        printf("Is %d a leap year? %s\n", years[i], isLeapYear(years[i]) ? "true" : "false");
    }

    return 0;
}

// sample output:
// Is 2020 a leap year? true
//Is 1900 a leap year? false
//Is 2000 a leap year? true
//Is 2021 a leap year? false
//Is 2022 a leap year? false
//Is 3036 a leap year? true
//Is 3033 a leap year? false
//Is 1986 a leap year? false
//Is 1956 a leap year? true
//Is 1600 a leap year? true

//******************************************************---****************************************************************
// 15. Problem Description: Check if a String Starts with a Specific Prefix
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
// 16. Pairs with Sum

//You are tasked with creating a C program to find all pairs of elements in an array whose sum is equal to a given target number.

//Input:
//    nums: An array of integers representing the input array.
//    target: An integer representing the target sum.
//
//Output:
//    Prints all pairs of elements in the array nums whose sum equals the target.

//// Example 1
//Input: nums = {1, 2, 3, 4, 5}, target = 5
//Output: (1, 4), (2, 3)
//Explanation: In the input array, the pairs (1, 4) and (2, 3) have a sum equal to the target 5.

//// Example 2
//Input: nums = {3, 8, 5, 2, 9}, target = 10
//Output: (3, 7), (8, 2)
//Explanation: In the input array, the pairs (3, 7) and (8, 2) have a sum equal to the target 10.

//Notes:
//    Each pair should be printed only once, and the order of elements within the pair does not matter.
//    If there are no such pairs in the array whose sum equals the target, print "No pairs found."

 #include <stdio.h>

// Function to find pairs with a given sum in an array
void findPairs(int nums[], int length, int target) {
    int foundPair = 0; // Boolean variable to track if pairs are found

    // Brute-force approach: Check all pairs of elements in the array
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (nums[i] + nums[j] == target) {
                printf("(%d, %d)\n", nums[i], nums[j]);
                foundPair = 1; // Update foundPair to true
            }
        }
    }

    if (!foundPair) {
        printf("No pairs found.\n");
    }
}

// Main function for testing
int main() {
    // Test Cases
    int nums1[] = {1, 2, 3, 4, 5};
    int target1 = 5;
    printf("Pairs with sum %d in nums1:\n", target1);
    findPairs(nums1, sizeof(nums1) / sizeof(nums1[0]), target1);

    int nums2[] = {3, 8, 5, 2, 9};
    int target2 = 10;
    printf("\nPairs with sum %d in nums2:\n", target2);
    findPairs(nums2, sizeof(nums2) / sizeof(nums2[0]), target2);

    int nums3[] = {1, 2, 3, 4, 5};
    int target3 = 20;
    printf("\nPairs with sum %d in nums3:\n", target3);
    findPairs(nums3, sizeof(nums3) / sizeof(nums3[0]), target3);

    int nums4[] = {5, 4, 6, 5};
    int target4 = 10;
    printf("\nPairs with sum %d in nums4:\n", target4);
    findPairs(nums4, sizeof(nums4) / sizeof(nums4[0]), target4);

    int nums5[] = {1, 2, 3, 4, 5};
    int target5 = 8;
    printf("\nPairs with sum %d in nums5:\n", target5);
    findPairs(nums5, sizeof(nums5) / sizeof(nums5[0]), target5);

    return 0;
}


// sample output:
// Pairs with sum 5 in nums1:
//(1, 4)
//(2, 3)

//Pairs with sum 10 in nums2:
//(8, 2)

//Pairs with sum 20 in nums3:
//No pairs found.

//Pairs with sum 10 in nums4:
//(5, 5)
//(4, 6)

//Pairs with sum 8 in nums5:
//(3, 5)


//******************************************************---****************************************************************
// 17. Swap numbers

//In this problem, you are given two integer variables a and b.
// The task is to swap the values of these variables without using an additional third variable.
//        This means that after the swapping operation, the value of a should be replaced with the original value of b, and vice versa, without using any extra storage.
//
//        The goal is to implement a method swap that performs this swapping operation efficiently,
//        ensuring that the original values of a and b are modified accordingly.
//
//        Test cases are provided to validate the correctness of the swapping operation,
//        covering different scenarios such as positive and negative integers, as well as zero.
//        The method should be able to handle these cases and produce the correct swapped values for a and b.

 #include <stdio.h>

// Function to swap two numbers without using a third variable
void swap(int *a, int *b) {
    printf("Before swapping:\n");
    printf("a = %d\n", *a);
    printf("b = %d\n", *b);

    // Swapping without using a third variable
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

    printf("After swapping:\n");
    printf("a = %d\n", *a);
    printf("b = %d\n", *b);
}

// Main function for testing
int main() {
    // Test Cases
    int num1 = 5, num2 = 10;
    printf("Swapping num1 and num2:\n");
    swap(&num1, &num2);

    int num3 = 3, num4 = 7;
    printf("\nSwapping num3 and num4:\n");
    swap(&num3, &num4);

    int num5 = 20, num6 = 50;
    printf("\nSwapping num5 and num6:\n");
    swap(&num5, &num6);

    int num7 = 1, num8 = 4;
    printf("\nSwapping num7 and num8:\n");
    swap(&num7, &num8);

    int num9 = 15, num10 = 25;
    printf("\nSwapping num9 and num10:\n");
    swap(&num9, &num10);

    return 0;
}


// sample output:
// Swapping num1 and num2:
//Before swapping:
//a = 5
//b = 10
//After swapping:
//a = 10
//b = 5
//
//Swapping num3 and num4:
//Before swapping:
//a = 3
//b = 7
//After swapping:
//a = 7
//b = 3
//
//Swapping num3 and num4:
//Before swapping:
//a = 20
//b = 50
//After swapping:
//a = 50
//b = 20
//
//Swapping num3 and num4:
//Before swapping:
//a = 1
//b = 4
//After swapping:
//a = 4
//b = 1
//
//Swapping num3 and num4:
//Before swapping:
//a = 15
//b = 25
//After swapping:
//a = 25
//b = 15



//******************************************************---****************************************************************
// 18. Finding Factors

//You are tasked with creating a C program to find all the factors (numbers that evenly divide) of a given input number.

//Input:
//    n: A positive integer representing the input number.

//Output:
//    Prints all the factors of the input number n.

//// Example 1
//Input: n = 12
//Output: Factors of 12: 1, 2, 3, 4, 6, 12
//Explanation: The factors of 12 are 1, 2, 3, 4, 6, and 12.

//// Example 2
//Input: n = 15
//Output: Factors of 15: 1, 3, 5, 15
//Explanation: The factors of 15 are 1, 3, 5, and 15.

//Notes:
//    Factors are the numbers that divide the given input number evenly without leaving a remainder.
//    The factors should be printed in ascending order.
//    Include the input number itself and 1 as factors.

#include <stdio.h>

// Function to find factors of a number
void findFactors(int n) {
    printf("Factors of %d: ", n);
    // Iterate from 1 to n and check if i divides n evenly
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d", i);
            // Print comma and space for separation except for the last factor
            if (i != n) {
                printf(", ");
            }
        }
    }
    printf("\n");
}

// Main function for testing
int main() {
    // Test Cases
    int num1 = 12;
    printf("Test Case 1:\n");
    findFactors(num1);

    int num2 = 15;
    printf("\nTest Case 2:\n");
    findFactors(num2);

    int num3 = 28;
    printf("\nTest Case 3:\n");
    findFactors(num3);

    return 0;
}


// sample output:
// Test Case 1:
//Factors of 12: 1, 2, 3, 4, 6, 12
//
//Test Case 2:
//Factors of 15: 1, 3, 5, 15
//
//Test Case 3:
//Factors of 28: 1, 2, 4, 7, 14, 28


//******************************************************---****************************************************************
// 19. Problem Description: Sum of Prime Numbers up to a Given Limit
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

    for (int i = 2; i*i <= num; i++) {
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

//  20. Skipped for C


//******************************************************---****************************************************************

//  21. Problem Description: Single Number

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

//  22. Problem Description: Missing Number

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

