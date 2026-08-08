/*Leetcode: 724. Find Pivot Index
Link: https://leetcode.com/problems/find-pivot-index/ */

class Solution {
    public int pivotIndex(int[] nums) 
    {
        int lSum=0;
        int totalSum=0;
        for (int i:nums)
        {
            totalSum+=i;
        }
        for (int i=0;i<nums.length;i++)
        {
            totalSum-=nums[i];
            if (totalSum==lSum)
            {
                return i;
            }
            lSum+=nums[i];
        }
        return -1;
    }
}