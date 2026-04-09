/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::unordered_map<int, Node*> m;
        std::queue<Node*> q;
        q.emplace(node);
        m[node->val] = new Node(node->val);
        
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            std::vector<Node*> nei = n->neighbors;
            for (int i = 0; i < nei.size(); ++i) {
                int value = nei[i]->val;
                if (m.count(value) == 0) {
                    m[value] = new Node(value);
                    q.emplace(nei[i]);
                }
                m[n->val]->neighbors.push_back(m[value]);
            }
        }
        return m[node->val];
    }
};
