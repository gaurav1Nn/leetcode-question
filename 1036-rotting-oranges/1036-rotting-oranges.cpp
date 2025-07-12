
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // Count fresh oranges and enqueue all initial rotten oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If no fresh oranges at start, return 0
        if (fresh == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            // Process all rotten oranges at this time step
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    // Check bounds and if fresh orange
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }
            if (rotted) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
