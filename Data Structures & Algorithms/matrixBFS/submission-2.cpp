class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<int>> visit(R, std::vector<int>(C, 0));
        q.push({0, 0});
        visit[0][0] = 1;

        int count = 0;

        while (!q.empty()) {
            int q_size = q.size();
            for (int j = 0; j < q_size; ++j) {
                std::pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if (r == R - 1 && c == C - 1) {
                    return count;
                }
    
                int dir[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
                for (int i = 0; i < 4; ++i) {
                    int nr = dir[i][0];
                    int nc = dir[i][1];
    
                    if (nr < 0 || nc < 0 || nr >= R || nc >= C || grid[nr][nc] == 1 || visit[nr][nc] == 1) {
                        continue;
                    }
    
                    q.push({nr, nc});
                    visit[nr][nc] = 1;
                }
            }
            count++;
        }
        return -1;
    }

};
