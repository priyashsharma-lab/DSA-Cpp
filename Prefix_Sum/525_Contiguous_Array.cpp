/*Leetcode: 525. Contiguous Array
Link: hhttps://leetcode.com/problems/contiguous-array

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
    int findMaxLength(vector<int>& nums) 
    {
        int one=0;
        int zero=0;
        int maxSize=0;
        for (int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if (nums[j]==1)
                {
                    one++;
                }
                else
                {
                    zero++;
                }
                int size=j-i+1;
                if (zero==one)
                {
                    if (size>maxSize)
                    {
                        maxSize=size;
                    }
                }
            }
            one=0;
            zero=0;
        }    
        return maxSize;
    }
};*/

// ---------------Approach 2: Prefix Sum---------------
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        
        firstIndex[0] = -1;   // prefix sum 0 before array starts
        
        int sum = 0;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            // treat 0 as -1
            if (nums[i] == 0)
                sum += -1;
            else
                sum += 1;
            
            // if same sum seen before
            if (firstIndex.count(sum)) {
                ans = max(ans, i - firstIndex[sum]);
            } else {
                // store first occurrence only
                firstIndex[sum] = i;
            }
        }
        
        return ans;
    }
};