/*Leetcode: 15. 3Sum
Link: https://leetcode.com/problems/3sum/

Approach 1: Brute force
Time: O(n^3)
Space:O(n^2)

Approach 2: Two Pointer
Time: O(n^2)
Space: O(n^2) 


---------------Approach 1: Brute Force---------------*/

/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        for (int i=0;i<nums.size();i++)
        {
            for (int j=i+1;j<nums.size();j++)
            {
                for (int k=j+1;k<nums.size();k++)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    if (i!=j && i!=k && j!=k && sum==0)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        if (find(ans.begin(),ans.end(),temp)==ans.end())
                        {
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};*/

/*---------------Approach 2: Two Pointer (Used)---------------*/
#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while (i<nums.size())
        {
            if (i>0 && nums[i]==nums[i-1])
            {
                i++;
                continue;
            }
            int l=i+1;
            int r=nums.size()-1;
            while (l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if (sum>0)
                {
                    r--;
                }
                else if (sum<0)
                {
                    l++;
                }
                else
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while (l<r && nums[l]==nums[l-1])
                    {
                        l++;
                    }
                    while (l<r && nums[r]==nums[r+1])
                    {
                        r--;
                    }
                }
            }
            i++;
        }
        return ans;
    }
};