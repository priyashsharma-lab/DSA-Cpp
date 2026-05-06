/*Leetcode: 438. Find All Anagrams in a String
Link: https://leetcode.com/problems/find-all-anagrams-in-a-string

Approach 1:  Sorting with sliding window
Time: O(n^2)
Space:O(1)

Approach 2: Sliding Window with vector mapping
Time: O(n)
Space: O(1)
*/

// ---------------Approach 1: Sorting with Sliding window---------------
/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int l=0;
        int r=0;
        vector<int> ans;
        sort(p.begin(),p.end());
        while (r<s.size())
        {
            if (r-l==p.size()-1)
            {
                string temp=s.substr(l,r-l+1);
                sort(temp.begin(),temp.end());
                if (temp==p)
                {
                    ans.push_back(l);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};*/

// ---------------Approach 2: Sliding Window with vector mapping---------------
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int l=0;
        int r=0;
        vector<int> ans;
        vector<int> v(26,0);
        int chk=0;
        for (int i=0;i<p.size();i++)
        {
            int index=(int)p[i]-(int)'a';
            v[index]++;
        }
        vector<int> temp=v;
        while (r<s.size())
        {
            int index=(int)s[r]-(int)'a';
            if (temp[index]==0)
            {
                while (temp[index]==0)
                {
                    temp[(int)s[l]-(int)'a']++;
                    l++;
                    chk--;
                }
            }
            temp[index]--;
            chk++;
            if (chk==p.size())
            {
                ans.push_back(l);
            }
            r++;
        }        
        return ans;
    }
};