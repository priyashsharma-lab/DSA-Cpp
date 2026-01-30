/*Leetcode: 217. Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/

Approach 1: Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Hashset or Hashmap
Time: O(n)
Space: O(n)

Approach 3: Sorting
Time: O(nlogn)
Space: O(1)

---------------Approach 2: Hashset---------------*/
/*class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        int ctr=nums.size();
        for (int i=0;i<ctr;i++)
        {
            if (s.find(nums[i])!=s.end())
            {
                return 1;
            }
            s.insert(nums[i]);
        }
        return 0;    
    }
};*/

// ---------------Approach 3: Sorting (Used)---------------
#include <bits/stdc++.h>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ctr=nums.size();
        for (int i=0;i<ctr-1;i++)
        {
            if (nums[i]==nums[i+1])
            {
                return 1;
            }
        }    
        return 0;
    }
};