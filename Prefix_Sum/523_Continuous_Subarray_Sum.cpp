/*Leetcode: 523. Continuous Subarray Sum
Link: https://leetcode.com/problems/continuous-subarray-sum

Approach 1:   Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Prefix Sum
Time: O(n)
Space: O(n)

*/

// ---------------Approach 1: Brute Force---------------
/*class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int sum=0;
        for (int i=0;i<nums.size();i++)
        {
            for (int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if (j-i+1<2)
                {
                    continue;
                }
                if (sum%k==0)
                {
                    return 1;
                }
            }
            sum=0;
        } 
        return 0;
    }
};*/
// ---------------Approach 2: Prefix Sum---------------
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        // remainder 0 seen before array starts
        mp[0] = -1;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            int rem = sum % k;

            // handle negative k cases
            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end()) {

                // subarray length must be >= 2
                if (i - mp[rem] >= 2)
                    return true;

            } else {

                // store first occurrence only
                mp[rem] = i;
            }
        }

        return false;
    }
};