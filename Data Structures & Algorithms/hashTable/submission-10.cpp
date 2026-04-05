// chaining version, using linked list
class Node {
public:
    int key;
    int val;
    Node* next;

    Node(int k, int v) : key(k), val(v), next(nullptr) {

    }
};

class HashTable {
    int cap;
    int size;
    std::vector<Node*> maps;

    int hash(int key) {
        return key % cap;
    }

public:
    HashTable(int capacity) : cap(capacity), size(0) {
        maps.resize(cap);
        for (auto& n : maps) {
            n = new Node(0, 0);
        }
    }

    void insert(int key, int value) {
        int index = hash(key);
        Node* node = maps[index];
        auto cur = node->next;
        while (cur != nullptr) {
            if (cur->key == key) {
                cur->val = value;
                return;
            }
            cur = cur->next;
        }

        Node* oldNext = node->next;
        node->next = new Node(key, value);
        size++;
        node->next->next = oldNext;
        if (size * 2 >= cap) {
            resize();
        }
    }

    int get(int key) {
        int index = hash(key);
        Node* node = maps[index];
        auto cur = node->next;
        while (cur != nullptr) {
            if (cur->key == key) {
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }

    bool remove(int key) {
        int index = hash(key);
        Node* node = maps[index];
        auto prev = node;
        while (prev->next != nullptr) {
            auto cur = prev->next;
            if (cur->key == key) {
                auto temp = cur;
                prev->next = cur->next;
                size--;
                delete temp;
                return true;
            }
            prev = cur;
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return cap;
    }

    void resize() {
        int newCap = cap * 2;
        std::vector<Node*> newMaps(newCap);
        for (auto& n : newMaps) {
            n = new Node(0, 0);
        }

        for (int i = 0; i < maps.size(); ++i) {
            Node* node = maps[i];
            auto cur = node->next;
            while (cur != nullptr) {
                int key = cur->key;
                int val = cur->val;
                int index = key % newCap;
                auto old = newMaps[index]->next;
                newMaps[index]->next = new Node(key, val);
                newMaps[index]->next->next = old;
                auto temp = cur;
                cur = cur->next;
                delete temp;
            }
            delete node;
        }

        cap = newCap;
        maps = newMaps;
    }
};
