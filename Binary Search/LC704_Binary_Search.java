/*Leetcode: 704. Binary Search
Link: https://leetcode.com/problems/binary-search/  */

class Solution {
    public int search(int[] a, int key) 
    {
        int n=a.length;
        int low=0;
        int high=n-1;
        int mid;
        while (low<=high)
        {
            mid=(low+high)/2;
            if (key==a[mid])
            {
                return mid;
            }
            else if (key>a[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;    
    }
}