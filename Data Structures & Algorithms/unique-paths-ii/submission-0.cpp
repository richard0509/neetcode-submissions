class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        int r = 0;
        int c = 0;

        std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));

        return brute_memo(r, c, m, n, obstacleGrid, memo);
    }

    int brute_memo(int r, int c, int m, int n, std::vector<std::vector<int>>& obstacleGrid, std::vector<std::vector<int>>& memo) {
        if (r == m || c == n || obstacleGrid[r][c] == 1) {
            return 0;
        }

        if (memo[r][c] > 0) {
            return memo[r][c];
        }

        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        memo[r][c] = brute_memo(r + 1, c, m, n, obstacleGrid, memo) + brute_memo(r, c + 1, m, n, obstacleGrid, memo);
        return memo[r][c];
    }

};