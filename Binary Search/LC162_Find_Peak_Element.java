/*Leetcode: 162. Find Peak Element
Link: https://leetcode.com/problems/find-peak-element/  */

// Using 2 pointers approach TC= O(n)
class Solution {
    public int findPeakElement(int[] nums) 
    {
        int l=-1;
        int r=1;
        if (nums.length==1)
        {
            return 0;
        }
        while (r!=nums.length+1)
        {
            if (l==-1)
            {
                if (nums[r-1]>nums[r])
                {
                    return r-1;
                }
            }
            else if (r==nums.length)
            {
                if (nums[r-1]>nums[l])
                {
                    return r-1;
                }
            }
            else if (nums[r-1]>nums[l] && nums[r-1]>nums[r])
            {
                return r-1;
            }
            l++;
            r++;
        }    
        return -1;
    }
}

// Using Binary Search TC= O(log n)

class Solution {
    public int findPeakElement(int[] nums) {
        int low = 0;
        int high = nums.length - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Going uphill → peak is on the right
                low = mid + 1;
            } else {
                // Going downhill → peak is at mid or on the left
                high = mid;
            }
        }

        return low;
    }
}