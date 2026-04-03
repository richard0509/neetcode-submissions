class LRUCache {
private:
    std::unordered_map<int, int> maps;
    int capa;
    std::list<int> dlist;

public:
    LRUCache(int capacity) : capa(capacity) {

    }
    
    int get(int key) {
        if (maps.count(key) == 0) {
            return -1;
        }
        dlist.remove(key);
        dlist.push_front(key);
        return maps[key];
    }
    
    void put(int key, int value) {
        auto it = std::find(dlist.begin(), dlist.end(), key);
        if (dlist.size() >= capa) {
            auto removed_ele = dlist.back();
            if (it == dlist.end()) {
                dlist.remove(removed_ele);
                maps.erase(removed_ele);
            }
        }
        dlist.remove(key);
        dlist.push_front(key);
        maps[key] = value;    
    }
};
