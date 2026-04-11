class Solution {
public:
    std::vector<std::vector<int>> table;
    std::vector<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        table.resize(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            table[i] = {};
            visiting.emplace_back(0);
        }

        for (auto& v : prerequisites) {
            table[v[0]].emplace_back(v[1]);
        }

        for (int src = 0; src < table.size(); ++src) {
            if (!dfs(src)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int src) {
        if (visiting[src] == 1) {
            return false;
        }

        if (table[src].empty()) {
            return true;
        }

        visiting[src] = 1;
        for (int nei : table[src]) {
            if (!dfs(nei)) {
                return false;
            }
        }
        visiting[src] = 0;
        table[src].clear();
        return true;
    }

};
