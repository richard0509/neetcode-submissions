class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        if (grid[0][0] == 1 || grid[R - 1][C - 1] == 1) {
            return 0;
        }

        int count = dfs(grid, 0, 0);
        return count;

    }

    int dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        int R = grid.size();
        int C = grid[0].size();

        if (r < 0 || c < 0 || r >= R || c >= C || grid[r][c] == 1) {
            return 0;
        }

        if (r == R - 1 && c == C - 1) {
            return 1;
        }

        grid[r][c] = 1;
        int count = 0;
        count += dfs(grid, r + 1, c);
        count += dfs(grid, r - 1, c);
        count += dfs(grid, r, c + 1);
        count += dfs(grid, r, c - 1);

        grid[r][c] = 0;
        return count;
    }
};
