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
//import java.util.Arrays;
//
//class TwoSum {
//
//    public static int[] twoSum(int[] nums, int target) {
//        int[] result = new int[2];
//
//        for (int i = 0; i < nums.length - 1; i++) {
//            for (int j = i + 1; j < nums.length; j++) {
//                if (nums[i] + nums[j] == target) {
//                    result[0] = i;
//                    result[1] = j;
//                    return result;
//                }
//            }
//        }
//
//        // If no solution is found
//        throw new IllegalArgumentException("No two elements sum up to the target");
//    }
//
//    public static void main(String[] args) {
//        // Test Case 1
//        int[] nums1 = {2, 7, 11, 15};
//        int target1 = 9;
//        System.out.println("Test Case 1: " + Arrays.toString(twoSum(nums1, target1)));
//
//        // Test Case 2
//        int[] nums2 = {3, 2, 4};
//        int target2 = 6;
//        System.out.println("Test Case 2: " + Arrays.toString(twoSum(nums2, target2)));
//
//        // Test Case 3
//        int[] nums3 = {3, 3};
//        int target3 = 6;
//        System.out.println("Test Case 3: " + Arrays.toString(twoSum(nums3, target3)));
//
//        // Test Case 4
//        int[] nums4 = {1, 2, 3, 4, 5};
//        int target4 = 9;
//        System.out.println("Additional Test Case 1: " + Arrays.toString(twoSum(nums4, target4)));
//
//        // Test Case 5
//        int[] nums5 = {-1, -2, -3, -4, -5};
//        int target5 = -8;
//        System.out.println("Additional Test Case 2: " + Arrays.toString(twoSum(nums5, target5)));
//
//    }
//}


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

//class CountVowels {
//
//    public static int countVowels(String str) {
//        int count = 0;
//        str = str.toLowerCase(); // Convert the string to lowercase for case-insensitivity
//
//        for (int i = 0; i < str.length(); i++) {
//            char ch = str.charAt(i);
//
//            // Check if the character is a vowel
//            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
//                count++;
//            }
//        }
//
//        return count;
//    }
//
//    public static void main(String[] args) {
//        // Test Case 1
//        String str1 = "Hello World";
//        System.out.println("Test Case 1: Number of vowels = " + countVowels(str1));
//
//        // Test Case 2
//        String str2 = "Programming is Fun";
//        System.out.println("Test Case 2: Number of vowels = " + countVowels(str2));
//
//        // Test Case 3
//        String str3 = "Java";
//        System.out.println("Test Case 3: Number of vowels = " + countVowels(str3));
//
//        // Test Case 4
//        String str4 = "Python";
//        System.out.println("Test Case 4: Number of vowels = " + countVowels(str4));
//
//        // Test Case 5
//        String str5 = "The quick brown fox jumps over the lazy dog";
//        System.out.println("Test Case 5: Number of vowels = " + countVowels(str5));
//
//        // Test Case 6 (Empty String)
//        String str6 = "";
//        System.out.println("Test Case 6: Number of vowels = " + countVowels(str6));
//    }
//}

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

//class CheckPrime {
//
//    public static boolean isPrime(int number) {
//        if (number <= 1) {
//            return false;
//        }
//
//        for (int i = 2; i <= Math.sqrt(number); i++) { // i < number if you want to iterate till the given number
//            if (number % i == 0) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    public static void main(String[] args) {
//        // Test Case 1
//        int num1 = 7;
//        System.out.println("Test Case 1: Is " + num1 + " prime? " + isPrime(num1));
//
//        // Test Case 2
//        int num2 = 15;
//        System.out.println("Test Case 2: Is " + num2 + " prime? " + isPrime(num2));
//
//        // Test Case 3
//        int num3 = 23;
//        System.out.println("Test Case 3: Is " + num3 + " prime? " + isPrime(num3));
//
//        // Test Case 4
//        int num4 = 1;
//        System.out.println("Test Case 4: Is " + num4 + " prime? " + isPrime(num4));
//
//        // Test Case 5
//        int num5 = 0;
//        System.out.println("Test Case 5: Is " + num5 + " prime? " + isPrime(num5));
//
//        // Test Case 6
//        int num6 = 97;
//        System.out.println("Test Case 6: Is " + num6 + " prime? " + isPrime(num6));
//    }
//}

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

//class CheckPalindrome {
//
//    public static boolean isPalindrome(String str) {
//        // Remove non-alphanumeric characters and convert to lowercase
//        String cleanStr = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
//
//        // Check if the cleaned string is a palindrome
//        int left = 0;
//        int right = cleanStr.length() - 1;
//
//        while (left < right) {
//            if (cleanStr.charAt(left) != cleanStr.charAt(right)) {
//                return false;
//            }
//            left++;
//            right--;
//        }
//
//        return true;
//    }
//
//    public static void main(String[] args) {
//        // Test Case 1
//        String str1 = "radar";
//        System.out.println("Test Case 1: Is \"" + str1 + "\" a palindrome? " + isPalindrome(str1));
//
//        // Test Case 2
//        String str2 = "Palindrome";
//        System.out.println("Test Case 2: Is \"" + str2 + "\" a palindrome? " + isPalindrome(str2));
//
//        // Test Case 3
//        String str3 = "A man, a plan, a canal, Panama";
//        System.out.println("Test Case 3: Is \"" + str3 + "\" a palindrome? " + isPalindrome(str3));
//
//        // Test Case 4
//        String str4 = "No lemon, no melon";
//        System.out.println("Test Case 4: Is \"" + str4 + "\" a palindrome? " + isPalindrome(str4));
//
//        // Test Case 5
//        String str5 = "Java";
//        System.out.println("Test Case 5: Is \"" + str5 + "\" a palindrome? " + isPalindrome(str5));
//    }
//}


// sample output:
// Test Case 1: Is "radar" a palindrome? true
//Test Case 2: Is "Palindrome" a palindrome? false
//Test Case 3: Is "A man, a plan, a canal, Panama" a palindrome? true
//Test Case 4: Is "No lemon, no melon" a palindrome? true
//Test Case 5: Is "Java" a palindrome? false