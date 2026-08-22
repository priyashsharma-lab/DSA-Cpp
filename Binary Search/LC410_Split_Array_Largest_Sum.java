/*Leetcode: 410. Split Array Largest Sum
Link: https://leetcode.com/problems/split-array-largest-sum/ */

class Solution {
    public int splitArray(int[] nums, int k) 
    {
        int low=Arrays.stream(nums).max().getAsInt();
        int high=Arrays.stream(nums).sum();
        int ans=low;
        if (k>nums.length)
        {
            return -1;
        }        
        if (k==nums.length)
        {
            return low;
        }
        while (low<=high)
        {
            int mid=(low+high)/2;
            int subArrayCount=1;
            int subArraySum=0;
            for (int i=0;i<nums.length;i++)
            {
                if (subArraySum+nums[i]>mid)
                {
                    subArrayCount++;
                    subArraySum=nums[i];
                }
                else
                {
                    subArraySum+=nums[i];
                }
                if (subArrayCount > k) 
                {
                    break;
                }
            }
            if (subArrayCount<=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
}
