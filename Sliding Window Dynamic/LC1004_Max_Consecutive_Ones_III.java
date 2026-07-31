/*Leetcode: 1004. Max Consecutive Ones III
Link: https://leetcode.com/problems/max-consecutive-ones-iii/ */
class Solution {
    public int longestOnes(int[] nums, int k) 
    {
        int maxCount=0;
        int l=0;
        int r=0;
        int zeroCount=0;
        while (r<nums.length)
        {
            if (nums[r]==0)
            {
                zeroCount++;
            }
            if (zeroCount>k)
            {
                while (zeroCount>k)
                {
                    if (nums[l]==0)
                    {
                        zeroCount--;
                    }
                    l++;
                }
            }
            maxCount=Math.max(maxCount,r-l+1);
            r++;
        }
        return maxCount;
    }
}