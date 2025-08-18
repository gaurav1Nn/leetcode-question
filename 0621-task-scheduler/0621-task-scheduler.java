import java.util.Arrays;

class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] cnt = new int[26];
        for (char c : tasks) cnt[c - 'A']++;

        Arrays.sort(cnt);                 // cnt[25] = max frequency
        int maxFreq = cnt[25];

        // Count how many tasks have the maximum frequency
        int maxCount = 0;
        for (int i = 25; i >= 0 && cnt[i] == maxFreq; i--) {
            maxCount++;
        }

        // Frames formula: (maxFreq - 1) * (n + 1) + maxCount
        int frames = (maxFreq - 1) * (n + 1) + maxCount;

        // If tasks fill all frames (or more), answer is tasks.length
        return Math.max(frames, tasks.length);
    }
}