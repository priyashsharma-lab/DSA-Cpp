/*Leetcode: 128. Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/ */

//Aproach 1: COunt links and then at the end add 1 to represent length
class Solution {
    public int longestConsecutive(int[] nums)
    {
        if (nums.length==0)
        {
            return 0;
        }
        Arrays.sort(nums);
        int count=0;
        int maxCount=0;
        for (int i=0;i<nums.length-1;i++)
        {
            if (nums[i]==nums[i+1])
            {
                continue;
            }
            if (nums[i]!=nums[i+1]-1)
            {
                count=0;
                continue;
            }
            count++;
            maxCount=Math.max(maxCount,count);
        }    
        return maxCount+1;
    }
}

// Approach 2: Count actual length of seq instead of links
int current = 1;
int longest = 1;

for (int i = 1; i < nums.length; i++) {
    if (nums[i] == nums[i - 1]) continue;

    if (nums[i] == nums[i - 1] + 1)
        current++;
    else
        current = 1;

    longest = Math.max(longest, current);
}

return longest;

// Approach 3 : HashSet to remove sorting
