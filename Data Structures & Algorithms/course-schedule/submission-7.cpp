class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> table(numCourses); 
        for (auto& v : prerequisites) {
            table[v[0]].emplace_back(v[1]);
        }

        std::vector<bool> visit(numCourses, false);
        std::vector<bool> no_cycle(numCourses, false);

        for (int i = 0; i < table.size(); ++i) {
            int src = i;
            if (!dfs(src, table, visit, no_cycle)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int src, std::vector<std::vector<int>>& table, std::vector<bool>& visit, std::vector<bool>& no_cycle) {
        if (no_cycle[src]) {
            return true;
        }

        if (visit[src]) {
            return false;
        } else {
            visit[src] = true;
        }

        for (int nei : table[src]) {
            if (!dfs(nei, table, visit, no_cycle)) {
                return false;
            }
        }

        visit[src] = false;
        no_cycle[src] = true;
        return true;
    }
};
