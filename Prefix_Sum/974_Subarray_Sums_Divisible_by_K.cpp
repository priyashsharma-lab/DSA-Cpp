/*Leetcode: 974. Subarray Sums Divisible by K
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k

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
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int sum=0;
        int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            for (int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if (sum%k==0)
                {
                    ans++;
                }
            }
            sum=0;
        }    
        return ans;
    }
};*/

// ---------------Approach 2: Prefix Sum---------------
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int num : nums) {

            sum += num;

            // handle negative remainder
            int rem = (sum % k + k) % k;

            if(mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};