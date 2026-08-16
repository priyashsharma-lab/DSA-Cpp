/*Leetcode: 34. Find First and Last Position of Element in Sorted Array
Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/  */
    class Solution {
        public int[] searchRange(int[] nums, int target) 
        {
            int low=0;
            int high=nums.length-1;
            int first=-1;
            while (low<=high)
            {
                int mid=(low+high)/2;
                if (nums[mid]==target)
                {
                    first=mid;
                    high=mid-1;
                }
                else if (target<nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }    
            if (first==-1)
            {
                return new int[]{-1,-1};
            }
            low=0;
            high=nums.length-1;
            int last=-1;
            while (low<=high)
            {
                int mid=(low+high)/2;
                if (nums[mid]==target)
                {
                    last=mid;
                    low=mid+1;
                }
                else if (target<nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }    
            return new int[]{first,last};
        }
    }