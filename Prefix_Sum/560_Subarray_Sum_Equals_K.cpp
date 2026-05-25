/*Leetcode: 560. Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k

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
    int subarraySum(vector<int>& nums, int k) 
    {
        int sum=0;
        int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            for (int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if (sum==k)
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
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> m;
        m.reserve(nums.size());

        m[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int num : nums) {

            sum += num;

            auto it = m.find(sum - k);

            if(it != m.end()) {
                ans += it->second;
            }

            m[sum]++;
        }

        return ans;
    }
};