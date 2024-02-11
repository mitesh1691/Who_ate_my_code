//******************************************************---****************************************************************

//  1. Problem Description: Check if Two Strings are Anagrams

//You are tasked with creating a Java program to determine whether two strings are anagrams of each other.
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

import java.util.Arrays;

class AnagramChecker {

    public static boolean areAnagrams(String str1, String str2) {
        if (str1 == null || str2 == null || str1.length() != str2.length()) {
            return false;
        }

        int[] charCount = new int[26]; // Assuming only lowercase alphabets, adjust if considering uppercase as well

        // Count the frequency of characters in str1
        for (char c : str1.toLowerCase().toCharArray()) {
            if (Character.isLetter(c)) {
                charCount[c - 'a']++;
            }
        }

        // Decrement the frequency of characters in str2
        for (char c : str2.toLowerCase().toCharArray()) {
            if (Character.isLetter(c)) {
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

    public static void main(String[] args) {
        // Test Case 1
        String s1 = "listen";
        String s2 = "silent";
        System.out.println("Test Case 1: Are Anagrams? " + areAnagrams(s1, s2));

        // Test Case 2
        String s3 = "Java";
        String s4 = "jAvA";
        System.out.println("Test Case 2: Are Anagrams? " + areAnagrams(s3, s4));

        // Test Case 3
        String s5 = "Hello";
        String s6 = "World";
        System.out.println("Test Case 3: Are Anagrams? " + areAnagrams(s5, s6));

        // Test Case 4
        String s7 = "Astronomer";
        String s8 = "Moon starer";
        System.out.println("Test Case 4: Are Anagrams? " + areAnagrams(s7, s8));

        // Test Case 5
        String s9 = "AABB";
        String s10 = "ABAB";
        System.out.println("Test Case 5: Are Anagrams? " + areAnagrams(s9, s10));

        // Test Case 6
        String s11 = "A gentleman";
        String s12 = "Elegant man";
        System.out.println("Test Case 6: Are Anagrams? " + areAnagrams(s11, s12));

        // Test Case 7
        String s13 = "Debit card";
        String s14 = "Bad credit";
        System.out.println("Test Case 7: Are Anagrams? " + areAnagrams(s13, s14));

        // Test Case 8
        String s15 = "School master";
        String s16 = "The classroom";
        System.out.println("Test Case 8: Are Anagrams? " + areAnagrams(s15, s16));

        // Test Case 9
        String s17 = "Dormitory";
        String s18 = "Dirty room";
        System.out.println("Test Case 9: Are Anagrams? " + areAnagrams(s17, s18));
    }
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
//You are tasked with creating a Java program to implement the binary search algorithm.
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


class BinarySearch {

    public static int binarySearch(int[] sortedArray, int target) {
        int left = 0;
        int right = sortedArray.length - 1;

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

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int target1 = 6;
        System.out.println("Test Case 1: Index of " + target1 + " = " + binarySearch(arr1, target1));

        // Test Case 2
        int[] arr2 = {2, 4, 6, 8, 10, 12, 14};
        int target2 = 5;
        System.out.println("Test Case 2: Index of " + target2 + " = " + binarySearch(arr2, target2));

        // Test Case 3
        int[] arr3 = {1, 3, 5, 7, 9, 11, 13};
        int target3 = 1;
        System.out.println("Test Case 3: Index of " + target3 + " = " + binarySearch(arr3, target3));

        // Test Case 4
        int[] arr4 = {3, 6, 9, 12, 15, 18};
        int target4 = 15;
        System.out.println("Test Case 4: Index of " + target4 + " = " + binarySearch(arr4, target4));

        // Test Case 5
        int[] arr5 = {5, 10, 15, 20, 25};
        int target5 = 8;
        System.out.println("Test Case 5: Index of " + target5 + " = " + binarySearch(arr5, target5));
    }
}

// sample output:
// Test Case 1: Index of 6 = 5
//Test Case 2: Index of 5 = -1
//Test Case 3: Index of 1 = 0
//Test Case 4: Index of 15 = 4
//Test Case 5: Index of 8 = -1



//******************************************************---****************************************************************

//  3. Problem Description: Find the nth Fibonacci Number without Recursion

//You are tasked with creating a Java program to find the nth Fibonacci number without using recursion.
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

class Fibonacci {

    public static int findNthFibonacci(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input should be a non-negative integer.");
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

    public static void main(String[] args) {
        // Test Case 1
        int result1 = findNthFibonacci(5);
        System.out.println("Test Case 1: Nth Fibonacci Number = " + result1);

        // Test Case 2
        int result2 = findNthFibonacci(8);
        System.out.println("Test Case 2: Nth Fibonacci Number = " + result2);

        // Test Case 3
        int result3 = findNthFibonacci(10);
        System.out.println("Test Case 3: Nth Fibonacci Number = " + result3);

        // Test Case 4
        int result4 = findNthFibonacci(0);
        System.out.println("Test Case 4: Nth Fibonacci Number = " + result4);

        // Test Case 5
        int result5 = findNthFibonacci(2);
        System.out.println("Test Case 5: Nth Fibonacci Number = " + result5);
    }
}

// sample output:
// Test Case 1: Nth Fibonacci Number = 5
//Test Case 2: Nth Fibonacci Number = 21
//Test Case 3: Nth Fibonacci Number = 55
//Test Case 4: Nth Fibonacci Number = 0
//Test Case 5: Nth Fibonacci Number = 1

//******************************************************---****************************************************************

//  4. Problem Description: Find the Next Prime Number

//You are tasked with creating a Java program to find the next prime number after a given number.
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

class NextPrime {

    public static int findNextPrime(int num) {
        if (num < 1) {
            throw new IllegalArgumentException("Input should be a positive integer greater than 1.");
        }

        while (true) {
            num++;

            if (isPrime(num)) {
                return num; // Found the next prime number
            }
        }
    }

    private static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }

        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false; // Found a divisor, not a prime number
            }
        }

        return true; // No divisors found, it's a prime number
    }

    public static void main(String[] args) {
        // Test Case 1
        int input1 = 10;
        int result1 = findNextPrime(input1);
        System.out.println("Test Case 1: Next Prime Number = " + result1);

        // Test Case 2
        int input2 = 20;
        int result2 = findNextPrime(input2);
        System.out.println("Test Case 2: Next Prime Number = " + result2);

        // Test Case 3
        int input3 = 31;
        int result3 = findNextPrime(input3);
        System.out.println("Test Case 3: Next Prime Number = " + result3);

        // Test Case 4
        int input4 = 1;
        try {
            int result4 = findNextPrime(input4);
            System.out.println("Test Case 4: Next Prime Number = " + result4);
        } catch (IllegalArgumentException e) {
            System.out.println("Test Case 4: " + e.getMessage());
        }
    }
}

//Sample Output:
// Test Case 1: Next Prime Number = 11
//Test Case 2: Next Prime Number = 23
//Test Case 3: Next Prime Number = 37
//Test Case 4: Next Prime Number = 2

//******************************************************---****************************************************************

//  5. Problem Description: Find Majority Element in an Array

//You are tasked with creating a Java program to find the majority element in an array.
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

class MajorityElement {

    public static int findMajorityElement(int[] nums) {
        int n = nums.length;

        if (n == 0) {
            return -1; // No majority element in an empty array
        }

        int[] elementCount = new int[1001]; // Assuming elements in the range [0, 1000]

        for (int num : nums) {
            elementCount[num]++;
        }

        for (int i = 0; i < elementCount.length; i++) {
            if (elementCount[i] > n / 2) {
                return i; // Found majority element
            }
        }

        return -1; // No majority element found
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {2, 2, 1, 1, 1, 2, 2};
        int result1 = findMajorityElement(arr1);
        System.out.println("Test Case 1: Majority Element = " + result1);

        // Test Case 2
        int[] arr2 = {3, 3, 4, 2, 4, 4, 2, 4, 4};
        int result2 = findMajorityElement(arr2);
        System.out.println("Test Case 2: Majority Element = " + result2);

        // Test Case 3
        int[] arr3 = {1, 2, 3, 4, 5};
        int result3 = findMajorityElement(arr3);
        System.out.println("Test Case 3: Majority Element = " + result3);

        // Test Case 4
        int[] arr4 = {1, 1, 1, 2, 2};
        int result4 = findMajorityElement(arr4);
        System.out.println("Test Case 4: Majority Element = " + result4);

        // Test Case 5
        int[] arr5 = {5};
        int result5 = findMajorityElement(arr5);
        System.out.println("Test Case 5: Majority Element = " + result5);
    }
}

// sample output:
//Test Case 1: Majority Element = 2
//        Test Case 2: Majority Element = 4
//        Test Case 3: Majority Element = -1
//        Test Case 4: Majority Element = 1
//        Test Case 5: Majority Element = 5


//******************************************************---****************************************************************

//  6. Problem Description: Calculate Character Frequency in a String

//You are tasked with creating a Java program to calculate the frequency of each character in a given string.
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

class CharacterFrequency {

    public static void calculateCharFrequency(String input) {
        if (input == null || input.isEmpty()) {
            System.out.println("Input string is empty.");
            return;
        }

        int[] charFrequency = new int[26];

        for (char c : input.toCharArray()) {
            if (Character.isLowerCase(c)) {
                charFrequency[c - 'a']++;
            }
        }

        for (int i = 0; i < charFrequency.length; i++) {
            if (charFrequency[i] > 0) {
                char currentChar = (char) ('a' + i);
                System.out.println(currentChar + ": " + charFrequency[i]);
            }
        }
    }

    public static void main(String[] args) {
        // Test Case 1
        String input1 = "abracadabra";
        System.out.println("Test Case 1:");
        calculateCharFrequency(input1);

        // Test Case 2
        String input2 = "hello";
        System.out.println("\nTest Case 2:");
        calculateCharFrequency(input2);

        // Test Case 3
        String input3 = "programming";
        System.out.println("\nTest Case 3:");
        calculateCharFrequency(input3);

        // Test Case 4
        String input4 = "java";
        System.out.println("\nTest Case 4:");
        calculateCharFrequency(input4);

        // Test Case 5
        String input5 = "";
        System.out.println("\nTest Case 5:");
        calculateCharFrequency(input5);
    }
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
//
////You are tasked with creating a Java program to find the sum of the two largest elements in an array.
//// The program should efficiently calculate and return the sum of the two largest distinct elements in the array.
//
////Input:
////    nums: An array of integers.
//
////Output:
////    Returns the sum of the two largest distinct elements in the array.
//
//// Example 1
////int[] arr1 = {3, 7, 2, 8, 5};
////int result1 = sumOfTwoLargest(arr1);
//// Output: 15 (The two largest elements are 8 and 7, and their sum is 15)
//
//// Example 2
////int[] arr2 = {5, 5, 5, 5};
////int result2 = sumOfTwoLargest(arr2);
//// Output: 10 (The two largest distinct elements are both 5, and their sum is 10)
//
////Notes:
////    The solution should efficiently find and calculate the sum of the two largest distinct elements in the array.
////    The function should consider arrays of varying sizes and handle cases where there are not enough distinct elements.
////    The program should run without errors for valid input arrays.
//
//class SumOfTwoLargest {
//
//    public static int sumOfTwoLargest(int[] nums) {
//        if (nums == null || nums.length < 2) {
//            throw new IllegalArgumentException("Array should contain at least two elements.");
//        }
//
//        int firstLargest = Integer.MIN_VALUE;
//        int secondLargest = Integer.MIN_VALUE;
//
//        for (int num : nums) {
//            if (num > firstLargest) {
//                secondLargest = firstLargest;
//                firstLargest = num;
//            } else if (num > secondLargest && num < firstLargest) {
//                secondLargest = num;
//            }
//        }
//
//        if (secondLargest == Integer.MIN_VALUE) {
//            throw new IllegalArgumentException("Array should contain at least two distinct elements.");
//        }
//
//        return firstLargest + secondLargest;
//    }
//
//    public static void main(String[] args) {
//        // Test Case 1
//        int[] arr1 = {3, 7, 2, 8, 5};
//        int result1 = sumOfTwoLargest(arr1);
//        System.out.println("Test Case 1: Sum of Two Largest = " + result1);
//
//        // Test Case 2
//        int[] arr2 = {5, 8, 4, 3};
//        int result2 = sumOfTwoLargest(arr2);
//        System.out.println("Test Case 2: Sum of Two Largest = " + result2);
//
//        // Test Case 3
//        int[] arr3 = {1, 2, 3, 4, 5};
//        int result3 = sumOfTwoLargest(arr3);
//        System.out.println("Test Case 3: Sum of Two Largest = " + result3);
//
//        // Test Case 4
//        int[] arr4 = {10, 10, 20, 20, 30};
//        int result4 = sumOfTwoLargest(arr4);
//        System.out.println("Test Case 4: Sum of Two Largest = " + result4);
//
//        // Test Case 5
//        int[] arr5 = {5, 3};
//        int result5 = sumOfTwoLargest(arr5);
//        System.out.println("Test Case 5: Sum of Two Largest = " + result5);
//    }
//}
//
////Sample Output:
//// Test Case 1: Sum of Two Largest = 15
////Test Case 2: Sum of Two Largest = 13
////Test Case 3: Sum of Two Largest = 9
////Test Case 4: Sum of Two Largest = 50
////Test Case 5: Sum of Two Largest = 8



//******************************************************---****************************************************************

//  8. Problem Description: Square of the Sum of Digits

//You are tasked with creating a Java program to find the square of the sum of digits of a given number.
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

class SquareOfSumOfDigits {

    public static int squareOfSumOfDigits(int num) {
        if (num < 0) {
            throw new IllegalArgumentException("Input should be a non-negative integer.");
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

    public static void main(String[] args) {
        // Test Case 1
        int input1 = 123;
        int result1 = squareOfSumOfDigits(input1);
        System.out.println("Test Case 1: Square of Sum of Digits = " + result1);

        // Test Case 2
        int input2 = 456;
        int result2 = squareOfSumOfDigits(input2);
        System.out.println("Test Case 2: Square of Sum of Digits = " + result2);

        // Test Case 3
        int input3 = 7890;
        int result3 = squareOfSumOfDigits(input3);
        System.out.println("Test Case 3: Square of Sum of Digits = " + result3);

        // Test Case 4
        int input4 = 0;
        int result4 = squareOfSumOfDigits(input4);
        System.out.println("Test Case 4: Square of Sum of Digits = " + result4);

        // Test Case 5
        int input5 = 987654321;
        int result5 = squareOfSumOfDigits(input5);
        System.out.println("Test Case 5: Square of Sum of Digits = " + result5);
    }
}

//Sample Output:
// Test Case 1: Square of Sum of Digits = 36
//Test Case 2: Square of Sum of Digits = 225
//Test Case 3: Square of Sum of Digits = 576
//Test Case 4: Square of Sum of Digits = 0
//Test Case 5: Square of Sum of Digits = 2025


//******************************************************---****************************************************************

//  9. Problem Description: Check if a Number is a Perfect Square

//You are tasked with creating a Java program to determine whether a given number is a perfect square.
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

class PerfectSquareCheck {

    public static boolean isPerfectSquare(int num) {
        if (num < 0) {
            throw new IllegalArgumentException("Input should be a non-negative integer.");
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

    public static void main(String[] args) {
        // Test Case 1
        int input1 = 16;
        boolean result1 = isPerfectSquare(input1);
        System.out.println("Test Case 1: Is Perfect Square? " + result1);

        // Test Case 2
        int input2 = 25;
        boolean result2 = isPerfectSquare(input2);
        System.out.println("Test Case 2: Is Perfect Square? " + result2);

        // Test Case 3
        int input3 = 14;
        boolean result3 = isPerfectSquare(input3);
        System.out.println("Test Case 3: Is Perfect Square? " + result3);

        // Test Case 4
        int input4 = 0;
        boolean result4 = isPerfectSquare(input4);
        System.out.println("Test Case 4: Is Perfect Square? " + result4);

        // Test Case 5
        int input5 = 100;
        boolean result5 = isPerfectSquare(input5);
        System.out.println("Test Case 5: Is Perfect Square? " + result5);
    }
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
//You are tasked with creating a Java program to find the difference between the sum of even-indexed elements and odd-indexed elements in an array.
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

class DifferenceBetweenSums {

    public static int differenceBetweenSums(int[] nums) {
        if (nums == null || nums.length < 2) {
            throw new IllegalArgumentException("Array should contain at least two elements.");
        }

        int sumEven = 0;
        int sumOdd = 0;

        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                sumEven += nums[i];
            } else {
                sumOdd += nums[i];
            }
        }

        return Math.abs(sumEven - sumOdd);
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {1, 2, 3, 4, 5};
        int result1 = differenceBetweenSums(arr1);
        System.out.println("Test Case 1: Difference Between Sums = " + result1);

        // Test Case 2
        int[] arr2 = {10, 20, 30, 40, 50, 60};
        int result2 = differenceBetweenSums(arr2);
        System.out.println("Test Case 2: Difference Between Sums = " + result2);

        // Test Case 3
        int[] arr3 = {5};
        try {
            int result3 = differenceBetweenSums(arr3);
            System.out.println("Test Case 3: Difference Between Sums = " + result3);
        } catch (IllegalArgumentException e) {
            System.out.println("Test Case 3: " + e.getMessage());
        }

        // Test Case 4
        int[] arr4 = {2, 4};
        int result4 = differenceBetweenSums(arr4);
        System.out.println("Test Case 4: Difference Between Sums = " + result4);

        // Test Case 5
        int[] arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int result5 = differenceBetweenSums(arr5);
        System.out.println("Test Case 5: Difference Between Sums = " + result5);
    }
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
//You are tasked with creating a Java program to determine whether a given integer 'n' is an Armstrong number.
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

class ArmstrongNumber {

    // Method to check if a number is Armstrong
    public static boolean isArmstrong(int n) {
        // Count the number of digits in the number
        int numDigits = String.valueOf(n).length();

        int sum = 0;
        int temp = n;

        // Calculate the sum of digits raised to the power of numDigits
        while (temp > 0) {
            int digit = temp % 10;
            sum += Math.pow(digit, numDigits);
            temp /= 10;
        }

        // Check if the sum is equal to the original number
        return sum == n;
    }

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        System.out.println("Test Case 1:");
        int n1 = 153;
        System.out.println("Input: " + n1);
        System.out.println("Output: " + isArmstrong(n1));

        System.out.println("\nTest Case 2:");
        int n2 = 370;
        System.out.println("Input: " + n2);
        System.out.println("Output: " + isArmstrong(n2));

        System.out.println("\nTest Case 3:");
        int n3 = 9474;
        System.out.println("Input: " + n3);
        System.out.println("Output: " + isArmstrong(n3));

        System.out.println("\nTest Case 4:");
        int n4 = 123;
        System.out.println("Input: " + n4);
        System.out.println("Output: " + isArmstrong(n4));
    }
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

//You are tasked with writing a Java program to count the number of unique characters in a given string.
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

class UniqueCharacterCounter {

    // Method to count the number of unique characters in a string
    public static int countUniqueCharacters(String str) {
        // Array to store frequency of characters, considering case insensitivity
        int[] frequency = new int[26];  // Considering only alphabets (case-insensitive)
        str = str.toLowerCase();  // Convert the string to lowercase

        // Iterate through the string and update frequency array
        for (char ch : str.toCharArray()) {
            if (Character.isLetter(ch)) {
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

    // Main method for testing
    public static void main(String[] args) {
        // Test Cases
        String str1 = "Hello";
        System.out.println("Test Case 1:");
        System.out.println("Input: " + str1);
        System.out.println("Output: " + countUniqueCharacters(str1));

        String str2 = "Mississippi";
        System.out.println("\nTest Case 2:");
        System.out.println("Input: " + str2);
        System.out.println("Output: " + countUniqueCharacters(str2));

        String str3 = "JavaProgramming";
        System.out.println("\nTest Case 3:");
        System.out.println("Input: " + str3);
        System.out.println("Output: " + countUniqueCharacters(str3));
    }
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

class PeakElement {

    public static int findPeakElement(int[] nums) {
        int n = nums.length;

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

    public static void main(String[] args) {
        // Test Cases
        int[] nums1 = {5, 10, 20, 15};
        System.out.println("Test Case 1: " + findPeakElement(nums1)); // Output: 20

        int[] nums2 = {1, 3, 6, 7, 4, 2};
        System.out.println("Test Case 2: " + findPeakElement(nums2)); // Output: 7

        int[] nums3 = {10, 20, 30, 40};
        System.out.println("Test Case 3: " + findPeakElement(nums3)); // Output: 40

        int[] nums4 = {5, 10, 15, 20, 25};
        System.out.println("Test Case 4: " + findPeakElement(nums4)); // Output: 25

        int[] nums5 = {1};
        System.out.println("Test Case 5: " + findPeakElement(nums5)); // Output: 1

        int[] nums6 = {10, 9, 8, 7};
        System.out.println("Test Case 6: " + findPeakElement(nums6)); // Output: 10

        int[] nums7 = {10, 11, 13, 16, 20, 8, 5, 4};
        System.out.println("Test Case 7: " + findPeakElement(nums7)); // Output: 20

        int[] nums8 = {20, 40, 50, 70, 90, 60, 30, 10};
        System.out.println("Test Case 8: " + findPeakElement(nums8)); // Output: 90
    }
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
//You are tasked with creating a Java program to determine whether a given year is a leap year or not.
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
class LeapYearChecker {

    public static boolean isLeapYear(int year) {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true; // Leap year condition satisfied
        } else {
            return false; // Not a leap year
        }
    }

    public static void main(String[] args) {
        // Test Cases
        int[] years = {2020, 1900, 2000, 2021, 2022, 3036, 3033, 1986, 1956, 1600};
        for (int year : years) {
            System.out.println("Is " + year + " a leap year? " + isLeapYear(year));
        }
    }
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

//You are tasked with creating a Java program to check if a given string starts with a specific prefix.
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

class PrefixCheck {

    public static boolean startsWithPrefix(String str, String prefix) {
        if (str == null || prefix == null) {
            throw new IllegalArgumentException("Input strings cannot be null.");
        }

        int prefixLength = prefix.length();

        if (prefixLength > str.length()) {
            return false; // Prefix is longer than the string, cannot be a match
        }

        for (int i = 0; i < prefixLength; i++) {
            if (str.charAt(i) != prefix.charAt(i)) {
                return false; // Mismatch at current position
            }
        }

        return true; // Prefix matches the start of the string
    }

    public static void main(String[] args) {
        // Test Case 1
        boolean result1 = startsWithPrefix("Hello, World!", "Hello");
        System.out.println("Test Case 1: Starts with Prefix? " + result1);

        // Test Case 2
        boolean result2 = startsWithPrefix("Java Programming", "Python");
        System.out.println("Test Case 2: Starts with Prefix? " + result2);

        // Test Case 3
        boolean result3 = startsWithPrefix("12345", "12");
        System.out.println("Test Case 3: Starts with Prefix? " + result3);

        // Test Case 4
        boolean result4 = startsWithPrefix("Java", "Java");
        System.out.println("Test Case 4: Starts with Prefix? " + result4);

        // Test Case 5
        boolean result5 = startsWithPrefix("", "Prefix");
        System.out.println("Test Case 5: Starts with Prefix? " + result5);
    }
}

//Sample Output:
// Test Case 1: Starts with Prefix? true
//Test Case 2: Starts with Prefix? false
//Test Case 3: Starts with Prefix? true
//Test Case 4: Starts with Prefix? true
//Test Case 5: Starts with Prefix? false

//******************************************************---****************************************************************
// 16. Pairs with Sum

//You are tasked with creating a Java program to find all pairs of elements in an array whose sum is equal to a given target number.

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

 class PairSum {

    public static void findPairs(int[] nums, int target) {
        boolean foundPair = false;
        // Brute-force approach: Check all pairs of elements in the array
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    System.out.println("(" + nums[i] + ", " + nums[j] + ")");
                    foundPair = true;
                }
            }
        }
        if (!foundPair) {
            System.out.println("No pairs found.");
        }
    }

    public static void main(String[] args) {
        // Test Cases
        int[] nums1 = {1, 2, 3, 4, 5};
        int target1 = 5;
        System.out.println("Pairs with sum " + target1 + " in nums1:");
        findPairs(nums1, target1);

        int[] nums2 = {3, 8, 5, 2, 9};
        int target2 = 10;
        System.out.println("\nPairs with sum " + target2 + " in nums2:");
        findPairs(nums2, target2);

        int[] nums3 = {1, 2, 3, 4, 5};
        int target3 = 20;
        System.out.println("\nPairs with sum " + target3 + " in nums3:");
        findPairs(nums3, target3);

        int[] nums4 = {5, 4, 6, 5};
        int target4 = 10;
        System.out.println("\nPairs with sum " + target4 + " in nums4:");
        findPairs(nums4, target4);

        int[] nums5 = {1, 2, 3, 4, 5};
        int target5 = 8;
        System.out.println("\nPairs with sum " + target5 + " in nums5:");
        findPairs(nums5, target5);
    }
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

 class SwapNumbers {

    public static void swap(int a, int b) {
        System.out.println("Before swapping:");
        System.out.println("a = " + a);
        System.out.println("b = " + b);

        // Swapping without using a third variable
        a = a + b;
        b = a - b;
        a = a - b;

        System.out.println("After swapping:");
        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }

    public static void main(String[] args) {
        // Test Cases
        int num1 = 5, num2 = 10;
        System.out.println("Swapping num1 and num2:");
        swap(num1, num2);

        int num3 = 3, num4 = 7;
        System.out.println("\nSwapping num3 and num4:");
        swap(num3, num4);

        int num5 = 20, num6 = 50;
        System.out.println("\nSwapping num3 and num4:");
        swap(num5, num6);

        int num7 = 1, num8 = 4;
        System.out.println("\nSwapping num3 and num4:");
        swap(num7, num8);

        int num9 = 15, num10 = 25;
        System.out.println("\nSwapping num3 and num4:");
        swap(num9, num10);
    }
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

//You are tasked with creating a Java program to find all the factors (numbers that evenly divide) of a given input number.

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

class Factors {

    public static void findFactors(int n) {
        System.out.print("Factors of " + n + ": ");
        // Iterate from 1 to n and check if i divides n evenly
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                System.out.print(i);
                // Print comma and space for separation except for the last factor
                if (i != n) {
                    System.out.print(", ");
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Test Cases
        int num1 = 12;
        System.out.println("Test Case 1:");
        findFactors(num1);

        int num2 = 15;
        System.out.println("\nTest Case 2:");
        findFactors(num2);

        int num3 = 28;
        System.out.println("\nTest Case 3:");
        findFactors(num3);
    }
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

//  19. Problem Description: Sum of Prime Numbers up to a Given Limit
//
//You are tasked with creating a Java program to find the sum of prime numbers up to a given limit.
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

class SumOfPrimes {

    public static int sumOfPrimes(int limit) {
        if (limit < 0) {
            throw new IllegalArgumentException("Limit should be a non-negative integer.");
        }

        int sum = 0;

        for (int i = 2; i <= limit; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }

        return sum;
    }

    private static boolean isPrime(int num) {
        if (num < 2) {
            return false;
        }

        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false; // Not a prime number
            }
        }

        return true; // Prime number
    }

    public static void main(String[] args) {
        // Test Case 1
        int result1 = sumOfPrimes(10);
        System.out.println("Test Case 1: Sum of Primes = " + result1);

        // Test Case 2
        int result2 = sumOfPrimes(20);
        System.out.println("Test Case 2: Sum of Primes = " + result2);

        // Test Case 3
        int result3 = sumOfPrimes(5);
        System.out.println("Test Case 3: Sum of Primes = " + result3);

        // Test Case 4
        int result4 = sumOfPrimes(0);
        System.out.println("Test Case 4: Sum of Primes = " + result4);

        // Test Case 5
        int result5 = sumOfPrimes(30);
        System.out.println("Test Case 5: Sum of Primes = " + result5);
    }
}


//Sample Output:
// Test Case 1: Sum of Primes = 17
//Test Case 2: Sum of Primes = 77
//Test Case 3: Sum of Primes = 10
//Test Case 4: Sum of Primes = 0
//Test Case 5: Sum of Primes = 129


//******************************************************---****************************************************************

//  20. Problem Description: Find the Kth Largest Element in an Array

//You are tasked with creating a Java program to find the Kth largest element in an array.
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

//import java.util.Arrays;
class KthLargestElement { // import Arrays

    public static int findKthLargest(int[] nums, int k) {
        if (nums == null || k <= 0 || k > nums.length) {
            throw new IllegalArgumentException("Invalid input parameters.");
        }

        Arrays.sort(nums);
        return nums[nums.length - k];
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {3, 1, 5, 7, 2, 4, 6};
        int k1 = 3;
        int result1 = findKthLargest(arr1, k1);
        System.out.println("Test Case 1: Kth Largest Element = " + result1);

        // Test Case 2
        int[] arr2 = {10, 20, 30, 40, 50};
        int k2 = 1;
        int result2 = findKthLargest(arr2, k2);
        System.out.println("Test Case 2: Kth Largest Element = " + result2);

        // Test Case 3
        int[] arr3 = {7};
        int k3 = 1;
        int result3 = findKthLargest(arr3, k3);
        System.out.println("Test Case 3: Kth Largest Element = " + result3);

        // Test Case 4
        int[] arr4 = {5, 5, 5, 5, 5};
        int k4 = 2;
        int result4 = findKthLargest(arr4, k4);
        System.out.println("Test Case 4: Kth Largest Element = " + result4);

        // Test Case 5
        int[] arr5 = {1, 2, 3, 4, 5};
        int k5 = 5;
        int result5 = findKthLargest(arr5, k5);
        System.out.println("Test Case 5: Kth Largest Element = " + result5);
    }
}

//Sample Output:
// Test Case 1: Kth Largest Element = 5
//Test Case 2: Kth Largest Element = 50
//Test Case 3: Kth Largest Element = 7
//Test Case 4: Kth Largest Element = 5
//Test Case 5: Kth Largest Element = 1


//******************************************************---****************************************************************

//  21. Problem Description: Single Number

//You are tasked with creating a Java program to find the single number in an array where every element appears twice except for one.
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

class SingleNumber {

    public static int findSingleNumber(int[] nums) {
        if (nums == null || nums.length % 2 == 0) {
            throw new IllegalArgumentException("Invalid input array.");
        }

        int result = 0;

        for (int num : nums) {
            result ^= num; // Using XOR operation to find the single number
        }

        return result;
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {4, 2, 7, 2, 4};
        int result1 = findSingleNumber(arr1);
        System.out.println("Test Case 1: Single Number = " + result1);

        // Test Case 2
        int[] arr2 = {1, 2, 3, 1, 3};
        int result2 = findSingleNumber(arr2);
        System.out.println("Test Case 2: Single Number = " + result2);

        // Test Case 3
        int[] arr3 = {5, 6, 6};
        int result3 = findSingleNumber(arr3);
        System.out.println("Test Case 3: Single Number = " + result3);
    }
}

//Sample Output:
// Test Case 1: Single Number = 7
//Test Case 2: Single Number = 2
//Test Case 3: Single Number = 5

//******************************************************---****************************************************************

//  22. Problem Description: Missing Number

//You are tasked with creating a Java program to find the missing number in an array.
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

class MissingNumber {

    public static int findMissingNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Invalid input array.");
        }

        int n = nums.length;
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {3, 0, 1};
        int result1 = findMissingNumber(arr1);
        System.out.println("Test Case 1: Missing Number = " + result1);

        // Test Case 2
        int[] arr2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
        int result2 = findMissingNumber(arr2);
        System.out.println("Test Case 2: Missing Number = " + result2);

        // Test Case 3
        int[] arr3 = {1};
        int result3 = findMissingNumber(arr3);
        System.out.println("Test Case 3: Missing Number = " + result3);
    }
}

//Sample Output:
// Test Case 1: Missing Number = 2
//Test Case 2: Missing Number = 8
//Test Case 3: Missing Number = 0

//******************************************************---****************************************************************
