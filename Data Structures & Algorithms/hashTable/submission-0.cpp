#include <optional>
#include <vector>

class HashTable {
    int size;
    int cap;
    std::pair<int,int> tombStone = {INT_MIN, INT_MIN};
    std::vector<std::optional<std::pair<int,int>>> hashMap;

    int hash(int key) {
        return key % cap;
    }

    void resize() {
        int newCap = cap * 2;
        std::vector<std::optional<std::pair<int,int>>> newMap(newCap);
        for (auto& slot : hashMap) {
            if (slot.has_value() && slot != tombStone) {
                int index = slot->first % newCap;
                while (newMap[index].has_value()) {
                    index = (index + 1) % newCap;
                }
                newMap[index] = slot;
            }
        }
        hashMap = newMap;
        cap = newCap;
    }

public:
    HashTable(int capacity) : size(0), cap(capacity) {
        hashMap.resize(cap);
    }

    void insert(int key, int value) {
        int index = hash(key);
        int count = 0;
        while (true) {
            if (!hashMap[index].has_value() || hashMap[index] == tombStone) {
                hashMap[index] = {key, value};
                size++;
                if (size >= cap / 2) resize();
                return;
            } else if (hashMap[index]->first == key) {
                hashMap[index]->second = value;
                return;
            }
            index = (index + 1) % cap;
            count++;
            if (count >= cap) return;
        }
    }

    int get(int key) {
        int index = hash(key);
        int count = 0;
        while (hashMap[index].has_value()) {
            if (hashMap[index] != tombStone && hashMap[index]->first == key) {
                return hashMap[index]->second;
            }
            index = (index + 1) % cap;
            count++;
            if (count >= cap) return -1;
        }
        return -1;
    }

    bool remove(int key) {
        if (get(key) == -1) return false;
        int index = hash(key);
        int count = 0;
        while (true) {
            if (!hashMap[index].has_value() || hashMap[index] == tombStone) {
                index = (index + 1) % cap;
                count++;
                if (count >= cap) return false;
                continue;
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

    int getSize() const { return size; }
    int getCapacity() const { return cap; }
};