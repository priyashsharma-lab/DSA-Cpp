/*Leetcode: 567. Permutation in String
Link: https://leetcode.com/problems/permutation-in-string

Approach 1:  Sorting with sliding window
Time: O(n^2)
Space:O(1)

Approach 2: Sliding Window with hashmap
Time: O(n)
Space: O(1)
*/

// ---------------Approach 1: Sorting with Sliding window---------------
/*#include<iostream>
#include<algorithm>
#include<string_view>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int l=0;
        int r=0;
        string temp;
        sort(s1.begin(),s1.end());
        while (r<s2.size())
        {
            temp+=s2[r];
            if (r-1==s1.size()-1)
            {
                string s=temp;
                sort(s.begin(),s.end());
                if (s==s1)
                {
                    return 1;
                }

                temp.erase(0,1);
                l++;
            }
            r++;
        }
        return 0;
    }
};*/

// ---------------Approach 2: Sliding Window with hashmap---------------

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int l=0;
        int r=0;
        int chk=0;
        unordered_map<char,int> temp;
        for (int i=0;i<s1.size();i++)
        {
            if (temp.find(s1[i])==temp.end())
            {
                temp.insert({s1[i],1});
            }
            else
            {
                temp[s1[i]]++;
            }
        }
        unordered_map<char,int> m=temp;
        while (r<s2.size())
        {
            if (m.find(s2[r])==m.end())
            {
                m=temp;
                r++;
                l=r;
                chk=0;
                continue;
            }
            else
            {
                if (m[s2[r]]==0)
                {
                    while (m[s2[r]]==0)
                    {
                        m[s2[l]]++;
                        l++;
                        chk--;
                    }
                }
                m[s2[r]]--;
                chk++;
                if (chk==s1.size())
                {
                    return 1;
                }
            }
            r++;
        }
        return 0;
    }
};