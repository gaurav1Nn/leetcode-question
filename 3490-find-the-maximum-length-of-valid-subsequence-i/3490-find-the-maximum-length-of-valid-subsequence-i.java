class Solution {

      public int maximumLength(int[] A) {
        int[] count = new int[2], end = new int[2];
        for (int a : A) {
            count[a % 2]++;
            end[a % 2] = end[1 - a % 2] + 1;
        }
        return Math.max(Math.max(count[0], count[1]), Math.max(end[0], end[1]));
    }
};