class Solution 
{
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();

        // Step 2: Initialize heaps
        priority_queue<int, vector<int>, greater<int>> usedQuery;
        priority_queue<int> availableQuery;

        // Step 1: Sort queries by start
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int queryPos = 0;
        int appliedCount = 0;

        // Step 3: Traverse nums
        for (int i = 0; i < n; ++i) 
        {
            // Step 3a: Add queries starting at i
            while (queryPos < queries.size() && queries[queryPos][0] == i) 
            {
                availableQuery.push(queries[queryPos][1]);
                ++queryPos;
            }

            // Step 3b: Subtract active coverage
            nums[i] -= usedQuery.size();

            // Step 3c: Apply more queries if needed
            while (nums[i] > 0 && !availableQuery.empty() && availableQuery.top() >= i) 
            {
                usedQuery.push(availableQuery.top()); availableQuery.pop();
                nums[i]--;
                appliedCount++;
            }

            // Step 3d: Return -1 if fail
            if (nums[i] > 0) 
            {
                return -1;
            }

            // Step 3e: Remove expired queries
            while (!usedQuery.empty() && usedQuery.top() == i) 
            {
                usedQuery.pop();
            }
        }

        // Step 4: Result
        return queries.size() - appliedCount;
    }
};