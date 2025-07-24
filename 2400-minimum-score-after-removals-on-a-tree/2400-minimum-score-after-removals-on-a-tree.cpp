class Solution {
public:
    int calculateDifference(int a, int b, int c) {
        return max({a, b, c}) - min({a, b, c});
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int time = 0;
        vector<int> xorSum(n), inTime(n), outTime(n);
        vector<vector<int>> graph(n);

        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // DFS to calculate subtree XORs and in/out times
        function<void(int, int)> dfs = [&](int node, int parent) {
            inTime[node] = time++;
            xorSum[node] = nums[node];
            for (int neighbor : graph[node]) {
                if (neighbor == parent) continue;
                dfs(neighbor, node);
                xorSum[node] ^= xorSum[neighbor];
            }
            outTime[node] = time;
        };

        dfs(0, -1); // Start DFS from root node

        int minScore = INT_MAX;

        // Try removing any two edges (u, v)
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int part1, part2, part3;

                if (inTime[v] > inTime[u] && inTime[v] < outTime[u]) {
                    part1 = xorSum[0] ^ xorSum[u];
                    part2 = xorSum[u] ^ xorSum[v];
                    part3 = xorSum[v];
                } else if (inTime[u] > inTime[v] && inTime[u] < outTime[v]) {
                    part1 = xorSum[0] ^ xorSum[v];
                    part2 = xorSum[v] ^ xorSum[u];
                    part3 = xorSum[u];
                } else {
                    part1 = xorSum[0] ^ xorSum[u] ^ xorSum[v];
                    part2 = xorSum[u];
                    part3 = xorSum[v];
                }
                minScore = min(minScore, calculateDifference(part1, part2, part3));
            }
        }

        return minScore;
    }
};
