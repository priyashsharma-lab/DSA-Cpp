/*Leetcode: 334. Increasing Triplet Subsequence
Link: https://leetcode.com/problems/increasing-triplet-subsequence

Approach 1:  Brute Force
Time: O(n^3)
Space:O(1)

Approach 2: Without formula
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Brute Force---------------
/*class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        for (int i=0;i<nums.size()-2;i++)
        {
            for (int j=1;j<nums.size()-1;j++)
            {
                for (int k=2;k<nums.size();k++)
                {
                    if (i<j && j<k && nums[i]<nums[j] && nums[j]<nums[k])
                    {
                        return true;
                    }
                }
            }
        }    
        return false;
    }
};*/

// ---------------Approach 2: Greedy---------------
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int minElement=INT_MAX;
        int secondMinElement=INT_MAX;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]<=minElement)
            {
                minElement=nums[i];
            }
            else if (nums[i]<=secondMinElement)
            {
                secondMinElement=nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};