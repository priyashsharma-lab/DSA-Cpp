/*Leetcode: 2348. Number of Zero-Filled Subarrays
Link: https://leetcode.com/problems/number-of-zero-filled-subarrays

Approach 1:  Using formula (n*(n+1))/2
Time: O(n)
Space:O(1)

Approach 2: Without formula
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Using formula (n*(n+1))/2---------------

/*class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans=0;
        long long n=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]!=0)
            {
                ans+=(n*(n+1))/2;
                n=0;
                continue;
            }
            n++;
        }    
        ans+=(n*(n+1))/2;
        return ans;
    }
};*/

// ---------------Approach 2: Without formula---------------

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans = 0;
        long long cnt = 0;

        for (int x : nums)
        {
            if (x == 0)
            {
                cnt++;
                ans += cnt;
            }
            else
            {
                cnt = 0;
            }
        }

        return ans;
    }
};