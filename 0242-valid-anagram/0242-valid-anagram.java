import java.util.HashMap;

class Solution {
    // using HashMap solution
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();

        // Count frequency of characters in s
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            map1.put(ch, map1.getOrDefault(ch, 0) + 1);
        }

        // Count frequency of characters in t
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            map2.put(ch, map2.getOrDefault(ch, 0) + 1);
        }

        // Compare both maps
        for (char ch1 : map1.keySet()) {
            int freq1 = map1.get(ch1);
            if (map2.containsKey(ch1)) {
                int freq2 = map2.get(ch1);
                if (freq1 != freq2) return false;
            } else {
                return false;
            }
        }
        return true;
    }
}
