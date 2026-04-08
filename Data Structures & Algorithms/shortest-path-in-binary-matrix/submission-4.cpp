#include <array>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        std::vector<std::vector<int>> visit(n, std::vector<int>(n, 0));
        std::queue<std::array<int, 3>> q;
        q.push({0, 0, 1});
        visit[0][0] = 1;

        while (!q.empty()) {
            std::array<int, 3> p = q.front();
            q.pop();
            int r = p[0];
            int c = p[1];
            int dist = p[2];

            if (r == n - 1 && c == n - 1) {
                return dist;
            }

            int dir[8][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1},
                            {r - 1, c - 1}, {r - 1, c + 1}, {r + 1, c - 1}, {r + 1, c + 1}};
            for (int j = 0; j < 8; ++j) {
                int nr = dir[j][0];
                int nc = dir[j][1];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] == 1 || visit[nr][nc] == 1) {
                    continue;
                }
                q.push({nr, nc, dist + 1});
                visit[nr][nc] = 1;
            }
        }
        return -1;
    }
};