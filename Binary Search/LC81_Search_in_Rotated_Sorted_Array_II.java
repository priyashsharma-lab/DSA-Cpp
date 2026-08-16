/*Leetcode: 81. Search in Rotated Sorted Array II
Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/  */
class Solution {
    public boolean search(int[] nums, int target) 
    {
        int low=0;
        int high=nums.length-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (nums[mid]==target)
            {
                return true;
            }
            else if (nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                low++;
                high--;
            }
            else if (nums[low]<=nums[mid])
            {
                if (nums[low]<=target && nums[mid]>=target)
                {   
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if (target>=nums[mid] && target<=nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }    
        return false;    
    }
}