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
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    // If no solution is found
    *returnSize = 0;
    return NULL;
}

int main() {
    // Test Case 1
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int* result1 = twoSum(nums1, sizeof(nums1) / sizeof(nums1[0]), target1, &returnSize1);
    printf("Test Case 1: [%d, %d]\n", result1[0], result1[1]);
    free(result1);

    // Test Case 2
    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int* result2 = twoSum(nums2, sizeof(nums2) / sizeof(nums2[0]), target2, &returnSize2);
    printf("Test Case 2: [%d, %d]\n", result2[0], result2[1]);
    free(result2);

    // Test Case 3
    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int* result3 = twoSum(nums3, sizeof(nums3) / sizeof(nums3[0]), target3, &returnSize3);
    printf("Test Case 3: [%d, %d]\n", result3[0], result3[1]);
    free(result3);

    // Test Case 4
    int nums4[] = {1, 2, 3, 4, 5};
    int target4 = 9;
    int returnSize4;
    int* result4 = twoSum(nums4, sizeof(nums4) / sizeof(nums4[0]), target4, &returnSize4);
    printf("Additional Test Case 1: [%d, %d]\n", result4[0], result4[1]);
    free(result4);

    // Test Case 5
    int nums5[] = {-1, -2, -3, -4, -5};
    int target5 = -8;
    int returnSize5;
    int* result5 = twoSum(nums5, sizeof(nums5) / sizeof(nums5[0]), target5, &returnSize5);
    printf("Additional Test Case 2: [%d, %d]\n", result5[0], result5[1]);
    free(result5);

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

//You are tasked with creating a C program to count the number of vowels and consonants in a given string.
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

#include <stdio.h>
#include <ctype.h>

void countVowelsAndConsonants(char* str) {
    int vowelCount = 0;
    int consonantCount = 0;

    while (*str != '\0') {
        char ch = tolower(*str);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        } else if ((ch >= 'a' && ch <= 'z')) {
            consonantCount++;
        }

        str++;
    }

    printf("Number of vowels = %d\n", vowelCount);
    printf("Number of consonants = %d\n", consonantCount);
}

int main() {
    // Test Cases
    char str1[] = "Hello World";
    printf("Test Case 1:\n");
    countVowelsAndConsonants(str1);
    printf("\n");

    char str2[] = "Programming is Fun";
    printf("Test Case 2:\n");
    countVowelsAndConsonants(str2);
    printf("\n");

    char str3[] = "Java";
    printf("Test Case 3:\n");
    countVowelsAndConsonants(str3);
    printf("\n");

    char str4[] = "Python";
    printf("Test Case 4:\n");
    countVowelsAndConsonants(str4);
    printf("\n");

    char str5[] = "The quick brown fox jumps over the lazy dog";
    printf("Test Case 5:\n");
    countVowelsAndConsonants(str5);
    printf("\n");

    char str6[] = ""; // Empty String
    printf("Test Case 6:\n");
    countVowelsAndConsonants(str6);
    printf("\n");

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
//You are required to create a C program that determines whether a given number is prime or not.
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

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Test Cases
    int num1 = 7;
    printf("Test Case 1: Is %d prime? %s\n", num1, isPrime(num1) ? "true" : "false");

    int num2 = 15;
    printf("Test Case 2: Is %d prime? %s\n", num2, isPrime(num2) ? "true" : "false");

    int num3 = 23;
    printf("Test Case 3: Is %d prime? %s\n", num3, isPrime(num3) ? "true" : "false");

    int num4 = 1;
    printf("Test Case 4: Is %d prime? %s\n", num4, isPrime(num4) ? "true" : "false");

    int num5 = 0;
    printf("Test Case 5: Is %d prime? %s\n", num5, isPrime(num5) ? "true" : "false");

    int num6 = 97;
    printf("Test Case 6: Is %d prime? %s\n", num6, isPrime(num6) ? "true" : "false");

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

//You are tasked with creating a C program to determine whether a given string is a palindrome or not.
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

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(const char *str) {
    // Remove non-alphanumeric characters and convert to lowercase
    char cleanStr[1000];
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            cleanStr[j++] = tolower(str[i]);
        }
    }
    cleanStr[j] = '\0';

    // Check if the cleaned string is a palindrome
    int left = 0;
    int right = strlen(cleanStr) - 1;

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
    // Test Cases
    const char *str1 = "radar";
    printf("Test Case 1: Is \"%s\" a palindrome? %s\n", str1, isPalindrome(str1) ? "true" : "false");

    const char *str2 = "Palindrome";
    printf("Test Case 2: Is \"%s\" a palindrome? %s\n", str2, isPalindrome(str2) ? "true" : "false");

    const char *str3 = "A man, a plan, a canal, Panama";
    printf("Test Case 3: Is \"%s\" a palindrome? %s\n", str3, isPalindrome(str3) ? "true" : "false");

    const char *str4 = "No lemon, no melon";
    printf("Test Case 4: Is \"%s\" a palindrome? %s\n", str4, isPalindrome(str4) ? "true" : "false");

    const char *str5 = "Java";
    printf("Test Case 5: Is \"%s\" a palindrome? %s\n", str5, isPalindrome(str5) ? "true" : "false");

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

//You are required to create a C program to calculate the factorial of a given number.
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

#include <stdio.h>
#include <stdlib.h>

long calculateFactorial(int n) {
    if (n < 0) {
        printf("Input must be a non-negative integer.\n");
        exit(1);
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
    // Test Cases
    int num1 = 5;
    printf("Test Case 1: Factorial of %d = %ld\n", num1, calculateFactorial(num1));

    int num2 = 0;
    printf("Test Case 2: Factorial of %d = %ld\n", num2, calculateFactorial(num2));

    int num3 = 10;
    printf("Test Case 3: Factorial of %d = %ld\n", num3, calculateFactorial(num3));

    int num4 = 15;
    printf("Test Case 4: Factorial of %d = %ld\n", num4, calculateFactorial(num4));

    int num5 = 3;
    printf("Test Case 5: Factorial of %d = %ld\n", num5, calculateFactorial(num5));

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
//You are required to create a C program to find the second smallest element in an array of integers.
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

#include <stdio.h>
#include <limits.h>

int findSecondSmallest(int arr[], int size) {
    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return -1;
    }

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    return secondSmallest;
}

int main() {
    // Test Cases
    int arr1[] = {5, 2, 8, 3, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test Case 1: Second Smallest Element = %d\n", findSecondSmallest(arr1, size1));

    int arr2[] = {10, 5, 7, 3, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Test Case 2: Second Smallest Element = %d\n", findSecondSmallest(arr2, size2));

    int arr3[] = {5, 2, 8, 3, 7, 1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Test Case 3: Second Smallest Element = %d\n", findSecondSmallest(arr3, size3));

    int arr4[] = {9, 9, 5, 2, 8, 3, 7};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Test Case 4: Second Smallest Element = %d\n", findSecondSmallest(arr4, size4));

    int arr5[] = {5, 5, 5, 2, 8, 3, 7};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Test Case 5: Second Smallest Element = %d\n", findSecondSmallest(arr5, size5));

    int arr6[] = {5, 2, 2, 8, 3, 7};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    printf("Test Case 6: Second Smallest Element = %d\n", findSecondSmallest(arr6, size6));

    int arr7[] = {10, 10, 5, 7, 3, 2};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    printf("Test Case 7: Second Smallest Element = %d\n", findSecondSmallest(arr7, size7));

    int arr8[] = {1, 2, 3, 4, 5};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    printf("Test Case 8: Second Smallest Element = %d\n", findSecondSmallest(arr8, size8));

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

//You are tasked with creating a C program to reverse a given string,
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

#include <stdio.h>
#include <string.h>

char* reverseString(char* str) {
    int left = 0;
    int right = strlen(str) - 1;

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
    // Test Cases
    char input1[] = "Hello World";
    printf("Test Case 1: Reversed String = %s\n", reverseString(input1));

    char input2[] = "Java Programming";
    printf("Test Case 2: Reversed String = %s\n", reverseString(input2));

    char input3[] = "12345";
    printf("Test Case 3: Reversed String = %s\n", reverseString(input3));

    char input4[] = "a";
    printf("Test Case 4: Reversed String = %s\n", reverseString(input4));

    char input5[] = "";
    printf("Test Case 5: Reversed String = %s\n", reverseString(input5));

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

//You are required to create a C program to calculate the power of a given number using recursion.
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

#include <stdio.h>

long calculatePower(int base, int exponent) {
    // Base case: any number raised to the power of 0 is 1
    if (exponent == 0) {
        return 1;
    }

    // Recursive case: calculate power using recursion
    return base * calculatePower(base, exponent - 1);
}

int main() {
    // Test Cases
    int base1 = 2;
    int exponent1 = 3;
    printf("Test Case 1: %d^%d = %ld\n", base1, exponent1, calculatePower(base1, exponent1));

    int base2 = 5;
    int exponent2 = 0;
    printf("Test Case 2: %d^%d = %ld\n", base2, exponent2, calculatePower(base2, exponent2));

    int base3 = 3;
    int exponent3 = 4;
    printf("Test Case 3: %d^%d = %ld\n", base3, exponent3, calculatePower(base3, exponent3));

    int base4 = 7;
    int exponent4 = 2;
    printf("Test Case 4: %d^%d = %ld\n", base4, exponent4, calculatePower(base4, exponent4));

    int base5 = 1;
    int exponent5 = 5;
    printf("Test Case 5: %d^%d = %ld\n", base5, exponent5, calculatePower(base5, exponent5));

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

#include <stdio.h>

void reverseNumberTriangle(int N) {
    // Iterate through each row
    for (int i = N; i >= 1; i--) {
        // Print numbers in decreasing order from 'N' to 'N - i + 1' for each row
        for (int j = N; j >= N - i + 1; j--) {
            printf("%d", j);
        }
        printf("\n"); // Move to the next line after printing each row
    }
}

int main() {
    // Test Cases
    printf("Test Case 1:\n");
    reverseNumberTriangle(5);

    printf("\nTest Case 2:\n");
    reverseNumberTriangle(3);

    printf("\nTest Case 3:\n");
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

// You are tasked with creating a C program to generate a right-angled number triangle with a specified number of rows.
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


#include <stdio.h>

// Function to print right-angled number triangle
void printRightAngledNumberTriangle(int rows) {
    int number = 1;

    // Iterate through each row
    for (int i = 1; i <= rows; i++) {
        // Print numbers in each row
        for (int j = 1; j <= i; j++) {
            printf("%d ", number);
            number += 2; // Increment number by 2 for next odd number
        }
        printf("\n"); // Move to the next line after printing each row
    }
}

// Main function for testing
int main() {
    // Test Cases
    printf("Test Case 1:\n");
    printRightAngledNumberTriangle(5);

    printf("\nTest Case 2:\n");
    printRightAngledNumberTriangle(4);

    printf("\nTest Case 3:\n");
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

// You are tasked with creating a C program to generate a right-angled pattern with consecutive even numbers starting from 2.
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

#include <stdio.h>

// Function to print right-angled pattern 2
void printRightAngledPattern2(int rows) {
    int number = 2;

    // Iterate through each row
    for (int i = 1; i <= rows; i++) {
        // Print numbers in each row
        for (int j = 1; j <= i; j++) {
            printf("%d ", number);
            number += 2; // Increment number by 2 for next even number
        }
        printf("\n"); // Move to the next line after printing each row
    }
}

// Main function for testing
int main() {
    // Test Cases
    printf("Test Case 1:\n");
    printRightAngledPattern2(5);

    printf("\nTest Case 2:\n");
    printRightAngledPattern2(4);

    printf("\nTest Case 3:\n");
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

//You are tasked with creating a C program to generate and print the Fibonacci series up to a specified number of terms.
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

#include <stdio.h>

// Function to print Fibonacci series
void printFibonacciSeries(int terms) {
    int firstTerm = 0, secondTerm = 1;

    // Print the first two terms of Fibonacci series
    printf("Fibonacci Series: %d %d", firstTerm, secondTerm);

    // Generate and print remaining terms
    for (int i = 2; i <= terms; i++) {
        int nextTerm = firstTerm + secondTerm;
        printf(" %d", nextTerm);
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
}

// Main function for testing
int main() {
    // Test Cases
    printf("Test Case 1:\n");
    printFibonacciSeries(8);

    printf("\nTest Case 2:\n");
    printFibonacciSeries(10);

    printf("\nTest Case 3:\n");
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

//You are tasked with creating a C program to calculate the sum of all numbers up to a given input, excluding the numbers that are divisible by 3.

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

#include <stdio.h>

// Function to calculate sum excluding multiples of three
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
    printf("Test Case 1:\n");
    int result1 = sumExcludingMultiplesOfThree(8);
    printf("Output: %d\n", result1);

    printf("\nTest Case 2:\n");
    int result2 = sumExcludingMultiplesOfThree(10);
    printf("Output: %d\n", result2);

    printf("\nTest Case 3:\n");
    int result3 = sumExcludingMultiplesOfThree(12);
    printf("Output: %d\n", result3);

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

//You are tasked with creating a C program to reverse a given number.
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

#include <stdio.h>
#include <stdlib.h> // for abs function

// Function to reverse a number
int reverseNumber(int number) {
    // Ensure number is positive
    number = abs(number);

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
    printf("Test Case 1:\n");
    int result1 = reverseNumber(3221);
    printf("Output: %d\n", result1);

    printf("\nTest Case 2:\n");
    int result2 = reverseNumber(12345);
    printf("Output: %d\n", result2);

    printf("\nTest Case 3:\n");
    int result3 = reverseNumber(987654321);
    printf("Output: %d\n", result3);

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

//You are tasked with creating a C program to determine whether a given number is a palindrome or not.
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

#include <stdio.h>
#include <stdlib.h> // for abs function

// Function to check if a number is palindrome
int isPalindrome(int number) {
    // Ensure number is positive
    number = abs(number);

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
    printf("Test Case 1:\n");
    int number1 = 1221;
    printf("Input: %d\n", number1);
    printf("Output: %s\n", isPalindrome(number1) ? "true" : "false");

    printf("\nTest Case 2:\n");
    int number2 = 12345;
    printf("Input: %d\n", number2);
    printf("Output: %s\n", isPalindrome(number2) ? "true" : "false");

    printf("\nTest Case 3:\n");
    int number3 = 12321;
    printf("Input: %d\n", number3);
    printf("Output: %s\n", isPalindrome(number3) ? "true" : "false");

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

//You are tasked with creating a C program to count the number of alphabetic characters (letters) in a given string.
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

#include <stdio.h>
#include <ctype.h> // for isalpha function

// Function to count alphabetic characters in a string
int countAlphabeticCharacters(const char *str) {
    int count = 0;

    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Check if the character is alphabetic
        if (isalpha(ch)) {
            count++;
        }
    }

    return count;
}

// Main function for testing
int main() {
    // Test Cases
    printf("Test Case 1:\n");
    const char *str1 = "Ja$#@ck";
    printf("Input: %s\n", str1);
    printf("Output: %d\n", countAlphabeticCharacters(str1));

    printf("\nTest Case 2:\n");
    const char *str2 = "Hello World!";
    printf("Input: %s\n", str2);
    printf("Output: %d\n", countAlphabeticCharacters(str2));

    printf("\nTest Case 3:\n");
    const char *str3 = "123ABCabcXYZxyz";
    printf("Input: %s\n", str3);
    printf("Output: %d\n", countAlphabeticCharacters(str3));

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

//You are required to implement a C program that finds the maximum and minimum elements in a given array of integers.

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

#include <stdio.h>

// Function to find maximum and minimum elements in an array
void findMaxAndMin(int nums[], int size, int result[]) {
    if (size == 0) {
        result[0] = result[1] = 0; // default values for empty array
        return;
    }

    int max = nums[0];
    int min = nums[0];

    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    result[0] = max;
    result[1] = min;
}

// Main function for testing
int main() {
    // Test Cases
    int nums1[] = {5, 2, 9, 3, 7};
    int result1[2];
    findMaxAndMin(nums1, sizeof(nums1) / sizeof(nums1[0]), result1);
    printf("Test Case 1:\n");
    printf("Input: ");
    for (int i = 0; i < sizeof(nums1) / sizeof(nums1[0]); i++) {
        printf("%d ", nums1[i]);
    }
    printf("\nOutput: Max = %d, Min = %d\n", result1[0], result1[1]);

    int nums2[] = {10, 20, 30, 40, 50};
    int result2[2];
    findMaxAndMin(nums2, sizeof(nums2) / sizeof(nums2[0]), result2);
    printf("\nTest Case 2:\n");
    printf("Input: ");
    for (int i = 0; i < sizeof(nums2) / sizeof(nums2[0]); i++) {
        printf("%d ", nums2[i]);
    }
    printf("\nOutput: Max = %d, Min = %d\n", result2[0], result2[1]);

    int nums3[] = {-5, -2, -9, -3, -7};
    int result3[2];
    findMaxAndMin(nums3, sizeof(nums3) / sizeof(nums3[0]), result3);
    printf("\nTest Case 3:\n");
    printf("Input: ");
    for (int i = 0; i < sizeof(nums3) / sizeof(nums3[0]); i++) {
        printf("%d ", nums3[i]);
    }
    printf("\nOutput: Max = %d, Min = %d\n", result3[0], result3[1]);

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

// 18. Product of Array Elements ***(skipped this question for C language)***

//You are required to create a C program to find the product of all elements in a given integer array.

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
//You are required to create a C program to calculate the summation of the first 'n' natural numbers.

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

#include <stdio.h>

// Function to calculate the sum of the first n natural numbers
int sumOfNaturalNumbers(int n) {
    // Calculate the summation using the formula (n * (n + 1)) / 2
    return (n * (n + 1)) / 2;
}

// Main function for testing
int main() {
    // Test Cases
    int numbers[] = {5, 10, 1, 100, 20, 30, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++) {
        int n = numbers[i];
        printf("Summation of first %d natural numbers: %d\n", n, sumOfNaturalNumbers(n));
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
