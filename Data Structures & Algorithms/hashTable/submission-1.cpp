class HashTable {
    int size;
    int cap;
    std::vector<std::optional<std::pair<int, int>>> hashMap;
    std::pair<int, int> tombStone;

    int hash(int key) {
        return key % cap;
    }

public:
    HashTable(int capacity) : size(0) {
        cap = capacity;
        hashMap.resize(cap);
        tombStone = {INT_MIN, INT_MIN};
    }

    void insert(int key, int value) {
        int index = hash(key);
        int count = 0;

        while (true) {
            if (!hashMap[index].has_value() || hashMap[index] == tombStone) {
                hashMap[index] = {key, value};
                size++;
                if (size >= cap / 2) {
                    resize();
                }
                return;
            } else if (hashMap[index]->first == key) {
                hashMap[index]->second = value;
                return;
            }

            index++;
            index %= cap;
            count++;
            if (count >= cap) {
                return;
            }
        }
    }

    int get(int key) {
        int index = hash(key);
        int count = 0;
        while (hashMap[index].has_value()) {
            if (hashMap[index]->first == key) {
                return hashMap[index]->second;
            }
            index++;
            index %= cap;
            count++;
            if (count >= cap) {
                return -1;
            }
        }
        return -1;
    }

    bool remove(int key) {
        if (get(key) == -1) {
            return false;
        }
        int index = hash(key);
        
        int count = 0;
        while (true) {
            if (!hashMap[index].has_value() || hashMap[index] == tombStone) {
                index = (index + 1) % cap;
                count++;
                if (count >= cap) return false;
                continue;  // 回到 while 頂端重新檢查
            }
            if (hashMap[index]->first == key) {
                hashMap[index] = tombStone;
                size--;
                return true;
            }
            index = (index + 1) % cap;
            count++;
            if (count >= cap) return false;
        }
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return cap;
    }

    void resize() {
        int newCap = cap * 2;
        std::vector<std::optional<std::pair<int, int>>> newMap(newCap);

        for (auto& pair : hashMap) {
            if (pair.has_value() && pair != tombStone) {
                int index = pair->first % newCap;
                while (newMap[index].has_value()) {
                    index++;
                    index %= newCap;
                }
                newMap[index] = pair;
            }
        }

        hashMap = newMap;
        cap = newCap;
    }
};
