/*Leetcode: 1011. Capacity To Ship Packages Within D Days
Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ */

class Solution {
    public int shipWithinDays(int[] weights, int days) 
    {
        int low=Arrays.stream(weights).max().getAsInt();;
        int high=Arrays.stream(weights).sum();
        int ans=high;
        while (low<=high)
        {
            int mid=(low+high)/2;
            int minDays=0;
            int cap=0;
            for (int i=0;i<weights.length;i++)
            {   
                cap+=weights[i];
                if (cap==mid)
                {
                    minDays++;
                    cap=0;
                }
                else if (cap>mid)
                {
                    i--;
                    cap=0;
                    minDays++;
                }
            }
            if (cap>0)
            {
                minDays++;
            }
            if (minDays<=days)
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
