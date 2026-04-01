class MinHeap {
private:
    std::vector<int> heap;

public:
    MinHeap() {
        heap.emplace_back(0);
    }

    void push(int val) {
        heap.emplace_back(val);
        int i = heap.size() - 1;
        while (i > 1 && heap[i] < heap[i / 2]) {
            std::swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    int pop() {
        if (heap.size() == 1) {
            return -1;
        }
        int res = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int i = 1;
        while (i * 2 < heap.size()) {
            int smallest = i * 2;
            if (i * 2 + 1 < heap.size() && heap[i * 2 + 1] < heap[smallest]) {
                smallest = i * 2 + 1;
            }

            if (heap[smallest] < heap[i]) {
                std::swap(heap[smallest], heap[i]);
                i = smallest;
            } else {
                break;
            }
        }
        return res;
    }

    int top() {
        if (heap.size() == 1) {
            return -1;
        }
        return heap[1];
    }

    void heapify(const vector<int>& arr) {
        if (arr.empty()) {
            return;
        }
        auto temp = arr;
        temp.emplace_back(temp[0]);
        heap = temp;

        int cur = (heap.size() - 1) / 2;
        while (cur > 0) {
            int i = cur;
            while (i * 2 < heap.size()) {
                int smallest = i * 2;
                if (i * 2 + 1 < heap.size() && heap[i * 2 + 1] < heap[smallest]) {
                    smallest = i * 2 + 1;
                }
    
                if (heap[smallest] < heap[i]) {
                    std::swap(heap[smallest], heap[i]);
                    i = smallest;
                } else {
                    break;
                }
            }
            cur--;
        }
    }
};
