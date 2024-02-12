//  1. Two Sum:
//        Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//        You may assume that each input would have exactly one solution, and you may not use the same element twice.
//        You can return the answer in any order.
//
//        Example 1:
//        Input: nums = [2,7,11,15], target = 9
//        Output: [0,1]
//        Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]
//
//        Example 2:
//        Input: nums = [3,2,4], target = 6
//        Output: [1,2]
//
//        Example 3:
//        Input: nums = [3,3], target = 6
//        Output: [0,1]

//Code:
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result(2);

    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    throw std::invalid_argument("No two elements sum up to the target");
}

int main() {
    // Test Case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    auto result1 = twoSum(nums1, target1);
    std::cout << "Test Case 1: [" << result1[0] << ", " << result1[1] << "]\n";

    // Test Case 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    auto result2 = twoSum(nums2, target2);
    std::cout << "Test Case 2: [" << result2[0] << ", " << result2[1] << "]\n";

    // Test Case 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    auto result3 = twoSum(nums3, target3);
    std::cout << "Test Case 3: [" << result3[0] << ", " << result3[1] << "]\n";

    // Additional Test Case 1
    std::vector<int> nums4 = {1, 2, 3, 4, 5};
    int target4 = 9;
    auto result4 = twoSum(nums4, target4);
    std::cout << "Additional Test Case 1: [" << result4[0] << ", " << result4[1] << "]\n";

    // Additional Test Case 2
    std::vector<int> nums5 = {-1, -2, -3, -4, -5};
    int target5 = -8;
    auto result5 = twoSum(nums5, target5);
    std::cout << "Additional Test Case 2: [" << result5[0] << ", " << result5[1] << "]\n";

    return 0;
}


//sample output:
//
//        Test Case 1: [0, 1]
//        Test Case 2: [1, 2]
//        Test Case 3: [0, 1]
//        Additional Test Case 1: [3, 4]
//        Additional Test Case 2: [2, 4]

//******************************************************---****************************************************************


//  2. Problem Description: Count Vowels and Consonants in a String

//You are tasked with creating a c++ program to count the number of vowels and consonants in a given string.
// Vowels are defined as the letters 'a', 'e', 'i', 'o', and 'u', while consonants are all other alphabetic characters.
// The program should be case-insensitive, meaning it should treat uppercase and lowercase letters as equivalent.

//        Input:
//        str: A string containing alphabetic characters (both uppercase and lowercase).

//        Output:
//        Prints the number of vowels and consonants in the input string.


// Example
//    String str = "Hello World";
//  System.out.println("Test Case:");
//        countVowelsAndConsonants(str);
// Output:
// Number of vowels = 3
// Number of consonants = 7


#include <iostream>
#include <string>

void countVowelsAndConsonants(const std::string& str) {
    int vowelCount = 0;
    int consonantCount = 0;
    std::string lowercaseStr = str;

    // Convert the string to lowercase for case-insensitivity
    for (char& ch : lowercaseStr) {
        ch = std::tolower(ch);
    }

    for (char ch : lowercaseStr) {
        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
        // Check if the character is a consonant
        else if (ch >= 'a' && ch <= 'z') {
            consonantCount++;
        }
    }

    std::cout << "Number of vowels = " << vowelCount << std::endl;
    std::cout << "Number of consonants = " << consonantCount << std::endl;
}

int main() {
    // Test Case 1
    std::string str1 = "Hello World";
    std::cout << "Test Case 1:\n";
    countVowelsAndConsonants(str1);
    std::cout << std::endl;

    // Test Case 2
    std::string str2 = "Programming is Fun";
    std::cout << "Test Case 2:\n";
    countVowelsAndConsonants(str2);
    std::cout << std::endl;

    // Test Case 3
    std::string str3 = "Java";
    std::cout << "Test Case 3:\n";
    countVowelsAndConsonants(str3);
    std::cout << std::endl;

    // Test Case 4
    std::string str4 = "Python";
    std::cout << "Test Case 4:\n";
    countVowelsAndConsonants(str4);
    std::cout << std::endl;

    // Test Case 5
    std::string str5 = "The quick brown fox jumps over the lazy dog";
    std::cout << "Test Case 5:\n";
    countVowelsAndConsonants(str5);
    std::cout << std::endl;

    // Test Case 6 (Empty String)
    std::string str6 = "";
    std::cout << "Test Case 6:\n";
    countVowelsAndConsonants(str6);
    std::cout << std::endl;

    return 0;
}


// sample output:
//Test Case 1:
//        Number of vowels = 3
//        Number of consonants = 7
//
//        Test Case 2:
//        Number of vowels = 5
//        Number of consonants = 11
//
//        Test Case 3:
//        Number of vowels = 2
//        Number of consonants = 2
//
//        Test Case 4:
//        Number of vowels = 1
//        Number of consonants = 5
//
//        Test Case 5:
//        Number of vowels = 11
//        Number of consonants = 24
//
//        Test Case 6:
//        Number of vowels = 0
//        Number of consonants = 0


//****************************************************---****************************************************************

//  3. Problem Description: Check Prime Number
//
//You are required to create a C++ program that determines whether a given number is prime or not.
// A prime number is defined as a natural number greater than 1 that is not a product of two smaller natural numbers.
// The program should efficiently check whether a given input number is prime and return a boolean result.

//Returns true if the input number is prime, and false otherwise.

//  Notes:
//    The solution should efficiently handle various input numbers.
//    The function should return false for numbers less than or equal to 1.
//    The program should run without errors for valid input numbers.

// // Example 1
//int num1 = 7;
//boolean result1 = isPrime(num1);
//// Output: true
//
//// Example 2
//int num2 = 15;
//boolean result2 = isPrime(num2);
//// Output: false
//
//// Example 3
//int num3 = 23;
//boolean result3 = isPrime(num3);
//// Output: true

#include <iostream>
#include <cmath>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++) { // i < number if you want to iterate till the given number
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Test Case 1
    int num1 = 7;
    std::cout << "Test Case 1: Is " << num1 << " prime? " << std::boolalpha << isPrime(num1) << std::endl;

    // Test Case 2
    int num2 = 15;
    std::cout << "Test Case 2: Is " << num2 << " prime? " << std::boolalpha << isPrime(num2) << std::endl;

    // Test Case 3
    int num3 = 23;
    std::cout << "Test Case 3: Is " << num3 << " prime? " << std::boolalpha << isPrime(num3) << std::endl;

    // Test Case 4
    int num4 = 1;
    std::cout << "Test Case 4: Is " << num4 << " prime? " << std::boolalpha << isPrime(num4) << std::endl;

    // Test Case 5
    int num5 = 0;
    std::cout << "Test Case 5: Is " << num5 << " prime? " << std::boolalpha << isPrime(num5) << std::endl;

    // Test Case 6
    int num6 = 97;
    std::cout << "Test Case 6: Is " << num6 << " prime? " << std::boolalpha << isPrime(num6) << std::endl;

    return 0;
}


// sample output:
// Test Case 1: Is 7 prime? true
//Test Case 2: Is 15 prime? false
//Test Case 3: Is 23 prime? true
//Test Case 4: Is 1 prime? false
//Test Case 5: Is 0 prime? false
//Test Case 6: Is 97 prime? true


//****************************************************---****************************************************************


//  4. Problem Description: Check Palindrome

//You are tasked with creating a C++ program to determine whether a given string is a palindrome or not.
// A palindrome is a word, phrase, number, or other sequences of characters that reads the same forward and backward
// (ignoring spaces, punctuation, and capitalization).
// The program should efficiently check whether a given input string is a palindrome and return a boolean result.

//    Returns true if the input string is a palindrome, and false otherwise.

//Example:
// Example 1
//String str1 = "radar";
//        boolean result1 = isPalindrome(str1);
// Output: true

// Example 2
//        String str2 = "Palindrome";
//        boolean result2 = isPalindrome(str2);
// Output: false

// Example 3
//        String str3 = "A man, a plan, a canal, Panama";
//        boolean result3 = isPalindrome(str3);
// Output: true


//  Notes:
//    The solution should efficiently handle various input strings.
//    The function should consider the alphanumeric characters only and ignore spaces, punctuation, and capitalization.
//    The program should run without errors for valid input strings.

#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(std::string str) {
    // Remove non-alphanumeric characters and convert to lowercase
    std::string cleanStr = "";
    for (char ch : str) {
        if (isalnum(ch)) {
            cleanStr += tolower(ch);
        }
    }

    // Check if the cleaned string is a palindrome
    int left = 0;
    int right = cleanStr.length() - 1;

    while (left < right) {
        if (cleanStr[left] != cleanStr[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    // Test Case 1
    std::string str1 = "radar";
    std::cout << "Test Case 1: Is \"" << str1 << "\" a palindrome? " << std::boolalpha << isPalindrome(str1) << std::endl;

    // Test Case 2
    std::string str2 = "Palindrome";
    std::cout << "Test Case 2: Is \"" << str2 << "\" a palindrome? " << std::boolalpha << isPalindrome(str2) << std::endl;

    // Test Case 3
    std::string str3 = "A man, a plan, a canal, Panama";
    std::cout << "Test Case 3: Is \"" << str3 << "\" a palindrome? " << std::boolalpha << isPalindrome(str3) << std::endl;

    // Test Case 4
    std::string str4 = "No lemon, no melon";
    std::cout << "Test Case 4: Is \"" << str4 << "\" a palindrome? " << std::boolalpha << isPalindrome(str4) << std::endl;

    // Test Case 5
    std::string str5 = "Java";
    std::cout << "Test Case 5: Is \"" << str5 << "\" a palindrome? " << std::boolalpha << isPalindrome(str5) << std::endl;

    return 0;
}



// sample output:
// Test Case 1: Is "radar" a palindrome? true
//Test Case 2: Is "Palindrome" a palindrome? false
//Test Case 3: Is "A man, a plan, a canal, Panama" a palindrome? true
//Test Case 4: Is "No lemon, no melon" a palindrome? true
//Test Case 5: Is "Java" a palindrome? false


//****************************************************---****************************************************************

//  5. Problem Description: Find Factorial of a Number

//You are required to create a C++ program to calculate the factorial of a given number.
// The factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n.
// The program should efficiently calculate the factorial of the input number and return the result.

// Returns the factorial of the input number as a long data type.

// Example 1
//int num1 = 5;
//long result1 = calculateFactorial(num1);
// Output: 120

// Example 2
//int num2 = 0;
//long result2 = calculateFactorial(num2);
// Output: 1

// Example 3
//int num3 = 10;
//long result3 = calculateFactorial(num3);
// Output: 3628800

//Notes:
//    The solution should efficiently handle various input numbers.
//    The function should return 1 for n equal to 0, as 0! is defined as 1.
//    The program should run without errors for valid input numbers.

#include <iostream>

long calculateFactorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Input must be a non-negative integer.");
    }

    // Base case: 0! is defined as 1
    if (n == 0) {
        return 1;
    }

    // Initialize result to 1
    long result = 1;

    // Calculate factorial using a loop
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    // Test Case 1
    int num1 = 5;
    std::cout << "Test Case 1: Factorial of " << num1 << " = " << calculateFactorial(num1) << std::endl;

    // Test Case 2
    int num2 = 0;
    std::cout << "Test Case 2: Factorial of " << num2 << " = " << calculateFactorial(num2) << std::endl;

    // Test Case 3
    int num3 = 10;
    std::cout << "Test Case 3: Factorial of " << num3 << " = " << calculateFactorial(num3) << std::endl;

    // Test Case 4
    int num4 = 15;
    std::cout << "Test Case 4: Factorial of " << num4 << " = " << calculateFactorial(num4) << std::endl;

    // Test Case 5
    int num5 = 3;
    std::cout << "Test Case 5: Factorial of " << num5 << " = " << calculateFactorial(num5) << std::endl;

    return 0;
}


// sample output:
// Test Case 1: Factorial of 5 = 120
//Test Case 2: Factorial of 0 = 1
//Test Case 3: Factorial of 10 = 3628800
//Test Case 4: Factorial of 15 = 1307674368000
//Test Case 5: Factorial of 3 = 6


//****************************************************---****************************************************************

//      6. Problem Description: Find Second Smallest Element in an Array
//
//You are required to create a C++ program to find the second smallest element in an array of integers.
// The program should efficiently determine the second smallest element and return the result.

// Example:
//  Example 1
//int[] arr1 = {5, 2, 8, 1, 3};
//int result1 = findSecondSmallest(arr1);
//// Output: 2

// Example 2
//int[] arr2 = {10, 7, 15, 4, 6};
//int result2 = findSecondSmallest(arr2);
//// Output: 6
//
// Example 3
//int[] arr3 = {3, 3, 1, 4, 5};
//int result3 = findSecondSmallest(arr3);
//// Output: 3

#include <iostream>
#include <climits>

int findSecondSmallest(int arr[], int size) {
    if (size < 2) {
        throw std::invalid_argument("Array must have at least two elements.");
    }

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        if (num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else if (num < secondSmallest && num != smallest) {
            secondSmallest = num;
        }
    }

    return secondSmallest;
}

int main() {
    // Test Case 1
    int arr1[] = {5, 2, 8, 3, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Test Case 1: Second Smallest Element = " << findSecondSmallest(arr1, size1) << std::endl;

    // Test Case 2
    int arr2[] = {10, 5, 7, 3, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Test Case 2: Second Smallest Element = " << findSecondSmallest(arr2, size2) << std::endl;

    // Test Case 3
    int arr10[] = {5, 2, 8, 3, 7, 1};
    int size10 = sizeof(arr10) / sizeof(arr10[0]);
    std::cout << "Test Case 3: Second Smallest Element = " << findSecondSmallest(arr10, size10) << std::endl;

    // Test Case 4
    int arr4[] = {9, 9, 5, 2, 8, 3, 7};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << "Test Case 4: Second Smallest Element = " << findSecondSmallest(arr4, size4) << std::endl;

    // Test Case 5
    int arr5[] = {5, 5, 5, 2, 8, 3, 7};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    std::cout << "Test Case 5: Second Smallest Element = " << findSecondSmallest(arr5, size5) << std::endl;

    // Test Case 6
    int arr6[] = {5, 2, 2, 8, 3, 7};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    std::cout << "Test Case 6: Second Smallest Element = " << findSecondSmallest(arr6, size6) << std::endl;

    // Test Case 7
    int arr7[] = {10, 10, 5, 7, 3, 2};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    std::cout << "Test Case 7: Second Smallest Element = " << findSecondSmallest(arr7, size7) << std::endl;

    // Test Case 8
    int arr8[] = {1, 2, 3, 4, 5};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    std::cout << "Test Case 8: Second Smallest Element = " << findSecondSmallest(arr8, size8) << std::endl;

    return 0;
}


//Sample output:
// Test Case 1: Second Smallest Element = 3
//Test Case 2: Second Smallest Element = 3
//Test Case 3: Second Smallest Element = 2
//Test Case 4: Second Smallest Element = 3
//Test Case 5: Second Smallest Element = 3
//Test Case 6: Second Smallest Element = 3
//Test Case 7: Second Smallest Element = 3
//Test Case 8: Second Smallest Element = 2


//****************************************************---****************************************************************

//  7. Problem Description: Reverse a String without Using the Reverse Function

//You are tasked with creating a C++ program to reverse a given string,
//without using the built-in reverse function or any other library functions that directly provide string reversal.
//The program should efficiently reverse the input string and return the result.

//Return a new string representing the reversed version of the input string.

// Example:
// Example 1
//String input1 = "Hello World";
//        String result1 = reverseString(input1);
// Output: "dlroW olleH"

// Example 2
//        String input2 = "Java Programming";
//        String result2 = reverseString(input2);
// Output: "gnimmargorP avaJ"

// Example 3
//        String input3 = "12345";
//        String result3 = reverseString(input3);
// Output: "54321"

#include <iostream>
#include <string>

std::string reverseString(std::string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        // Swap characters at left and right indices
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // Move indices towards the center
        left++;
        right--;
    }

    return str;
}

int main() {
    // Test Case 1
    std::string input1 = "Hello World";
    std::cout << "Test Case 1: Reversed String = " << reverseString(input1) << std::endl;

    // Test Case 2
    std::string input2 = "Java Programming";
    std::cout << "Test Case 2: Reversed String = " << reverseString(input2) << std::endl;

    // Test Case 3
    std::string input3 = "12345";
    std::cout << "Test Case 3: Reversed String = " << reverseString(input3) << std::endl;

    // Test Case 4
    std::string input4 = "a";
    std::cout << "Test Case 4: Reversed String = " << reverseString(input4) << std::endl;

    // Test Case 5
    std::string input5 = "";
    std::cout << "Test Case 5: Reversed String = " << reverseString(input5) << std::endl;

    return 0;
}


// sample output:
//Test Case 1: Reversed String = dlroW olleH
//Test Case 2: Reversed String = gnimmargorP avaJ
//Test Case 3: Reversed String = 54321
//Test Case 4: Reversed String = a
//Test Case 5: Reversed String =


//****************************************************---****************************************************************
//  8. Problem Description: Calculate Power of a Number using Recursion

//You are required to create a C++ program to calculate the power of a given number using recursion.
// The power of a number a raised to the power of b (denoted as a^b) is the product of multiplying a by itself b times.
// The program should efficiently calculate the power using recursion and return the result.

//Input:
//    base: An integer representing the base.
//    exponent: An integer representing the exponent.

//Output:
//    Returns the result of raising the base to the power of the exponent.

//Example:
// Example 1
//int base1 = 2;
//        int exponent1 = 3;
//        long result1 = calculatePower(base1, exponent1);
// Output: 8

// Example 2
//        int base2 = 5;
//        int exponent2 = 0;
//        long result2 = calculatePower(base2, exponent2);
// Output: 1

// Example 3
//        int base3 = 3;
//        int exponent3 = 4;
//        long result3 = calculatePower(base3, exponent3);
// Output: 81

//Notes:
//        The function should use recursion to calculate the power.

#include <iostream>

long calculatePower(int base, int exponent) {
    // Base case: any number raised to the power of 0 is 1
    if (exponent == 0) {
        return 1;
    }

    // Recursive case: calculate power using recursion
    return base * calculatePower(base, exponent - 1);
}

int main() {
    // Test Case 1
    int base1 = 2;
    int exponent1 = 3;
    std::cout << "Test Case 1: " << base1 << "^" << exponent1 << " = " << calculatePower(base1, exponent1) << std::endl;

    // Test Case 2
    int base2 = 5;
    int exponent2 = 0;
    std::cout << "Test Case 2: " << base2 << "^" << exponent2 << " = " << calculatePower(base2, exponent2) << std::endl;

    // Test Case 3
    int base3 = 3;
    int exponent3 = 4;
    std::cout << "Test Case 3: " << base3 << "^" << exponent3 << " = " << calculatePower(base3, exponent3) << std::endl;

    // Test Case 4
    int base4 = 7;
    int exponent4 = 2;
    std::cout << "Test Case 4: " << base4 << "^" << exponent4 << " = " << calculatePower(base4, exponent4) << std::endl;

    // Test Case 5
    int base5 = 1;
    int exponent5 = 5;
    std::cout << "Test Case 5: " << base5 << "^" << exponent5 << " = " << calculatePower(base5, exponent5) << std::endl;

    return 0;
}


// sample output:
// Test Case 1: 2^3 = 8
//Test Case 2: 5^0 = 1
//Test Case 3: 3^4 = 81
//Test Case 4: 7^2 = 49
//Test Case 5: 1^5 = 1

//****************************************************---****************************************************************
// 9. Reverse N-Number Triangle

//Aryan and his friends have a fascination for patterns.
// They want to create a reverse N-number triangle for a given positive integer 'N'.
// The reverse N-number triangle consists of rows where each row contains decreasing numbers starting from 'N' down to 1.

//  Input:
//        N: A positive integer representing the number of rows in the reverse number triangle.

//    Output:
//        Prints the reverse N-number triangle pattern as described.

#include <iostream>

void reverseNumberTriangle(int N) {
    // Iterate through each row
    for (int i = N; i >= 1; i--) {
        // Print numbers in decreasing order from 'N' to 'N - i + 1' for each row
        for (int j = N; j >= N - i + 1; j--) {
            std::cout << j;
        }
        std::cout << std::endl; // Move to the next line after printing each row
    }
}

int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    reverseNumberTriangle(5);

    std::cout << "\nTest Case 2:" << std::endl;
    reverseNumberTriangle(3);

    std::cout << "\nTest Case 3:" << std::endl;
    reverseNumberTriangle(7);

    return 0;
}


//sample output:
// Test Case 1:
//54321
//5432
//543
//54
//5

//Test Case 2:
//321
//32
//3

//Test Case 3:
//7654321
//765432
//76543
//7654
//765
//76
//7


//****************************************************---****************************************************************
// 10. : Right Angled Number Triangle

// You are tasked with creating a C++ program to generate a right-angled number triangle with a specified number of rows.
// Each row of the triangle contains consecutive odd numbers starting from 1.
// The first row contains 1, the second row contains 3 and 5, the third row contains 7, 9, and 11, and so on.

//Input:
//        rows: An integer representing the number of rows in the triangle.

//        Output:
//        Prints the right-angled number triangle pattern as described.

// Example
//Input: Enter number of rows: 5
//Output:
//1
//3 5
//7 9 11
//13 15 17 19
//21 23 25 27 29

//Notes:
//        The solution should efficiently generate and print the right-angled number triangle pattern.
//        The input rows will always be a positive integer.
//        The program should run without errors for valid input values.


#include <iostream>

// Function to print right-angled number triangle
void printRightAngledNumberTriangle(int rows) {
    int number = 1;

    // Iterate through each row
    for (int i = 1; i <= rows; i++) {
        // Print numbers in each row
        for (int j = 1; j <= i; j++) {
            std::cout << number << " ";
            number += 2; // Increment number by 2 for next odd number
        }
        std::cout << std::endl; // Move to the next line after printing each row
    }
}

// Main function for testing
int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    printRightAngledNumberTriangle(5);

    std::cout << "\nTest Case 2:" << std::endl;
    printRightAngledNumberTriangle(4);

    std::cout << "\nTest Case 3:" << std::endl;
    printRightAngledNumberTriangle(6);

    return 0;
}



// sample output:
//Test Case 1:
//        1
//        3 5
//        7 9 11
//        13 15 17 19
//        21 23 25 27 29

//        Test Case 2:
//        1
//        3 5
//        7 9 11
//        13 15 17 19

//        Test Case 3:
//        1
//        3 5
//        7 9 11
//        13 15 17 19
//        21 23 25 27 29
//        31 33 35 37 39 41



//****************************************************---****************************************************************
// 11. Right Angled Pattern 2

// You are tasked with creating a C++ program to generate a right-angled pattern with consecutive even numbers starting from 2.
// Each row of the pattern contains consecutive even numbers incremented by 2.
// The first row contains 2, the second row contains 4 and 6, the third row contains 8, 10, and 12, and so on.

//Input:
//    rows: An integer representing the number of rows in the pattern.

//Output:
//    Prints the right-angled pattern 2 as described.

// Example
//Input: Enter the number of rows: 5
//Output:
//2
//4 6
//8 10 12
//14 16 18 20
//22 24 26 28 30

//Notes:
//    The solution should efficiently generate and print the right-angled pattern 2.
//    The input rows will always be a positive integer.
//    The program should run without errors for valid input values.

#include <iostream>

// Function to print right-angled pattern 2
void printRightAngledPattern2(int rows) {
    int number = 2;

    // Iterate through each row
    for (int i = 1; i <= rows; i++) {
        // Print numbers in each row
        for (int j = 1; j <= i; j++) {
            std::cout << number << " ";
            number += 2; // Increment number by 2 for next even number
        }
        std::cout << std::endl; // Move to the next line after printing each row
    }
}

// Main function for testing
int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    printRightAngledPattern2(5);

    std::cout << "\nTest Case 2:" << std::endl;
    printRightAngledPattern2(4);

    std::cout << "\nTest Case 3:" << std::endl;
    printRightAngledPattern2(6);

    return 0;
}


// sample output:
// Test Case 1:
//2
//4 6
//8 10 12
//14 16 18 20
//22 24 26 28 30

//Test Case 2:
//2
//4 6
//8 10 12
//14 16 18 20

//Test Case 3:
//2
//4 6
//8 10 12
//14 16 18 20
//22 24 26 28 30
//32 34 36 38 40 42


//****************************************************---****************************************************************

// 12. Problem Description: Print Fibonacci Series

//You are tasked with creating a C++ program to generate and print the Fibonacci series up to a specified number of terms.
// The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, starting from 0 and 1.
// The sequence thus starts as 0, 1, 1, 2, 3, 5, 8, 13, 21, and so on.


//Input:
//    terms: An integer representing the number of terms in the Fibonacci series to generate and print.

//Output:
//    Prints the Fibonacci series up to the specified number of terms.


// Example
//Input: Enter the number of terms: 8
//Output:
//Fibonacci Series: 0 1 1 2 3 5 8 13 21

//Notes:
//    The solution should efficiently generate and print the Fibonacci series.
//    The input terms will always be a positive integer.
//    The program should run without errors for valid input values.

#include <iostream>

// Function to print Fibonacci series
void printFibonacciSeries(int terms) {
    int firstTerm = 0, secondTerm = 1;

    // Print the first two terms of Fibonacci series
    std::cout << "Fibonacci Series: " << firstTerm << " " << secondTerm;

    // Generate and print remaining terms
    for (int i = 2; i <= terms; i++) {
        int nextTerm = firstTerm + secondTerm;
        std::cout << " " << nextTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
}

// Main function for testing
int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    printFibonacciSeries(8);

    std::cout << "\nTest Case 2:" << std::endl;
    printFibonacciSeries(10);

    std::cout << "\nTest Case 3:" << std::endl;
    printFibonacciSeries(12);

    return 0;
}


// sample output:
// Test Case 1:
//Fibonacci Series: 0 1 1 2 3 5 8 13 21
//Test Case 2:
//Fibonacci Series: 0 1 1 2 3 5 8 13 21 34 55
//Test Case 3:
//Fibonacci Series: 0 1 1 2 3 5 8 13 21 34 55 89 144

//****************************************************---****************************************************************
// 13. Calculate Sum Excluding Multiples of 3

//You are tasked with creating a C++ program to calculate the sum of all numbers up to a given input, excluding the numbers that are divisible by 3.

//Input:
//    n: An integer representing the upper limit up to which the sum should be calculated (inclusive).

//Output:
//    Returns an integer representing the sum of numbers up to n, excluding those divisible by 3.

// Example
//Input: 8
//Output: 27
//Explanation: The sum of numbers up to 8 excluding multiples of 3: 1 + 2 + 4 + 5 + 7 + 8 = 27

//Notes:
//    The solution should efficiently calculate the sum excluding multiples of 3.
//    The input n will always be a non-negative integer.
//    The program should run without errors for valid input values.

#include <iostream>

// Function to calculate sum excluding multiples of 3
int sumExcludingMultiplesOfThree(int n) {
    int sum = 0;

    // Iterate through numbers up to n
    for (int i = 1; i <= n; i++) {
        // Add the number to sum if it's not divisible by 3
        if (i % 3 != 0) {
            sum += i;
        }
    }
    return sum;
}

// Main function for testing
int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    int result1 = sumExcludingMultiplesOfThree(8);
    std::cout << "Output: " << result1 << std::endl;

    std::cout << "\nTest Case 2:" << std::endl;
    int result2 = sumExcludingMultiplesOfThree(10);
    std::cout << "Output: " << result2 << std::endl;

    std::cout << "\nTest Case 3:" << std::endl;
    int result3 = sumExcludingMultiplesOfThree(12);
    std::cout << "Output: " << result3 << std::endl;

    return 0;
}


// sample output:
//Test Case 1:
//Output: 27

//Test Case 2:
//Output: 37

//Test Case 3:
//Output: 48

//****************************************************---****************************************************************
// 14. Reverse a Number

//You are tasked with creating a C++ program to reverse a given number.
// Given an input integer, the program should reverse the digits of the number and return the result.

//Input:
//    number: An integer representing the number to be reversed.

//Output:
//    Returns an integer representing the reversed number.

//Example
//Input: 3221
//Output: 1223

//Notes:
//    The solution should efficiently reverse the digits of the given number.
//    Ignore negative numbers, as reversing them would change the sign.
//    The program should run without errors for valid input values.

#include <iostream>
#include <cmath>

// Function to reverse a number
int reverseNumber(int number) {
    // Ensure number is positive
    number = std::abs(number);

    int reversedNumber = 0;

    // Reverse the digits of the number
    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    return reversedNumber;
}

// Main function for testing
int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    int result1 = reverseNumber(3221);
    std::cout << "Output: " << result1 << std::endl;

    std::cout << "\nTest Case 2:" << std::endl;
    int result2 = reverseNumber(12345);
    std::cout << "Output: " << result2 << std::endl;

    std::cout << "\nTest Case 3:" << std::endl;
    int result3 = reverseNumber(987654321);
    std::cout << "Output: " << result3 << std::endl;

    return 0;
}


// sample output:
// Test Case 1:
//Output: 1223

//Test Case 2:
//Output: 54321

//Test Case 3:
//Output: 123456789


//****************************************************---****************************************************************
// 15.  Check Palindrome Number

//You are tasked with creating a C++ program to determine whether a given number is a palindrome or not.
// A palindrome number is a number that remains the same when its digits are reversed.

//Input:
//    number: An integer representing the number to be checked for palindrome property.

//Output:
//    Returns a boolean value true if the given number is a palindrome, false otherwise.

//// Example
//Input: 1221
//Output: true
//Explanation: 1221 is a palindrome number.

//Input: 12345
//Output: false
//Explanation: 12345 is not a palindrome number.

//Notes:
//    The solution should efficiently determine whether the given number is a palindrome.
//    Ignore negative numbers, as reversing them would change the sign.
//    The program should run without errors for valid input values

#include <iostream>
#include <cmath>

// Function to check if a number is palindrome
bool isPalindrome(int number) {
    // Ensure number is positive
    number = std::abs(number);

    // Reverse the number
    int reversedNumber = 0;
    int originalNumber = number;

    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    // Check if original number is equal to reversed number
    return originalNumber == reversedNumber;
}

// Main function for testing
int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    int number1 = 1221;
    std::cout << "Input: " << number1 << std::endl;
    std::cout << "Output: " << std::boolalpha << isPalindrome(number1) << std::endl;

    std::cout << "\nTest Case 2:" << std::endl;
    int number2 = 12345;
    std::cout << "Input: " << number2 << std::endl;
    std::cout << "Output: " << std::boolalpha << isPalindrome(number2) << std::endl;

    std::cout << "\nTest Case 3:" << std::endl;
    int number3 = 12321;
    std::cout << "Input: " << number3 << std::endl;
    std::cout << "Output: " << std::boolalpha << isPalindrome(number3) << std::endl;

    return 0;
}

// sample output:
// Test Case 1:
//Input: 1221
//Output: true

//Test Case 2:
//Input: 12345
//Output: false

//Test Case 3:
//Input: 12321
//Output: true


//****************************************************---****************************************************************
// 16. Count Alphabetic Characters in a String

//You are tasked with creating a C++ program to count the number of alphabetic characters (letters) in a given string.
// Alphabetic characters include all uppercase and lowercase letters of the alphabet (A-Z, a-z).

//Input:
//    str: A string representing the input string in which alphabetic characters need to be counted.

//Output:
//    Returns an integer representing the count of alphabetic characters in the input string.

// Example
//Input: "Ja$#@ck"
//Output: 4
//Explanation: The string contains the alphabetic characters 'J', 'a', 'c', and 'k'.

//Input: "Hello World!"
//Output: 10
//Explanation: The string contains alphabetic characters from 'a' to 'z' and 'A' to 'Z'.

//Notes:
//    The solution should efficiently count the number of alphabetic characters in the given string.
//    Consider both uppercase and lowercase alphabetic characters.
//    Ignore non-alphabetic characters (e.g., digits, symbols, spaces).
//    The program should run without errors for valid input values.

#include <iostream>
#include <cctype>

// Function to count alphabetic characters in a string
int countAlphabeticCharacters(std::string str) {
    int count = 0;

    // Iterate through each character in the string
    for (char ch : str) {
        // Check if the character is alphabetic
        if (std::isalpha(ch)) {
            count++;
        }
    }

    return count;
}

// Main function for testing
int main() {
    // Test Cases
    std::cout << "Test Case 1:" << std::endl;
    std::string str1 = "Ja$#@ck";
    std::cout << "Input: " << str1 << std::endl;
    std::cout << "Output: " << countAlphabeticCharacters(str1) << std::endl;

    std::cout << "\nTest Case 2:" << std::endl;
    std::string str2 = "Hello World!";
    std::cout << "Input: " << str2 << std::endl;
    std::cout << "Output: " << countAlphabeticCharacters(str2) << std::endl;

    std::cout << "\nTest Case 3:" << std::endl;
    std::string str3 = "123ABCabcXYZxyz";
    std::cout << "Input: " << str3 << std::endl;
    std::cout << "Output: " << countAlphabeticCharacters(str3) << std::endl;

    return 0;
}


// sample output:
// Test Case 1:
//Input: Ja$#@ck
//Output: 4

//Test Case 2:
//Input: Hello World!
//Output: 10

//Test Case 3:
//Input: 123ABCabcXYZxyz
//Output: 12



//****************************************************---****************************************************************
// 17. Find Maximum and Minimum Elements in an Array

//You are required to implement a C++ program that finds the maximum and minimum elements in a given array of integers.

//Input
//    nums: An array of integers.

//Output:
//    Returns an array of two integers, where the first element represents the maximum element in the input array nums,
//    and the second element represents the minimum element in the array.

//// Example 1
//Input: [5, 2, 9, 3, 7]
//Output: [9, 2]

//// Example 2
//Input: [10, 20, 30, 40, 50]
//Output: [50, 10]

//// Example 3
//Input: [-5, -2, -9, -3, -7]
//Output: [-2, -9]

//Notes:
//    The input array may contain both positive and negative integers.
//    The array will not be empty, and it will contain at least one element.
//    The program should efficiently determine the maximum and minimum elements in the array.

#include <iostream>
#include <vector>
#include <climits>

// Function to find maximum and minimum elements in an array
std::vector<int> findMaxAndMin(std::vector<int>& nums) {
    std::vector<int> result(2);
    if (nums.empty()) {
        return result;
    }

    int max = nums[0];
    int min = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    result[0] = max;
    result[1] = min;

    return result;
}

// Main function for testing
int main() {
    // Test Cases
    std::vector<int> nums1 = {5, 2, 9, 3, 7};
    std::vector<int> result1 = findMaxAndMin(nums1);
    std::cout << "Test Case 1:" << std::endl;
    std::cout << "Input: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Output: Max = " << result1[0] << ", Min = " << result1[1] << std::endl;

    std::vector<int> nums2 = {10, 20, 30, 40, 50};
    std::vector<int> result2 = findMaxAndMin(nums2);
    std::cout << "\nTest Case 2:" << std::endl;
    std::cout << "Input: ";
    for (int num : nums2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Output: Max = " << result2[0] << ", Min = " << result2[1] << std::endl;

    std::vector<int> nums3 = {-5, -2, -9, -3, -7};
    std::vector<int> result3 = findMaxAndMin(nums3);
    std::cout << "\nTest Case 3:" << std::endl;
    std::cout << "Input: ";
    for (int num : nums3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Output: Max = " << result3[0] << ", Min = " << result3[1] << std::endl;

    return 0;
}


// sample output:
// Test Case 1:
//Input: [5, 2, 9, 3, 7]
//Output: Max = 9, Min = 2
//
//Test Case 2:
//Input: [10, 20, 30, 40, 50]
//Output: Max = 50, Min = 10
//
//Test Case 3:
//Input: [-5, -2, -9, -3, -7]
//Output: Max = -2, Min = -9

//****************************************************---****************************************************************
// 18. Product of Array Elements

//You are required to create a C++ program to find the product of all elements in a given integer array.

//Input:
//    nums: An integer array containing the elements whose product needs to be calculated.

//Output:
//    Returns a long integer representing the product of all elements in the input array.

//// Example 1
//Input: nums = {1, 2, 3, 4, 5}
//Output: 120
//Explanation: The product of all elements in the array {1, 2, 3, 4, 5} is 1 * 2 * 3 * 4 * 5 = 120.

//// Example 2
//Input: nums = {3, 7, 2, 8}
//Output: 336
//Explanation: The product of all elements in the array {3, 7, 2, 8} is 3 * 7 * 2 * 8 = 336.

//// Example 3
//Input: nums = {5}
//Output: 5
//Explanation: The product of all elements in the array {5} is 5.

//Notes:
//    The input array may contain both positive and negative integers.
//    The input array may have zero or multiple elements.
//    The product of array elements should be calculated and returned as a long integer.

#include <iostream>
#include <vector>

// Function to calculate the product of array elements
long long productOfArrayElements(const std::vector<int>& nums) {
    long long product = 1;
    for (int num : nums) {
        product *= num;
    }
    return product;
}

int main() {
    // Test Cases
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 4, 5},
        {3, 7, 2, 8},
        {5},
        {-1, -2, -3, -4, -5},
        {0},
        {10, 20, 30, 40}
    };

    for (const auto& nums : testCases) {
        std::cout << "Product of array elements: " << productOfArrayElements(nums) << std::endl;
    }

    return 0;
}


// sample output:
// Product of array elements: 120
//Product of array elements: 336
//Product of array elements: 5
//Product of array elements: -120
//Product of array elements: 0
//Product of array elements: 240000


//****************************************************---****************************************************************
// 19. Summation of Natural Numbers
//
//You are required to create a C++ program to calculate the summation of the first 'n' natural numbers.

//Input:
//    n: An integer representing the number of natural numbers for which the summation needs to be calculated.

//Output:
//    Returns an integer representing the summation of the first 'n' natural numbers.

//// Example 1
//Input: n = 5
//Output: 15
//Explanation: The summation of the first 5 natural numbers (1 + 2 + 3 + 4 + 5) is 15.

//// Example 2
//Input: n = 10
//Output: 55
//Explanation: The summation of the first 10 natural numbers (1 + 2 + 3 + ... + 10) is 55.

//// Example 3
//Input: n = 1
//Output: 1
//Explanation: The summation of the first 1 natural number (1) is 1.

//Notes:
//    The input 'n' represents the count of natural numbers for which the summation needs to be calculated.
//    The calculated summation should be returned as an integer.

#include <iostream>

// Function to calculate the sum of the first n natural numbers
int sumOfNaturalNumbers(int n) {
    // Calculate the summation using the formula (n * (n + 1)) / 2
    return (n * (n + 1)) / 2;
}

int main() {
    // Test Cases
    int numbers[] = {5, 10, 1, 100, 20, 30, 15};
    for (int n : numbers) {
        std::cout << "Summation of first " << n << " natural numbers: " << sumOfNaturalNumbers(n) << std::endl;
    }

    return 0;
}

// sample output:
// Summation of first 5 natural numbers: 15
//Summation of first 10 natural numbers: 55
//Summation of first 1 natural numbers: 1
//Summation of first 100 natural numbers: 5050
//Summation of first 20 natural numbers: 210
//Summation of first 30 natural numbers: 465
//Summation of first 15 natural numbers: 120


//****************************************************---****************************************************************
// 20. Problem Description: Find Factorial using Recursion

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


//****************************************************---****************************************************************
// 21. Problem Description: Find the Average of Elements in an Array

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



//****************************************************---****************************************************************
// 22. Problem Description: Count Even and Odd Numbers in an Array

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



//****************************************************---****************************************************************
// 23. Problem Description: Find the Maximum of Three Numbers

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


//****************************************************---****************************************************************
// 24. Sum of Digits

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

//****************************************************---****************************************************************
