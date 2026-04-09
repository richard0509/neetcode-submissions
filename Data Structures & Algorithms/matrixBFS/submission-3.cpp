class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        std::queue<std::pair<int, int>> q;
        q.push({0, 0});

        int length = 0;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                std::pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;

                if (r == R - 1 && c == C - 1) {
                    return length;
                }

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dir[j][0];
                    int nc = c + dir[j][1];

                    if (nr < 0 || nc < 0 || nr >= R || nc >= C || grid[nr][nc] == 1) {
                        continue;
                    }

                    q.push({nr, nc});
                    grid[nr][nc] = 1;
                }
            }
            length++;
        }
        return -1;
    }
};
