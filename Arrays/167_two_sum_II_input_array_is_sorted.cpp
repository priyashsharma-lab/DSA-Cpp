/*Leetcode: 167. Two Sum II - Input Array is sorted
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Approach 1: Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Two Pointer
Time: O(n)
Space: O(1)


---------------Approach 1: Brute Force---------------*/
/*class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        for (int i=0;i<numbers.size();i++)
        {
            for (int j=i+1;j<numbers.size();j++)
            {
                if (numbers[i]+numbers[j]==target)
                {
                    numbers.clear();
                    numbers.push_back(i+1);
                    numbers.push_back(j+1);
                }
            }
        }    
        return numbers;
    }
};*/

// ---------------Approach 2: Two Pointer (Used)---------------
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l=0;
        int r=numbers.size()-1;  
        int sum=0;
        while (r>l)
        {
            sum=numbers[l]+numbers[r];
            if (sum==target)
            {
                return {l+1,r+1};
            }
            if (sum>target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }  
        return {l+1,r+1};
    }
};