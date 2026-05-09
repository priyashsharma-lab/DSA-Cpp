/*Leetcode: 238. Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self

Approach 1:  Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Dynamic Programming with O(n) storage
Time: O(n)
Space: O(n)

Approach 3: Dynamic Programming with O(1) storage
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Brute Force---------------

/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int p=1;
        vector<int> ans(nums.size());
        for (int i=0;i<nums.size();i++)
        {
            for (int j=0;j<nums.size();j++)
            {
                if (i==j)
                {
                    continue;
                }
                p=p*nums[j];
            }
            ans[i]=p;
            p=1;
        }    
        return ans;
    }
};*/

// ---------------Approach 2: Dynamic Programming with O(n) storage---------------
/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> ans(nums.size());
        int pp=1;
        int ps=1;
        int r=nums.size()-1;
        for (int i=0;i<nums.size();i++)
        {
            if (i==0)
            {
                prefix[i]=1;
                // continue;
            }
            if (r==nums.size()-1)
            {
                suffix[r]=1;
                r--;
                continue;
            }
            pp*=nums[i-1];
            prefix[i]=pp;
            ps*=nums[r+1];
            suffix[r]=ps;
            r--;
        }
        for (int i=0;i<nums.size();i++)
        {
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
};*/

// ---------------Approach 3: Dynamic Programming with O(1) storage---------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        int p=1;
        for (int i=0;i<nums.size();i++)
        {
            if (i==0)
            {
                ans[i]=1;
                continue;
            }
            else
            {
                p*=nums[i-1];
                ans[i]=p;
            }
        }
        p=1;
        // int r=nums.size()-1;
        for (int i=nums.size()-1;i>=0;i--)
        {
            if (i==nums.size()-1)
            {
                ans[i]=ans[i]*1;
                continue;
            }
            else
            {
                p*=nums[i+1];
                ans[i]=ans[i]*p;
            }
        }
        return ans;
    }
};