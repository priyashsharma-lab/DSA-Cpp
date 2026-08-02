/*Leetcode: 49. Group Anagrams
Link: https://leetcode.com/problems/group-anagrams/ */
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) 
    {
        HashMap<String,Integer> s=new HashMap<>();
        List<List<String>> ans=new ArrayList<>();
        int x=0;
        for (int i=0;i<strs.length;i++)
        {
            char[] arr = strs[i].toCharArray();
            Arrays.sort(arr);
            String sorted = new String(arr);
            if (s.containsKey(sorted))
            {
                int idx=s.get(sorted);
                (ans.get(idx)).add(strs[i]);
                continue;
            }
            s.put(sorted,x);
            x++;
            ArrayList<String> temp = new ArrayList<>();
            temp.add(strs[i]);
            ans.add(temp);
        }
        return ans;
    }
}
// we can use arrays to store freq of the chars for this q
// if the q allows all unicode chars the given sol is the most optimal
// Use map.computeIfAbsent() method to remove x and improve efficiency