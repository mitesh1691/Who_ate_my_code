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


//  2. Problem Description: Count Vowels and Consonants in a String

//You are tasked with creating a Java program to count the number of vowels and consonants in a given string.
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

class CountVowelsAndConsonants {

    public static void countVowelsAndConsonants(String str) {
        int vowelCount = 0;
        int consonantCount = 0;
        str = str.toLowerCase(); // Convert the string to lowercase for case-insensitivity

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            // Check if the character is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            // Check if the character is a consonant
            else if ((ch >= 'a' && ch <= 'z')) {
                consonantCount++;
            }
        }

        System.out.println("Number of vowels = " + vowelCount);
        System.out.println("Number of consonants = " + consonantCount);
    }

    public static void main(String[] args) {
        // Test Case 1
        String str1 = "Hello World";
        System.out.println("Test Case 1:");
        countVowelsAndConsonants(str1);
        System.out.println();

        // Test Case 2
        String str2 = "Programming is Fun";
        System.out.println("Test Case 2:");
        countVowelsAndConsonants(str2);
        System.out.println();

        // Test Case 3
        String str3 = "Java";
        System.out.println("Test Case 3:");
        countVowelsAndConsonants(str3);
        System.out.println();

        // Test Case 4
        String str4 = "Python";
        System.out.println("Test Case 4:");
        countVowelsAndConsonants(str4);
        System.out.println();

        // Test Case 5
        String str5 = "The quick brown fox jumps over the lazy dog";
        System.out.println("Test Case 5:");
        countVowelsAndConsonants(str5);
        System.out.println();

        // Test Case 6 (Empty String)
        String str6 = "";
        System.out.println("Test Case 6:");
        countVowelsAndConsonants(str6);
        System.out.println();
    }
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

//****************************************************---****************************************************************
// 9. Reverse N-Number Triangle

//Aryan and his friends have a fascination for patterns.
// They want to create a reverse N-number triangle for a given positive integer 'N'.
// The reverse N-number triangle consists of rows where each row contains decreasing numbers starting from 'N' down to 1.

//  Input:
//        N: A positive integer representing the number of rows in the reverse number triangle.

//    Output:
//        Prints the reverse N-number triangle pattern as described.
class ReverseNumberTriangle {
    public static void reverseNumberTriangle(int N) {
        // Iterate through each row
        for (int i = N; i >= 1; i--) {
            // Print numbers in decreasing order from 'N' to 'N - i + 1' for each row
            for (int j = N; j >= N - i + 1; j--) {
                System.out.print(j);
            }
            System.out.println(); // Move to the next line after printing each row
        }
    }

    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        reverseNumberTriangle(5);

        System.out.println("\nTest Case 2:");
        reverseNumberTriangle(3);

        System.out.println("\nTest Case 3:");
        reverseNumberTriangle(7);
    }
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

// You are tasked with creating a Java program to generate a right-angled number triangle with a specified number of rows.
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


 class RightAngledNumberTriangle {

    // Method to print right-angled number triangle
    public static void printRightAngledNumberTriangle(int rows) {
        int number = 1;

        // Iterate through each row
        for (int i = 1; i <= rows; i++) {
            // Print numbers in each row
            for (int j = 1; j <= i; j++) {
                System.out.print(number + " ");
                number += 2; // Increment number by 2 for next odd number
            }
            System.out.println(); // Move to the next line after printing each row
        }
    }

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        printRightAngledNumberTriangle(5);

        System.out.println("\nTest Case 2:");
        printRightAngledNumberTriangle(4);

        System.out.println("\nTest Case 3:");
        printRightAngledNumberTriangle(6);
    }
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

// You are tasked with creating a Java program to generate a right-angled pattern with consecutive even numbers starting from 2.
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

class RightAngledPattern2 {

    // Method to print right-angled pattern 2
    public static void printRightAngledPattern2(int rows) {
        int number = 2;

        // Iterate through each row
        for (int i = 1; i <= rows; i++) {
            // Print numbers in each row
            for (int j = 1; j <= i; j++) {
                System.out.print(number + " ");
                number += 2; // Increment number by 2 for next even number
            }
            System.out.println(); // Move to the next line after printing each row
        }
    }

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        printRightAngledPattern2(5);

        System.out.println("\nTest Case 2:");
        printRightAngledPattern2(4);

        System.out.println("\nTest Case 3:");
        printRightAngledPattern2(6);
    }
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

//You are tasked with creating a Java program to generate and print the Fibonacci series up to a specified number of terms.
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

class FibonacciSeries {

    // Method to print Fibonacci series
    public static void printFibonacciSeries(int terms) {
        int firstTerm = 0, secondTerm = 1;

        // Print the first two terms of Fibonacci series
        System.out.print("Fibonacci Series: " + firstTerm + " " + secondTerm);

        // Generate and print remaining terms
        for (int i = 2; i <= terms; i++) {
            int nextTerm = firstTerm + secondTerm;
            System.out.print(" " + nextTerm);
            firstTerm = secondTerm;
            secondTerm = nextTerm;
        }
    }

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        printFibonacciSeries(8);

        System.out.println("\nTest Case 2:");
        printFibonacciSeries(10);

        System.out.println("\nTest Case 3:");
        printFibonacciSeries(12);
    }
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

//You are tasked with creating a Java program to calculate the sum of all numbers up to a given input, excluding the numbers that are divisible by 3.

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

class SumExcludingMultiplesOfThree {

    // Method to calculate sum excluding multiples of 3
    public static int sumExcludingMultiplesOfThree(int n) {
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

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        int result1 = sumExcludingMultiplesOfThree(8);
        System.out.println("Output: " + result1);

        System.out.println("\nTest Case 2:");
        int result2 = sumExcludingMultiplesOfThree(10);
        System.out.println("Output: " + result2);

        System.out.println("\nTest Case 3:");
        int result3 = sumExcludingMultiplesOfThree(12);
        System.out.println("Output: " + result3);
    }
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

//You are tasked with creating a Java program to reverse a given number.
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

class ReverseNumber {

    // Method to reverse a number
    public static int reverseNumber(int number) {
        // Ensure number is positive
        number = Math.abs(number);

        int reversedNumber = 0;

        // Reverse the digits of the number
        while (number > 0) {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }

        return reversedNumber;
    }

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        int result1 = reverseNumber(3221);
        System.out.println("Output: " + result1);

        System.out.println("\nTest Case 2:");
        int result2 = reverseNumber(12345);
        System.out.println("Output: " + result2);

        System.out.println("\nTest Case 3:");
        int result3 = reverseNumber(987654321);
        System.out.println("Output: " + result3);
    }
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

//You are tasked with creating a Java program to determine whether a given number is a palindrome or not.
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

class PalindromeNumber {

    // Method to check if a number is palindrome
    public static boolean isPalindrome(int number) {
        // Ensure number is positive
        number = Math.abs(number);

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

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        int number1 = 1221;
        System.out.println("Input: " + number1);
        System.out.println("Output: " + isPalindrome(number1));

        System.out.println("\nTest Case 2:");
        int number2 = 12345;
        System.out.println("Input: " + number2);
        System.out.println("Output: " + isPalindrome(number2));

        System.out.println("\nTest Case 3:");
        int number3 = 12321;
        System.out.println("Input: " + number3);
        System.out.println("Output: " + isPalindrome(number3));
    }
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

//You are tasked with creating a Java program to count the number of alphabetic characters (letters) in a given string.
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

class CountAlphabeticCharacters {

    // Method to count alphabetic characters in a string
    public static int countAlphabeticCharacters(String str) {
        int count = 0;

        // Iterate through each character in the string
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            // Check if the character is alphabetic
            if (Character.isLetter(ch)) {
                count++;
            }
        }

        return count;
    }

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        String str1 = "Ja$#@ck";
        System.out.println("Input: " + str1);
        System.out.println("Output: " + countAlphabeticCharacters(str1));

        System.out.println("\nTest Case 2:");
        String str2 = "Hello World!";
        System.out.println("Input: " + str2);
        System.out.println("Output: " + countAlphabeticCharacters(str2));

        System.out.println("\nTest Case 3:");
        String str3 = "123ABCabcXYZxyz";
        System.out.println("Input: " + str3);
        System.out.println("Output: " + countAlphabeticCharacters(str3));
    }
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

//You are required to implement a Java program that finds the maximum and minimum elements in a given array of integers.

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


//import java.util.Arrays;
class MaxMinInArray { // import arrays

    // Method to find maximum and minimum elements in an array
    public static int[] findMaxAndMin(int[] nums) {
        int[] result = new int[2];
        if (nums == null || nums.length == 0) {
            return result;
        }

        int max = nums[0];
        int min = nums[0];

        for (int i = 1; i < nums.length; i++) {
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

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        int[] nums1 = {5, 2, 9, 3, 7};
        int[] result1 = findMaxAndMin(nums1);
        System.out.println("Test Case 1:");
        System.out.println("Input: " + Arrays.toString(nums1));
        System.out.println("Output: Max = " + result1[0] + ", Min = " + result1[1]);

        int[] nums2 = {10, 20, 30, 40, 50};
        int[] result2 = findMaxAndMin(nums2);
        System.out.println("\nTest Case 2:");
        System.out.println("Input: " + Arrays.toString(nums2));
        System.out.println("Output: Max = " + result2[0] + ", Min = " + result2[1]);

        int[] nums3 = {-5, -2, -9, -3, -7};
        int[] result3 = findMaxAndMin(nums3);
        System.out.println("\nTest Case 3:");
        System.out.println("Input: " + Arrays.toString(nums3));
        System.out.println("Output: Max = " + result3[0] + ", Min = " + result3[1]);
    }
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

//You are required to create a Java program to find the product of all elements in a given integer array.

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

class ProductOfArrayElements {

    public static long productOfArrayElements(int[] nums) {
        long product = 1;
        for (int num : nums) {
            product *= num;
        }
        return product;
    }

    public static void main(String[] args) {
        // Test Cases
        int[][] testCases = {
                {1, 2, 3, 4, 5},
                {3, 7, 2, 8},
                {5},
                {-1, -2, -3, -4, -5},
                {0},
                {10, 20, 30, 40}
        };

        for (int[] nums : testCases) {
            System.out.println("Product of array elements: " + productOfArrayElements(nums));
        }
    }
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
//You are required to create a Java program to calculate the summation of the first 'n' natural numbers.

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

class SumOfNaturalNumbers {

    public static int sumOfNaturalNumbers(int n) {
        // Calculate the summation using the formula (n * (n + 1)) / 2
        return (n * (n + 1)) / 2;
    }

    public static void main(String[] args) {
        // Test Cases
        int[] numbers = {5, 10, 1, 100, 20, 30, 15};
        for (int n : numbers) {
            System.out.println("Summation of first " + n + " natural numbers: " + sumOfNaturalNumbers(n));
        }
    }
}

// sample output:
// Summation of first 5 natural numbers: 15
//Summation of first 10 natural numbers: 55
//Summation of first 1 natural numbers: 1
//Summation of first 100 natural numbers: 5050
//Summation of first 20 natural numbers: 210
//Summation of first 30 natural numbers: 465
//Summation of first 15 natural numbers: 120
