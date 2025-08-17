import java.util.*;

class Solution {
    public void sortColors(int[] nums) {
        List<Integer> ans = new ArrayList<>();

        // Collect all 0s
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) ans.add(0);
        }

        // Collect all 1s
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) ans.add(1);
        }

        // Collect all 2s
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 2) ans.add(2);
        }

        // Copy back to nums[]
        for (int i = 0; i < nums.length; i++) {
            nums[i] = ans.get(i);
        }
    }
}
