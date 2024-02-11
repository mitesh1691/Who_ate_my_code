import java.util.Arrays;
//******************************************************---****************************************************************

//  1. Problem Description: Excel Sheet Column Title

//You are given an integer columnNumber, representing the column number in an Excel sheet. Your task is to return its corresponding column title.

//In Excel, column titles are represented using letters from the English alphabet,
// starting from "A" for column 1, "B" for column 2, and so on.
// After "Z" (column 26), the titles continue with "AA", "AB", ..., "AZ" (columns 27, 28, ..., 52), and then "BA", "BB", ..., "BZ" (columns 53, 54, ..., 78), and so forth.

//Input:
//    columnNumber: An integer representing the column number in the Excel sheet (1 ≤ columnNumber ≤ 2^31 - 1).

//Output:
//    Returns a string representing the column title corresponding to the given column number.

//Approach:
//        To convert the column number to its corresponding title, we can use the base-26 numbering system.
//        However, in Excel, the numbering system is 1-based rather than 0-based.

//// Example 1
//Input: columnNumber = 1
//Output: "A"
//Explanation: Column 1 corresponds to column title "A" in the Excel sheet.

//// Example 2
//Input: columnNumber = 28
//Output: "AB"
//Explanation: Column 28 corresponds to column title "AB" in the Excel sheet.

//// Example 3
//Input: columnNumber = 701
//Output: "ZY"
//Explanation: Column 701 corresponds to column title "ZY" in the Excel sheet.

//Notes:
//    The column title is represented as a string composed of uppercase English letters.
//    The column number mapping starts from 1, with "A" corresponding to 1, "B" corresponding to 2, and so on.
//    The column title is generated in a similar fashion to how numbers are represented in a base-26 numeral system, where the alphabet is used as digits.

class ExcelColumnTitle {

    public static String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();

        // Convert the column number to corresponding Excel column title
        while (columnNumber > 0) {
            columnNumber--; // Adjust to 0-based indexing
            int remainder = columnNumber % 26;
            char ch = (char) (remainder + 'A'); // Map remainder to corresponding character
            sb.insert(0, ch); // Insert character at the beginning of StringBuilder
            columnNumber /= 26; // Update columnNumber for next iteration
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        // Test Cases
        int column1 = 1;
        System.out.println("Test Case 1: " + convertToTitle(column1));

        int column2 = 28;
        System.out.println("Test Case 2: " + convertToTitle(column2));

        int column3 = 701;
        System.out.println("Test Case 3: " + convertToTitle(column3));

        int column4 = 52;
        System.out.println("Test Case 4: " + convertToTitle(column4));
    }
}
//Sample output:
//         Test Case 1: A
//        Test Case 2: AB
//        Test Case 3: ZY
//        Test Case 4: AZ


//******************************************************---****************************************************************

//  2. Problem Description: Move Zeroes

//You are given an integer array nums, containing both zero and non-zero integers.
// Your task is to move all the zeroes to the end of the array while maintaining the relative order of the non-zero elements.
// The operation must be performed in-place, without making a copy of the array.

//Example:
//Consider an array nums = [0,1,0,3,12]:
//    After moving zeroes to the end while preserving the order of non-zero elements, the array becomes [1,3,12,0,0].

//Input:
//    An integer array nums containing both zero and non-zero integers (0 ≤ nums[i] ≤ 10^4).
//    The array may contain duplicates.

//Output:
//    Returns the modified array with zeroes moved to the end while maintaining the order of non-zero elements.

//Example:
//    For nums = [0,1,0,3,12], the output should be [1,3,12,0,0].
//    For nums = [0], the output should be [0].

//import java.util.Arrays;
class MoveZeroes { // import arrays
    public static void moveZeroes(int[] nums) {
        int nonZeroIndex = 0; // Initialize the index to place the next non-zero element

        // Iterate through the array
        for (int i = 0; i < nums.length; i++) {
            // If the current element is non-zero, swap it with the element at nonZeroIndex
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = nums[nonZeroIndex];
                nums[nonZeroIndex] = temp;

                // Increment nonZeroIndex to indicate the next position for non-zero elements
                nonZeroIndex++;
            }
        }
    }

    public static void main(String[] args) {
        // Test cases
        int[] nums1 = {0, 1, 0, 3, 12};
        moveZeroes(nums1);
        System.out.println("Test Case 1: " + Arrays.toString(nums1)); // Output: [1, 3, 12, 0, 0]

        int[] nums2 = {0};
        moveZeroes(nums2);
        System.out.println("Test Case 2: " + Arrays.toString(nums2)); // Output: [0]

        int[] nums3 = {1, 2, 3, 0, 4, 0, 5, 6};
        moveZeroes(nums3);
        System.out.println("Test Case 3: " + Arrays.toString(nums3)); // Output: [1, 2, 3, 4, 5, 6, 0, 0]

        int[] nums4 = {0, 0, 0, 0};
        moveZeroes(nums4);
        System.out.println("Test Case 4: " + Arrays.toString(nums4)); // Output: [0, 0, 0, 0]
    }
}

//sample output:
//        Test Case 1: [1, 3, 12, 0, 0]
//        Test Case 2: [0]
//        Test Case 3: [1, 2, 3, 4, 5, 6, 0, 0]
//        Test Case 4: [0, 0, 0, 0]



//******************************************************---****************************************************************

//  3. Problem Description: Check if given String is Pangram or not

//A pangram is a sentence that contains every letter of the alphabet at least once.
// Given a string, determine if it is a pangram or not.

//Input:
//A string representing a sentence.

//Output:
//A message indicating whether the given string is a pangram or not.

//Example:
//Input: "The quick brown fox jumps over the lazy dog"
//Output: "is a Pangram"
//Explanation: The input string contains all the letters from 'a' to 'z'.

//Input: "The quick brown fox jumps over the dog"
//Output: "is not a Pangram"
//Explanation: The input string is missing some letters from 'a' to 'z'.

class PangramChecker {
    public static boolean isPangram(String str) {
        boolean[] alphabet = new boolean[26];
        str = str.toLowerCase();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                alphabet[ch - 'a'] = true;
            }
        }

        for (boolean present : alphabet) {
            if (!present) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        // Test cases
        String input1 = "The quick brown fox jumps over the lazy dog";
        String input2 = "The quick brown fox jumps over the dog";
        String input3 = "Pack my box with five dozen liquor jugs";
        String input4 = "The quick brown fox jumps over a lazy cat";
        String input5 = "abcdefghijklmnopqrstuvwxyz";

        System.out.println("Test Case 1: " + (isPangram(input1) ? "is a Pangram" : "is not a Pangram"));
        System.out.println("Test Case 2: " + (isPangram(input2) ? "is a Pangram" : "is not a Pangram"));
        System.out.println("Test Case 3: " + (isPangram(input3) ? "is a Pangram" : "is not a Pangram"));
        System.out.println("Test Case 4: " + (isPangram(input4) ? "is a Pangram" : "is not a Pangram"));
        System.out.println("Test Case 5: " + (isPangram(input5) ? "is a Pangram" : "is not a Pangram"));
    }
}

// sample output:
// Test Case 1: is a Pangram
//Test Case 2: is not a Pangram
//Test Case 3: is a Pangram
//Test Case 4: is not a Pangram
//Test Case 5: is a Pangram



//******************************************************---****************************************************************

//  4. Problem Description: Interchange elements of first and last rows in matrix

//You are given a 4x4 matrix, and you need to interchange the elements of the first and last rows. The resulting matrix should reflect this interchange.

//Input:
//    A 4x4 matrix of integers.

//Output:
//    The modified matrix where the elements of the first and last rows are interchanged.

//Example:
//Suppose you are given the following matrix as input:
//Input:
//3 4 5 0
//2 6 1 2
//2 7 1 2
//2 1 1 2

//Output:
//2 1 1 2
//2 6 1 2
//2 7 1 2
//3 4 5 0

//In this example, the elements of the first and last rows have been interchanged, resulting in the output matrix.

class InterchangeRows {
    public static void interchangeRows(int[][] matrix) {
        // Interchange the elements of the first and last rows
        int[] temp = matrix[0];
        matrix[0] = matrix[matrix.length - 1];
        matrix[matrix.length - 1] = temp;
    }

    public static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Test cases
        int[][] matrix1 = {
                {3, 4, 5, 0},
                {2, 6, 1, 2},
                {2, 7, 1, 2},
                {2, 1, 1, 2}
        };
        System.out.println("Test Case 1:");
        interchangeRows(matrix1);
        printMatrix(matrix1);

        int[][] matrix2 = {
                {9, 7, 5, 1},
                {2, 3, 4, 1},
                {5, 6, 6, 5},
                {1, 2, 3, 1}
        };
        System.out.println("\nTest Case 2:");
        interchangeRows(matrix2);
        printMatrix(matrix2);

        // Additional test cases
        int[][] matrix3 = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}
        };
        System.out.println("\nTest Case 3:");
        interchangeRows(matrix3);
        printMatrix(matrix3);

        int[][] matrix4 = {
                {1, 0, 0, 1},
                {0, 1, 1, 0},
                {1, 1, 0, 1},
                {0, 0, 1, 1}
        };
        System.out.println("\nTest Case 4:");
        interchangeRows(matrix4);
        printMatrix(matrix4);
    }
}

// sample output:
// Test Case 1:
//2 1 1 2
//2 6 1 2
//2 7 1 2
//3 4 5 0

//Test Case 2:
//1 2 3 1
//2 3 4 1
//5 6 6 5
//9 7 5 1

//Test Case 3:
//13 14 15 16
//5 6 7 8
//9 10 11 12
//1 2 3 4

//Test Case 4:
//0 0 1 1
//0 1 1 0
//1 1 0 1
//1 0 0 1



//******************************************************---****************************************************************

//  5. Reverse letters in a string but keep digits in their current order.

// Problem Description:
//You are tasked with creating a Java program that reverses the letters in a given string while keeping the digits in their current order.
// The goal is to reverse the sequence of letters in the string, maintaining the relative positions of the digits.

//For example, if the input string is "a1b2c3", the output should be "c3b2a1".
// Notice that the digits '1', '2', and '3' remain in their original positions, while the letters 'a', 'b', and 'c' are reversed.

//Your program should efficiently handle strings of any length and contain only letters and digits.

//Input:
//    A string containing a combination of letters and digits.

//Output:
//    The string with the letters reversed but the digits remaining in their original order.

//Example:
//Input: "a1b2c3"
//Output: "c3b2a1"

//Note:
//    The input string can contain uppercase and lowercase letters.
//    There may be leading or trailing spaces in the input string, and they should be preserved in the output.


class ReverseLetters {
    public static String reverseLetters(String str) {
        char[] chars = str.toCharArray();
        int left = 0, right = chars.length - 1;

        while (left < right) {
            if (!Character.isDigit(chars[left])) {
                if (!Character.isDigit(chars[right])) {
                    char temp = chars[left];
                    chars[left] = chars[right];
                    chars[right] = temp;
                    left++;
                }
                right--;
            } else {
                left++;
            }
        }
        return new String(chars);
    }

    public static void main(String[] args) {
        // Test cases
        String input1 = "a1b2c3d";
        String input2 = "hello123world";
        String input3 = "12345abcdef";
        String input4 = "1a2b3c4d5e";

        System.out.println("Test Case 1: " + reverseLetters(input1));
        System.out.println("Test Case 2: " + reverseLetters(input2));
        System.out.println("Test Case 3: " + reverseLetters(input3));
        System.out.println("Test Case 4: " + reverseLetters(input4));
    }
}

// sample output:
// Test Case 1: d1c2b3a
//Test Case 2: dlrow123olleh
//Test Case 3: 12345fedcba
//Test Case 4: 1e2d3c4b5a

//******************************************************---****************************************************************


