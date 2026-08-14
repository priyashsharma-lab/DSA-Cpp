/*Leetcode: 152. Maximum Product Subarray
Link: https://leetcode.com/problems/maximum-product-subarray/  */

class Solution {
    public int maxProduct(int[] nums) 
    {
        int maxi=nums[0];
        int mini=nums[0];
        int mx=nums[0];
        int temp=0;
        for (int i=1;i<nums.length;i++)
        {
            if (nums[i]>0)
            {
                maxi=Math.max(nums[i],nums[i]*maxi);
                mini=Math.min(nums[i],nums[i]*mini);
            }
            else if (nums[i]==0)
            {
                maxi=mini=0;
            }
            else
            {
                temp=maxi;
                maxi=Math.max(nums[i],nums[i]*mini);
                mini=Math.min(nums[i],nums[i]*temp);
            }
            mx=Math.max(mx,maxi);
        }    
        return mx;
    }
}