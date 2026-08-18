/*Leetcode: 875. Koko Eating Bananas
Link: https://leetcode.com/problems/koko-eating-bananas/  */

class Solution {
    public int minEatingSpeed(int[] piles, int h) 
    {
        long low=1;
        long high=Arrays.stream(piles).max().getAsInt();
        long ans=Long.MAX_VALUE;
        while (low<=high)
        {
            long mid=(low+high)/2;
            long totalHrs=0;
            for (int i:piles)
            {
                totalHrs+=Math.ceil((double)i/mid);
                // totalHrs += (i + mid - 1) / mid; use this to reduce time complexity
                if (totalHrs>h)
                {
                    break;
                }
            }
            if (totalHrs<=h)
            {
                ans=Math.min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }    
        return (int)ans;
    }
}
