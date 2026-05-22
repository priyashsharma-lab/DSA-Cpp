/*Leetcode: 14. Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix

Approach 1: IDk
Time: O(n)
Space:O(1)

// ---------------Approach 1: Two Pointer (using isalnum() function)---------------*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans="";
        bool b=0;
        for (int i=0;i<strs[0].size();i++)
        {
            char c=strs[0][i];
            for (int j=0;j<strs.size();j++)
            {
                if (c!=strs[j][i])
                {
                    b=1;
                    break;
                }
            }
            if (b==1)
            {
                break;
            }
            ans+=strs[0][i];
        }    
        return ans;
    }
};