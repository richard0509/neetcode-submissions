class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> prev(n, 0);

        for (int row = m - 1; row >= 0; row--) {
            std::vector<int> cur(n, 0);
            cur[n - 1] = 1;
            for (int col = n - 2; col >= 0; col--) {
                cur[col] = cur[col + 1] + prev[col];
            }
            prev = cur;
        }

        return prev[0];
    }


};
