import java.util.*;

class Solution {
    private Map<String, List<String>> memo = new HashMap<>();

    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict); // O(1) lookups
        return wordBreakHelper(s, wordSet);
    }

    private List<String> wordBreakHelper(String s, Set<String> wordSet) {
        if (memo.containsKey(s)) {
            return memo.get(s);
        }

        List<String> result = new ArrayList<>();
        
        if (s.isEmpty()) {
            result.add("");  // base case: return a list with an empty string
            return result;
        }

        for (int i = 1; i <= s.length(); i++) {
            String prefix = s.substring(0, i);

            if (wordSet.contains(prefix)) {
                String suffix = s.substring(i);
                List<String> suffixWays = wordBreakHelper(suffix, wordSet);

                for (String way : suffixWays) {
                    if (way.isEmpty()) {
                        result.add(prefix);
                    } else {
                        result.add(prefix + " " + way);
                    }
                }
            }
        }

        memo.put(s, result);
        return result;
    }
}
