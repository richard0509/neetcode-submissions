class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return -1;
        } 
        int R = grid.size();
        int C = grid[0].size();

        int visit[R][C] = {0};

        std::queue<std::pair<int, int>> queue;
        queue.push(std::pair<int, int>(0, 0));
        visit[0][0] = 1;

        int length = 1;
        while (queue.size()) {
            int q_size = queue.size();
            for (int i = 0; i < q_size; ++i) {
                std::pair<int, int> p = queue.front();
                queue.pop();
                int r = p.first;
                int c = p.second;

                if (r == R - 1 && c == C - 1) {
                    return length;
                }

                int dir[8][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1},
                                 {r - 1, c - 1}, {r - 1, c + 1}, {r + 1, c - 1}, {r + 1, c + 1}};
                for (int i = 0; i < 8; ++i) {
                    int new_r = dir[i][0];
                    int new_c = dir[i][1];
                    if (new_r < 0 || new_c < 0 || new_r >= R || new_c >= C || grid[new_r][new_c] == 1 || visit[new_r][new_c] == 1) {
                        continue;
                    }

                    queue.push(std::pair<int, int>(new_r, new_c));
                    visit[new_r][new_c] = 1;
                }

            }   
            length++;
        }
        return -1;
    }
};