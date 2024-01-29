import java.util.Arrays;
//******************************************************---****************************************************************

//  1. Problem Description: Find the Next Prime Number

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

//  2. Problem Description: Find the Sum of Two Largest Elements in an Array

//You are tasked with creating a Java program to find the sum of the two largest elements in an array.
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

class SumOfTwoLargest {

    public static int sumOfTwoLargest(int[] nums) {
        if (nums == null || nums.length < 2) {
            throw new IllegalArgumentException("Array should contain at least two elements.");
        }

        int firstLargest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;

        for (int num : nums) {
            if (num > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = num;
            } else if (num > secondLargest && num < firstLargest) {
                secondLargest = num;
            }
        }

        if (secondLargest == Integer.MIN_VALUE) {
            throw new IllegalArgumentException("Array should contain at least two distinct elements.");
        }

        return firstLargest + secondLargest;
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {3, 7, 2, 8, 5};
        int result1 = sumOfTwoLargest(arr1);
        System.out.println("Test Case 1: Sum of Two Largest = " + result1);

        // Test Case 2
        int[] arr2 = {5, 8, 4, 3};
        int result2 = sumOfTwoLargest(arr2);
        System.out.println("Test Case 2: Sum of Two Largest = " + result2);

        // Test Case 3
        int[] arr3 = {1, 2, 3, 4, 5};
        int result3 = sumOfTwoLargest(arr3);
        System.out.println("Test Case 3: Sum of Two Largest = " + result3);

        // Test Case 4
        int[] arr4 = {10, 10, 20, 20, 30};
        int result4 = sumOfTwoLargest(arr4);
        System.out.println("Test Case 4: Sum of Two Largest = " + result4);

        // Test Case 5
        int[] arr5 = {5, 3};
        int result5 = sumOfTwoLargest(arr5);
        System.out.println("Test Case 5: Sum of Two Largest = " + result5);
    }
}

//Sample Output:
// Test Case 1: Sum of Two Largest = 15
//Test Case 2: Sum of Two Largest = 13
//Test Case 3: Sum of Two Largest = 9
//Test Case 4: Sum of Two Largest = 50
//Test Case 5: Sum of Two Largest = 8


//******************************************************---****************************************************************

//  3. Problem Description: Square of the Sum of Digits

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

//  4. Problem Description: Check if a Number is a Perfect Square

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

//  5. Problem Description: Check if a String Starts with a Specific Prefix
//
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

//  6. Problem Description: Sum of Prime Numbers up to a Given Limit
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

//  7. Problem Description: Find the Kth Largest Element in an Array

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

//  8. Problem Description: Single Number

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

//  9. Problem Description: Missing Number

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

//  10.


//******************************************************---****************************************************************

//  11.


//******************************************************---****************************************************************

//  12.


//******************************************************---****************************************************************

//  13.

