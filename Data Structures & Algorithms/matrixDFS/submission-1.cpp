class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        if (grid[0][0] == 1 || grid[R - 1][C - 1] == 1) {
            return 0;
        }

        std::vector<std::vector<int>> visit(R, std::vector<int>(C, 0));

        return dfs(grid, 0, 0, visit);

    }

    int dfs(std::vector<std::vector<int>> &grid, int r, int c, std::vector<std::vector<int>>& visit) {
        int R = grid.size();
        int C = grid[0].size();
        
        if (r < 0 || c < 0 || r >= R || c >= C || grid[r][c] == 1 || visit[r][c] == 1) {
            return 0;
        }
        
        if (r == R - 1 && c == C - 1) {
            return 1;
        }

        int count = 0;
        visit[r][c] = 1;

        count += dfs(grid, r + 1, c, visit);
        count += dfs(grid, r - 1, c, visit);
        count += dfs(grid, r, c + 1, visit);
        count += dfs(grid, r, c - 1, visit);

        visit[r][c] = 0;

        return count;
    }
};
