/*Leetcode: 26. Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array

Approach 1:  Two pointer
Time: O(n)
Space:O(1)

*/

// ---------------Approach 1: Two pointer---------------
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int l=0;
        int r=0;
        while (r<nums.size())
        {
            if (nums[l]!=nums[r])
            {
                l++;
                nums[l]=nums[r];
            }
            r++;
        }
        return l+1;
    }
};