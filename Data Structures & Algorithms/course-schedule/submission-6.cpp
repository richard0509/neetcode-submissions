class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> table;
        for (auto& v : prerequisites) {
            table[v[0]].insert(v[1]);
        }

        std::unordered_set<int> visit;
        std::unordered_set<int> no_cycle;

        for (auto& entry : table) {
            int src = entry.first;
            if (!dfs(src, table, visit, no_cycle)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int src, std::unordered_map<int, std::unordered_set<int>>& table, std::unordered_set<int>& visit, std::unordered_set<int>& no_cycle) {
        if (no_cycle.find(src) != no_cycle.end()) {
            return true;
        }

        if (visit.find(src) == visit.end()) {
            visit.insert(src);
        } else {
            return false;
        }

        for (int nei : table[src]) {
            if (!dfs(nei, table, visit, no_cycle)) {
                return false;
            }
        }

        visit.erase(src);
        no_cycle.insert(src);
        return true;
    }
};
