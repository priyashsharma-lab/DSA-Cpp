/*Leetcode: 283. Move Zeros
Link: https://leetcode.com/problems/move-zeroes/

Approach 1: Brute force
Time: O(n^2)
Space:O(n)

Approach 2: Two Pointer
Time: O(n)
Space: O(1)


---------------Approach 1: Brute Force---------------*/
/*class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        vector<int> c(nums.size());
        auto it=c.begin();
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]!=0)
            {
                c.erase(it);
                c.insert(it,nums[i]);
                it++;
            }
        }    
        nums.swap(c);
    }
};*/

/*---------------Approach 2: Two Pointer (Used)---------------*/
#include <bits/stdc++.h>
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
       int l=0;
       int r=0;
       while (r<nums.size())
       {
            if (nums[r]!=0)
            {
                int temp=nums[l];
                nums[l]=nums[r];
                nums[r]=temp;
                l++;
            }
            r++;
       } 
    }
};