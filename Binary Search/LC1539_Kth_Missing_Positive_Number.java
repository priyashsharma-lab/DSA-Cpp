/*Leetcode: 1539. Kth Missing Positive Number
Link: https://leetcode.com/problems/kth-missing-positive-number/ */

class Solution {
    public int findKthPositive(int[] arr, int k) 
    {
        int low=0;
        int high=arr.length-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (arr[mid]-(mid+1)<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }    
        return high+k+1;
        // return low+k; or
    }
}