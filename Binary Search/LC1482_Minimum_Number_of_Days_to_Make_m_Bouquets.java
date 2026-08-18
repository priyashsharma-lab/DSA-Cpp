/*Leetcode: 1482. Minimum Number of Days to Make m Bouquets
Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/  */

class Solution {
    public int minDays(int[] bloomDay, int m, int k) 
    {
        if (bloomDay.length<m*k)
        {
            return -1;
        }
        int low=1;  
        int high=Arrays.stream(bloomDay).max().getAsInt();
        int ans=-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            int boqCount=0;
            int x=0;
            for (int i=0;i<bloomDay.length;i++)
            {
                if (mid>=bloomDay[i])
                {
                    x++;
                    if (x==k)
                    {
                        boqCount++;
                        x=0;
                    }
                }
                else
                {
                    x=0;
                }
                if (boqCount==m)
                {
                    break;
                }
            }
            if (boqCount>=m)
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
