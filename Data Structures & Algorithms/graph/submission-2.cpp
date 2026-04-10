class Graph {
private:
    std::unordered_map<int, std::vector<int>> table;
public:
    Graph() {}

    void addEdge(int src, int dst) {
        if (table.count(src) == 0) {
            table[src];
        }
        if (table.count(dst) == 0) {
            table[dst];
        }
        table[src].emplace_back(dst);
    }

    bool removeEdge(int src, int dst) {
        if (table.count(src) == 0 || table.count(dst) == 0) {
            return false;
        }
        auto it = std::find(table[src].begin(), table[src].end(), dst);
        if (it != table[src].end()) {
            table[src].erase(it);
            return true;
        }
        return false;
    }

    bool hasPath(int src, int dst) {
        std::unordered_set<int> visit;
        return dfs(src, dst, visit);
    }

    bool dfs(int src, int dst, std::unordered_set<int>& visit) {
        if (src == dst) {
            return true;
        }
        visit.insert(src);
        for (int nei : table[src]) {
            if(visit.count(nei) == 0 && dfs(nei, dst, visit)) {
                return true;
            }
        }

        return false;
    }
};
