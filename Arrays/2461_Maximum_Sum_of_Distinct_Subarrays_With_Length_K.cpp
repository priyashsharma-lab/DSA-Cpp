/*Leetcode: 2461. Maximum Sum of Distint Subarrays With Length K
Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

Approach 1: Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Sliding Window
Time: O(n)
Space: O(1)
*/

// ---------------Approach 1: Brute Force---------------
/*class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int l=0;
        int r=0;
        int sum=0;
        int maxSum=0;
        bool flag=0;
        while (r<nums.size())
        {
            sum+=nums[r];
            if (r-l==k-1)
            {
                for (int i=l;i<r;i++)
                {
                    for (int j=i+1;j<=r;j++)
                    {
                        if (nums[i]==nums[j])
                        {
                            flag=1;
                        }
                    }
                }
                if (sum>maxSum && flag==0)
                {
                    maxSum=sum;
                }
                sum-=nums[l];
                l++;
            }
            flag=0;
            r++;
        }    
        return maxSum;
    }
}; */

// ---------------Approach 2: Sliding Window---------------
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int l=0;
        int r=0;
        long long sum=0;
        long long maxSum=0;
        unordered_map<int,int> temp;
        bool flag=0;
        while (r<nums.size())
        {
            if (temp.find(nums[r])==temp.end())
            {
                sum+=nums[r];
                temp.insert({nums[r],1});
            }
            else
            {
                while(temp.find(nums[r])!=temp.end())
                {
                    sum-=nums[l];
                    temp.erase(nums[l]);
                    l++;
                }
                sum+=nums[r];
                temp.insert({nums[r],1});
            }

            if (r-l==k-1)
            {
                if (sum>maxSum)
                {
                    maxSum=sum;
                }
                sum-=nums[l];
                temp.erase(nums[l]);
                l++;

            }
            r++;
        }    
        return maxSum;
    }
};