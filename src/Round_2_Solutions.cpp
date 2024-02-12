//******************************************************---****************************************************************

//  1. Problem Description: Check if Two Strings are Anagrams

//You are tasked with creating a C++ program to determine whether two strings are anagrams of each other.
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

#include <iostream>
#include <string>
#include <algorithm>

// Function to check if two strings are anagrams
bool areAnagrams(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    // Convert strings to lowercase
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    // Frequency array for characters
    int charCount[26] = {0};

    // Count the frequency of characters in str1
    for (char c : str1) {
        if (std::isalpha(c)) {
            charCount[c - 'a']++;
        }
    }

    // Decrement the frequency of characters in str2
    for (char c : str2) {
        if (std::isalpha(c)) {
            charCount[c - 'a']--;
        }
    }

    // Check if all character frequencies are zero
    for (int count : charCount) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Test Cases
    std::string s1 = "listen";
    std::string s2 = "silent";
    std::cout << "Test Case 1: Are Anagrams? " << std::boolalpha << areAnagrams(s1, s2) << std::endl;

    std::string s3 = "Java";
    std::string s4 = "jAvA";
    std::cout << "Test Case 2: Are Anagrams? " << std::boolalpha << areAnagrams(s3, s4) << std::endl;

    std::string s5 = "Hello";
    std::string s6 = "World";
    std::cout << "Test Case 3: Are Anagrams? " << std::boolalpha << areAnagrams(s5, s6) << std::endl;

    std::string s7 = "Astronomer";
    std::string s8 = "Moon starer";
    std::cout << "Test Case 4: Are Anagrams? " << std::boolalpha << areAnagrams(s7, s8) << std::endl;

    std::string s9 = "AABB";
    std::string s10 = "ABAB";
    std::cout << "Test Case 5: Are Anagrams? " << std::boolalpha << areAnagrams(s9, s10) << std::endl;

    std::string s11 = "A gentleman";
    std::string s12 = "Elegant man";
    std::cout << "Test Case 6: Are Anagrams? " << std::boolalpha << areAnagrams(s11, s12) << std::endl;

    std::string s13 = "Debit card";
    std::string s14 = "Bad credit";
    std::cout << "Test Case 7: Are Anagrams? " << std::boolalpha << areAnagrams(s13, s14) << std::endl;

    std::string s15 = "School master";
    std::string s16 = "The classroom";
    std::cout << "Test Case 8: Are Anagrams? " << std::boolalpha << areAnagrams(s15, s16) << std::endl;

    std::string s17 = "Dormitory";
    std::string s18 = "Dirty room";
    std::cout << "Test Case 9: Are Anagrams? " << std::boolalpha << areAnagrams(s17, s18) << std::endl;

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
//You are tasked with creating a C++ program to implement the binary search algorithm.
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


#include <iostream>
#include <vector>

// Function to perform binary search on a sorted array
int binarySearch(std::vector<int>& sortedArray, int target) {
    int left = 0;
    int right = sortedArray.size() - 1;

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
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target1 = 6;
    std::cout << "Test Case 1: Index of " << target1 << " = " << binarySearch(arr1, target1) << std::endl;

    std::vector<int> arr2 = {2, 4, 6, 8, 10, 12, 14};
    int target2 = 5;
    std::cout << "Test Case 2: Index of " << target2 << " = " << binarySearch(arr2, target2) << std::endl;

    std::vector<int> arr3 = {1, 3, 5, 7, 9, 11, 13};
    int target3 = 1;
    std::cout << "Test Case 3: Index of " << target3 << " = " << binarySearch(arr3, target3) << std::endl;

    std::vector<int> arr4 = {3, 6, 9, 12, 15, 18};
    int target4 = 15;
    std::cout << "Test Case 4: Index of " << target4 << " = " << binarySearch(arr4, target4) << std::endl;

    std::vector<int> arr5 = {5, 10, 15, 20, 25};
    int target5 = 8;
    std::cout << "Test Case 5: Index of " << target5 << " = " << binarySearch(arr5, target5) << std::endl;

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

//You are tasked with creating a C++ program to find the nth Fibonacci number without using recursion.
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

#include <iostream>

// Function to find the nth Fibonacci number
int findNthFibonacci(int n) {
    if (n < 0) {
        throw std::invalid_argument("Input should be a non-negative integer.");
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
    int result1 = findNthFibonacci(5);
    std::cout << "Test Case 1: Nth Fibonacci Number = " << result1 << std::endl;

    int result2 = findNthFibonacci(8);
    std::cout << "Test Case 2: Nth Fibonacci Number = " << result2 << std::endl;

    int result3 = findNthFibonacci(10);
    std::cout << "Test Case 3: Nth Fibonacci Number = " << result3 << std::endl;

    int result4 = findNthFibonacci(0);
    std::cout << "Test Case 4: Nth Fibonacci Number = " << result4 << std::endl;

    int result5 = findNthFibonacci(2);
    std::cout << "Test Case 5: Nth Fibonacci Number = " << result5 << std::endl;

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

//You are tasked with creating a C++ program to find the next prime number after a given number.
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

#include <iostream>
#include <cmath>

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
        throw std::invalid_argument("Input should be a positive integer greater than 1.");
    }

    while (true) {
        num++;

        if (isPrime(num)) {
            return num; // Found the next prime number
        }
    }
}

int main() {
    // Test Cases
    int input1 = 10;
    int result1 = findNextPrime(input1);
    std::cout << "Test Case 1: Next Prime Number = " << result1 << std::endl;

    int input2 = 20;
    int result2 = findNextPrime(input2);
    std::cout << "Test Case 2: Next Prime Number = " << result2 << std::endl;

    int input3 = 31;
    int result3 = findNextPrime(input3);
    std::cout << "Test Case 3: Next Prime Number = " << result3 << std::endl;

    int input4 = 1;
    try {
        int result4 = findNextPrime(input4);
        std::cout << "Test Case 4: Next Prime Number = " << result4 << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Test Case 4: " << e.what() << std::endl;
    }

    return 0;
}


//Sample Output:
// Test Case 1: Next Prime Number = 11
//Test Case 2: Next Prime Number = 23
//Test Case 3: Next Prime Number = 37
//Test Case 4: Next Prime Number = 2

//******************************************************---****************************************************************

//  5. Problem Description: Find Majority Element in an Array

//You are tasked with creating a C++ program to find the majority element in an array.
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

#include <iostream>
#include <vector>
#include <algorithm>

int findMajorityElement(std::vector<int>& nums) {
    int n = nums.size();

    if (n == 0) {
        return -1; // No majority element in an empty array
    }

    std::vector<int> elementCount(1001, 0); // Assuming elements in the range [0, 1000]

    for (int num : nums) {
        elementCount[num]++;
    }

    for (int i = 0; i < elementCount.size(); i++) {
        if (elementCount[i] > n / 2) {
            return i; // Found majority element
        }
    }

    return -1; // No majority element found
}

int main() {
    // Test Cases
    std::vector<int> arr1 = {2, 2, 1, 1, 1, 2, 2};
    int result1 = findMajorityElement(arr1);
    std::cout << "Test Case 1: Majority Element = " << result1 << std::endl;

    std::vector<int> arr2 = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int result2 = findMajorityElement(arr2);
    std::cout << "Test Case 2: Majority Element = " << result2 << std::endl;

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    int result3 = findMajorityElement(arr3);
    std::cout << "Test Case 3: Majority Element = " << result3 << std::endl;

    std::vector<int> arr4 = {1, 1, 1, 2, 2};
    int result4 = findMajorityElement(arr4);
    std::cout << "Test Case 4: Majority Element = " << result4 << std::endl;

    std::vector<int> arr5 = {5};
    int result5 = findMajorityElement(arr5);
    std::cout << "Test Case 5: Majority Element = " << result5 << std::endl;

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

//You are tasked with creating a C++ program to calculate the frequency of each character in a given string.
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

#include <iostream>
#include <string>
#include <array>

void calculateCharFrequency(const std::string& input) {
    if (input.empty()) {
        std::cout << "Input string is empty." << std::endl;
        return;
    }

    std::array<int, 26> charFrequency = {0};

    for (char c : input) {
        if (std::islower(c)) {
            charFrequency[c - 'a']++;
        }
    }

    for (int i = 0; i < charFrequency.size(); i++) {
        if (charFrequency[i] > 0) {
            char currentChar = 'a' + i;
            std::cout << currentChar << ": " << charFrequency[i] << std::endl;
        }
    }
}

int main() {
    // Test Cases
    std::string input1 = "abracadabra";
    std::cout << "Test Case 1:" << std::endl;
    calculateCharFrequency(input1);

    std::string input2 = "hello";
    std::cout << "\nTest Case 2:" << std::endl;
    calculateCharFrequency(input2);

    std::string input3 = "programming";
    std::cout << "\nTest Case 3:" << std::endl;
    calculateCharFrequency(input3);

    std::string input4 = "java";
    std::cout << "\nTest Case 4:" << std::endl;
    calculateCharFrequency(input4);

    std::string input5 = "";
    std::cout << "\nTest Case 5:" << std::endl;
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

//You are tasked with creating a C++ program to find the sum of the two largest elements in an array.
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

#include <iostream>
#include <vector>
#include <stdexcept>
#include <climits>

// Function to find the sum of the two largest elements in an array
int sumOfTwoLargest(std::vector<int>& nums) {
    if (nums.size() < 2) {
        throw std::invalid_argument("Array should contain at least two elements.");
    }

    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int num : nums) {
        if (num > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = num;
        } else if (num > secondLargest && num < firstLargest) {
            secondLargest = num;
        }
    }

    if (secondLargest == INT_MIN) {
        throw std::invalid_argument("Array should contain at least two distinct elements.");
    }

    return firstLargest + secondLargest;
}

int main() {
    // Test Cases
    std::vector<int> arr1 = {3, 7, 2, 8, 5};
    int result1 = sumOfTwoLargest(arr1);
    std::cout << "Test Case 1: Sum of Two Largest = " << result1 << std::endl;

    std::vector<int> arr2 = {5, 8, 4, 3};
    int result2 = sumOfTwoLargest(arr2);
    std::cout << "Test Case 2: Sum of Two Largest = " << result2 << std::endl;

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    int result3 = sumOfTwoLargest(arr3);
    std::cout << "Test Case 3: Sum of Two Largest = " << result3 << std::endl;

    std::vector<int> arr4 = {10, 10, 20, 20, 30};
    int result4 = sumOfTwoLargest(arr4);
    std::cout << "Test Case 4: Sum of Two Largest = " << result4 << std::endl;

    std::vector<int> arr5 = {5, 3};
    int result5 = sumOfTwoLargest(arr5);
    std::cout << "Test Case 5: Sum of Two Largest = " << result5 << std::endl;

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

//You are tasked with creating a C++ program to find the square of the sum of digits of a given number.
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

#include <iostream>
#include <stdexcept>

// Function to calculate the square of the sum of digits of a non-negative integer
int squareOfSumOfDigits(int num) {
    if (num < 0) {
        throw std::invalid_argument("Input should be a non-negative integer.");
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

int main() {
    // Test Cases
    int input1 = 123;
    int result1 = squareOfSumOfDigits(input1);
    std::cout << "Test Case 1: Square of Sum of Digits = " << result1 << std::endl;

    int input2 = 456;
    int result2 = squareOfSumOfDigits(input2);
    std::cout << "Test Case 2: Square of Sum of Digits = " << result2 << std::endl;

    int input3 = 7890;
    int result3 = squareOfSumOfDigits(input3);
    std::cout << "Test Case 3: Square of Sum of Digits = " << result3 << std::endl;

    int input4 = 0;
    int result4 = squareOfSumOfDigits(input4);
    std::cout << "Test Case 4: Square of Sum of Digits = " << result4 << std::endl;

    int input5 = 987654321;
    int result5 = squareOfSumOfDigits(input5);
    std::cout << "Test Case 5: Square of Sum of Digits = " << result5 << std::endl;

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

//You are tasked with creating a C++ program to determine whether a given number is a perfect square.
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

#include <iostream>
#include <stdexcept>

// Function to check if a number is a perfect square
bool isPerfectSquare(int num) {
    if (num < 0) {
        throw std::invalid_argument("Input should be a non-negative integer.");
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

int main() {
    // Test Cases
    int input1 = 16;
    bool result1 = isPerfectSquare(input1);
    std::cout << "Test Case 1: Is Perfect Square? " << std::boolalpha << result1 << std::endl;

    int input2 = 25;
    bool result2 = isPerfectSquare(input2);
    std::cout << "Test Case 2: Is Perfect Square? " << std::boolalpha << result2 << std::endl;

    int input3 = 14;
    bool result3 = isPerfectSquare(input3);
    std::cout << "Test Case 3: Is Perfect Square? " << std::boolalpha << result3 << std::endl;

    int input4 = 0;
    bool result4 = isPerfectSquare(input4);
    std::cout << "Test Case 4: Is Perfect Square? " << std::boolalpha << result4 << std::endl;

    int input5 = 100;
    bool result5 = isPerfectSquare(input5);
    std::cout << "Test Case 5: Is Perfect Square? " << std::boolalpha << result5 << std::endl;

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
//You are tasked with creating a C++ program to find the difference between the sum of even-indexed elements and odd-indexed elements in an array.
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

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

int differenceBetweenSums(std::vector<int> nums) {
    if (nums.size() < 2) {
        throw std::invalid_argument("Array should contain at least two elements.");
    }

    int sumEven = 0;
    int sumOdd = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            sumEven += nums[i];
        } else {
            sumOdd += nums[i];
        }
    }

    return std::abs(sumEven - sumOdd);
}

int main() {
    // Test Cases
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    int result1 = differenceBetweenSums(arr1);
    std::cout << "Test Case 1: Difference Between Sums = " << result1 << std::endl;

    std::vector<int> arr2 = {10, 20, 30, 40, 50, 60};
    int result2 = differenceBetweenSums(arr2);
    std::cout << "Test Case 2: Difference Between Sums = " << result2 << std::endl;

    std::vector<int> arr3 = {5};
    try {
        int result3 = differenceBetweenSums(arr3);
        std::cout << "Test Case 3: Difference Between Sums = " << result3 << std::endl;
    } catch (std::invalid_argument& e) {
        std::cout << "Test Case 3: " << e.what() << std::endl;
    }

    std::vector<int> arr4 = {2, 4};
    int result4 = differenceBetweenSums(arr4);
    std::cout << "Test Case 4: Difference Between Sums = " << result4 << std::endl;

    std::vector<int> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result5 = differenceBetweenSums(arr5);
    std::cout << "Test Case 5: Difference Between Sums = " << result5 << std::endl;

    return 0;
}

// sample output:
// Test Case 1: Difference Between Sums = 3
//Test Case 2: Difference Between Sums = 30
//Test Case 3: Array should contain at least two elements.
//Test Case 4: Difference Between Sums = 2
//Test Case 5: Difference Between Sums = 5

//******************************************************---****************************************************************
// 11. Armstrong Number
//
//You are tasked with creating a C++ program to determine whether a given integer 'n' is an Armstrong number.
// An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits in the number.

//Input:
//    n: An integer representing the number to be checked for being an Armstrong number.

//Output:
//    Returns true if the input number n is an Armstrong number, and false otherwise.

// Example 1
//Input: 153
//Output: true
//Explanation: 1^3 + 5^3 + 3^3 = 153

// Example 2
//Input: 370
//Output: true
//Explanation: 3^3 + 7^3 + 0^3 = 370

// Example 3
//Input: 9474
//Output: true
//Explanation: 9^4 + 4^4 + 7^4 + 4^4 = 9474

//// Example 4
//Input: 123
//Output: false
//Explanation: 1^3 + 2^3 + 3^3 ≠ 123

//Notes:
//        The solution should efficiently determine whether the input number is an Armstrong number.
//        Armstrong numbers are positive integers with at least two digits.
//        The program should run without errors for valid input values.

#include <iostream>
#include <cmath>
#include <string>

bool isArmstrong(int n) {
    // Count the number of digits in the number
    int numDigits = std::to_string(n).length();

    int sum = 0;
    int temp = n;

    // Calculate the sum of digits raised to the power of numDigits
    while (temp > 0) {
        int digit = temp % 10;
        sum += std::pow(digit, numDigits);
        temp /= 10;
    }

    // Check if the sum is equal to the original number
    return sum == n;
}

int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    int n1 = 153;
    std::cout << "Input: " << n1 << std::endl;
    std::cout << "Output: " << std::boolalpha << isArmstrong(n1) << std::endl;

    std::cout << "\nTest Case 2:" << std::endl;
    int n2 = 370;
    std::cout << "Input: " << n2 << std::endl;
    std::cout << "Output: " << std::boolalpha << isArmstrong(n2) << std::endl;

    std::cout << "\nTest Case 3:" << std::endl;
    int n3 = 9474;
    std::cout << "Input: " << n3 << std::endl;
    std::cout << "Output: " << std::boolalpha << isArmstrong(n3) << std::endl;

    std::cout << "\nTest Case 4:" << std::endl;
    int n4 = 123;
    std::cout << "Input: " << n4 << std::endl;
    std::cout << "Output: " << std::boolalpha << isArmstrong(n4) << std::endl;

    return 0;
}

// sample output:
// Test Case 1:
//Input: 153
//Output: true

//Test Case 2:
//Input: 370
//Output: true

//Test Case 3:
//Input: 9474
//Output: true

//Test Case 4:
//Input: 123
//Output: false


//******************************************************---****************************************************************
// 12.  Count Unique Characters in a String

//You are tasked with writing a C++ program to count the number of unique characters in a given string.
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

#include <iostream>
#include <string>
#include <vector>

int countUniqueCharacters(std::string str) {
    // Array to store frequency of characters, considering case insensitivity
    std::vector<int> frequency(26, 0); // Considering only alphabets (case-insensitive)

    // Convert the string to lowercase
    for (char& ch : str) {
        if (std::isalpha(ch)) {
            ch = std::tolower(ch);
        }
    }

    // Iterate through the string and update frequency array
    for (char ch : str) {
        if (std::isalpha(ch)) {
            frequency[ch - 'a']++;
        }
    }

    // Count unique characters
    int uniqueCount = 0;
    for (int freq : frequency) {
        if (freq == 1) {
            uniqueCount++;
        }
    }

    return uniqueCount;
}

int main() {
    // Test Cases
    std::string str1 = "Hello";
    std::cout << "Test Case 1:" << std::endl;
    std::cout << "Input: " << str1 << std::endl;
    std::cout << "Output: " << countUniqueCharacters(str1) << std::endl;

    std::string str2 = "Mississippi";
    std::cout << "\nTest Case 2:" << std::endl;
    std::cout << "Input: " << str2 << std::endl;
    std::cout << "Output: " << countUniqueCharacters(str2) << std::endl;

    std::string str3 = "JavaProgramming";
    std::cout << "\nTest Case 3:" << std::endl;
    std::cout << "Input: " << str3 << std::endl;
    std::cout << "Output: " << countUniqueCharacters(str3) << std::endl;

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

#include <iostream>
#include <vector>

int findPeakElement(std::vector<int>& nums) {
    int n = nums.size();

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

int main() {
    // Test Cases
    std::vector<int> nums1 = {5, 10, 20, 15};
    std::cout << "Test Case 1: " << findPeakElement(nums1) << std::endl; // Output: 20

    std::vector<int> nums2 = {1, 3, 6, 7, 4, 2};
    std::cout << "Test Case 2: " << findPeakElement(nums2) << std::endl; // Output: 7

    std::vector<int> nums3 = {10, 20, 30, 40};
    std::cout << "Test Case 3: " << findPeakElement(nums3) << std::endl; // Output: 40

    std::vector<int> nums4 = {5, 10, 15, 20, 25};
    std::cout << "Test Case 4: " << findPeakElement(nums4) << std::endl; // Output: 25

    std::vector<int> nums5 = {1};
    std::cout << "Test Case 5: " << findPeakElement(nums5) << std::endl; // Output: 1

    std::vector<int> nums6 = {10, 9, 8, 7};
    std::cout << "Test Case 6: " << findPeakElement(nums6) << std::endl; // Output: 10

    std::vector<int> nums7 = {10, 11, 13, 16, 20, 8, 5, 4};
    std::cout << "Test Case 7: " << findPeakElement(nums7) << std::endl; // Output: 20

    std::vector<int> nums8 = {20, 40, 50, 70, 90, 60, 30, 10};
    std::cout << "Test Case 8: " << findPeakElement(nums8) << std::endl; // Output: 90

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
//You are tasked with creating a C++ program to determine whether a given year is a leap year or not.
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

#include <iostream>
#include <vector>

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true; // Leap year condition satisfied
    } else {
        return false; // Not a leap year
    }
}

int main() {
    // Test Cases
    std::vector<int> years = {2020, 1900, 2000, 2021, 2022, 3036, 3033, 1986, 1956, 1600};
    for (int year : years) {
        std::cout << "Is " << year << " a leap year? " << std::boolalpha << isLeapYear(year) << std::endl;
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
//You are tasked with creating a C++ program to check if a given string starts with a specific prefix.
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

#include <iostream>
#include <stdexcept>

// Function to check if a string starts with a given prefix
bool startsWithPrefix(const std::string& str, const std::string& prefix) {
    if (prefix.length() > str.length()) {
        return false; // Prefix is longer than the string, cannot be a match
    }

    for (size_t i = 0; i < prefix.length(); i++) {
        if (str[i] != prefix[i]) {
            return false; // Mismatch at current position
        }
    }

    return true; // Prefix matches the start of the string
}

int main() {
    // Test Cases
    bool result1 = startsWithPrefix("Hello, World!", "Hello");
    std::cout << "Test Case 1: Starts with Prefix? " << std::boolalpha << result1 << std::endl;

    bool result2 = startsWithPrefix("Java Programming", "Python");
    std::cout << "Test Case 2: Starts with Prefix? " << std::boolalpha << result2 << std::endl;

    bool result3 = startsWithPrefix("12345", "12");
    std::cout << "Test Case 3: Starts with Prefix? " << std::boolalpha << result3 << std::endl;

    bool result4 = startsWithPrefix("Java", "Java");
    std::cout << "Test Case 4: Starts with Prefix? " << std::boolalpha << result4 << std::endl;

    bool result5 = startsWithPrefix("", "Prefix");
    std::cout << "Test Case 5: Starts with Prefix? " << std::boolalpha << result5 << std::endl;

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

//You are tasked with creating a C++ program to find all pairs of elements in an array whose sum is equal to a given target number.

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

#include <iostream>
#include <vector>

void findPairs(int nums[], int length, int target) {
    bool foundPair = false;
    // Brute-force approach: Check all pairs of elements in the array
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (nums[i] + nums[j] == target) {
                std::cout << "(" << nums[i] << ", " << nums[j] << ")" << std::endl;
                foundPair = true;
            }
        }
    }
    if (!foundPair) {
        std::cout << "No pairs found." << std::endl;
    }
}

int main() {
    // Test Cases
    int nums1[] = {1, 2, 3, 4, 5};
    int target1 = 5;
    std::cout << "Pairs with sum " << target1 << " in nums1:" << std::endl;
    findPairs(nums1, sizeof(nums1) / sizeof(nums1[0]), target1);

    int nums2[] = {3, 8, 5, 2, 9};
    int target2 = 10;
    std::cout << "\nPairs with sum " << target2 << " in nums2:" << std::endl;
    findPairs(nums2, sizeof(nums2) / sizeof(nums2[0]), target2);

    int nums3[] = {1, 2, 3, 4, 5};
    int target3 = 20;
    std::cout << "\nPairs with sum " << target3 << " in nums3:" << std::endl;
    findPairs(nums3, sizeof(nums3) / sizeof(nums3[0]), target3);

    int nums4[] = {5, 4, 6, 5};
    int target4 = 10;
    std::cout << "\nPairs with sum " << target4 << " in nums4:" << std::endl;
    findPairs(nums4, sizeof(nums4) / sizeof(nums4[0]), target4);

    int nums5[] = {1, 2, 3, 4, 5};
    int target5 = 8;
    std::cout << "\nPairs with sum " << target5 << " in nums5:" << std::endl;
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

#include <iostream>

void swap(int& a, int& b) {
    std::cout << "Before swapping:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    // Swapping without using a third variable
    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "After swapping:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

int main() {
    // Test Cases
    int num1 = 5, num2 = 10;
    std::cout << "Swapping num1 and num2:" << std::endl;
    swap(num1, num2);

    int num3 = 3, num4 = 7;
    std::cout << "\nSwapping num3 and num4:" << std::endl;
    swap(num3, num4);

    int num5 = 20, num6 = 50;
    std::cout << "\nSwapping num5 and num6:" << std::endl;
    swap(num5, num6);

    int num7 = 1, num8 = 4;
    std::cout << "\nSwapping num7 and num8:" << std::endl;
    swap(num7, num8);

    int num9 = 15, num10 = 25;
    std::cout << "\nSwapping num9 and num10:" << std::endl;
    swap(num9, num10);

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

//You are tasked with creating a C++ program to find all the factors (numbers that evenly divide) of a given input number.

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

#include <iostream>

void findFactors(int n) {
    std::cout << "Factors of " << n << ": ";
    // Iterate from 1 to n and check if i divides n evenly
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            std::cout << i;
            // Print comma and space for separation except for the last factor
            if (i != n) {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    // Test Cases
    int num1 = 12;
    std::cout << "Test Case 1:" << std::endl;
    findFactors(num1);

    int num2 = 15;
    std::cout << "\nTest Case 2:" << std::endl;
    findFactors(num2);

    int num3 = 28;
    std::cout << "\nTest Case 3:" << std::endl;
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
//You are tasked with creating a C++ program to find the sum of prime numbers up to a given limit.
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

#include <iostream>
#include <stdexcept>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= std::sqrt(num); i++) {
        if (num % i == 0) {
            return false; // Not a prime number
        }
    }

    return true; // Prime number
}

// Function to calculate the sum of prime numbers up to a given limit
int sumOfPrimes(int limit) {
    if (limit < 0) {
        throw std::invalid_argument("Limit should be a non-negative integer.");
    }

    int sum = 0;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    // Test Cases
    int result1 = sumOfPrimes(10);
    std::cout << "Test Case 1: Sum of Primes = " << result1 << std::endl;

    int result2 = sumOfPrimes(20);
    std::cout << "Test Case 2: Sum of Primes = " << result2 << std::endl;

    int result3 = sumOfPrimes(5);
    std::cout << "Test Case 3: Sum of Primes = " << result3 << std::endl;

    int result4 = sumOfPrimes(0);
    std::cout << "Test Case 4: Sum of Primes = " << result4 << std::endl;

    int result5 = sumOfPrimes(30);
    std::cout << "Test Case 5: Sum of Primes = " << result5 << std::endl;

    return 0;
}


//Sample Output:
// Test Case 1: Sum of Primes = 17
//Test Case 2: Sum of Primes = 77
//Test Case 3: Sum of Primes = 10
//Test Case 4: Sum of Primes = 0
//Test Case 5: Sum of Primes = 129


//******************************************************---****************************************************************

//  20. Problem Description: Find the Kth Largest Element in an Array

//You are tasked with creating a C++ program to find the Kth largest element in an array.
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

#include <iostream>
#include <algorithm>
#include <stdexcept>

// Function to find the kth largest element in an array
int findKthLargest(int nums[], int size, int k) {
    if (nums == nullptr || k <= 0 || k > size) {
        throw std::invalid_argument("Invalid input parameters.");
    }

    std::sort(nums, nums + size);
    return nums[size - k];
}

int main() {
    // Test Cases
    int arr1[] = {3, 1, 5, 7, 2, 4, 6};
    int k1 = 3;
    int result1 = findKthLargest(arr1, sizeof(arr1) / sizeof(arr1[0]), k1);
    std::cout << "Test Case 1: Kth Largest Element = " << result1 << std::endl;

    int arr2[] = {10, 20, 30, 40, 50};
    int k2 = 1;
    int result2 = findKthLargest(arr2, sizeof(arr2) / sizeof(arr2[0]), k2);
    std::cout << "Test Case 2: Kth Largest Element = " << result2 << std::endl;

    int arr3[] = {7};
    int k3 = 1;
    int result3 = findKthLargest(arr3, sizeof(arr3) / sizeof(arr3[0]), k3);
    std::cout << "Test Case 3: Kth Largest Element = " << result3 << std::endl;

    int arr4[] = {5, 5, 5, 5, 5};
    int k4 = 2;
    int result4 = findKthLargest(arr4, sizeof(arr4) / sizeof(arr4[0]), k4);
    std::cout << "Test Case 4: Kth Largest Element = " << result4 << std::endl;

    int arr5[] = {1, 2, 3, 4, 5};
    int k5 = 5;
    int result5 = findKthLargest(arr5, sizeof(arr5) / sizeof(arr5[0]), k5);
    std::cout << "Test Case 5: Kth Largest Element = " << result5 << std::endl;

    return 0;
}

//Sample Output:
// Test Case 1: Kth Largest Element = 5
//Test Case 2: Kth Largest Element = 50
//Test Case 3: Kth Largest Element = 7
//Test Case 4: Kth Largest Element = 5
//Test Case 5: Kth Largest Element = 1


//******************************************************---****************************************************************

//  21. Problem Description: Single Number

//You are tasked with creating a C++ program to find the single number in an array where every element appears twice except for one.
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

#include <iostream>
#include <unordered_set>
#include <stdexcept>

// Function to find the single number in the array
int findSingleNumber(int nums[], int size) {
    if (nums == nullptr || size % 2 == 0) {
        throw std::invalid_argument("Invalid input array.");
    }

    int result = 0;

    for (int i = 0; i < size; ++i) {
        result ^= nums[i]; // Using XOR operation to find the single number
    }

    return result;
}

int main() {
    // Test Cases
    int arr1[] = {4, 2, 7, 2, 4};
    int result1 = findSingleNumber(arr1, sizeof(arr1) / sizeof(arr1[0]));
    std::cout << "Test Case 1: Single Number = " << result1 << std::endl;

    int arr2[] = {1, 2, 3, 1, 3};
    int result2 = findSingleNumber(arr2, sizeof(arr2) / sizeof(arr2[0]));
    std::cout << "Test Case 2: Single Number = " << result2 << std::endl;

    int arr3[] = {5, 6, 6};
    int result3 = findSingleNumber(arr3, sizeof(arr3) / sizeof(arr3[0]));
    std::cout << "Test Case 3: Single Number = " << result3 << std::endl;

    return 0;
}

//Sample Output:
// Test Case 1: Single Number = 7
//Test Case 2: Single Number = 2
//Test Case 3: Single Number = 5

//******************************************************---****************************************************************

//  22. Problem Description: Missing Number

//You are tasked with creating a C++ program to find the missing number in an array.
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

#include <iostream>
#include <stdexcept>

// Function to find the missing number in the array
int findMissingNumber(int nums[], int size) {
    if (nums == nullptr || size == 0) {
        throw std::invalid_argument("Invalid input array.");
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
    // Test Cases
    int arr1[] = {3, 0, 1};
    int result1 = findMissingNumber(arr1, sizeof(arr1) / sizeof(arr1[0]));
    std::cout << "Test Case 1: Missing Number = " << result1 << std::endl;

    int arr2[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int result2 = findMissingNumber(arr2, sizeof(arr2) / sizeof(arr2[0]));
    std::cout << "Test Case 2: Missing Number = " << result2 << std::endl;

    int arr3[] = {1};
    int result3 = findMissingNumber(arr3, sizeof(arr3) / sizeof(arr3[0]));
    std::cout << "Test Case 3: Missing Number = " << result3 << std::endl;

    return 0;
}


//Sample Output:
// Test Case 1: Missing Number = 2
//Test Case 2: Missing Number = 8
//Test Case 3: Missing Number = 0


//******************************************************---****************************************************************

