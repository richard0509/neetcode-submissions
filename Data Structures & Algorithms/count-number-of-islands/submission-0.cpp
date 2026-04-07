class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    helper(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    void helper(vector<vector<char>>& grid, int r, int c) {
        int ROW = grid.size();
        int COL = grid[0].size();

        if (min(r, c) < 0 || r == ROW || c == COL || grid[r][c] != '1') {
            return;
        }

        grid[r][c] = '0';

        helper(grid, r + 1, c);
        helper(grid, r - 1, c);
        helper(grid, r, c + 1);
        helper(grid, r, c - 1);

        

    }
};
