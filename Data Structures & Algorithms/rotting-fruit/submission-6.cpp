class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        std::queue<std::pair<int, int>> q;
        int fruit = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 2) {
                    // init multiple starting points
                    q.push(std::pair<int, int>(i, j));
                } else if (grid[i][j] == 1) {
                    // count how many 1 there are for impossible cases
                    fruit++;
                }
            }
        }

        // there's no fruit
        // no fresh fruit at minute 0
        if (fruit == 0) {
            return 0;
        }

        int minute = 0;
        while (!q.empty()) {
            // just like shortest path
            // we have to count how many minutes(steps)
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                std::pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;

                // down, up, right, left
                int dir[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
                for (int j = 0; j < 4; ++j) {
                    int nr = dir[j][0];
                    int nc = dir[j][1];

                    // grids that we skip
                    if (nr < 0 || nc < 0 || nr >= R || nc >= C || grid[nr][nc] != 1) {
                        continue;
                    }

                    q.push(std::pair<int, int>(nr, nc));
                    // mark visited
                    grid[nr][nc] = 2;
                    // decrease fruit amounts
                    fruit--;
                }
            }
            minute++;
            // there's no fresh fruit remaining
            if (fruit == 0) {
                return minute;
            }
        }
        // there are still some fruits left behind, but won't be rotted
        // fruit != 0
        return -1;
    }
};