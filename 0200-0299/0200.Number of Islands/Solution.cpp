class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = '0';
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
                    dfs(x, y);
                }
            }
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};