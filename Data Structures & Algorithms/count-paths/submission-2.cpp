class Solution {
public:
    int uniquePaths(int m, int n) {
        int r = 0;
        int c = 0;

        std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
        return brute(r, c, m, n, memo);
    }

    int brute(int r, int c, int m, int n, std::vector<std::vector<int>>& memo) {
        if (r == m || c == n) {
            return 0;
        }

        if (memo[r][c] > 0) {
            return memo[r][c];
        }

        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        memo[r][c] = brute(r + 1, c, m, n, memo) + brute(r, c + 1, m, n, memo);
        return memo[r][c];
    }
};
