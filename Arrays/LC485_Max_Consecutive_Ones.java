/*Leetcode: 485. Max Consecutive Ones
Link: https://leetcode.com/problems/max-consecutive-ones/ */

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) 
    {
        int oneCount=0;
        int maxOneCount=0;
        for (int i=0;i<nums.length;i++)
        {
            if (nums[i]==1)
            {
                oneCount++;
            }
            else
            {
                maxOneCount=Math.max(maxOneCount,oneCount);
                oneCount=0;
            }
            if (i==nums.length-1)
            {
                maxOneCount=Math.max(maxOneCount,oneCount);
            }
        }    
        return maxOneCount;    
    }
}
