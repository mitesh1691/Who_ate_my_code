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

//  4. Problem Description: Find Factorial using Recursion

//You are tasked with creating a Java program to find the factorial of a given number using 'recursion'.
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


class FactorialRecursive {

    public static long calculateFactorial(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input should be a non-negative integer.");
        }

        if (n == 0 || n == 1) {
            return 1; // Factorial of 0 and 1 is 1
        }

        return n * calculateFactorial(n - 1);
    }

    public static void main(String[] args) {
        // Test Case 1
        int input1 = 5;
        long result1 = calculateFactorial(input1);
        System.out.println("Test Case 1: Factorial of " + input1 + " = " + result1);

        // Test Case 2
        int input2 = 8;
        long result2 = calculateFactorial(input2);
        System.out.println("Test Case 2: Factorial of " + input2 + " = " + result2);

        // Test Case 3
        int input3 = 0;
        long result3 = calculateFactorial(input3);
        System.out.println("Test Case 3: Factorial of " + input3 + " = " + result3);

        // Test Case 4
        int input4 = 3;
        long result4 = calculateFactorial(input4);
        System.out.println("Test Case 4: Factorial of " + input4 + " = " + result4);

        // Test Case 5
        int input5 = 7;
        long result5 = calculateFactorial(input5);
        System.out.println("Test Case 5: Factorial of " + input5 + " = " + result5);
    }
}

// Sample Output:
// Test Case 1: Factorial of 5 = 120
//Test Case 2: Factorial of 8 = 40320
//Test Case 3: Factorial of 0 = 1
//Test Case 4: Factorial of 3 = 6
//Test Case 5: Factorial of 7 = 5040

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

//  7.

//******************************************************---****************************************************************

//  8.

//******************************************************---****************************************************************

//  9.

//******************************************************---****************************************************************




