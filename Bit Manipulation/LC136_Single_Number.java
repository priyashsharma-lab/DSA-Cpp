/*Leetcode: 136. Single Number
Link: https://leetcode.com/problems/single-number/  */

//Without Bit Manipulation 
class Solution {
    public int singleNumber(int[] nums) 
    {
        HashMap<Integer,Integer> m=new HashMap<>();
        for (int i=0;i<nums.length;i++)
        {
            m.put(nums[i],m.getOrDefault(nums[i],0)+1);
        }    
        for (int i=0;i<nums.length;i++)
        {
            if (m.get(nums[i])==1)
            {
                return nums[i];
            }
        }
        return 0;
    }
}

// With Bit Manipulation
class Solution {
    public int singleNumber(int[] nums) 
    {
        int ans=nums[0];
        for (int i=1;i<nums.length;i++)
        {
            ans=ans^nums[i];
        }
        return ans;
    }
}