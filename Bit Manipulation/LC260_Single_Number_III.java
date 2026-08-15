/*Leetcode: 260. Single Number III
Link: https://leetcode.com/problems/single-number-iii/  */

class Solution {
    public int[] singleNumber(int[] nums) {
        int xor = 0;

        // XOR all numbers → x ^ y
        for (int num : nums) {
            xor ^= num;
        }

        // Get rightmost set bit
        int mask = xor & -xor;

        int x = 0;
        int y = 0;

        // Divide into two groups and XOR
        for (int num : nums) {
            if ((num & mask) != 0) {
                x ^= num;
            } else {
                y ^= num;
            }
        }

        return new int[]{x, y};
    }
}