/*Leetcode: 209. Minimum Size Subarray Sum
Link: https://leetcode.com/problems/minimum-size-subarray-sum/ */
class Solution {
    public int minSubArrayLen(int target, int[] nums) 
    {
        int sum=0;
        int minCount=Integer.MAX_VALUE;
        int l=0;
        int r=0;
        while (r<nums.length)
        {
            sum+=nums[r];
            if (sum>=target)
            {
                minCount=Math.min(minCount,r-l+1);
                while (sum>=target)
                {
                    sum-=nums[l];
                    l++;
                    if (sum>=target)
                    {
                        minCount=Math.min(minCount,r-l+1);
                    }
                }
            }
            r++;
        }    
        if (minCount==Integer.MAX_VALUE)
        {
            return 0;
        }
        return minCount;
    }
}