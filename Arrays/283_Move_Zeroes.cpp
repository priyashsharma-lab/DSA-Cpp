/*Leetcode: 283. Move Zeroes
Link: https://leetcode.com/problems/move-zeroes

Approach 1:  Two pointer

*/
// ---------------Approach 1: Two Pointer---------------
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
       int l=0;
       int r=0;
       while (r<nums.size())
       {
            if (nums[r]!=0)
            {
                int temp=nums[l];
                nums[l]=nums[r];
                nums[r]=temp;
                l++;
            }
            r++;
       } 
    }
};