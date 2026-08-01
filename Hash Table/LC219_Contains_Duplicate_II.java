/*Leetcode: 219. Contains Duplicate II
Link: https://leetcode.com/problems/contains-duplicate-ii/ */

//Approach 1: Using HashMap(store index) 
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) 
    {
        HashMap<Integer,Integer> m=new HashMap<>();
        for (int i=0;i<nums.length;i++)
        {
            if (m.containsKey(nums[i]))
            {
                int l=m.get(nums[i]);
                int r=i;
                if (r-l<=k)
                {
                    return true;
                }
            }
            m.put(nums[i],i);
        }
        return false;
    }
}
// we can eliminate m.containsKey with get to reduce one hash lookup

//Approach 2: Sliding Window with HashSet (Time Complexity is same but Space Complexity is O(min(k,n)))
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) 
    {
        HashSet<Integer> s=new HashSet<>();
        int l=0;
        int r=0;
        while (r<nums.length)
        {
            if (r-l>k)
            {
                s.remove(nums[l]);
                l++;
            }
            if (s.contains(nums[r]))
            {
                if (r-l<=k)
                {
                    return true;
                }
            }
            s.add(nums[r]);
            r++;
        }    
        return false;
    }
}