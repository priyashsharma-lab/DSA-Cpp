/*Leetcode: 125. Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome

Approach 1:   Two Pointer (using isalnum() function)
Time: O(n)
Space:O(1)

Approach 2: Two Pointer (using ASCII values)
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Two Pointer (using isalnum() function)---------------
/*class Solution {
public:
    bool isPalindrome(string s) 
    {
        int i=0;
        int j=s.length()-1;
        while (i<j)
        {
            if (!isalnum(s[i]))
            {
                i++;
                continue;
            }
            if (!isalnum(s[j]))
            {
                j--;
                continue;
            }
            char ci=tolower(s[i]);
            char cj=tolower(s[j]);
            if (ci!=cj)
            {
                return 0;
            }
            i++;
            j--;
        }    
        return 1;
    }
};*/

// ---------------Approach 2: Two Pointer (using ASCII values)---------------
class Solution {
public:
    bool isPalindrome(string s) 
    {
        int l=0;
        int r=s.size()-1;
        while (l<r)
        {
            int sl=int(tolower(s[l]));
            int sr=int(tolower(s[r]));
            if (sl<48 || (sl>57 && sl<97) || sl>122)
            {
                l++;
                continue;
            }
            if (sr<48 || (sr>57 && sr<97) || sr>122)
            {
                r--;
                continue;
            }
            if (tolower(s[l])!=tolower(s[r]))
            {
                return 0;
            }
            l++;
            r--;
        }    
        return 1;
    }
};