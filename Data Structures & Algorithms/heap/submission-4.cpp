class MinHeap {
private:
    std::vector<int> heap;

    void siftUp(int index) {
        while (index > 1 && heap[index] < heap[index / 2]) {
            std::swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }

    void siftDown(int index) {
        while (index * 2 < heap.size()) {
            int smallest = index * 2;
            if (index * 2 + 1 < heap.size() && heap[index * 2 + 1] < heap[smallest]) {
                smallest = index * 2 + 1;
            }

            if (heap[smallest] < heap[index]) {
                std::swap(heap[smallest], heap[index]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    MinHeap() {
        heap.emplace_back(0);
    }

    void push(int val) {
        heap.emplace_back(val);
        int i = heap.size() - 1;
        siftUp(i);
    }

    int pop() {
        if (heap.size() == 1) {
            return -1;
        }
        int res = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int i = 1;
        siftDown(i);
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
            siftDown(i);
            cur--;
        }
    }
};
