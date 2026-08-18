/*Leetcode: 1283. Find the Smallest Divisor Given a Threshold
Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/ */

class Solution {
    public int smallestDivisor(int[] nums, int threshold) 
    {
        int low=1;
        int high=Arrays.stream(nums).max().getAsInt();
        int ans=low;
        while (low<=high)
        {
            int mid=(low+high)/2;
            int sum=0;
            for (int i:nums)
            {
                sum+=Math.ceil((double)i/mid);
                // sum += (i + mid - 1) / mid; use this to reduce time 
                if (sum>threshold)
                {
                    break;
                }
            }
            if (sum<=threshold)
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
