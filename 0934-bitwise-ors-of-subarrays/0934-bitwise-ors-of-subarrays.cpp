class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;    // Stores all distinct OR values
        unordered_set<int> current;   // Stores OR values of subarrays ending at current position

        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num); // Single element subarray

            // Extend previous subarrays by including current number
            for (int val : current) {
                next.insert(val | num);
            }

            current = next;

            // Add all current subarray OR results to global result
            result.insert(current.begin(), current.end());
        }

        return result.size();
    }
};