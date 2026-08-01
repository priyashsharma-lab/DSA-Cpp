/*Leetcode: 205. Isomorphic Strings
Link: https://leetcode.com/problems/isomorphic-strings/ */

class Solution {
    public boolean isIsomorphic(String s, String t) 
    {
        HashMap<Character, Character> m = new HashMap<>();
        HashSet<Character> tset = new HashSet<>();

        for (int i = 0; i < s.length(); i++)
        {
            char sc = s.charAt(i);
            char tc = t.charAt(i);

            if (m.containsKey(sc))
            {
                if (m.get(sc) != tc)
                {
                    return false;
                }
            }
            else
            {
                if (tset.contains(tc))
                {
                    return false;
                }
            }

            m.put(sc, tc);
            tset.add(tc);
        }
        return true;
    }
}
// We can use arrays to make it faster