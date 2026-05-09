/*Leetcode: 169. Majority Element
Link: https://leetcode.com/problems/majority-element

Approach 1:  Using Hashmap
Time: O(n)
Space:O(n)

Approach 2: Without Hashmap
Time: O(n)
Space: O(1)
*/

// ---------------Approach 1: With Hashmap---------------
/*class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        int major=nums.size()/2;
        for (int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int maxi=0;
        for (int i=0;i<nums.size();i++)
        {
            if (m[nums[i]]>major)
            {
                maxi=nums[i];
            }
        }  
        return maxi;  
    }
};*/

// ---------------Approach 2: Without Hashmap (Boyer–Moore Voting Algorithm)---------------
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count=0;
        int candidate=0;
        for (int i:nums)
        {
            if (count==0)
            {
                candidate=i;
            }
            if (candidate==i)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};