/*Leetcode: 392. Is Subsequence
Link: https://leetcode.com/problems/is-subsequence

Approach 1: 2 pointer
Time: O(n)
Space:O(1)

*/

// ---------------Approach 1: 2 pointer---------------
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int sp=0;
        int tp=0;
        while (tp<t.size())
        {
            if (s[sp]==t[tp])
            {
                sp++;
            }
            tp++;
        }
        if (sp>=s.size())
        {
            return true;
        }
        return false;
    }
};
