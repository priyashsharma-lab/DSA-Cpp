/*Leetcode: 42. Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water/

Approach 1: Two Pointer
Time: O(n)
Space:O(1)

---------------Approach 1: Two Pointer (Used)---------------*/
#include <bits/stdc++.h>
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int ans=0;
        int l=0;
        int r=height.size()-1;
        int Lmax=height[l];
        int Rmax=height[r];
        while (l<r)
        {
            if (Lmax<Rmax)
            {
                l++;
                Lmax=max(Lmax,height[l]);
                ans+=Lmax-height[l];
            }
            else
            {
                r--;
                Rmax=max(Rmax,height[r]);
                ans+=Rmax-height[r];
            }
        }    
        return ans;
    }
};
