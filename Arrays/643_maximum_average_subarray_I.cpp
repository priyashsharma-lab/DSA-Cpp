/*Leetcode: 643. Maximum Average Subarray I
Link: https://leetcode.com/problems/maximum-average-subarray-i/

Approach 1: Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Sliding Window
Time: O(n)
Space: O(1)


---------------Approach 1: Brute Force---------------*/
/*class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double maxAvg=-1e18;
        double sum=0;
        int l=0;
        int r=l+k-1;
        while (r<nums.size())
        {
            for (int i=l;i<=r;i++)
            {
                sum+=nums[i];
            }
            double avg=sum/k;
            double avg=accumulate(itL,itL+k,0.0)/k; This can also be used to find avg
            if (avg>maxAvg)
            {
                maxAvg=avg;
            }
            l++;
            r=l+k-1;
            sum=0;
        }   
        return maxAvg;
    }
};*/

// ---------------Approach 2: Sliding Window (Used)---------------
#include <bits/stdc++.h>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double maxAvg=-1e18;
        double sum=0;
        int l=0;
        int r=0;
        while (r<nums.size())
        {
            sum+=nums[r];
            if (r-l==k-1)
            {
                double avg=sum/k;
                if (avg>maxAvg)
                {
                    maxAvg=avg;
                }
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return maxAvg;
    }
};


// Tiny extra notes

/*You could also track maxSum instead of maxAvg and divide once at the end, but what you wrote is totally fine.

Using double for sum is okay, but you could also use long long for better precision and convert at the end.*/