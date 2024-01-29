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

//  7. Problem Description: Find the Average of Elements in an Array

//You are tasked with creating a Java program to find the average of elements in an array.
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

class AverageOfElements {

    public static double findAverage(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Array should contain at least one element.");
        }

        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        return (double) sum / nums.length;
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {1, 2, 3, 4, 5};
        double result1 = findAverage(arr1);
        System.out.println("Test Case 1: Average of Elements = " + result1);

        // Test Case 2
        int[] arr2 = {10, 20, 30, 40, 50};
        double result2 = findAverage(arr2);
        System.out.println("Test Case 2: Average of Elements = " + result2);

        // Test Case 3
        int[] arr3 = {5};
        double result3 = findAverage(arr3);
        System.out.println("Test Case 3: Average of Elements = " + result3);

        // Test Case 4
        int[] arr4 = {-1, 0, 1};
        double result4 = findAverage(arr4);
        System.out.println("Test Case 4: Average of Elements = " + result4);

        // Test Case 5
        int[] arr5 = {2, 4, 6, 8, 10};
        double result5 = findAverage(arr5);
        System.out.println("Test Case 5: Average of Elements = " + result5);
    }
}

// sample output:
// Test Case 1: Average of Elements = 3.0
//Test Case 2: Average of Elements = 30.0
//Test Case 3: Average of Elements = 5.0
//Test Case 4: Average of Elements = 0.0
//Test Case 5: Average of Elements = 6.0



//******************************************************---****************************************************************

//  8. Problem Description: Count Even and Odd Numbers in an Array

//You are tasked with creating a Java program to count the number of even and odd numbers in an array.
// The program should efficiently determine and return the count of even and odd numbers present in the array.

//Input:
//    nums: An array of integers.

//Output:
//    Returns an array where the first element is the count of even numbers, and the second element is the count of odd numbers.

// Example
//    int[] arr = {2, 5, 8, 3, 6, 7};
//    int[] result = countEvenOddNumbers(arr);
// Output: [3, 3] (There are 3 even numbers {2, 8, 6} and 3 odd numbers {5, 3, 7})


class CountEvenOddNumbers {

    public static int[] countEvenOddNumbers(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Array should contain at least one element.");
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

        return new int[]{evenCount, oddCount};
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {2, 5, 8, 3, 6, 7};
        int[] result1 = countEvenOddNumbers(arr1);
        System.out.println("Test Case 1: Even Count = " + result1[0] + ", Odd Count = " + result1[1]);

        // Test Case 2
        int[] arr2 = {10, 20, 30, 40, 50};
        int[] result2 = countEvenOddNumbers(arr2);
        System.out.println("Test Case 2: Even Count = " + result2[0] + ", Odd Count = " + result2[1]);

        // Test Case 3
        int[] arr3 = {7};
        int[] result3 = countEvenOddNumbers(arr3);
        System.out.println("Test Case 3: Even Count = " + result3[0] + ", Odd Count = " + result3[1]);

        // Test Case 4
        int[] arr4 = {-1, 0, 1};
        int[] result4 = countEvenOddNumbers(arr4);
        System.out.println("Test Case 4: Even Count = " + result4[0] + ", Odd Count = " + result4[1]);

        // Test Case 5
        int[] arr5 = {2, 4, 6, 8, 10};
        int[] result5 = countEvenOddNumbers(arr5);
        System.out.println("Test Case 5: Even Count = " + result5[0] + ", Odd Count = " + result5[1]);
    }
}

// sample output:
//Test Case 1: Even Count = 3, Odd Count = 3
//Test Case 2: Even Count = 5, Odd Count = 0
//Test Case 3: Even Count = 0, Odd Count = 1
//Test Case 4: Even Count = 1, Odd Count = 2
//Test Case 5: Even Count = 5, Odd Count = 0


//******************************************************---****************************************************************

//  9. Problem Description: Find the Maximum of Three Numbers

//You are tasked with creating a Java program to find the maximum of three numbers.
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


class FindMaximum {

    public static int findMaximum(int num1, int num2, int num3) {
        int max = num1;

        if (num2 > max) {
            max = num2;
        }

        if (num3 > max) {
            max = num3;
        }

        return max;
    }

    public static void main(String[] args) {
        // Test Case 1
        int result1 = findMaximum(5, 12, 8);
        System.out.println("Test Case 1: Maximum = " + result1);

        // Test Case 2
        int result2 = findMaximum(20, 15, 25);
        System.out.println("Test Case 2: Maximum = " + result2);

        // Test Case 3
        int result3 = findMaximum(10, 10, 10);
        System.out.println("Test Case 3: Maximum = " + result3);

        // Test Case 4
        int result4 = findMaximum(-5, -2, -8);
        System.out.println("Test Case 4: Maximum = " + result4);

        // Test Case 5
        int result5 = findMaximum(0, 0, 0);
        System.out.println("Test Case 5: Maximum = " + result5);
    }
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