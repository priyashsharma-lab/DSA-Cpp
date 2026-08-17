/*Leetcode: 154. Find Minimum in Rotated Sorted Array II
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/  */

class Solution {
    public int findMin(int[] nums) 
    {
        int low=0;
        int high=nums.length-1;
        int minAns=Integer.MAX_VALUE;
        if (nums.length==1)
        {
            return nums[0];
        }
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (nums[low]==nums[mid] && nums[mid]==nums[high])
            {

                minAns=Math.min(minAns,nums[low]);
                low++;
                high--;
            }
            else if (nums[low]<=nums[mid])
            {
                minAns=Math.min(minAns,nums[low]);
                low=mid+1;
            }
            else
            {
                minAns=Math.min(minAns,nums[mid]);
                high=mid-1;
            }
        }    
        return minAns;
    }
}
