#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BFS function to simulate rotting process
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int fresh) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = -1;

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            int size = q.size();
            minutes++;
            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // rot the orange
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return (fresh == 0) ? minutes : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Collect all rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; // no fresh oranges

        // Step 2: Call BFS
        return bfs(grid, q, fresh);
    }
};


