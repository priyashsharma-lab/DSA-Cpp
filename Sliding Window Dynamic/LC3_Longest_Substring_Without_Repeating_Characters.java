/*Leetcode: 3. Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Approach 1: Without HashSet
Time: O(n^2)
Space:O(n)

Approach 2: Sliding window with Hashset
Time: O(n)
Space: O(1)
*/
// ---------------Approach 1: Without Hashset---------------*/
/*class Solution {
    public int lengthOfLongestSubstring(String s) 
    {
        int l=0;
        int r=1;
        String substr;
        int count=0;
        int maxCount=0;
        if (s.length()==1)
        {
            return 1;
        }
        while (r<s.length())
        {
            substr=s.substring(l,r);
            if (substr.contains(String.valueOf(s.charAt(r))))
            {
                count=r-l;
                maxCount=Math.max(count,maxCount);
                while (s.charAt(l)!=s.charAt(r))
                {
                    l++;
                }
                l++;
            }
            if (r==s.length()-1)
            {
                count=r-l;
                maxCount=Math.max(count+1,maxCount);
            }
            r++;
        }    
        return maxCount;
    }
}*/

// ---------------Approach 2: Sliding window with Hashset---------------*/
class Solution {
    public int lengthOfLongestSubstring(String s) {

        int l = 0;
        int r = 0;
        int maxCount = 0;

        HashSet<Character> substr = new HashSet<>();

        while (r < s.length()) {

            while (substr.contains(s.charAt(r))) {
                substr.remove(s.charAt(l));
                l++;
            }

            substr.add(s.charAt(r));

            maxCount = Math.max(maxCount, r - l + 1);

            r++;
        }

        return maxCount;
    }
}