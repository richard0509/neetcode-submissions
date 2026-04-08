class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int max = count;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                count = 0;
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, count);
                    if (count > max) {
                        max = count;
                    }
                }
            }
        }

        return max;
        
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& count) {
        int R = grid.size();
        int C = grid[0].size();

        if (r < 0 || c < 0 || r >= R || c >= C || grid[r][c] != 1) {
            return;
        }

        grid[r][c] = 0;
        count++;

        dfs(grid, r + 1, c, count);
        dfs(grid, r - 1, c, count);
        dfs(grid, r, c + 1, count);
        dfs(grid, r, c - 1, count);
    }
};
