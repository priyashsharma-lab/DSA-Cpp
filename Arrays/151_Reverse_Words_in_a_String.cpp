/*Leetcode: 151. Reverse Words in a String
Link: https://leetcode.com/problems/reverse-words-in-a-string

Approach 1:  Using multiple loops and checks
Time: O(n)
Space:O(1)

Approach 2: Using substr function
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Using multiple loops and checks---------------
/*class Solution {
public:
    string reverseWords(string s) 
    {
        string ans;
        int l=s.size()-1;
        int r=l;
        while (l>=0)
        {
            if (s[l]==' ')
            {
                string t="";
                for (int i=l+1;i<=r;i++)
                {
                    if (s[i]==' ')
                    {
                        continue;
                    }
                    t+=s[i];
                }
                if (t!="")
                {
                    if(ans!="")
                    {
                        ans+=' ';
                    }
                    ans+=t;
                }
                r=l-1;
            }
            if (l==0)
            {
                string t="";
                for (int i=l;i<=r;i++)
                {
                    if (s[i]==' ')
                    {
                        continue;
                    }
                    t+=s[i];
                }
                if (t!="")
                {
                    if(ans!="")
                    {
                        ans+=' ';
                    }
                    ans+=t;
                }
                r=l-1;
            }
            l--;
        }
        return ans;
    }
};*/

// ---------------Approach 2: Using substr function---------------

class Solution {
public:
    string reverseWords(string s) 
    {
        int l=s.size()-1;
        int r=l;
        string ans;
        while (l>=0)
        {
            if (s[l]==' ')
            {
                string t="";
                t=s.substr(l+1,r-l);
                if (t!="")
                {
                    if (ans!="")
                    {
                        ans+=' ';
                    }
                    ans+=t;
                }
                r=l-1;
            }
            if (l==0)
            {
                string t="";
                t=s.substr(l,r-l+1);
                if (t!="")
                {
                    if (ans!="")
                    {
                        ans+=' ';
                    }
                    ans+=t;
                }
                r=l-1;
            }
            l--;
        }   
        return ans; 
    }
};