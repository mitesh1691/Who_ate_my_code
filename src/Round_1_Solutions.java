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
import java.util.Arrays;

class TwoSum {

    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];

        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }

        // If no solution is found
        throw new IllegalArgumentException("No two elements sum up to the target");
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;
        System.out.println("Test Case 1: " + Arrays.toString(twoSum(nums1, target1)));

        // Test Case 2
        int[] nums2 = {3, 2, 4};
        int target2 = 6;
        System.out.println("Test Case 2: " + Arrays.toString(twoSum(nums2, target2)));

        // Test Case 3
        int[] nums3 = {3, 3};
        int target3 = 6;
        System.out.println("Test Case 3: " + Arrays.toString(twoSum(nums3, target3)));

        // Test Case 4
        int[] nums4 = {1, 2, 3, 4, 5};
        int target4 = 9;
        System.out.println("Additional Test Case 1: " + Arrays.toString(twoSum(nums4, target4)));

        // Test Case 5
        int[] nums5 = {-1, -2, -3, -4, -5};
        int target5 = -8;
        System.out.println("Additional Test Case 2: " + Arrays.toString(twoSum(nums5, target5)));

    }
}


//sample output:
//
//        Test Case 1: [0, 1]
//        Test Case 2: [1, 2]
//        Test Case 3: [0, 1]
//        Additional Test Case 1: [3, 4]
//        Additional Test Case 2: [2, 4]

//******************************************************---****************************************************************


//  2. Problem Description: Count Vowels in a String

//You are tasked with creating a Java program to count the number of vowels in a given string.
// Vowels are defined as the letters 'a', 'e', 'i', 'o', and 'u', and the program should be case-insensitive.
// The goal is to provide a robust solution that efficiently determines the count of vowels in any given input string.

//Returns an integer representing the count of vowels in the input string.

class CountVowels {

    public static int countVowels(String str) {
        int count = 0;
        str = str.toLowerCase(); // Convert the string to lowercase for case-insensitivity

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            // Check if the character is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        // Test Case 1
        String str1 = "Hello World";
        System.out.println("Test Case 1: Number of vowels = " + countVowels(str1));

        // Test Case 2
        String str2 = "Programming is Fun";
        System.out.println("Test Case 2: Number of vowels = " + countVowels(str2));

        // Test Case 3
        String str3 = "Java";
        System.out.println("Test Case 3: Number of vowels = " + countVowels(str3));

        // Test Case 4
        String str4 = "Python";
        System.out.println("Test Case 4: Number of vowels = " + countVowels(str4));

        // Test Case 5
        String str5 = "The quick brown fox jumps over the lazy dog";
        System.out.println("Test Case 5: Number of vowels = " + countVowels(str5));

        // Test Case 6 (Empty String)
        String str6 = "";
        System.out.println("Test Case 6: Number of vowels = " + countVowels(str6));
    }
}

// sample output:
//          Test Case 1: Number of vowels = 3
//        Test Case 2: Number of vowels = 5
//        Test Case 3: Number of vowels = 2
//        Test Case 4: Number of vowels = 1
//        Test Case 5: Number of vowels = 11
//        Test Case 6: Number of vowels = 0


//****************************************************---****************************************************************

//  3. Problem Description: Check Prime Number
//
//You are required to create a Java program that determines whether a given number is prime or not.
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

class CheckPrime {

    public static boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }

        for (int i = 2; i <= Math.sqrt(number); i++) { // i < number if you want to iterate till the given number
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        // Test Case 1
        int num1 = 7;
        System.out.println("Test Case 1: Is " + num1 + " prime? " + isPrime(num1));

        // Test Case 2
        int num2 = 15;
        System.out.println("Test Case 2: Is " + num2 + " prime? " + isPrime(num2));

        // Test Case 3
        int num3 = 23;
        System.out.println("Test Case 3: Is " + num3 + " prime? " + isPrime(num3));

        // Test Case 4
        int num4 = 1;
        System.out.println("Test Case 4: Is " + num4 + " prime? " + isPrime(num4));

        // Test Case 5
        int num5 = 0;
        System.out.println("Test Case 5: Is " + num5 + " prime? " + isPrime(num5));

        // Test Case 6
        int num6 = 97;
        System.out.println("Test Case 6: Is " + num6 + " prime? " + isPrime(num6));
    }
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

//You are tasked with creating a Java program to determine whether a given string is a palindrome or not.
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

class CheckPalindrome {

    public static boolean isPalindrome(String str) {
        // Remove non-alphanumeric characters and convert to lowercase
        String cleanStr = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();

        // Check if the cleaned string is a palindrome
        int left = 0;
        int right = cleanStr.length() - 1;

        while (left < right) {
            if (cleanStr.charAt(left) != cleanStr.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {
        // Test Case 1
        String str1 = "radar";
        System.out.println("Test Case 1: Is \"" + str1 + "\" a palindrome? " + isPalindrome(str1));

        // Test Case 2
        String str2 = "Palindrome";
        System.out.println("Test Case 2: Is \"" + str2 + "\" a palindrome? " + isPalindrome(str2));

        // Test Case 3
        String str3 = "A man, a plan, a canal, Panama";
        System.out.println("Test Case 3: Is \"" + str3 + "\" a palindrome? " + isPalindrome(str3));

        // Test Case 4
        String str4 = "No lemon, no melon";
        System.out.println("Test Case 4: Is \"" + str4 + "\" a palindrome? " + isPalindrome(str4));

        // Test Case 5
        String str5 = "Java";
        System.out.println("Test Case 5: Is \"" + str5 + "\" a palindrome? " + isPalindrome(str5));
    }
}


// sample output:
// Test Case 1: Is "radar" a palindrome? true
//Test Case 2: Is "Palindrome" a palindrome? false
//Test Case 3: Is "A man, a plan, a canal, Panama" a palindrome? true
//Test Case 4: Is "No lemon, no melon" a palindrome? true
//Test Case 5: Is "Java" a palindrome? false


//****************************************************---****************************************************************

//  5. Problem Description: Find Factorial of a Number

//You are required to create a Java program to calculate the factorial of a given number.
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

class Factorial {

    public static long calculateFactorial(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input must be a non-negative integer.");
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

    public static void main(String[] args) {
        // Test Case 1
        int num1 = 5;
        System.out.println("Test Case 1: Factorial of " + num1 + " = " + calculateFactorial(num1));

        // Test Case 2
        int num2 = 0;
        System.out.println("Test Case 2: Factorial of " + num2 + " = " + calculateFactorial(num2));

        // Test Case 3
        int num3 = 10;
        System.out.println("Test Case 3: Factorial of " + num3 + " = " + calculateFactorial(num3));

        // Test Case 4
        int num4 = 15;
        System.out.println("Test Case 4: Factorial of " + num4 + " = " + calculateFactorial(num4));

        // Test Case 5
        int num5 = 3;
        System.out.println("Test Case 5: Factorial of " + num5 + " = " + calculateFactorial(num5));
    }
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
//You are required to create a Java program to find the second smallest element in an array of integers.
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

class SecondSmallestElement {

    public static int findSecondSmallest(int[] arr) {
        if (arr == null || arr.length < 2) {
            throw new IllegalArgumentException("Array must have at least two elements.");
        }

        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;

        for (int num : arr) {
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else if (num < secondSmallest && num != smallest) {
                secondSmallest = num;
            }
        }

        return secondSmallest;
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {5, 2, 8, 3, 7};
        System.out.println("Test Case 1: Second Smallest Element = " + findSecondSmallest(arr1));

        // Test Case 2
        int[] arr2 = {10, 5, 7, 3, 2};
        System.out.println("Test Case 2: Second Smallest Element = " + findSecondSmallest(arr2));

        // Test Case 3
        int[] arr10 = {5, 2, 8, 3, 7, 1};
        System.out.println("Test Case 3: Second Smallest Element = " + findSecondSmallest(arr10));

        // Test Case 4
        int[] arr4 = {9, 9, 5, 2, 8, 3, 7};
        System.out.println("Test Case 4: Second Smallest Element = " + findSecondSmallest(arr4));

        // Test Case 5
        int[] arr5 = {5, 5, 5, 2, 8, 3, 7};
        System.out.println("Test Case 5: Second Smallest Element = " + findSecondSmallest(arr5));

        // Test Case 6
        int[] arr6 = {5, 2, 2, 8, 3, 7};
        System.out.println("Test Case 6: Second Smallest Element = " + findSecondSmallest(arr6));

        // Test Case 7
        int[] arr7 = {10, 10, 5, 7, 3, 2};
        System.out.println("Test Case 7: Second Smallest Element = " + findSecondSmallest(arr7));

        // Test Case 8
        int[] arr8 = {1, 2, 3, 4, 5};
        System.out.println("Test Case 8: Second Smallest Element = " + findSecondSmallest(arr8));
    }
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

//You are tasked with creating a Java program to reverse a given string,
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

class ReverseString {

    public static String reverseString(String str) {
        char[] charArray = str.toCharArray();
        int left = 0;
        int right = charArray.length - 1;

        while (left < right) {
            // Swap characters at left and right indices
            char temp = charArray[left];
            charArray[left] = charArray[right];
            charArray[right] = temp;

            // Move indices towards the center
            left++;
            right--;
        }

        return new String(charArray);
    }

    public static void main(String[] args) {
        // Test Case 1
        String input1 = "Hello World";
        System.out.println("Test Case 1: Reversed String = " + reverseString(input1));

        // Test Case 2
        String input2 = "Java Programming";
        System.out.println("Test Case 2: Reversed String = " + reverseString(input2));

        // Test Case 3
        String input3 = "12345";
        System.out.println("Test Case 3: Reversed String = " + reverseString(input3));

        // Test Case 4
        String input4 = "a";
        System.out.println("Test Case 4: Reversed String = " + reverseString(input4));

        // Test Case 5
        String input5 = "";
        System.out.println("Test Case 5: Reversed String = " + reverseString(input5));
    }
}

// sample output:
//Test Case 1: Reversed String = dlroW olleH
//Test Case 2: Reversed String = gnimmargorP avaJ
//Test Case 3: Reversed String = 54321
//Test Case 4: Reversed String = a
//Test Case 5: Reversed String =


//****************************************************---****************************************************************
//  8. Problem Description: Calculate Power of a Number using Recursion

//You are required to create a Java program to calculate the power of a given number using recursion.
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

class PowerCalculator {

    public static long calculatePower(int base, int exponent) {
        // Base case: any number raised to the power of 0 is 1
        if (exponent == 0) {
            return 1;
        }

        // Recursive case: calculate power using recursion
        return base * calculatePower(base, exponent - 1);
    }

    public static void main(String[] args) {
        // Test Case 1
        int base1 = 2;
        int exponent1 = 3;
        System.out.println("Test Case 1: " + base1 + "^" + exponent1 + " = " + calculatePower(base1, exponent1));

        // Test Case 2
        int base2 = 5;
        int exponent2 = 0;
        System.out.println("Test Case 2: " + base2 + "^" + exponent2 + " = " + calculatePower(base2, exponent2));

        // Test Case 3
        int base3 = 3;
        int exponent3 = 4;
        System.out.println("Test Case 3: " + base3 + "^" + exponent3 + " = " + calculatePower(base3, exponent3));

        // Test Case 4
        int base4 = 7;
        int exponent4 = 2;
        System.out.println("Test Case 4: " + base4 + "^" + exponent4 + " = " + calculatePower(base4, exponent4));

        // Test Case 5
        int base5 = 1;
        int exponent5 = 5;
        System.out.println("Test Case 5: " + base5 + "^" + exponent5 + " = " + calculatePower(base5, exponent5));
    }
}

// sample output:
// Test Case 1: 2^3 = 8
//Test Case 2: 5^0 = 1
//Test Case 3: 3^4 = 81
//Test Case 4: 7^2 = 49
//Test Case 5: 1^5 = 1

