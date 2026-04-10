class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> table;
        for (auto& v : prerequisites) {
            table[v[0]].insert(v[1]);
        }

        std::unordered_set<int> visit;
        for (auto& entry : table) {
            int src = entry.first;
            if (!dfs(src, table, visit)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int src, std::unordered_map<int, std::unordered_set<int>>& table, std::unordered_set<int>& visit) {
        if (visit.find(src) == visit.end()) {
            visit.insert(src);
        } else {
            return false;
        }

        for (int nei : table[src]) {
            if (!dfs(nei, table, visit)) {
                return false;
            }
        }

        visit.erase(src);
        return true;
    }
};
