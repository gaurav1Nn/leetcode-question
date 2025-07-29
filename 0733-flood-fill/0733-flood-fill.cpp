class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oc, int color) {
        int m = image.size();      // number of rows
        int n = image[0].size();   // number of columns

        // Correct boundary check: row index with m, column index with n
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != oc)
            return;

        image[sr][sc] = color; // Fill current cell

        // 4-direction DFS
        dfs(image, sr + 1, sc, oc, color); // down
        dfs(image, sr - 1, sc, oc, color); // up
        dfs(image, sr, sc + 1, oc, color); // right
        dfs(image, sr, sc - 1, oc, color); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc]; // original color
        if (oc != color) { 
            dfs(image, sr, sc, oc, color); // pass sr, sc in correct order
        }
        return image;
    }
};
