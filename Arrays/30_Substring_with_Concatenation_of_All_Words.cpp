/*Leetcode: 30. Substring with Concatenation of All Words
Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words

Approach 1:  Sliding window (high time complexity)
Time: O(n^2)
Space:O(1)

Approach 2: Sliding Window with hashmap
Time: O(n)
Space: O(1)
*/

// ---------------Approach 1: Sliding window (high time complexity)---------------
/*class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> ans;

        unordered_map<string,int> m;
        for (int i=0;i<words.size();i++)
        {
            if (m.find(words[i])==m.end())
            {
                m.insert({words[i],1});
            }
            else
            {
                m[words[i]]++;
            }
        }

        for (int i=0;i<words[0].size();i++)   
        {
            int l=i;
            int r=i+words[0].size();
            int chk=0;

            unordered_map<string,int> temp=m;

            while (r<=s.size())
            {
                string str=s.substr(r-words[0].size(),words[0].size());

                if (temp.find(str)==temp.end())
                {
                    l=r;
                    r+=words[0].size();
                    temp=m;
                    chk=0;
                    continue;
                }
                else
                {
                    if (temp[str]==0)
                    {
                        while(temp[str]==0)
                        {
                            string k=s.substr(l,words[0].size());
                            temp[k]++;
                            chk--;
                            l+=words[0].size();
                        }
                    }

                    temp[str]--;
                    chk++;

                    if (chk==words.size())
                    {
                        ans.push_back(l);
                    }
                }

                r+=words[0].size();
            }
        }

        return ans;
    }
};*/