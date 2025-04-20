class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count[1000] = {0};
        for (int x : answers) {
            count[x]++;
        }

        int result = 0;
        // for each distinct answer x...
        for (int x = 0; x < 1000; ++x) {
            if (count[x] == 0) continue;

            // group size is (x + 1)
            int size = x + 1;
            int groups = count[x] / size;
            if (count[x] % size != 0) {
                groups++;
            }
            result += groups * size;
        }

        return result;
    }
};
