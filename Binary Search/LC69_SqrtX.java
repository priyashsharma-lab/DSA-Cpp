/*Leetcode: 69. Sqrt(x)
Link: https://leetcode.com/problems/sqrtx/ */

class Solution {
    public int mySqrt(int x) 
    {
        long low=1;
        long high=(x/2)+1;
        long ans=Long.MIN_VALUE;
        if (x==0)
        {
            return 0;
        }
        if (x==1)
        {
            return 1;
        }
        while (low<=high)
        {
            long mid=(low+high)/2;
            if (mid*mid==x)
            {
                return (int)mid;
            }
            else if (mid*mid>x)
            {
                high=mid-1;
            }
            else
            {
                ans=Math.max(ans,mid);
                low=mid+1;
            }
        }    
        return (int)ans;
    }
}
