class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        std::vector<std::vector<int>> visit(n, std::vector<int>(n, 0));
        std::queue<std::pair<int, int>> q;
        q.push(std::pair<int, int>(0, 0));
        visit[0][0] = 1;

        int length = 1;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                std::pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;

                if (r == n - 1 && c == n - 1) {
                    return length;
                }

                int dir[8][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1},
                                {r - 1, c - 1}, {r - 1, c + 1}, {r + 1, c - 1}, {r + 1, c + 1}};
                for (int j = 0; j < 8; ++j) {
                    int nr = dir[j][0];
                    int nc = dir[j][1];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] == 1 || visit[nr][nc] == 1) {
                        continue;
                    }
                    q.push(std::pair<int, int>(nr, nc));
                    visit[nr][nc] = 1;
                }
            }
            length++;
        }
        return -1;
    }
};