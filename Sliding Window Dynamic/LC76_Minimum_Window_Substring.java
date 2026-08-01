/*Leetcode: 76. Minimum Window Substring
Link: https://leetcode.com/problems/minimum-window-substring/ */

class Solution {
    public String minWindow(String s, String t) 
    {
        HashMap<Character,Integer> tmap=new HashMap<>();
        HashMap<Character,Integer> smap=new HashMap<>();
        int l=0;
        int r=0;
        int fl=0;
        int fr=Integer.MAX_VALUE-1;
        for (int i=0;i<t.length();i++)
        {
            tmap.put(t.charAt(i),tmap.getOrDefault(t.charAt(i),0)+1);
        }
        int x=0;
        while (r<s.length())
        {
            char cr=s.charAt(r);
            if (tmap.containsKey(cr))
            {
                smap.put(cr,smap.getOrDefault(cr,0)+1);
                if (smap.get(cr)<=tmap.get(cr))
                {
                    x++;
                }
            }

            while (x==t.length())
            {
                char cl=s.charAt(l);
                if (tmap.containsKey(cl))
                {
                    if (smap.get(cl)>tmap.get(cl))
                    {
                        smap.put(cl,smap.get(cl)-1);
                    }
                    else
                    {
                        if (fr-fl+1>r-l+1)
                        {
                            fr=r;
                            fl=l;
                        }
                        smap.put(cl,smap.get(cl)-1);
                        x--;
                    }
                }
                l++;
            }

            r++;
        }
        if (fr == Integer.MAX_VALUE-1)
        {
            return "";
        }
        return s.substring(fl,fr+1);
    }
}
// We can use arrays instead of HashMaps to improve efficiency