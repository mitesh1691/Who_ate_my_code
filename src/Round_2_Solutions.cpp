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

//  4. Problem Description: Find Factorial using Recursion

//You are tasked with creating a C++ program to find the factorial of a given number using 'recursion'.
// The factorial of a non-negative integer n is the product of all positive integers less than or equal to n.
// The program should efficiently calculate and return the factorial of the input number.

//      Input:
//        n: A non-negative integer for which the factorial needs to be calculated (n >= 0).
//
//      Output:
//        Returns the factorial of the input number.

//Example:
// Example 1
//long result1 = calculateFactorial(5);
// Output: 120 (Factorial of 5: 5 * 4 * 3 * 2 * 1 = 120)

// Example 2
//long result2 = calculateFactorial(8);
// Output: 40320 (Factorial of 8: 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 = 40320)

// Example 3
//long result3 = calculateFactorial(0);
// Output: 1 (Factorial of 0 is defined as 1)

// The function should use recursion to calculate the factorial.


#include <iostream>
#include <stdexcept>

// Function to calculate factorial recursively
long calculateFactorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Input should be a non-negative integer.");
    }

    if (n == 0 || n == 1) {
        return 1; // Factorial of 0 and 1 is 1
    }

    return n * calculateFactorial(n - 1);
}

int main() {
    // Test Cases
    int input1 = 5;
    long result1 = calculateFactorial(input1);
    std::cout << "Test Case 1: Factorial of " << input1 << " = " << result1 << std::endl;

    int input2 = 8;
    long result2 = calculateFactorial(input2);
    std::cout << "Test Case 2: Factorial of " << input2 << " = " << result2 << std::endl;

    int input3 = 0;
    long result3 = calculateFactorial(input3);
    std::cout << "Test Case 3: Factorial of " << input3 << " = " << result3 << std::endl;

    int input4 = 3;
    long result4 = calculateFactorial(input4);
    std::cout << "Test Case 4: Factorial of " << input4 << " = " << result4 << std::endl;

    int input5 = 7;
    long result5 = calculateFactorial(input5);
    std::cout << "Test Case 5: Factorial of " << input5 << " = " << result5 << std::endl;

    return 0;
}


// Sample Output:
// Test Case 1: Factorial of 5 = 120
//Test Case 2: Factorial of 8 = 40320
//Test Case 3: Factorial of 0 = 1
//Test Case 4: Factorial of 3 = 6
//Test Case 5: Factorial of 7 = 5040

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

//  7. Problem Description: Find the Average of Elements in an Array

//You are tasked with creating a C++ program to find the average of elements in an array.
// The program should efficiently calculate and return the average of all elements present in the array.

//Input:
//    nums: An array of integers.

//Output:
//    Returns the average of all elements in the array.


// Example 1
//int[] arr1 = {1, 2, 3, 4, 5};
//double result1 = findAverage(arr1);
// Output: 3.0 (The average of elements 1, 2, 3, 4, 5 is (1 + 2 + 3 + 4 + 5) / 5 = 3.0)

// Example 2
//int[] arr2 = {10, 20, 30, 40, 50};
//double result2 = findAverage(arr2);
// Output: 30.0 (The average of elements 10, 20, 30, 40, 50 is (10 + 20 + 30 + 40 + 50) / 5 = 30.0)

#include <iostream>
#include <vector>

double findAverage(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Vector should contain at least one element.");
    }

    int sum = 0;

    for (int num : nums) {
        sum += num;
    }

    return static_cast<double>(sum) / nums.size();
}

int main() {
    // Test Cases
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    double result1 = findAverage(arr1);
    std::cout << "Test Case 1: Average of Elements = " << result1 << std::endl;

    std::vector<int> arr2 = {10, 20, 30, 40, 50};
    double result2 = findAverage(arr2);
    std::cout << "Test Case 2: Average of Elements = " << result2 << std::endl;

    std::vector<int> arr3 = {5};
    double result3 = findAverage(arr3);
    std::cout << "Test Case 3: Average of Elements = " << result3 << std::endl;

    std::vector<int> arr4 = {-1, 0, 1};
    double result4 = findAverage(arr4);
    std::cout << "Test Case 4: Average of Elements = " << result4 << std::endl;

    std::vector<int> arr5 = {2, 4, 6, 8, 10};
    double result5 = findAverage(arr5);
    std::cout << "Test Case 5: Average of Elements = " << result5 << std::endl;

    return 0;
}


// sample output:
// Test Case 1: Average of Elements = 3.0
//Test Case 2: Average of Elements = 30.0
//Test Case 3: Average of Elements = 5.0
//Test Case 4: Average of Elements = 0.0
//Test Case 5: Average of Elements = 6.0



//******************************************************---****************************************************************

//  8. Problem Description: Count Even and Odd Numbers in an Array

//You are tasked with creating a C++ program to count the number of even and odd numbers in an array.
// The program should efficiently determine and return the count of even and odd numbers present in the array.

//Input:
//    nums: An array of integers.

//Output:
//    Returns an array where the first element is the count of even numbers, and the second element is the count of odd numbers.

// Example
//    int[] arr = {2, 5, 8, 3, 6, 7};
//    int[] result = countEvenOddNumbers(arr);
// Output: [3, 3] (There are 3 even numbers {2, 8, 6} and 3 odd numbers {5, 3, 7})


#include <iostream>
#include <vector>

std::vector<int> countEvenOddNumbers(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Vector should contain at least one element.");
    }

    int evenCount = 0;
    int oddCount = 0;

    for (int num : nums) {
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    return {evenCount, oddCount};
}

int main() {
    // Test Cases
    std::vector<int> arr1 = {2, 5, 8, 3, 6, 7};
    auto result1 = countEvenOddNumbers(arr1);
    std::cout << "Test Case 1: Even Count = " << result1[0] << ", Odd Count = " << result1[1] << std::endl;

    std::vector<int> arr2 = {10, 20, 30, 40, 50};
    auto result2 = countEvenOddNumbers(arr2);
    std::cout << "Test Case 2: Even Count = " << result2[0] << ", Odd Count = " << result2[1] << std::endl;

    std::vector<int> arr3 = {7};
    auto result3 = countEvenOddNumbers(arr3);
    std::cout << "Test Case 3: Even Count = " << result3[0] << ", Odd Count = " << result3[1] << std::endl;

    std::vector<int> arr4 = {-1, 0, 1};
    auto result4 = countEvenOddNumbers(arr4);
    std::cout << "Test Case 4: Even Count = " << result4[0] << ", Odd Count = " << result4[1] << std::endl;

    std::vector<int> arr5 = {2, 4, 6, 8, 10};
    auto result5 = countEvenOddNumbers(arr5);
    std::cout << "Test Case 5: Even Count = " << result5[0] << ", Odd Count = " << result5[1] << std::endl;

    return 0;
}

// sample output:
//Test Case 1: Even Count = 3, Odd Count = 3
//Test Case 2: Even Count = 5, Odd Count = 0
//Test Case 3: Even Count = 0, Odd Count = 1
//Test Case 4: Even Count = 1, Odd Count = 2
//Test Case 5: Even Count = 5, Odd Count = 0


//******************************************************---****************************************************************

//  9. Problem Description: Find the Maximum of Three Numbers

//You are tasked with creating a C++ program to find the maximum of three numbers.
// The program should efficiently determine and return the largest value among the three input numbers.

//Input:
//    num1, num2, and num3: Three integers.

//Output:
//    Returns the maximum value among the three input numbers.

// Example
//int result = findMaximum(5, 12, 8);
// Output: 12 (Among the numbers 5, 12, and 8, 12 is the largest)

//Notes:
//    The solution should efficiently find and return the maximum value among the three input numbers.
//    The function should handle integer inputs.
//    The program should run without errors for valid input numbers.


#include <iostream>

int findMaximum(int num1, int num2, int num3) {
    int max = num1;

    if (num2 > max) {
        max = num2;
    }

    if (num3 > max) {
        max = num3;
    }

    return max;
}

int main() {
    // Test Cases
    int result1 = findMaximum(5, 12, 8);
    std::cout << "Test Case 1: Maximum = " << result1 << std::endl;

    int result2 = findMaximum(20, 15, 25);
    std::cout << "Test Case 2: Maximum = " << result2 << std::endl;

    int result3 = findMaximum(10, 10, 10);
    std::cout << "Test Case 3: Maximum = " << result3 << std::endl;

    int result4 = findMaximum(-5, -2, -8);
    std::cout << "Test Case 4: Maximum = " << result4 << std::endl;

    int result5 = findMaximum(0, 0, 0);
    std::cout << "Test Case 5: Maximum = " << result5 << std::endl;

    return 0;
}


// sample output:
// Test Case 1: Maximum = 12
//Test Case 2: Maximum = 25
//Test Case 3: Maximum = 10
//Test Case 4: Maximum = -2
//Test Case 5: Maximum = 0

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
// 15. Sum of Digits

//You are tasked with creating a C++ program to calculate the sum of digits of a given integer number.

//Input:
//    number: An integer representing the number whose digits' sum needs to be calculated.

//Output:
//    Returns an integer representing the sum of digits of the input number.

//// Example 1
//Input: number = 123
//Output: 6
//Explanation: The sum of digits of the number 123 is 1 + 2 + 3 = 6.

//// Example 2
//Input: number = 9876
//Output: 30
//Explanation: The sum of digits of the number 9876 is 9 + 8 + 7 + 6 = 30.

//// Example 3
//Input: number = 5
//Output: 5
//Explanation: The sum of digits of the number 5 is 5.

//Notes:
//    The input number may be positive or negative.
//    The sum of digits should be calculated for the absolute value of the number.
//    The calculated sum should be returned as an integer.

#include <iostream>
#include <cmath>

int sumOfDigits(int number) {
    // Take absolute value to handle negative numbers
    number = std::abs(number);
    int sum = 0;
    while (number > 0) {
        sum += number % 10; // Add the last digit to the sum
        number /= 10; // Remove the last digit
    }
    return sum;
}

int main() {
    // Test Cases
    int numbers[] = {123, 9876, 5, -456, 0};
    for (int number : numbers) {
        std::cout << "Sum of digits for " << number << ": " << sumOfDigits(number) << std::endl;
    }
    return 0;
}


// sample output:
// Sum of digits for 123: 6
//Sum of digits for 9876: 30
//Sum of digits for 5: 5
//Sum of digits for -456: 15
//Sum of digits for 0: 0


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
// 19.

//******************************************************---****************************************************************
// 20.
