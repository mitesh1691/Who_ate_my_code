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

//  2.

//******************************************************---****************************************************************

//  3.

//******************************************************---****************************************************************

//  4.

//******************************************************---****************************************************************

//  5.

//******************************************************---****************************************************************

//  6.

//******************************************************---****************************************************************

//  7.

//******************************************************---****************************************************************

//  8.

//******************************************************---****************************************************************

//  9.

//******************************************************---****************************************************************




