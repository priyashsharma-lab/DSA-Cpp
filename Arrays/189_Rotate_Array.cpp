/*Leetcode: 189. Rotate Array
Link: https://leetcode.com/problems/rotate-array

Approach 1:  Brute force
Time: O(n^2)
Space:O(n)

Approach 2: Using a temp vector
Time: O(n)
Space: O(n)

Approach 3: Reverse the array
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Brute Force---------------
/*class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> temp=nums;
        for (int i=0;i<k;i++)
        {
            for (int j=0;j<nums.size();j++)
            {
                if (j==nums.size()-1)
                {
                    nums[0]=temp[j];
                    continue;
                }
                nums[j+1]=temp[j];
            }
            temp=nums;
        }
    }
};*/

// ---------------Approach 2: Using a temp vector ---------------
/*class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if (nums.size()==1 || k==0)
        {
            return;
        }
        vector<int> v=nums;
        int Lindex=nums.size()-1;
        for (int i=0;i<k;i++)
        {
            if (Lindex==nums.size()-1)
            {
                Lindex=0;
                continue;
            }
            Lindex++;
        }
        nums[Lindex]=v[nums.size()-1];
        int ni=Lindex+1;
        for (int i=0;i<nums.size()-1;i++)
        {
            if (ni==nums.size())
            {
                ni=0;
            }
            nums[ni]=v[i];
            ni++;
        }
    }
};*/

// ---------------Approach 3: Reverse the array ---------------
class Solution {
public:
    void reverse(vector<int>& nums, int l, int r)
    {
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();

        k %= n;

        reverse(nums, 0, n - 1);

        reverse(nums, 0, k - 1);

        reverse(nums, k, n - 1);
    }
};