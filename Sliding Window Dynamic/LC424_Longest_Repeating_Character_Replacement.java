/*Leetcode: 424. Longest Repeating Character Replacement
Link: https://leetcode.com/problems/longest-repeating-character-replacement/ */
class Solution {
    public int characterReplacement(String s, int k) 
    {
        HashMap<Character,Integer> m=new HashMap<>();
        int l=0;
        int r=0;
        int maxCount=0;
        int maxFreq=0;
        while (r<s.length())
        {
            m.put(s.charAt(r), m.getOrDefault(s.charAt(r), 0) + 1);
            maxFreq=Math.max(maxFreq,m.get(s.charAt(r)));
            if ((r-l+1)-maxFreq>k)
            {
                while ((r-l+1)-maxFreq>k)
                {
                    m.put(s.charAt(l),m.get(s.charAt(l))-1);
                    l++;
                }
            }
            maxCount=Math.max(maxCount,r-l+1);
            r++;
        }    
        return maxCount;
    }
}
