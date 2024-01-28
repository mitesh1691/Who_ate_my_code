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

//----------------------------------------------------*****************----------------------------------------------


//  2.
