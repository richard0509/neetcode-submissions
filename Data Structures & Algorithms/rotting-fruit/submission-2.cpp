class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        std::queue<std::pair<int, int>> q;
        int fruits = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 2) {
                    q.push(std::pair<int, int>(i, j));
                } else if (grid[i][j] == 1) {
                    fruits++;
                }
            }
        }

        if (fruits == 0) {
            return 0;
        }

        int minute = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                std::pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;

                int dir[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c- 1}};
                for (int j = 0; j < 4; ++j) {
                    int nr = dir[j][0];
                    int nc = dir[j][1];

                    if (nr < 0 || nc < 0 || nr >= R || nc >= C || grid[nr][nc] != 1) {
                        continue;
                    }

                    q.push(std::pair<int, int>(nr, nc));
                    grid[nr][nc] = 2;
                    fruits--;
                }

            }
            minute++;
            if (fruits == 0) {
                return minute;
            }
        }
        return -1;
    }

};
