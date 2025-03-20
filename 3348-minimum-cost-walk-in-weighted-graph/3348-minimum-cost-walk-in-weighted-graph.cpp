class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> vis(n, false);
        vector<int> comp(n), cost;
        int cid = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cost.push_back(findCost(i, adj, vis, comp, cid));
                cid++;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]] ? cost[comp[q[0]]] : -1);
        }
        return ans;
    }

private:
    int findCost(int src, vector<vector<pair<int, int>>>& adj, vector<bool>& vis, vector<int>& comp, int cid) {
        queue<int> q;
        int minCost = INT_MAX;

        q.push(src);
        vis[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            comp[node] = cid;

            for (auto& [nbr, w] : adj[node]) {
                minCost &= w;
                if (vis[nbr]) continue;
                vis[nbr] = true;
                q.push(nbr);
            }
        }
        return minCost;
    }
};
