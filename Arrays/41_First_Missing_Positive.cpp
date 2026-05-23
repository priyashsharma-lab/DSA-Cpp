/*Leetcode: 41. First Missing Positive
Link: https://leetcode.com/problems/first-missing-positive

Approach 1:   Using sorting
Time: O(nlogn)
Space:O(1)

Approach 2: O(n) sol
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Using sorting---------------
/*class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=1;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]<=0)
            {
                continue;
            }
            if (nums[i]==ans)
            {
                ans++;
            }
        }
        return ans;
    }   
};*/

// ---------------Approach 2: O(n) sol---------------
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            while (nums[i] >= 1 &&
                   nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {

                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};