class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int value) : key(key), val(value), prev(nullptr), next(nullptr) {

    }
};
class LRUCache {
    int cap;
    Node* left;
    Node* right;
    std::unordered_map<int, Node*> maps;

    void remove(Node* node) {
        auto prev = node->prev;
        auto next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        auto prev = right->prev;
        auto next = right;
        node->prev = prev;
        node->next = next;
        prev->next = node;
        right->prev = node;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (maps.find(key) != maps.end()) {
            auto node = maps[key];
            int res = node->val;
            remove(node);
            insert(node);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (maps.find(key) != maps.end()) {
            auto node = maps[key];
            remove(node);
            delete node;
        }
        Node* node = new Node(key, value);
        insert(node);
        maps[key] = node; 

        if (maps.size() > cap) {
            auto node = left->next;
            remove(node);
            maps.erase(node->key);
            delete node;
        }
    }
};
