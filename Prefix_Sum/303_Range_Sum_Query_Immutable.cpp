/*Leetcode: 303. Range Sum Query - Immutable
Link: https://leetcode.com/problems/range-sum-query-immutable

Approach 1:   Prefix Sum
Time: O(n)
Space:O(n)

*/

// ---------------Approach 1: Prefix Sum---------------
class NumArray {
public:
    int* prefix;
    NumArray(vector<int>& nums) 
    {
        prefix=new int[nums.size()];
        prefix[0]=nums[0];
        for (int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) 
    {
        if (left==0)
        {
            return prefix[right];
        }
        return prefix[right]-prefix[left-1];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */