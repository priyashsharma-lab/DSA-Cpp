/*Leetcode: 11. Container With Most Water
Link: https://leetcode.com/problems/container-with-most-water/

Approach 1: Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Two Pointer
Time: O(n)
Space: O(1)


---------------Approach 1: Brute Force---------------*/
/*class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxA=0;
        for (int i=0;i<height.size();i++)
        {
            for (int j=i+1;j<height.size();j++)
            {
                int minH=min(height[i],height[j]);
                int area=(j-i)*minH;
                if (area>maxA)
                {
                    maxA=area;
                }
            }
        }
        return maxA;
    }
};*/

/*---------------Approach 2: Two Pointer (Used)---------------*/
#include <bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int l=0;
        int r=height.size()-1;
        int maxA=0;
        while (l<r)
        {
            int minH=min(height[l],height[r]);
            int area=(r-l)*minH;
            if (area>maxA)
            {
                maxA=area;
            }
            if (height[l]>height[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return maxA;
    }
};