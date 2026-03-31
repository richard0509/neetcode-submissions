class KthLargest {
    int k;
    std::vector<int> n = {0};
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            push(nums[i]);
            if (n.size() > k + 1) {
                pop();
            }
        }
    }
    
    int add(int val) {
        push(val);
        if (n.size() > k + 1) {
            pop();
        }
        return n[1];
    }

    void push(int val) {
        n.emplace_back(val);
        int i = n.size() - 1;

        while (i > 1 && n[i] < n[i / 2]) {
            int temp = n[i];
            n[i] = n[i / 2];
            n[i / 2] = temp;
            i /= 2;
        }
    }

    int pop() {
        if (n.size() == 1) {
            return -1;
        } else if (n.size() == 2) {
            int res = n[n.size() - 1];
            n.pop_back();
            return res;
        }

        int res = n[1];
        n[1] = n[n.size() - 1];
        n.pop_back();
        int i = 1;
        while (i * 2 < n.size()) {
            int smallest = i * 2;
            if (i * 2 + 1 < n.size() && n[i * 2 + 1] < n[smallest]) {
                smallest = i * 2 + 1;
            }
            if (n[smallest] < n[i]) {
                std::swap(n[i], n[smallest]);
                i = smallest;
            } else {
                break;
            } 
        }
        return res;
    }
};
