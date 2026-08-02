/*Leetcode: 535. Encode and Decode TinyURL
Link: https://leetcode.com/problems/encode-and-decode-tinyurl/ */
import java.util.HashMap;

class LC535_Encode_and_Decode_TinyURL {

    HashMap<String, Integer> urlToId = new HashMap<>();
    HashMap<Integer, String> idToUrl = new HashMap<>();
    int id = 0;

    public String encode(String longUrl) {

        if (urlToId.containsKey(longUrl))
            return "http://tinyurl.com/" + urlToId.get(longUrl);

        urlToId.put(longUrl, id);
        idToUrl.put(id, longUrl);

        return "http://tinyurl.com/" + id++;
    }

    public String decode(String shortUrl) {

        int idx = Integer.parseInt(shortUrl.split("/")[3]);
        return idToUrl.get(idx);
    }
}